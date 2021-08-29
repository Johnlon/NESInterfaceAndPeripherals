/*
 * Implements a two digit seven segment common cathode display driver.
 * The same approach will also drive a common anode with the same PCB 
 * layout by reversing the high/low logic of the pins below.
 */

#include "mcc_generated_files/mcc.h"
#include "i2c.h"
#include "controller.h"

void output(uint8_t out);
uint8_t rand8(void);

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
void port_callbacks_init## PORTNO(struct I2CPort* port) { \
    port->sdaHi = port## PORTNO ##SdaHi; \
    port->sdaLo = port## PORTNO ##SdaLo; \
    port->sclHi = port## PORTNO ##SclHi; \
    port->sclLo = port## PORTNO ##SclLo; \
    port->sclInput = port## PORTNO ##SCLSetDigitalInput; \
    port->sclOutput = port## PORTNO ##SCLSetDigitalOutput; \
    port->sdaInput = port## PORTNO ##SDASetDigitalInput; \
    port->sdaOutput = port## PORTNO ##SDASetDigitalOutput; \
    port->sclRead = port## PORTNO ##SCLGetValue; \
    port->sdaRead = port## PORTNO ##SDAGetValue;     \
}

PORT_FN_DEF(1)
PORT_FN_DEF(2)

void setupShiftPort() {
    OUT_SCLK_SetPushPull();
    OUT_SCLK_SetDigitalOutput();
    OUT_SCLK_SetHigh();
    
    OUT_RCLK_SetPushPull();
    OUT_RCLK_SetDigitalOutput();
    OUT_RCLK_SetHigh();
    
    OUT_DATA1_SetPushPull();
    OUT_DATA1_SetDigitalOutput();
    OUT_DATA1_SetLow();
    
    OUT_DATA2_SetPushPull();
    OUT_DATA2_SetDigitalOutput();
    OUT_DATA2_SetLow();
    
    OUT_DATA3_SetPushPull();
    OUT_DATA3_SetDigitalOutput();
    OUT_DATA3_SetLow();
}

void serialClock() {
    OUT_SCLK_SetLow();
    dly();
    OUT_SCLK_SetHigh();
    dly();
}

void serialLatch() {
    OUT_RCLK_SetLow();
    dly();
    OUT_RCLK_SetHigh();
    dly();
}

void shiftOut(uint8_t value0, uint8_t value1, uint8_t value2) {
    
    for (int i = 7; i >= 0; i--) {
        OUT_DATA1_LAT = (value0 & 0x80) ? 1: 0;
        OUT_DATA2_LAT = (value1 & 0x80) ? 1: 0;
        OUT_DATA3_LAT = (value2 & 0x80) ? 1: 0;

        value0 = (uint8_t)(value0 << 1);
        value1 = (uint8_t)(value1 << 1);
        value2 = (uint8_t)(value2 << 1);
        
        serialClock();
    }
    serialLatch();
}

    
void main(void) {
   SYSTEM_Initialize();
    
    // skip a little time to allow controller to power up
    __delay_ms(100);
    
    port1Setup();
    port2Setup();
    
    struct I2CPort port1, port2;

    port_callbacks_init1(&port1);
    port_callbacks_init2(&port2);
        
    setupShiftPort();
            
    uint8_t id[6];
    controller_disable_encryption(&port1);
    controller_init(&port1);
    controller_id(&port1, id);

    controller_disable_encryption(&port2);
    controller_init(&port2);
    controller_id(&port2, id);

    // program starts with a slow I2C clock and we do init slowly - seems to make startup more reliable
    // switch from slow speed to higher speed.
    
    while (1) {
      
        uint8_t state1 = controller_state(&port1); 
        output(state1);
        
        uint8_t state2 = controller_state(&port2); 
        output(state2); 
    
        uint8_t state3 = rand8();
        shiftOut(state1, state2, state3); 
    }
}

void output(uint8_t out) {
    RAND_0_LAT = (out & 1);
    RAND_1_LAT = (out & 2) >> 1;
    RAND_2_LAT = (out & 4) >> 2;
    RAND_3_LAT = (out & 8) >> 3;
    RAND_4_LAT = (out & 16) >> 4;
    RAND_5_LAT = (out & 32) >> 5;
    RAND_6_LAT = (out & 64) >> 6;
    RAND_7_LAT = (out & 128) >> 7;

}

uint8_t rand8() {
    return  (uint8_t)(rand() % 256);
}

/**
 End of File
 */
