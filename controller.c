
#include "xc.h"
#include "mcc_generated_files/mcc.h"
#include "i2c.h"
#include "controller.h"


#define I2C_WRITE 0
#define I2C_READ 1

#define CONTROLLER_ADDR (0x52 << 1)


// see https://github.com/theisolinearchip/nesmini_usb_adapter/blob/main/nesminicontrollerdrv.c
// https://github.com/djtulan/nunchuk64/blob/master/src/controller.c
void controller_init(struct I2CPort* port) {

	// According to http://wiibrew.org/wiki/Wiimote/Extension_Controllers the way to initialize the
	// SNES Mini Controller is by writting 0x55 to 0xF0 and 0x00 to 0xFB BUT it seems it works only
	// with the first write. The NES Mini does not require the init, but works anyway with it
     
    // SEE EXPLANATION HERE THAT THIS DISABLED ENCRYPTION : https://wiibrew.org/wiki/Wiimote/Extension_Controllers
    
	i2cStart(port);
	i2cWrite(port, CONTROLLER_ADDR | I2C_WRITE); // 0x52
	i2cWrite(port, 0xF0); // "address"
	i2cWrite(port, 0x55); // info to write
	i2cStop(port);
    dly(); 
    
    i2cStart(port);
	i2cWrite(port, CONTROLLER_ADDR | I2C_WRITE); // 0x52
	i2cWrite(port, 0xFB); // "address"
	i2cWrite(port, 0x00); // info to write
	i2cStop(port);
    dly(); 
    
    i2cStart(port);
	i2cWrite(port, CONTROLLER_ADDR | I2C_WRITE); // 0x52
	i2cWrite(port, 0xFE); // "address"
	i2cWrite(port, 0x03); // info to write
	i2cStop(port);
    dly(); 
}

/* https://wiibrew.org/wiki/Wiimote/Extension_Controllers
 The key is written in 3 blocks of 6, 6, and 4 bytes.
 */
void controller_disable_encryption(struct I2CPort* port) {
       
	i2cWrite(port,CONTROLLER_ADDR | I2C_WRITE); 
	i2cWrite(port,0xF0); // "address"
	i2cWrite(port,0xAA); // info to write
	i2cStop(port);
    dly(); 
    
    i2cStart(port);
	i2cWrite(port, CONTROLLER_ADDR | I2C_WRITE); // 0x52
	i2cWrite(port,0x40); 
    for (uint8_t i = 0; i < 6; i++)
        i2cWrite(port,0x00);
    i2cStop(port);
    dly(); 

    i2cStart(port);
	i2cWrite(port,CONTROLLER_ADDR | I2C_WRITE); // 0x52
	i2cWrite(port,0x40); 
    for (uint8_t i = 0; i < 6; i++)
        i2cWrite(port,0x00);
    i2cStop(port);
    dly();     

    i2cStart(port);
	i2cWrite(port,CONTROLLER_ADDR | I2C_WRITE); // 0x52
	i2cWrite(port,0x40); 
    for (uint8_t i = 0; i < 4; i++)
        i2cWrite(port,0x00);
    i2cStop(port);
    dly(); 
}

/* see read_id https://github.com/djtulan/nunchuk64/blob/master/src/controller.c
 got : 0x01 0x00 0xa4 0x20 0x00 0x01 =   ID_NES_Classic_Mini_Clone_Encrypted
 **/
void controller_id(struct I2CPort* port, uint8_t id[6]) {

    i2cStart(port);
	i2cWrite(port,CONTROLLER_ADDR | I2C_WRITE); 
	i2cWrite(port,0xFA); 
    i2cStop(port);
    dly(); 
    
    i2cStart(port);
	i2cWrite(port,CONTROLLER_ADDR | I2C_READ);
    
    for (char x = 0; x < 6; x++) {
        bool allBytesRead = x >= 5;
        
        // send a low ack to indicate we are not finished 
		id[x] = i2cRead(port,allBytesRead); // nack ("not gonna ask for more" / "stop" / "omgexplosions" when fetching the last one)
	}
    i2cStop(port);
    dly(); 
}

uint8_t controller_state(struct I2CPort* port) {
    // result is active low 
    int state = controller_state_raw(port);
    
    // also active low
    uint8_t padValue = 0;

    if ((state & S_UP)) {
        padValue |= UP;
    }
    if ((state & S_DOWN)) {
        padValue |= DOWN;
    }
    if ((state & S_LEFT)) {
        padValue |= LEFT;
    }
    if ((state & S_RIGHT)) {
        padValue |= RIGHT;
    }
    if ((state & S_BUTTONA)) {
        padValue |= BUTTONA;
    }
    if ((state & S_BUTTONB)) {
        padValue |= BUTTONB;
    }
    if ((state & S_SELECT)) {
        padValue |= SELECT;
    }
    if ((state & S_START)) {
        padValue |= START;
    }
    
    
    // flip to active high
    return padValue ^ 0xff;
}

int16_t controller_state_raw(struct I2CPort* port) {
	i2cStart(port);

	i2cWrite(port,CONTROLLER_ADDR | I2C_WRITE); // write
	i2cWrite(port,0x00); // we're gonna read from 0x00
	i2cStop(port);

    dlyLong(); 

	i2cStart(port);

	i2cWrite(port,CONTROLLER_ADDR | I2C_READ); // read

	// Correct logic: read 6 bytes, use only the last two ones
	// (need to "read" the first 4 bytes in order
	// to "advance" to the last two ones)
    
    // HOWEVER my controllers have this bug : https://github.com/dmadison/NintendoExtensionCtrl/issues/33
    // Need to read 8 bytes and keep the last two rather than 6 and keep the last two.
	int16_t state = 0;
	int controllerBytes = 8;
	for (char x = 0; x < controllerBytes; x++) {
        bool allBytesRead = x >= (controllerBytes-1);
        
        // send a low ack to indicate we are not finished 
		uint8_t read = i2cRead(port,allBytesRead); // nack ("not gonna ask for more" / "stop" / "omgexplosions" when fetching the last one)
	
        if (x >= (controllerBytes-2)) {
//			read ^= 0xFF; // "255 - read"
			state |= read;
			if (x == (controllerBytes-2)) state <<= 8;
		}
	}

	i2cStop(port);

	return state;
}

