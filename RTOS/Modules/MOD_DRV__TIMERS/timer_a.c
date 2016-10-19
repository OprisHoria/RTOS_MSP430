/*
 * timer_a.c
 *
 *  Created on: Oct 18, 2016
 *      Author: MSC
 */
#include "timer_a.h"
#include <msp430.h>
#include "settings.h"

static void Tma__TimerA0Setup(void);
static uint16_t Tim__CompareRegSet(uint16_t U16_TimerResetMs);

/* Timer A initialization*/
extern void Tma_Init(void)
{
  Tma__TimerA0Setup();
}

/* Reset timer shall trigger an interrupt at every 1 millisecond.
 *
 * SMCLK : 32768 HZ
 *
 * 1000 milliseconds in a second, so for 1 millisecond, SMCLK ticks 32 times
 * */
static void Tma__TimerA0Setup(void)
{
  /* TIMER REG Setup */
  TA0CTL = TASSEL_2 | MC_1 | ID_3;
  TA0CCR0 = Tim__CompareRegSet(1U);

  /* Enable interrupts */
  TA0CCTL0 = CCIE;
  __enable_interrupt();
}

/* Parameter: Desired timer interrupt in milliseconds.
 * Returns value to be used in capture and compare register for generating interrupt.
 * This value is calculated by dividing the frequency by 1000 and multiplying with
 * the number of milliseconds that we should have between interrupts.
 *
 * \note : This function can be turned into a function like macro, but it is done in
 * this manner because it is only called once at power on. */
static uint16_t Tim__CompareRegSet(uint16_t U16_TimerResetMs)
{
  static const uint16_t U16_SmclkFreqHz = 32768U;
  uint16_t U16_CompareRegSet;

  U16_CompareRegSet = ((U16_SmclkFreqHz * U16_TimerResetMs) / 1000U);

  return (U16_CompareRegSet);
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void Tma_InterruptTimerA0(void)
{
  P1OUT ^= BIT0;                          // Toggle P1.0
}
