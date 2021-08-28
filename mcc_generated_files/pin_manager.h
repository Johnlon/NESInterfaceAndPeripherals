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

// get/set OUT_DATA3 aliases
#define OUT_DATA3_TRIS                 TRISAbits.TRISA4
#define OUT_DATA3_LAT                  LATAbits.LATA4
#define OUT_DATA3_PORT                 PORTAbits.RA4
#define OUT_DATA3_WPU                  WPUAbits.WPUA4
#define OUT_DATA3_OD                   ODCONAbits.ODCA4
#define OUT_DATA3_ANS                  ANSELAbits.ANSA4
#define OUT_DATA3_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define OUT_DATA3_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define OUT_DATA3_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define OUT_DATA3_GetValue()           PORTAbits.RA4
#define OUT_DATA3_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define OUT_DATA3_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define OUT_DATA3_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define OUT_DATA3_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define OUT_DATA3_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define OUT_DATA3_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define OUT_DATA3_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define OUT_DATA3_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set OUT_RCLK aliases
#define OUT_RCLK_TRIS                 TRISAbits.TRISA5
#define OUT_RCLK_LAT                  LATAbits.LATA5
#define OUT_RCLK_PORT                 PORTAbits.RA5
#define OUT_RCLK_WPU                  WPUAbits.WPUA5
#define OUT_RCLK_OD                   ODCONAbits.ODCA5
#define OUT_RCLK_ANS                  ANSELAbits.ANSA5
#define OUT_RCLK_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define OUT_RCLK_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define OUT_RCLK_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define OUT_RCLK_GetValue()           PORTAbits.RA5
#define OUT_RCLK_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define OUT_RCLK_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define OUT_RCLK_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define OUT_RCLK_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define OUT_RCLK_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define OUT_RCLK_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define OUT_RCLK_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define OUT_RCLK_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

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

// get/set SCL2 aliases
#define SCL2_TRIS                 TRISBbits.TRISB6
#define SCL2_LAT                  LATBbits.LATB6
#define SCL2_PORT                 PORTBbits.RB6
#define SCL2_WPU                  WPUBbits.WPUB6
#define SCL2_OD                   ODCONBbits.ODCB6
#define SCL2_ANS                  ANSELBbits.ANSB6
#define SCL2_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define SCL2_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define SCL2_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define SCL2_GetValue()           PORTBbits.RB6
#define SCL2_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define SCL2_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define SCL2_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define SCL2_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define SCL2_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define SCL2_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define SCL2_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define SCL2_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set SDA2 aliases
#define SDA2_TRIS                 TRISBbits.TRISB7
#define SDA2_LAT                  LATBbits.LATB7
#define SDA2_PORT                 PORTBbits.RB7
#define SDA2_WPU                  WPUBbits.WPUB7
#define SDA2_OD                   ODCONBbits.ODCB7
#define SDA2_ANS                  ANSELBbits.ANSB7
#define SDA2_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define SDA2_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define SDA2_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define SDA2_GetValue()           PORTBbits.RB7
#define SDA2_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define SDA2_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define SDA2_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define SDA2_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define SDA2_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define SDA2_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define SDA2_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define SDA2_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

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

// get/set OUT_SCLK aliases
#define OUT_SCLK_TRIS                 TRISCbits.TRISC3
#define OUT_SCLK_LAT                  LATCbits.LATC3
#define OUT_SCLK_PORT                 PORTCbits.RC3
#define OUT_SCLK_WPU                  WPUCbits.WPUC3
#define OUT_SCLK_OD                   ODCONCbits.ODCC3
#define OUT_SCLK_ANS                  ANSELCbits.ANSC3
#define OUT_SCLK_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define OUT_SCLK_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define OUT_SCLK_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define OUT_SCLK_GetValue()           PORTCbits.RC3
#define OUT_SCLK_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define OUT_SCLK_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define OUT_SCLK_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define OUT_SCLK_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define OUT_SCLK_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define OUT_SCLK_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define OUT_SCLK_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define OUT_SCLK_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set OUT_DATA1 aliases
#define OUT_DATA1_TRIS                 TRISCbits.TRISC4
#define OUT_DATA1_LAT                  LATCbits.LATC4
#define OUT_DATA1_PORT                 PORTCbits.RC4
#define OUT_DATA1_WPU                  WPUCbits.WPUC4
#define OUT_DATA1_OD                   ODCONCbits.ODCC4
#define OUT_DATA1_ANS                  ANSELCbits.ANSC4
#define OUT_DATA1_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define OUT_DATA1_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define OUT_DATA1_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define OUT_DATA1_GetValue()           PORTCbits.RC4
#define OUT_DATA1_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define OUT_DATA1_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define OUT_DATA1_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define OUT_DATA1_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define OUT_DATA1_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define OUT_DATA1_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define OUT_DATA1_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define OUT_DATA1_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set OUT_DATA2 aliases
#define OUT_DATA2_TRIS                 TRISCbits.TRISC5
#define OUT_DATA2_LAT                  LATCbits.LATC5
#define OUT_DATA2_PORT                 PORTCbits.RC5
#define OUT_DATA2_WPU                  WPUCbits.WPUC5
#define OUT_DATA2_OD                   ODCONCbits.ODCC5
#define OUT_DATA2_ANS                  ANSELCbits.ANSC5
#define OUT_DATA2_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define OUT_DATA2_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define OUT_DATA2_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define OUT_DATA2_GetValue()           PORTCbits.RC5
#define OUT_DATA2_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define OUT_DATA2_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define OUT_DATA2_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define OUT_DATA2_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define OUT_DATA2_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define OUT_DATA2_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define OUT_DATA2_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define OUT_DATA2_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set SDA1 aliases
#define SDA1_TRIS                 TRISCbits.TRISC6
#define SDA1_LAT                  LATCbits.LATC6
#define SDA1_PORT                 PORTCbits.RC6
#define SDA1_WPU                  WPUCbits.WPUC6
#define SDA1_OD                   ODCONCbits.ODCC6
#define SDA1_ANS                  ANSELCbits.ANSC6
#define SDA1_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define SDA1_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define SDA1_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define SDA1_GetValue()           PORTCbits.RC6
#define SDA1_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define SDA1_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define SDA1_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define SDA1_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define SDA1_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define SDA1_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define SDA1_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define SDA1_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set SCL1 aliases
#define SCL1_TRIS                 TRISCbits.TRISC7
#define SCL1_LAT                  LATCbits.LATC7
#define SCL1_PORT                 PORTCbits.RC7
#define SCL1_WPU                  WPUCbits.WPUC7
#define SCL1_OD                   ODCONCbits.ODCC7
#define SCL1_ANS                  ANSELCbits.ANSC7
#define SCL1_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define SCL1_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define SCL1_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define SCL1_GetValue()           PORTCbits.RC7
#define SCL1_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define SCL1_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define SCL1_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define SCL1_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define SCL1_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define SCL1_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define SCL1_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define SCL1_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

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