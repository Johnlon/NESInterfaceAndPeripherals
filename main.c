/*
 * Implements a two digit seven segment common cathode display driver.
 * The same approach will also drive a common anode with the same PCB 
 * layout by reversing the high/low logic of the pins below.
 */

#include "mcc_generated_files/mcc.h"
typedef unsigned char result_t;

void output(result_t out) {
    RAND_0_LAT = (out & 1);
    RAND_1_LAT = (out & 2) >> 1;
    RAND_2_LAT = (out & 4) >> 2;
    RAND_3_LAT = (out & 8) >> 3;
    RAND_4_LAT = (out & 16) >> 4;
    RAND_5_LAT = (out & 32) >> 5;
    RAND_6_LAT = (out & 64) >> 6;
    RAND_7_LAT = (out & 128) >> 7;

}

void pause() {
    //__delay_us(1);
}
//
//void nesInit() {
//    // set clock to inactive low state before starting transfer
//    NES_CLK_SetLow();
//    NES_LATCH_SetLow();
//}
//
//void nesLatch() {
//    // load controller's 4021 shift register on +ve edge of latch
//    NES_LATCH_SetHigh();
//    NES_LATCH_SetLow();
//}
//
//void nesClock() {
//    NES_CLK_SetHigh();
//    NES_CLK_SetLow();
//}
//
//void rcvInit() {
//    // set clock to inactive low state before starting transfer
//    OUT_CLK_SetLow();
//    OUT_LATCH_SetLow();    
//}
//
//void rcvLatch() {
//    // 74595 latches data into output reg on +ve edge
//    // https://assets.nexperia.com/documents/data-sheet/74HC_HCT595.pdf
//    OUT_LATCH_SetHigh();
//    OUT_LATCH_SetLow();    
//}
//
//void rcvClock() {
//    OUT_CLK_SetHigh();
//    OUT_CLK_SetLow();
//}
//
//// see https://tresi.github.io/nes/ for signalling logic
//void nesTransfer() {
//   
//    nesInit();
//    rcvInit();
//    
//    nesLatch();
//    rcvClock();
//    
//    nesClock();
//    rcvClock();
//    
//    nesClock();
//    rcvClock();
//    
//    nesClock();
//    rcvClock();
//    
//    nesClock();
//    rcvClock();
//    
//    nesClock();
//    rcvClock();
//    
//    nesClock();
//    rcvClock();
//    
//    nesClock();
//    rcvClock();
//
//    rcvLatch();
//}

void randUpdate() {
    result_t r = (result_t)(rand() % 256);
    output(r);
}



void i2cDemo(); 
void i2cInit(); 
uint16_t nes_get_state();

void main(void) {
    SYSTEM_Initialize();

    i2cInit();
    
    while (1) {

        //nesTransfer();
        //i2cDemo(); 
//        randUpdate();
        uint16_t state = nes_get_state();
        uint16_t x = state;
    }
}


/**
 End of File
 */
