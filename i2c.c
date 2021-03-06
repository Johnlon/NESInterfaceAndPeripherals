#include "xc.h"
#include "mcc_generated_files/mcc.h"
#include "i2c.h"

#define I2C_WRITE 0
#define I2C_READ 1

// https://github.com/theisolinearchip/nesmini_usb_adapter
// http://www.bitbanging.space/posts/bitbang-i2c
// https://www.robot-electronics.co.uk/i2c-tutorial
// https://sudonull.com/post/21200-Connect-the-gamepad-from-the-Nintendo-Classic-Mini-to-the-Raspberry-pi


// All participants on the SDA/SCL line are expected to be open collector/drain so 
// when a pin is driven high then it is actually not driven at all and so to get reliable logic levels 
// one must put a pull-up resistor on the SDA/SCL lines.
// This mean that if the I2C master parks an output pin in the high state then it's effectively 
// released control of the wire and so the slave can actually drive the pin if it need to send data like 
// an ack back to the master.
// So in the code below we see the SDA line being set high prior to reading back the Ack state of the pin. 
// With the output set high then reading the output pin, if we find it low then 
// the slave must be responsible for asserting a 0 on that line and this signals an Ack.

// In an ardiuino one can read from pins despite them having been setup as digital ouputs and in this case 
// the read actually reflects the current voltage at that pin. 
// In arduino each pin can be accessed either via the "PORT" register which is used to write to a pin 
// or the "PIN" register which is used to read it..
// So if the arduino output attempting to drive the pin high using the PORT but the pin is shorted to ground 
// then when we read the pin via PIN we will see a 0. 

// However, I'm writing this for the PIC16F micro and it also has bit accessors for each pin called 
// LAT and PORT and these behave similarly to the arduino. 
// You can write to either the PORT or LAT and this sets the output value, then if read the pin via LAT then you are merely 
// reading the value previously written to the port latch, however, 
// however if you read the pin via PORT then you are sensing the actual line voltage. 

// Having said the above about the PIC PORT register ..
// In the ack functions below I'm not merely reading the wire value by reading the PORT, but I'm
// actually flipping the pin to an input momentarily before reading it. I'm doing this however 
// because in the MPLAB simulator reading a PORT when the pin is an output doesn't seem to work.
// So, instead I flip the pin to an input before sampling it.
// In the real hardware this is probably unnecessary however since this logic is actually fine in both the
// the HW and the simulator I'm leaving it like this.
// to use this then open the PIC MPLab pin configurator and name two pins as SDA and SCL.

/* Read Ack/Nack
 * https://learn.sparkfun.com/tutorials/i2c/all
 * If the receiving device does not pull the SDA line low before the 9th clock pulse, 
 * it can be inferred that the receiving device either did not receive the data 
 * or did not know how to parse the message. In that case, the exchange halts, 
 * and it's up to the controller of the system to decide how to proceed. 
*/
/* TI document .. https://www.ti.com/lit/an/slva704/slva704.pdf?ts=1629155123445#:~:text=I2C%20communication%20with%20this%20device,high%20defines%20a%20START%20condition.
When the SDA line remains high during the ACK/NACK-related clock period, this is interpreted as a NACK. 
There are several conditions that lead to the generation of a NACK:
1. The receiver is unable to receive or transmit because it is performing some real-time function and is
not ready to start communication with the master.
2. During the transfer, the receiver gets data or commands that it does not understand.
3. During the transfer, the receiver cannot receive any more data bytes.
4. A master-receiver is done reading data and indicates this to the slave through a NACK
 */
uint8_t readSDA(struct I2CPort* port) {
    // read the state of the SDA pin. if it's low then then the slave is pulling it low    
    port->sdaSetAsInput();
    bool val = port->sdaRead();
    port->sdaSetAsOutput();
    return val;
}

uint8_t readSCL(struct I2CPort* port) {    
    port->sclSetAsInput();
    bool val = port->sclRead();    // Acknowledge bit
    port->sclSetAsOutput();
    return val;
}

void dly(){
    __delay_us(1);
}

void dlyLong(){
    __delay_us(100);
}

void i2cStart(struct I2CPort* port){
    port->sdaHi();
    dly();
    port->sclHi();
    dly();
    
    port->sdaLo();
    dly();
    port->sclLo();
    dly();
}

void i2cClockStretch(struct I2CPort* port) {
    // added clock stretching as shown here https://github.com/theisolinearchip/nesmini_usb_adapter/blob/main/i2cattiny85/i2cattiny85.c
    // if it's being pulled low but slave then wait
    do{
    }while(port->sclRead() == 0);  
}

void i2cStop(struct I2CPort* port){
    port->sdaLo();
    dly();
    port->sclHi();
    dly();
    
    i2cClockStretch(port);
    dly();
    
    port->sdaHi();
    dly();
}

void i2cWriteBit(struct I2CPort* port, uint8_t bit){
    if (bit) port->sdaHi();
    else port->sdaLo();
    dly();  
    
    port->sclHi(); 
    dly();
    
    i2cClockStretch(port);
    
    port->sclLo();
    dly();
}

bool i2cWrite(struct I2CPort* port, uint8_t dat){
    
    // clock out 8 bits
    for(uint8_t i = 8; i; i--){
        uint8_t bit = (dat & 0x80); //Mask for the eight bit
        dat<<=1;  //Move 
        
        i2cWriteBit(port, bit);
    }
    
    // on 9th clock read back in the ack bit
    port->sdaHi(); // port goes high - SDA is released
    dly();
    
    // if receiver is acking by pulling SDA low then it must do so before the clock goes high and then remain stable during the high.
    port->sclHi(); 
    dly();
    
    bool ack = readSDA(port);    // Acknowledge bit
    
    port->sclLo();
    
    return ack;
}

uint8_t i2cReadBit(struct I2CPort* port){
    // make sure SDA is released and clock a value onto the SDA line
    port->sdaHi();
    port->sclHi();
    dly();

    i2cClockStretch(port);
    
    uint8_t bit = port->sdaRead();
    
    port->sclLo();
    dly();
 
    return bit; 
}

// when reading send a low to ack to the slave that data has been received ie nack
// if nack is low then a low will be sent to the slave - this is an ack.
// during a read an ack (low) should be sent to signal the desire to read more.)
uint8_t i2cRead(struct I2CPort* port, bool nack){
    uint8_t dat = 0;
    port->sdaHi();
    for( uint8_t i =0; i<8; i++){
        dat <<= 1;
        uint8_t bit = i2cReadBit(port);
        if(bit) dat |=1;
    }
    
    // send a 0 bit (ie nack) if we want to read more  
    i2cWriteBit(port, nack);

    dly();
    port->sclLo();
    port->sdaHi();
    return(dat); 
}


