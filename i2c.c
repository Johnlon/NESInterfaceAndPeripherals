#include "mcc_generated_files/mcc.h"

// http://www.bitbanging.space/posts/bitbang-i2c

// All participants on the SDA line are expected to be open collector/drain so when a pin is driven high then it is actually not driven at all.
// The SDA line must carry a weak-pull up resistor.
// This mean that if the master parks an output pin in the high state then it's effectively released control of the pin and so the slave can actuallyh drive the pin if it need to send data like an ack back to the master.
// So in the code below we see the SDA line being set high prior to reading back the state of the pin. With the output set high then reading the output pin, if we find it still high then this means 
// the slave was not asserting a 0 on that line.
// In an ardiuino one can read from output pins and the read actually reflects the current voltage at that pin. So if the arduino output attempting to drive the pin high but it is shorted to ground 
// then when we read the output pin we will see a 0. In arduino the "PORT" is used to write to a pin and the "PIN" register is used to read it.
// However, I'm writing this for the PIC16F micro and it also has one bit accessors for each pin call PORT and LAT. You can write to either the PORT or LAT and this sets the output value
// but if you read the PORT then you are sensing the voltage whereas if you read the LAT then you are merely reading the value previously written to the port latch.

// data line
#define SDA_ON (NES_SDA1_LAT=1)
#define SDA_OFF (NES_SDA1_LAT=0)

// clock line
#define SCL_ON (NES_SCL_LAT=1)
#define SCL_OFF (NES_SCL_LAT=0)

// ports to read back
#define SDA_READ NES_SDA1_PORT
#define SCL_READ NES_SCL_PORT

#define WRITE_BIT 0x00
#define READ_BIT 0x01

inline void dly(){
    __delay_us(1);
}

int readSDA() {
    // read the state of the SDA pin. if it's low then then the slave is pulling it low
    
    // turn the pin into an input momentarily to read the logic level of the SDA pin.
    // doing this is possibly only needed to make this code simulator PORT work
    
    NES_SDA1_TRIS=1; 
    bool val = !SDA_READ;    // Acknowledge bit
    NES_SDA1_TRIS=0;
    return val;
}

int readSCL() {
    // read the state of the SDA pin. if it's low then then the slave is pulling it low
    
    // turn the pin into an input momentarily to read the logic level of the SDA pin.
    // doing this is possibly only needed to make this code simulator PORT work
    
    NES_SDA1_TRIS=1; 
    bool val = !SDA_READ;    // Acknowledge bit
    NES_SDA1_TRIS=0;
    return val;
}
/*  i2c start sequence */
void start(){
    SDA_ON;
    dly();
    SCL_ON;
    dly();
    SDA_OFF;
    dly();
    SCL_OFF;
    dly();
}

/*  i2c stop sequence */
void stop(){
    SDA_OFF;
    dly();
    SCL_ON;
    dly();
    SDA_ON;
    dly();
}

/* Transmit 8 bit data to slave */
bool Tx(uint8_t dat){

    for(uint8_t i = 8; i; i--){
        (dat & 0x80) ? SDA_ON : SDA_OFF; //Mask for the eigth bit
        dat<<=1;  //Move 
        dly();
        SCL_ON;
        dly();
        SCL_OFF;
        dly();
    }
    
    SDA_ON; // port goes high 7
    SCL_ON;
    dly();
    
    bool ack = readSDA();    // Acknowledge bit
    
    SCL_OFF;
    return ack;
}

uint8_t Rx(bool ack){
    uint8_t dat = 0;
    SDA_ON;
    for( uint8_t i =0; i<8; i++){
        dat <<= 1;
        do{
            SCL_ON;
        }while(readSCL() == 0);  //clock stretching
        dly();
        if(readSDA()) dat |=1;
        dly();
        SCL_OFF;
    }
    ack ? SDA_OFF : SDA_ON;
    SCL_ON;
    dly();
    SCL_OFF;
    SDA_ON;
    return(dat); 
}

void i2cDemo() {
    
    //DDRB = (1<<DDB1)|(1<<DDB0); // Set the PB0 and PB1 as output
    uint8_t ADDR=0x52;
    start();
    Tx((ADDR<<1)|WRITE_BIT); // Transfer the slave address plus 

    for (int i = 0; i<256; i++) {
        
        NUB7_LAT = 1;
        Tx(i); // Register address where we want to write
        NUB7_LAT = 0;
        Tx(0x00); // Register address where we want to write
    }
    stop();

//    while(1){
//    } // do nothing

}
