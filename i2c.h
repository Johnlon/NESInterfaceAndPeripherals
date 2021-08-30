#ifndef I2C_H
#define I2C_H

#include <stdint.h>
#include <stdbool.h>

#include "xc.h"


bool longDelay=true;

struct I2CPort {
    void ((*setup)(void));

    void ((*sdaHi)(void));
    void ((*sdaLo)(void));
    void ((*sclHi)(void));
    void ((*sclLo)(void));
    void ((*sclSetAsInput)(void));
    void ((*sclSetAsOutput)(void));
    void ((*sdaSetAsInput)(void));
    void ((*sdaSetAsOutput)(void));

    unsigned char ((*sdaRead)(void));
    unsigned char((*sclRead)(void));
};

/* Utility macro for creating the necessary hook functions to implement the I2C 
 * protocol on a PIC micro. This code assumes that the I2C ports on this micro 
 * are called SCL1/SDA1, SCL2/SDA2 etc.
 */
#define PORT_FN_DEF(PORTNO) \
    \
    void port## PORTNO ##SdaHi(void) { \
       SDA## PORTNO ##_LAT=1; \
    } \
    \
    void port## PORTNO ##SdaLo(void) { \
       SDA## PORTNO ##_LAT=0; \
    } \
    \
    void port## PORTNO ##SclHi(void) { \
       SCL## PORTNO ##_LAT=1; \
    } \
    \
    void port## PORTNO ##SclLo(void) { \
       SCL## PORTNO ##_LAT=0; \
    } \
    \
    void port## PORTNO ##SCLSetDigitalInput(void) { \
       SCL## PORTNO ##_SetDigitalInput(); \
    } \
    \
    void port## PORTNO ##SCLSetDigitalOutput(void) { \
       SCL## PORTNO ##_SetDigitalOutput(); \
    } \
    \
    void port## PORTNO ##SDASetDigitalInput(void) { \
       SDA## PORTNO ##_SetDigitalInput(); \
    } \
    \
    void port## PORTNO ##SDASetDigitalOutput(void) { \
       SDA## PORTNO ##_SetDigitalOutput(); \
    } \
    \
    uint8_t port## PORTNO ##SDAGetValue(void) { \
       return SDA## PORTNO ##_GetValue(); \
    } \
    \
    uint8_t port## PORTNO ##SCLGetValue(void) { \
       return SCL## PORTNO ##_GetValue(); \
    } \
    \
    void port## PORTNO ##Setup() { \
       SCL## PORTNO ##_SetDigitalOutput(); \
       SDA## PORTNO ##_SetDigitalOutput(); \
       SCL## PORTNO ##_SetOpenDrain(); \
       SDA## PORTNO ##_SetOpenDrain(); \
       SDA## PORTNO ##_SetPullup(); \
       SCL## PORTNO ##_SetPullup(); \
       SCL## PORTNO ##_SetHigh(); \
       SDA## PORTNO ##_SetHigh();  \
    } \
    \
    struct I2CPort createPort## PORTNO ##() { \
       struct I2CPort port; \
       SCL## PORTNO ##_SetDigitalOutput(); \
       SDA## PORTNO ##_SetDigitalOutput(); \
       SCL## PORTNO ##_SetOpenDrain(); \
       SDA## PORTNO ##_SetOpenDrain(); \
       SDA## PORTNO ##_SetPullup(); \
       SCL## PORTNO ##_SetPullup(); \
       SCL## PORTNO ##_SetHigh(); \
       SDA## PORTNO ##_SetHigh();  \
       \
       port.setup = port## PORTNO ##Setup; \
       port.sdaHi = port## PORTNO ##SdaHi; \
       port.sdaLo = port## PORTNO ##SdaLo; \
       port.sclHi = port## PORTNO ##SclHi; \
       port.sclLo = port## PORTNO ##SclLo; \
       port.sclSetAsInput = port## PORTNO ##SCLSetDigitalInput; \
       port.sclSetAsOutput = port## PORTNO ##SCLSetDigitalOutput; \
       port.sdaSetAsInput = port## PORTNO ##SDASetDigitalInput; \
       port.sdaSetAsOutput = port## PORTNO ##SDASetDigitalOutput; \
       port.sclRead = port## PORTNO ##SCLGetValue; \
       port.sdaRead = port## PORTNO ##SDAGetValue;     \
       return port; \
    }



void i2cSetup(struct I2CPort* port);
void i2cStart(struct I2CPort* port);
void i2cStop(struct I2CPort* port);
bool i2cWrite(struct I2CPort* port, uint8_t dat);
uint8_t i2cRead(struct I2CPort* port, bool nack);


void dly(void);
void dlyLong(void);


#endif
