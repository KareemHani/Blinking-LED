/*
 * Timers.c
 *
 *  Created on: Aug 25, 2023
 *      Author: Kareem Hani
 */
#include "Timers.h"
#include "Software Layers/LIB/tm4c123gh6pm.h"


// This Function is used to Initialize the OneShot & Periodic Timer
void periodic_Timer_Init()
{   // Enabling the RCC For the Timer
    SETBIT(SYSCTL_RCGCTIMER_R, 0);

    // 1st Step
    CLEARBIT(TIMER0_CTL_R,0);

    // 2nd Step
    TIMER0_CFG_R=0x00000000;

    // 3rd Step
    TIMER0_TAMR_R=0x2;

    //4th Step (Counting Down)
    CLEARBIT(TIMER0_TAMR_R,4);

    //5th Step (Configuring the register with the value to start count down from it) (one second)
    TIMER0_TAILR_R=16000000;

    //6th Step
    SETBIT(TIMER0_IMR_R,0);

    //7th Step
    SETBIT(TIMER0_CTL_R,0);

    //8th Step
    SETBIT(TIMER0_ICR_R,0);

    //Enabling the interrupt for Timer0A
    SETBIT(NVIC_EN0_R, 19);
}


