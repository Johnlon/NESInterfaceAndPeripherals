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

// get/set DATA_7 aliases
#define DATA_7_TRIS                 TRISAbits.TRISA0
#define DATA_7_LAT                  LATAbits.LATA0
#define DATA_7_PORT                 PORTAbits.RA0
#define DATA_7_WPU                  WPUAbits.WPUA0
#define DATA_7_OD                   ODCONAbits.ODCA0
#define DATA_7_ANS                  ANSELAbits.ANSA0
#define DATA_7_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define DATA_7_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define DATA_7_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define DATA_7_GetValue()           PORTAbits.RA0
#define DATA_7_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define DATA_7_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define DATA_7_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define DATA_7_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define DATA_7_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define DATA_7_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define DATA_7_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define DATA_7_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set DATA_6 aliases
#define DATA_6_TRIS                 TRISAbits.TRISA1
#define DATA_6_LAT                  LATAbits.LATA1
#define DATA_6_PORT                 PORTAbits.RA1
#define DATA_6_WPU                  WPUAbits.WPUA1
#define DATA_6_OD                   ODCONAbits.ODCA1
#define DATA_6_ANS                  ANSELAbits.ANSA1
#define DATA_6_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define DATA_6_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define DATA_6_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define DATA_6_GetValue()           PORTAbits.RA1
#define DATA_6_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define DATA_6_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define DATA_6_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define DATA_6_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define DATA_6_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define DATA_6_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define DATA_6_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define DATA_6_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set DATA_5 aliases
#define DATA_5_TRIS                 TRISAbits.TRISA2
#define DATA_5_LAT                  LATAbits.LATA2
#define DATA_5_PORT                 PORTAbits.RA2
#define DATA_5_WPU                  WPUAbits.WPUA2
#define DATA_5_OD                   ODCONAbits.ODCA2
#define DATA_5_ANS                  ANSELAbits.ANSA2
#define DATA_5_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define DATA_5_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define DATA_5_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define DATA_5_GetValue()           PORTAbits.RA2
#define DATA_5_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define DATA_5_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define DATA_5_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define DATA_5_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define DATA_5_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define DATA_5_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define DATA_5_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define DATA_5_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set _RDNES2 aliases
#define _RDNES2_TRIS                 TRISAbits.TRISA4
#define _RDNES2_LAT                  LATAbits.LATA4
#define _RDNES2_PORT                 PORTAbits.RA4
#define _RDNES2_WPU                  WPUAbits.WPUA4
#define _RDNES2_OD                   ODCONAbits.ODCA4
#define _RDNES2_ANS                  ANSELAbits.ANSA4
#define _RDNES2_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define _RDNES2_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define _RDNES2_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define _RDNES2_GetValue()           PORTAbits.RA4
#define _RDNES2_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define _RDNES2_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define _RDNES2_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define _RDNES2_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define _RDNES2_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define _RDNES2_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define _RDNES2_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define _RDNES2_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set _RDNES1 aliases
#define _RDNES1_TRIS                 TRISAbits.TRISA5
#define _RDNES1_LAT                  LATAbits.LATA5
#define _RDNES1_PORT                 PORTAbits.RA5
#define _RDNES1_WPU                  WPUAbits.WPUA5
#define _RDNES1_OD                   ODCONAbits.ODCA5
#define _RDNES1_ANS                  ANSELAbits.ANSA5
#define _RDNES1_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define _RDNES1_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define _RDNES1_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define _RDNES1_GetValue()           PORTAbits.RA5
#define _RDNES1_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define _RDNES1_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define _RDNES1_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define _RDNES1_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define _RDNES1_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define _RDNES1_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define _RDNES1_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define _RDNES1_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set DATA_1 aliases
#define DATA_1_TRIS                 TRISBbits.TRISB4
#define DATA_1_LAT                  LATBbits.LATB4
#define DATA_1_PORT                 PORTBbits.RB4
#define DATA_1_WPU                  WPUBbits.WPUB4
#define DATA_1_OD                   ODCONBbits.ODCB4
#define DATA_1_ANS                  ANSELBbits.ANSB4
#define DATA_1_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define DATA_1_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define DATA_1_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define DATA_1_GetValue()           PORTBbits.RB4
#define DATA_1_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define DATA_1_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define DATA_1_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define DATA_1_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define DATA_1_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define DATA_1_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define DATA_1_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define DATA_1_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set DATA_0 aliases
#define DATA_0_TRIS                 TRISBbits.TRISB5
#define DATA_0_LAT                  LATBbits.LATB5
#define DATA_0_PORT                 PORTBbits.RB5
#define DATA_0_WPU                  WPUBbits.WPUB5
#define DATA_0_OD                   ODCONBbits.ODCB5
#define DATA_0_ANS                  ANSELBbits.ANSB5
#define DATA_0_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define DATA_0_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define DATA_0_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define DATA_0_GetValue()           PORTBbits.RB5
#define DATA_0_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define DATA_0_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define DATA_0_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define DATA_0_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define DATA_0_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define DATA_0_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define DATA_0_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define DATA_0_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set NU aliases
#define NU_TRIS                 TRISBbits.TRISB6
#define NU_LAT                  LATBbits.LATB6
#define NU_PORT                 PORTBbits.RB6
#define NU_WPU                  WPUBbits.WPUB6
#define NU_OD                   ODCONBbits.ODCB6
#define NU_ANS                  ANSELBbits.ANSB6
#define NU_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define NU_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define NU_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define NU_GetValue()           PORTBbits.RB6
#define NU_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define NU_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define NU_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define NU_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define NU_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define NU_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define NU_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define NU_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set _RDADC aliases
#define _RDADC_TRIS                 TRISBbits.TRISB7
#define _RDADC_LAT                  LATBbits.LATB7
#define _RDADC_PORT                 PORTBbits.RB7
#define _RDADC_WPU                  WPUBbits.WPUB7
#define _RDADC_OD                   ODCONBbits.ODCB7
#define _RDADC_ANS                  ANSELBbits.ANSB7
#define _RDADC_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define _RDADC_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define _RDADC_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define _RDADC_GetValue()           PORTBbits.RB7
#define _RDADC_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define _RDADC_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define _RDADC_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define _RDADC_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define _RDADC_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define _RDADC_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define _RDADC_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define _RDADC_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set DATA_4 aliases
#define DATA_4_TRIS                 TRISCbits.TRISC0
#define DATA_4_LAT                  LATCbits.LATC0
#define DATA_4_PORT                 PORTCbits.RC0
#define DATA_4_WPU                  WPUCbits.WPUC0
#define DATA_4_OD                   ODCONCbits.ODCC0
#define DATA_4_ANS                  ANSELCbits.ANSC0
#define DATA_4_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define DATA_4_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define DATA_4_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define DATA_4_GetValue()           PORTCbits.RC0
#define DATA_4_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define DATA_4_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define DATA_4_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define DATA_4_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define DATA_4_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define DATA_4_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define DATA_4_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define DATA_4_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set DATA_3 aliases
#define DATA_3_TRIS                 TRISCbits.TRISC1
#define DATA_3_LAT                  LATCbits.LATC1
#define DATA_3_PORT                 PORTCbits.RC1
#define DATA_3_WPU                  WPUCbits.WPUC1
#define DATA_3_OD                   ODCONCbits.ODCC1
#define DATA_3_ANS                  ANSELCbits.ANSC1
#define DATA_3_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define DATA_3_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define DATA_3_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define DATA_3_GetValue()           PORTCbits.RC1
#define DATA_3_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define DATA_3_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define DATA_3_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define DATA_3_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define DATA_3_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define DATA_3_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define DATA_3_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define DATA_3_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set DATA_2 aliases
#define DATA_2_TRIS                 TRISCbits.TRISC2
#define DATA_2_LAT                  LATCbits.LATC2
#define DATA_2_PORT                 PORTCbits.RC2
#define DATA_2_WPU                  WPUCbits.WPUC2
#define DATA_2_OD                   ODCONCbits.ODCC2
#define DATA_2_ANS                  ANSELCbits.ANSC2
#define DATA_2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define DATA_2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define DATA_2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define DATA_2_GetValue()           PORTCbits.RC2
#define DATA_2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define DATA_2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define DATA_2_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define DATA_2_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define DATA_2_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define DATA_2_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define DATA_2_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define DATA_2_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set NES_DATA1 aliases
#define NES_DATA1_TRIS                 TRISCbits.TRISC3
#define NES_DATA1_LAT                  LATCbits.LATC3
#define NES_DATA1_PORT                 PORTCbits.RC3
#define NES_DATA1_WPU                  WPUCbits.WPUC3
#define NES_DATA1_OD                   ODCONCbits.ODCC3
#define NES_DATA1_ANS                  ANSELCbits.ANSC3
#define NES_DATA1_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define NES_DATA1_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define NES_DATA1_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define NES_DATA1_GetValue()           PORTCbits.RC3
#define NES_DATA1_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define NES_DATA1_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define NES_DATA1_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define NES_DATA1_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define NES_DATA1_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define NES_DATA1_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define NES_DATA1_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define NES_DATA1_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set NES_LATCH aliases
#define NES_LATCH_TRIS                 TRISCbits.TRISC4
#define NES_LATCH_LAT                  LATCbits.LATC4
#define NES_LATCH_PORT                 PORTCbits.RC4
#define NES_LATCH_WPU                  WPUCbits.WPUC4
#define NES_LATCH_OD                   ODCONCbits.ODCC4
#define NES_LATCH_ANS                  ANSELCbits.ANSC4
#define NES_LATCH_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define NES_LATCH_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define NES_LATCH_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define NES_LATCH_GetValue()           PORTCbits.RC4
#define NES_LATCH_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define NES_LATCH_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define NES_LATCH_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define NES_LATCH_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define NES_LATCH_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define NES_LATCH_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define NES_LATCH_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define NES_LATCH_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set NES_CLK aliases
#define NES_CLK_TRIS                 TRISCbits.TRISC5
#define NES_CLK_LAT                  LATCbits.LATC5
#define NES_CLK_PORT                 PORTCbits.RC5
#define NES_CLK_WPU                  WPUCbits.WPUC5
#define NES_CLK_OD                   ODCONCbits.ODCC5
#define NES_CLK_ANS                  ANSELCbits.ANSC5
#define NES_CLK_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define NES_CLK_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define NES_CLK_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define NES_CLK_GetValue()           PORTCbits.RC5
#define NES_CLK_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define NES_CLK_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define NES_CLK_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define NES_CLK_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define NES_CLK_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define NES_CLK_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define NES_CLK_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define NES_CLK_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set NES_DATA2 aliases
#define NES_DATA2_TRIS                 TRISCbits.TRISC6
#define NES_DATA2_LAT                  LATCbits.LATC6
#define NES_DATA2_PORT                 PORTCbits.RC6
#define NES_DATA2_WPU                  WPUCbits.WPUC6
#define NES_DATA2_OD                   ODCONCbits.ODCC6
#define NES_DATA2_ANS                  ANSELCbits.ANSC6
#define NES_DATA2_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define NES_DATA2_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define NES_DATA2_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define NES_DATA2_GetValue()           PORTCbits.RC6
#define NES_DATA2_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define NES_DATA2_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define NES_DATA2_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define NES_DATA2_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define NES_DATA2_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define NES_DATA2_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define NES_DATA2_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define NES_DATA2_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set ADCIN aliases
#define ADCIN_TRIS                 TRISCbits.TRISC7
#define ADCIN_LAT                  LATCbits.LATC7
#define ADCIN_PORT                 PORTCbits.RC7
#define ADCIN_WPU                  WPUCbits.WPUC7
#define ADCIN_OD                   ODCONCbits.ODCC7
#define ADCIN_ANS                  ANSELCbits.ANSC7
#define ADCIN_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define ADCIN_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define ADCIN_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define ADCIN_GetValue()           PORTCbits.RC7
#define ADCIN_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define ADCIN_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define ADCIN_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define ADCIN_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define ADCIN_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define ADCIN_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define ADCIN_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define ADCIN_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

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