#include "mcc_generated_files/mcc.h"

// https://github.com/theisolinearchip/nesmini_usb_adapter
// http://www.bitbanging.space/posts/bitbang-i2c
// https://www.robot-electronics.co.uk/i2c-tutorial


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

// I2C protocol bits
uint8_t forWrite(uint8_t val) {
    return (uint8_t)(val << 1);
}
uint8_t forRead(uint8_t val) {
    return (uint8_t)(val << 1 | 0x01);
}

// data line
#define SDA_ON (SDA_LAT=1)
#define SDA_OFF (SDA_LAT=0)

// clock line
#define SCL_ON (SCL_LAT=1)
#define SCL_OFF (SCL_LAT=0)

// Ack is explained here .. https://learn.sparkfun.com/tutorials/i2c/all
uint8_t readSDA() {
    // read the state of the SDA pin. if it's low then then the slave is pulling it low
    
    SDA_TRIS = 1; 
    bool val = SDA_PORT;    // Acknowledge bit
    SDA_TRIS=0;
    return val;
}

uint8_t readSCL() {    
    SCL_TRIS=1; 
    bool val = SCL_PORT;    // Acknowledge bit
    SCL_TRIS=0;
    return val;
}

inline void dly(){
    __delay_us(10);
}

inline void dlyLong(){
    __delay_us(100);
}

//  setup the pin types OR do this using the MPLab MCC tool.
void i2cInit() {
    SCL_SetDigitalOutput();
    SDA_SetDigitalOutput();
    SCL_SetOpenDrain();
    SDA_SetOpenDrain();
    SDA_SetPullup();
    SCL_SetPullup();
    SCL_ON;
    SDA_ON;
}

/*  i2c start sequence */
void i2cStart(){
    SDA_ON;
    dly();
    SCL_ON;
    dly();
    SDA_OFF;
    dly();
    SCL_OFF;
    dly();
}

/*  i2c stop sequence */
void i2cStop(){
    SDA_OFF;
    dly();
    SCL_ON;
    dly();
    
    do{
        SCL_ON; /// time waste
    }while(readSCL() == 0);  //added clock stretching as shown here https://github.com/theisolinearchip/nesmini_usb_adapter/blob/main/i2cattiny85/i2cattiny85.c
        
    dly();
    
    SDA_ON;
    dly();
}

void i2cWriteBit(uint8_t bit){
    if (bit) SDA_ON;
    else SDA_OFF;
    dly();
      
    SCL_ON; 
    do{
       //added clock stretching as shown here https://github.com/theisolinearchip/nesmini_usb_adapter/blob/main/i2cattiny85/i2cattiny85.c   
    }while(readSCL() == 0);  
    dly();
    
    SCL_OFF;
    dly();


}


/* Transmit 8 bit data to slave */
bool i2cWrite(uint8_t dat){
    
    // clock out 8 bits
    for(uint8_t i = 8; i; i--){
        uint8_t bit = (dat & 0x80); //Mask for the eight bit
        dat<<=1;  //Move 
        
        i2cWriteBit(bit);
        dly();
    }
    
    // on 9th clock read back in the ack bit
    SDA_ON; // port goes high
    SCL_ON;
    dly();
    
    bool ack = readSDA();    // Acknowledge bit
    
    SCL_OFF;
    
    return ack;
}


uint8_t i2cReadBit(){
    SDA_ON;
    SCL_ON;
    dly();

    do{
        // pause
    }while(readSCL() == 0);  //clock stretching
    dly();
    
    uint8_t bit = readSDA();
    
    SCL_OFF;
    dly();
 
    return bit; 
}

// low to ack ie nack
uint8_t i2cRead(bool nack){
    uint8_t dat = 0;
    SDA_ON;
    for( uint8_t i =0; i<8; i++){
        dat <<= 1;
        uint8_t bit = i2cReadBit();
        if(bit) dat |=1;
    }
    
    // send a 0 bit (ie nack) if we want to read more  
    i2cWriteBit(nack);

    dly();
    SCL_OFF;
    SDA_ON;
    return(dat); 
}


// https://sudonull.com/post/21200-Connect-the-gamepad-from-the-Nintendo-Classic-Mini-to-the-Raspberry-pi

void i2cDemo() {
    
    uint8_t ADDR=0x52;
    i2cStart();
    i2cWrite(forWrite(ADDR)); // Transfer the slave address plus 
    dly();

    i2cWrite(0xaa); // Transfer the slave address plus 
    dly();
    dly();

    for (int i = 0; i<256; i++) {
        unsigned ack = i2cWrite((uint8_t)i); // Register address where we want to write
    }
    i2cStop();
}


