/*
 * settings.c
 *
 *  Created on: Oct 18, 2016
 *      Author: MSC
 */
#include "settings.h"
#include <msp430.h>

/* Contains all code necessary to utilize the MSP 430 controller. */
extern void Set_MspSetup(void)
{
  WDTCTL = WDTPW | WDTHOLD; /* Stops the watch-dog timer. */
  PMMCTL0 = PMMPW; /* Opens PMM Module. */
  PM5CTL0 &= ~LOCKLPM5; /* Clears locked Input output pins. */
}
