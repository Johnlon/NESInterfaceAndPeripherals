/*
 * Implements a two digit seven segment common cathode display driver.
 * The same approach will also drive a common anode with the same PCB 
 * layout by reversing the high/low logic of the pins below.
 */

#include "mcc_generated_files/mcc.h"
#include "i2c.h"
#include "controller.h"


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

void main(void) {
    SYSTEM_Initialize();
    i2cSetup();
    controller_disable_encryption();
    controller_init();
    
    uint8_t id[6];
    controller_id(id);

    while (1) {

        //randUpdate();
        
        uint8_t state = controller_state(); 
        output(state ^ 0xff); 
   }
}


/**
 End of File
 */
