#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "stdlib.h"
#include "i2c.h"
#include "i2cport.h"


// Raw positions of the button signals in bytes 7 and 8 (combined as a 16 bit int))
// signals as per http://spinalcode.co.uk/2018/08/14/wii-classic-controller-protocol/
enum NESSignalBitMask {
  // from byte 7
  S_RIGHT     = (1 << 15), 
  S_DOWN      = (1 << 14), 
  S_SELECT    = (1 << 12), 
  S_START     = (1 << 10), 
  // from byte 8
  S_BUTTONB   = (1 << 6),  
  S_BUTTONA   = (1 << 4), 
  S_LEFT      = (1 << 1), 
  S_UP        = (1 << 0), 
};

/* mapping of the buttons into their position in the 8 bit response */
enum ControllerOutputBits {
  UP        = (1 << 0), 
  DOWN      = (1 << 1), 
  LEFT      = (1 << 2), 
  RIGHT     = (1 << 3), 
  SELECT    = (1 << 4), 
  START     = (1 << 5), 
  BUTTONB   = (1 << 6), 
  BUTTONA   = (1 << 7) 
};


void controller_id(struct I2CPort* port, uint8_t id[6]);
int16_t controller_state_raw(struct I2CPort* port);
uint8_t controller_state(struct I2CPort* port);
void controller_disable_encryption(struct I2CPort* port);
void controller_init(struct I2CPort* port);
#endif

