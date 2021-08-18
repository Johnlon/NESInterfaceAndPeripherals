#include "mcc_generated_files/mcc.h"
#include "i2c.h"
#define I2C_WRITE 0
#define I2C_READ 1

#define CONTROLLER_ADDR (0x52 << 1)



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
//
//// I2C protocol bits
//uint8_t forWrite(uint8_t val) {
//    return (uint8_t)(val << 1);
//}
//uint8_t forRead(uint8_t val) {
//    return (uint8_t)(val << 1 | 0x01);
//}

// data line
#define SDA_ON (SDA_LAT=1)
#define SDA_OFF (SDA_LAT=0)

// clock line
#define SCL_ON (SCL_LAT=1)
#define SCL_OFF (SCL_LAT=0)

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
uint8_t readSDA() {
    // read the state of the SDA pin. if it's low then then the slave is pulling it low    
    SDA_TRIS = 1; // turn pin to an input
    bool val = SDA_PORT;    // read Acknowledge bit
    SDA_TRIS=0; // turn pin to an output
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
void i2cSetup() {
    SCL_SetDigitalOutput();
    SDA_SetDigitalOutput();
    SCL_SetOpenDrain();
    SDA_SetOpenDrain();
    SDA_SetPullup();
    SCL_SetPullup();
    SCL_ON;
    SDA_ON;
}

/* i2c start sequence.
 * A high-to-low transition on the SDA line while the SCL is high defines a START condition 
 */
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

void i2cClockStretch() {
    // added clock stretching as shown here https://github.com/theisolinearchip/nesmini_usb_adapter/blob/main/i2cattiny85/i2cattiny85.c
    // if it's being pulled low but slave then wait
    do{
    }while(readSCL() == 0);  
}

/* i2c stop sequence.
 * A low-to-high transition on the SDA line while the SCL is high defines a STOP condition.
*/
void i2cStop(){
    SDA_OFF;
    dly();
    SCL_ON;
    dly();
    
    i2cClockStretch();
    dly();
    
    SDA_ON;
    dly();
}

void i2cWriteBit(uint8_t bit){
    if (bit) SDA_ON;
    else SDA_OFF;
    dly();  
    SCL_ON; 
    dly();
    
    i2cClockStretch();
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
    SDA_ON; // port goes high - SDA is released
    dly();
    
    // if receiver is acking by pulling SDA low then it must do so before the clock goes high and then remain stable during the high.
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

    i2cClockStretch();
    dly();
    
    uint8_t bit = readSDA();
    
    SCL_OFF;
    dly();
 
    return bit; 
}

// when reading send a low to ack to the slave that data has been received ie nack
// if nack is low then a low will be sent to the slave - this is an ack.
// during a read an ack (low) should be sent to signal the desire to read more.)
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
    
    uint8_t ADDR=0x52 << 1;
    i2cStart();
    i2cWrite(ADDR | I2C_WRITE); // Transfer the slave address plus 
    dly();

    i2cWrite(0xaa); // Transfer the slave address plus 
    dly();
    dly();

    for (int i = 0; i<256; i++) {
        unsigned ack = i2cWrite((uint8_t)i); // Register address where we want to write
    }
    i2cStop();
}

// see https://github.com/theisolinearchip/nesmini_usb_adapter/blob/main/nesminicontrollerdrv.c
// https://github.com/djtulan/nunchuk64/blob/master/src/controller.c
void controller_init() {

	// According to http://wiibrew.org/wiki/Wiimote/Extension_Controllers the way to initialize the
	// SNES Mini Controller is by writting 0x55 to 0xF0 and 0x00 to 0xFB BUT it seems it works only
	// with the first write. The NES Mini does not require the init, but works anyway with it

    // SEE EXPLANATION HERE THAT THIS DISABLED ENCRYPTION : https://wiibrew.org/wiki/Wiimote/Extension_Controllers
    
	i2cStart();
	i2cWrite(CONTROLLER_ADDR | I2C_WRITE); // 0x52
	i2cWrite(0xF0); // "address"
	i2cWrite(0x55); // info to write
	i2cStop();
    dly(); 
    
    i2cStart();
	i2cWrite(CONTROLLER_ADDR | I2C_WRITE); // 0x52
	i2cWrite(0xFB); // "address"
	i2cWrite(0x00); // info to write
	i2cStop();
    dly(); 
    
    i2cStart();
	i2cWrite(CONTROLLER_ADDR | I2C_WRITE); // 0x52
	i2cWrite(0xFE); // "address"
	i2cWrite(0x00); // info to write
	i2cStop();
    dly(); 
}

/* https://wiibrew.org/wiki/Wiimote/Extension_Controllers
 The key is written in 3 blocks of 6, 6, and 4 bytes.
 */
