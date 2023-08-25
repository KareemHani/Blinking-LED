

/**
 * Author: Kareem Hani
 */
#include "Software Layers/LIB/tm4c123gh6pm.h"
#include "Software Layers/MCAL/Timers.h"
#include "Software Layers/LIB/BITWISE_OPERATIONS.h"
#include "Software Layers/MCAL/DIO.h"

#define PUSHBUTTON1 0
#define PUSHBUTTON2 4
#define RED 1
#define BLUE 2
#define GREEN 3

int main(void)
{
    periodic_Timer_Init();
    DIO_INIT(PORTF, 0b00001110, 0);


    while(1)
    {

    }

	return 0;
}

void GPTIMER_ISR()
{

    SETBIT(TIMER0_ICR_R, 0);
    SETBIT(NVIC_UNPEND0_R, 19);

    TOGGLEBIT(GPIO_PORTF_DATA_R, RED);
    TOGGLEBIT(GPIO_PORTF_DATA_R, BLUE);
    TOGGLEBIT(GPIO_PORTF_DATA_R, GREEN);

}
