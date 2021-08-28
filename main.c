/*
 * Implements a two digit seven segment common cathode display driver.
 * The same approach will also drive a common anode with the same PCB 
 * layout by reversing the high/low logic of the pins below.
 */

#include "mcc_generated_files/mcc.h"
#include "i2c.h"
#include "controller.h"

void output(uint8_t out);

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
    port->setup = port## PORTNO ##Setup; \
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

    
void main(void) {
    SYSTEM_Initialize();
    
    port1Setup();
    port2Setup();
    
    struct I2CPort port1, port2;

    port_callbacks_init1(&port1);
    port_callbacks_init2(&port2);
        
    port1.setup();
    
    // wait a couple of secs before trying to talk to controller
    //__delay_ms(2*1000);
    
    uint8_t id[6];
    controller_disable_encryption(&port1);
    controller_init(&port1);
    controller_id(&port1, id);

    controller_disable_encryption(&port2);
    controller_init(&port2);
    controller_id(&port2, id);

    
    while (1) {
      
        //randUpdate();
        uint8_t state;
        
        state = controller_state(&port1); 
        output(state); 
        state = controller_state(&port2); 
        output(state); 
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

void randUpdate() {
    uint8_t r = (uint8_t)(rand() % 256);
    output(r);
}

/**
 End of File
 */
