/*
 * main.c
 */
#include <msp430.h> 
#include "settings.h"
#include "timer_a.h"

static void Mai__Init(void);

void main(void)
{
  Set_MspSetup();
  Mai__Init();

  P1DIR |= 0x01 | 0x80;
  P9DIR |= 0x80;

  while (1)
  {
    P1OUT ^= BIT0;
  }
}

static void Mai__Init(void)
{
  Tma_Init();
}
