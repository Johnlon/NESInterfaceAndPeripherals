/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F18446
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RAND_7 aliases
#define RAND_7_TRIS                 TRISAbits.TRISA0
#define RAND_7_LAT                  LATAbits.LATA0
#define RAND_7_PORT                 PORTAbits.RA0
#define RAND_7_WPU                  WPUAbits.WPUA0
#define RAND_7_OD                   ODCONAbits.ODCA0
#define RAND_7_ANS                  ANSELAbits.ANSA0
#define RAND_7_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define RAND_7_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define RAND_7_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define RAND_7_GetValue()           PORTAbits.RA0
#define RAND_7_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define RAND_7_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define RAND_7_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define RAND_7_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define RAND_7_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define RAND_7_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define RAND_7_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define RAND_7_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set RAND_6 aliases
#define RAND_6_TRIS                 TRISAbits.TRISA1
#define RAND_6_LAT                  LATAbits.LATA1
#define RAND_6_PORT                 PORTAbits.RA1
#define RAND_6_WPU                  WPUAbits.WPUA1
#define RAND_6_OD                   ODCONAbits.ODCA1
#define RAND_6_ANS                  ANSELAbits.ANSA1
#define RAND_6_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define RAND_6_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define RAND_6_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define RAND_6_GetValue()           PORTAbits.RA1
#define RAND_6_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define RAND_6_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define RAND_6_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define RAND_6_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define RAND_6_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define RAND_6_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define RAND_6_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define RAND_6_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set RAND_5 aliases
#define RAND_5_TRIS                 TRISAbits.TRISA2
#define RAND_5_LAT                  LATAbits.LATA2
#define RAND_5_PORT                 PORTAbits.RA2
#define RAND_5_WPU                  WPUAbits.WPUA2
#define RAND_5_OD                   ODCONAbits.ODCA2
#define RAND_5_ANS                  ANSELAbits.ANSA2
#define RAND_5_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define RAND_5_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define RAND_5_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define RAND_5_GetValue()           PORTAbits.RA2
#define RAND_5_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define RAND_5_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define RAND_5_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define RAND_5_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define RAND_5_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define RAND_5_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define RAND_5_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define RAND_5_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set dddd aliases
#define dddd_TRIS                 TRISAbits.TRISA4
#define dddd_LAT                  LATAbits.LATA4
#define dddd_PORT                 PORTAbits.RA4
#define dddd_WPU                  WPUAbits.WPUA4
#define dddd_OD                   ODCONAbits.ODCA4
#define dddd_ANS                  ANSELAbits.ANSA4
#define dddd_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define dddd_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define dddd_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define dddd_GetValue()           PORTAbits.RA4
#define dddd_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define dddd_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define dddd_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define dddd_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define dddd_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define dddd_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define dddd_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define dddd_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set OUT_CLK aliases
#define OUT_CLK_TRIS                 TRISAbits.TRISA5
#define OUT_CLK_LAT                  LATAbits.LATA5
#define OUT_CLK_PORT                 PORTAbits.RA5
#define OUT_CLK_WPU                  WPUAbits.WPUA5
#define OUT_CLK_OD                   ODCONAbits.ODCA5
#define OUT_CLK_ANS                  ANSELAbits.ANSA5
#define OUT_CLK_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define OUT_CLK_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define OUT_CLK_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define OUT_CLK_GetValue()           PORTAbits.RA5
#define OUT_CLK_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define OUT_CLK_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define OUT_CLK_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define OUT_CLK_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define OUT_CLK_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define OUT_CLK_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define OUT_CLK_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define OUT_CLK_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set RAND_1 aliases
#define RAND_1_TRIS                 TRISBbits.TRISB4
#define RAND_1_LAT                  LATBbits.LATB4
#define RAND_1_PORT                 PORTBbits.RB4
#define RAND_1_WPU                  WPUBbits.WPUB4
#define RAND_1_OD                   ODCONBbits.ODCB4
#define RAND_1_ANS                  ANSELBbits.ANSB4
#define RAND_1_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define RAND_1_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define RAND_1_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RAND_1_GetValue()           PORTBbits.RB4
#define RAND_1_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define RAND_1_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define RAND_1_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define RAND_1_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define RAND_1_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define RAND_1_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define RAND_1_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define RAND_1_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set RAND_0 aliases
#define RAND_0_TRIS                 TRISBbits.TRISB5
#define RAND_0_LAT                  LATBbits.LATB5
#define RAND_0_PORT                 PORTBbits.RB5
#define RAND_0_WPU                  WPUBbits.WPUB5
#define RAND_0_OD                   ODCONBbits.ODCB5
#define RAND_0_ANS                  ANSELBbits.ANSB5
#define RAND_0_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define RAND_0_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define RAND_0_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RAND_0_GetValue()           PORTBbits.RB5
#define RAND_0_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define RAND_0_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define RAND_0_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define RAND_0_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define RAND_0_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define RAND_0_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define RAND_0_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define RAND_0_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set RAND_SEQ aliases
#define RAND_SEQ_TRIS                 TRISBbits.TRISB6
#define RAND_SEQ_LAT                  LATBbits.LATB6
#define RAND_SEQ_PORT                 PORTBbits.RB6
#define RAND_SEQ_WPU                  WPUBbits.WPUB6
#define RAND_SEQ_OD                   ODCONBbits.ODCB6
#define RAND_SEQ_ANS                  ANSELBbits.ANSB6
#define RAND_SEQ_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define RAND_SEQ_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define RAND_SEQ_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define RAND_SEQ_GetValue()           PORTBbits.RB6
#define RAND_SEQ_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define RAND_SEQ_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define RAND_SEQ_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define RAND_SEQ_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define RAND_SEQ_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define RAND_SEQ_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define RAND_SEQ_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define RAND_SEQ_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set NUB7 aliases
#define NUB7_TRIS                 TRISBbits.TRISB7
#define NUB7_LAT                  LATBbits.LATB7
#define NUB7_PORT                 PORTBbits.RB7
#define NUB7_WPU                  WPUBbits.WPUB7
#define NUB7_OD                   ODCONBbits.ODCB7
#define NUB7_ANS                  ANSELBbits.ANSB7
#define NUB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define NUB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define NUB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define NUB7_GetValue()           PORTBbits.RB7
#define NUB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define NUB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define NUB7_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define NUB7_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define NUB7_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define NUB7_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define NUB7_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define NUB7_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set RAND_4 aliases
#define RAND_4_TRIS                 TRISCbits.TRISC0
#define RAND_4_LAT                  LATCbits.LATC0
#define RAND_4_PORT                 PORTCbits.RC0
#define RAND_4_WPU                  WPUCbits.WPUC0
#define RAND_4_OD                   ODCONCbits.ODCC0
#define RAND_4_ANS                  ANSELCbits.ANSC0
#define RAND_4_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define RAND_4_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define RAND_4_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RAND_4_GetValue()           PORTCbits.RC0
#define RAND_4_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define RAND_4_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define RAND_4_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define RAND_4_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define RAND_4_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define RAND_4_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define RAND_4_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define RAND_4_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set RAND_3 aliases
#define RAND_3_TRIS                 TRISCbits.TRISC1
#define RAND_3_LAT                  LATCbits.LATC1
#define RAND_3_PORT                 PORTCbits.RC1
#define RAND_3_WPU                  WPUCbits.WPUC1
#define RAND_3_OD                   ODCONCbits.ODCC1
#define RAND_3_ANS                  ANSELCbits.ANSC1
#define RAND_3_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RAND_3_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RAND_3_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RAND_3_GetValue()           PORTCbits.RC1
#define RAND_3_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RAND_3_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define RAND_3_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define RAND_3_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define RAND_3_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define RAND_3_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define RAND_3_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define RAND_3_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set RAND_2 aliases
#define RAND_2_TRIS                 TRISCbits.TRISC2
#define RAND_2_LAT                  LATCbits.LATC2
#define RAND_2_PORT                 PORTCbits.RC2
#define RAND_2_WPU                  WPUCbits.WPUC2
#define RAND_2_OD                   ODCONCbits.ODCC2
#define RAND_2_ANS                  ANSELCbits.ANSC2
#define RAND_2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define RAND_2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define RAND_2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define RAND_2_GetValue()           PORTCbits.RC2
#define RAND_2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define RAND_2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define RAND_2_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define RAND_2_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define RAND_2_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define RAND_2_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define RAND_2_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define RAND_2_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set SCL aliases
#define SCL_TRIS                 TRISCbits.TRISC3
#define SCL_LAT                  LATCbits.LATC3
#define SCL_PORT                 PORTCbits.RC3
#define SCL_WPU                  WPUCbits.WPUC3
#define SCL_OD                   ODCONCbits.ODCC3
#define SCL_ANS                  ANSELCbits.ANSC3
#define SCL_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define SCL_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define SCL_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define SCL_GetValue()           PORTCbits.RC3
#define SCL_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define SCL_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define SCL_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define SCL_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define SCL_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define SCL_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define SCL_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define SCL_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set OUT_DATA2 aliases
#define OUT_DATA2_TRIS                 TRISCbits.TRISC4
#define OUT_DATA2_LAT                  LATCbits.LATC4
#define OUT_DATA2_PORT                 PORTCbits.RC4
#define OUT_DATA2_WPU                  WPUCbits.WPUC4
#define OUT_DATA2_OD                   ODCONCbits.ODCC4
#define OUT_DATA2_ANS                  ANSELCbits.ANSC4
#define OUT_DATA2_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define OUT_DATA2_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define OUT_DATA2_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define OUT_DATA2_GetValue()           PORTCbits.RC4
#define OUT_DATA2_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define OUT_DATA2_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define OUT_DATA2_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define OUT_DATA2_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define OUT_DATA2_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define OUT_DATA2_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define OUT_DATA2_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define OUT_DATA2_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set OUT_DATA1 aliases
#define OUT_DATA1_TRIS                 TRISCbits.TRISC5
#define OUT_DATA1_LAT                  LATCbits.LATC5
#define OUT_DATA1_PORT                 PORTCbits.RC5
#define OUT_DATA1_WPU                  WPUCbits.WPUC5
#define OUT_DATA1_OD                   ODCONCbits.ODCC5
#define OUT_DATA1_ANS                  ANSELCbits.ANSC5
#define OUT_DATA1_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define OUT_DATA1_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define OUT_DATA1_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define OUT_DATA1_GetValue()           PORTCbits.RC5
#define OUT_DATA1_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define OUT_DATA1_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define OUT_DATA1_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define OUT_DATA1_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define OUT_DATA1_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define OUT_DATA1_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define OUT_DATA1_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define OUT_DATA1_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set SDA aliases
#define SDA_TRIS                 TRISCbits.TRISC6
#define SDA_LAT                  LATCbits.LATC6
#define SDA_PORT                 PORTCbits.RC6
#define SDA_WPU                  WPUCbits.WPUC6
#define SDA_OD                   ODCONCbits.ODCC6
#define SDA_ANS                  ANSELCbits.ANSC6
#define SDA_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define SDA_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define SDA_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define SDA_GetValue()           PORTCbits.RC6
#define SDA_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define SDA_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define SDA_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define SDA_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define SDA_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define SDA_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define SDA_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define SDA_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set SDA2 aliases
#define SDA2_TRIS                 TRISCbits.TRISC7
#define SDA2_LAT                  LATCbits.LATC7
#define SDA2_PORT                 PORTCbits.RC7
#define SDA2_WPU                  WPUCbits.WPUC7
#define SDA2_OD                   ODCONCbits.ODCC7
#define SDA2_ANS                  ANSELCbits.ANSC7
#define SDA2_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define SDA2_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define SDA2_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define SDA2_GetValue()           PORTCbits.RC7
#define SDA2_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define SDA2_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define SDA2_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define SDA2_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define SDA2_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define SDA2_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define SDA2_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define SDA2_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/