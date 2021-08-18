#ifndef I2C_H
#define I2C_H

#include <stdint.h>
#include <stdbool.h>

#include "xc.h"

void i2cDemo(void); 
void i2cSetup(void);
void i2cStart(void);
void i2cStop(void);
bool i2cWrite(uint8_t dat);
uint8_t i2cRead(bool nack);
void dly(void);
void dlyLong(void);

#endif
