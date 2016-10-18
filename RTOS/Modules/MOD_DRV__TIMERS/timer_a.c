/*
 * timer_a.c
 *
 *  Created on: Oct 18, 2016
 *      Author: MSC
 */
#include "timer_a.h"
#include <msp430.h>

/* Timer A initialization*/
extern void Tma_Init(void)
{
	/* TIMER REG Setup */
	TA0CTL = TASSEL_2 | MC_1 | ID_3;
	TA0CCR0 = 10000;

	/* Enable interrupts */
	TA0CCTL0 = CCIE;
	__enable_interrupt();
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void Tma_InterruptTimerA0(void)
{
	P1OUT ^= BIT0;                          // Toggle P1.0
}