void controller_disable_encryption() {

    i2cStart();
	i2cWrite(CONTROLLER_ADDR | I2C_WRITE); 
	i2cWrite(0xF0); // "address"
	i2cWrite(0xAA); // info to write
	i2cStop();
    dly(); 
    
    i2cStart();
	i2cWrite(CONTROLLER_ADDR | I2C_WRITE); // 0x52
	i2cWrite(0x40); 
    for (uint8_t i = 0; i < 6; i++)
        i2cWrite(0x00);
    i2cStop();
    dly(); 

    i2cStart();
	i2cWrite(CONTROLLER_ADDR | I2C_WRITE); // 0x52
	i2cWrite(0x40); 
    for (uint8_t i = 0; i < 6; i++)
        i2cWrite(0x00);
    i2cStop();
    dly();     

    i2cStart();
	i2cWrite(CONTROLLER_ADDR | I2C_WRITE); // 0x52
	i2cWrite(0x40); 
    for (uint8_t i = 0; i < 4; i++)
        i2cWrite(0x00);
    i2cStop();
    dly(); 
}

/* see read_id https://github.com/djtulan/nunchuk64/blob/master/src/controller.c
 got : 0x01 0x00 0xa4 0x20 0x00 0x01 =   ID_NES_Classic_Mini_Clone_Encrypted
 **/
void controller_id(uint8_t id[6]) {

    i2cStart();
	i2cWrite(CONTROLLER_ADDR | I2C_WRITE); 
	i2cWrite(0xFA); 
    i2cStop();
    dly(); 
    

    i2cStart();
	i2cWrite(CONTROLLER_ADDR | I2C_READ);
    
    for (char x = 0; x < 6; x++) {
        bool allBytesRead = x >= 5;
        
        // send a low ack to indicate we are not finished 
		id[x] = i2cRead(allBytesRead); // nack ("not gonna ask for more" / "stop" / "omgexplosions" when fetching the last one)
	}
    i2cStop();
    dly(); 
}

uint8_t nes_get_state8() {
    uint8_t data[2];
    uint16_t state = nes_get_state(data);
    uint8_t joystick = 0;

    if ((state & S_UP)) {
        joystick |= UP;
    }
    if ((state & S_DOWN)) {
        joystick |= DOWN;
    }
    if ((state & S_LEFT)) {
        joystick |= LEFT;
    }
    if ((state & S_RIGHT)) {
        joystick |= RIGHT;
    }
    if ((state & S_BUTTONA)) {
        joystick |= BUTTONA;
    }
    if ((state & S_BUTTONB)) {
        joystick |= BUTTONB;
    }
    if ((state & S_SELECT)) {
        joystick |= SELECT;
    }
    if ((state & S_START)) {
        joystick |= START;
    }
    
    return joystick;
}

uint16_t nes_get_state(uint8_t data[2]) {
	i2cStart();

	i2cWrite(CONTROLLER_ADDR | I2C_WRITE); // write
	i2cWrite(0x00); // we're gonna read from 0x00
	i2cStop();

    dlyLong(); 

	i2cStart();

	i2cWrite(CONTROLLER_ADDR | I2C_READ); // read

	// Correct logic: read 6 bytes, use only the last two ones
	// (need to "read" the first 4 bytes in order
	// to "advance" to the last two ones)
    
    // HOWEVER my controllers have this bug : https://github.com/dmadison/NintendoExtensionCtrl/issues/33
    // Need to read 8 bytes and keep the last two rather than 6 and keep the last two.
	uint16_t state = 0;
	uint8_t read = 0;
    int controllerBytes = 8;
	for (char x = 0; x < controllerBytes; x++) {
        bool allBytesRead = x >= (controllerBytes-1);
        
        // send a low ack to indicate we are not finished 
		read = i2cRead(allBytesRead); // nack ("not gonna ask for more" / "stop" / "omgexplosions" when fetching the last one)

        if (x == controllerBytes-2) {
            data[0] = read; // "upper"
        }
        
        if (x == controllerBytes-1) {
            data[1] = read; // "lower"
        }
	
        if (x >= (controllerBytes-2)) {
//			read ^= 0xFF; // "255 - read"
			state |= read;
			if (x == (controllerBytes-2)) state <<= 8;
		}
	}

	i2cStop();

	return state;
}

uint16_t nes_device_id() {
	i2cStart();

	i2cWrite(CONTROLLER_ADDR | I2C_WRITE); // write
	i2cWrite(0xfa); // we're gonna read from 0x00
	i2cStop();

	dly(); // the nes mini controller seems to work fine without this delay

	i2cStart();

	i2cWrite(CONTROLLER_ADDR | I2C_READ); // read

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
			//read ^= 0xFF; // "255 - read"
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
            i2cWrite( (addr << 1) | I2C_WRITE ); 
            i2cStop();
        }
    }
}



// https://github.com/nyh-workshop/nesClassicController/blob/master/nesClassicController.cpp

//uint8_t readNes(uint8_t data) {
//    uint8_t addr=forRead(CONTROLLER_ADDR); // low bit clear therefore write
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
