//*****************************************************************************
//
// blinky.c - Simple example to blink the on-board LED.
//
// Copyright (c) 2007-2013 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
//
// Texas Instruments (TI) is supplying this software for use solely and
// exclusively on TI's microcontroller products. The software is owned by
// TI and/or its suppliers, and is protected under applicable copyright
// laws. You may not combine this software with "viral" open-source
// software in order to form a larger program.
//
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
// CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
// DAMAGES, FOR ANY REASON WHATSOEVER.
//
// This is part of revision 10636 of the EK-LM3S8962 Firmware Package.
//
//*****************************************************************************

//******************************************************************************
// 이 파일은 Texas Instrument의 StellarisWare에 포함된 에제를
// 위드로봇(주)의 myCortex-LM8962 보드에 맞도록 수정한 파일이다.
//
// 모든 저작권 및 소유권은 Texas Instrument에 있다.
//******************************************************************************

#include "inc/lm3s8962.h"

//*****************************************************************************
//
//! \addtogroup example_list
//! <h1>Blinky (blinky)</h1>
//!
//! A very simple example that blinks the on-board LED.
//
//*****************************************************************************

//*****************************************************************************
//
// Blink the on-board LED.
//
//*****************************************************************************
int
main(void)
{
    volatile unsigned long ulLoop;

    //
    // Enable the GPIO port that is used for the on-board LED.
    //
    SYSCTL_RCGC2_R = SYSCTL_RCGC2_GPIOG;

    //
    // Do a dummy read to insert a few cycles after enabling the peripheral.
    //
    ulLoop = SYSCTL_RCGC2_R;

    //
    // Enable the GPIO pin for the LED (PG0).  Set the direction as output, and
    // enable the GPIO pin for digital function.
    //
    GPIO_PORTG_DIR_R = 0x01;
    GPIO_PORTG_DEN_R = 0x01;

    //
    // Loop forever.
    //
    while(1)
    {
        //
        // Turn on the LED.
        //
        GPIO_PORTG_DATA_R |= 0x01;

        //
        // Delay for a bit.
        //
        for(ulLoop = 0; ulLoop < 200000; ulLoop++)
        {
        }

        //
        // Turn off the LED.
        //
        GPIO_PORTG_DATA_R &= ~(0x01);

        //
        // Delay for a bit.
        //
        for(ulLoop = 0; ulLoop < 200000; ulLoop++)
        {
        }
    }
}