#define NES_ADDR 0x52
// A4
#define NES_I2C_ADDRESS_WRITE (NES_ADDR << 1)
// A5
#define NES_I2C_ADDRESS_READ  ((NES_ADDR << 1) | 1)


// see https://github.com/theisolinearchip/nesmini_usb_adapter/blob/main/nesminicontrollerdrv.c
void snes_init() {

	// According to http://wiibrew.org/wiki/Wiimote/Extension_Controllers the way to initialize the
	// SNES Mini Controller is by writting 0x55 to 0xF0 and 0x00 to 0xFB BUT it seems it works only
	// with the first write. The NES Mini does not require the init, but works anyway with it

    // SEE EXPLANATION HERE THAT THIS DISABLED ENCRYPTION : https://wiibrew.org/wiki/Wiimote/Extension_Controllers
    
	i2cStart();
	i2cWrite(NES_I2C_ADDRESS_WRITE); // 0x52
	i2cWrite(0xF0); // "address"
	i2cWrite(0x55); // info to write
	i2cStop();
    dly(); // the nes mini controller seems to work fine without this delay

    i2cStart();
	i2cWrite(NES_I2C_ADDRESS_WRITE); // 0x52
	i2cWrite(0xFB); // "address"
	i2cWrite(0x00); // info to write
	i2cStop();
    dly(); // the nes mini controller seems to work fine without this delay

}

uint16_t nes_get_state() {
	i2cStart();

	i2cWrite(NES_I2C_ADDRESS_WRITE); // write
//	i2cWrite(0x40); // we're gonna read from 0x00
	i2cWrite(0x00); // we're gonna read from 0x00
	i2cStop();

    dlyLong(); 

	i2cStart();

	i2cWrite(NES_I2C_ADDRESS_READ); // read

	// read 6 bytes, use only the last two ones
	// (need to "read" the first 4 bytes in order
	// to "advance" to the last two ones)
	uint16_t state = 0;
	uint8_t read = 0;
	for (char x = 0; x < 6; x++) {
        bool allBytesRead = x >= 5;
        
        // send a low ack to indicate we are not finished 
		read = i2cRead(allBytesRead); // nack ("not gonna ask for more" / "stop" / "omgexplosions" when fetching the last one)

		if (x >= 4) {
			read ^= 0xFF; // "255 - read"
			state |= read;
			if (x == 4) state <<= 8;
		}
	}

	i2cStop();

	return state;
}

uint16_t nes_device_id() {
	i2cStart();

	i2cWrite(NES_I2C_ADDRESS_WRITE); // write
	i2cWrite(0xfa); // we're gonna read from 0x00
	i2cStop();

	dly(); // the nes mini controller seems to work fine without this delay

	i2cStart();

	i2cWrite(NES_I2C_ADDRESS_READ); // read

	// read 6 bytes, use only the last two ones
	// (need to "read" the first 4 bytes in order
	// to "advance" to the last two ones)
	uint16_t state = 0;
	uint8_t read = 0;
	for (char x = 0; x < 6; x++) {
        bool allBytesRead = x >= 5;
        
        // send a low ack to indicate we are not finished 
		read = i2cRead(allBytesRead); // nack ("not gonna ask for more" / "stop" / "omgexplosions" when fetching the last one)

		if (x >= 4) {
			read ^= 0xFF; // "255 - read"
			state |= read;
			if (x == 4) state <<= 8;
		}
	}

	i2cStop();

	return state;
}

void i2cIdentify() {
    
    while(1==1) {
    	dly(); 
        for (int addr = 0; addr < 127; addr++) {
            i2cStart();
            i2cWrite(addr << 1); 
            i2cStop();
        }
    }
}



// https://github.com/nyh-workshop/nesClassicController/blob/master/nesClassicController.cpp

//uint8_t readNes(uint8_t data) {
//    uint8_t addr=forRead(NES_ADDR); // low bit clear therefore write
//    
//    start();              // send start sequence
//    Tx(addr);             // I2C address with R/W bit clear
//    // need to write 00 to register 0x40
//    Tx(0x00);             // 
//    Tx(0x40);             // 
//    
//    start();              // send start sequence
//    Tx(0);             // I2C address with R/W bit clear
//    stop();
//}
