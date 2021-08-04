/*
 * Implements a two digit seven segment common cathode display driver.
 * The same approach will also drive a common anode with the same PCB 
 * layout by reversing the high/low logic of the pins below.
 */

#include "mcc_generated_files/mcc.h"
typedef unsigned char result_t;

void output(result_t out) {
    DATA_0_LAT = (out & 1);
    DATA_1_LAT = (out & 2) >> 1;
    DATA_2_LAT = (out & 4) >> 2;
    DATA_3_LAT = (out & 8) >> 3;
    DATA_4_LAT = (out & 16) >> 4;
    DATA_5_LAT = (out & 32) >> 5;
    DATA_6_LAT = (out & 64) >> 6;
    DATA_7_LAT = (out & 128) >> 7;

}

result_t readAdc() {
    // see https://microchipdeveloper.com/xpress:analog-read-serial-write-using-the-adcc-peripheral
    adc_result_t result12Bit = ADCC_GetSingleConversion(ADCIN);
    
    // this code assumes that the reading is "left aligned" in the ADRESH and ADRESL registers.
    // this is a setting in the ADC section of the code configurator.
    // this automatically put the most significant 8 bits into the ADRESH reg.
    return ADRESH;
}

/**
 * 
 * @param nes1
 * @param nes2
 */
void readNesInput(result_t* nes1, result_t* nes2) {
    // see https://tresi.github.io/nes/ for signalling logic

    NES_CLK_SetLow();

    NES_LATCH_SetHigh();
    NES_LATCH_SetLow();
    unsigned int nes1_a = NES_DATA1_GetValue();
    unsigned int nes2_a = NES_DATA2_GetValue();

    NES_CLK_SetHigh();
    NES_CLK_SetLow();
    unsigned int nes1_b = NES_DATA1_GetValue();
    unsigned int nes2_b = NES_DATA2_GetValue();

    NES_CLK_SetHigh();
    NES_CLK_SetLow();
    unsigned int nes1_select = NES_DATA1_GetValue();
    unsigned int nes2_select = NES_DATA2_GetValue();

    NES_CLK_SetHigh();
    NES_CLK_SetLow();
    unsigned int nes1_start = NES_DATA1_GetValue();
    unsigned int nes2_start = NES_DATA2_GetValue();

    NES_CLK_SetHigh();
    NES_CLK_SetLow();
    unsigned int nes1_up = NES_DATA1_GetValue();
    unsigned int nes2_up = NES_DATA2_GetValue();

    NES_CLK_SetHigh();
    NES_CLK_SetLow();
    unsigned int nes1_down = NES_DATA1_GetValue();
    unsigned int nes2_down = NES_DATA2_GetValue();

    NES_CLK_SetHigh();
    NES_CLK_SetLow();
    unsigned int nes1_left = NES_DATA1_GetValue();
    unsigned int nes2_left = NES_DATA2_GetValue();

    NES_CLK_SetHigh();
    NES_CLK_SetLow();
    unsigned int nes1_right = NES_DATA1_GetValue();
    unsigned int nes2_right = NES_DATA2_GetValue();

    *nes1 = (result_t)(
            (nes1_a << 7) +
            (nes1_b << 6) +
            (nes1_select << 5) +
            (nes1_start << 4) +
            (nes1_up << 3) +
            (nes1_down << 2) +
            (nes1_left << 1) +
            (nes1_right << 0)
            );

    *nes2 = (result_t)(
            (nes2_a << 7) +
            (nes2_b << 6) +
            (nes2_select << 5) +
            (nes2_start << 4) +
            (nes2_up << 3) +
            (nes2_down << 2) +
            (nes2_left << 1) +
            (nes2_right << 0)
            );
}

result_t readRand() {
    result_t r = (result_t)(rand() % 256);
    return r;
}

void main(void) {
    SYSTEM_Initialize();

    result_t nes1;
    result_t nes2;
    readNesInput(&nes1, &nes2);

    result_t adc = readAdc();
    result_t rnd = readRand();

    while (1) {

        if (!_RDADC_GetValue()) {
            output(adc);
        } else if (!_RDNES1_GetValue()) {
            output(nes1);
        } else if (!_RDNES2_GetValue()) {
            output(nes2);
        } else if (!_RDRAND_GetValue()) {
            output(rnd);
        } 
        
        readNesInput(&nes1, &nes2);
        adc = readAdc();
        rnd = readRand();

        output(rnd);
        
        __delay_us(1);

    }
}


/**
 End of File
 */
