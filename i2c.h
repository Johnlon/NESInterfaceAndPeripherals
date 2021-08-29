#ifndef I2C_H
#define I2C_H

#include <stdint.h>
#include <stdbool.h>

#include "xc.h"


bool longDelay=true;

struct I2CPort {
    void ((*sdaHi)(void));
    void ((*sdaLo)(void));
    void ((*sclHi)(void));
    void ((*sclLo)(void));
    void ((*sclInput)(void));
    void ((*sclOutput)(void));
    void ((*sdaInput)(void));
    void ((*sdaOutput)(void));
    
    unsigned char ((*sdaRead)(void));
    unsigned char((*sclRead)(void));

};

void i2cSetup(struct I2CPort* port);
void i2cStart(struct I2CPort* port);
void i2cStop(struct I2CPort* port);
bool i2cWrite(struct I2CPort* port, uint8_t dat);
uint8_t i2cRead(struct I2CPort* port, bool nack);


void dly(void);
void dlyLong(void);


#endif
