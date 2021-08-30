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
    
    struct I2CPort port1 = createPort1();
    struct I2CPort port2 = createPort2();
       
    setupShiftPort();
            
    uint8_t id[6];
    controllerDisableEncryption(&port1);
    controllerInit(&port1);
    controllerId(&port1, id);

    controllerDisableEncryption(&port2);
    controllerInit(&port2);
    controllerId(&port2, id);

    // program starts with a slow I2C clock and we do init slowly - seems to make startup more reliable
    // switch from slow speed to higher speed.
    
    while (1) {
      
        uint8_t state1 = controllerState(&port1); 
        output(state1);
        
        uint8_t state2 = controllerState(&port2); 
        output(state2); 
    
        uint8_t state3 = rand8();
        shiftOut(state1, state2, state3); 
    }
}

void output(uint8_t out) {
    DATA_0_LAT = (out & 1);
    DATA_1_LAT = (out & 2) >> 1;
    DATA_2_LAT = (out & 4) >> 2;
    DATA_3_LAT = (out & 8) >> 3;
    DATA_4_LAT = (out & 16) >> 4;
    DATA_5_LAT = (out & 32) >> 5;
    DATA_6_LAT = (out & 64) >> 6;
    DATA_7_LAT = (out & 128) >> 7;

}

uint8_t rand8() {
    return  (uint8_t)(rand() % 256);
}

/**
 End of File
 */
