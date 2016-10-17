#include <msp430.h> 

/*
 * main.c
 */
void main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	PMMCTL0 = PMMPW;// Open PMM Module
	PM5CTL0 &= ~LOCKLPM5;// Clear locked IO Pins

	P1DIR |= 0x01 | 0x80;
	P9DIR |= 0x80;
	while (1) {
		P1OUT ^= BIT0;
	}
}
#if 0
unsigned int x;

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;		// Stop watchdog timer
	PMMCTL0 = PMMPW;// Open PMM Module
	PM5CTL0 &= ~LOCKLPM5;// Clear locked IO Pins

	P1DIR |= 0x01 | 0x80;
	P9DIR |= 0x80;

	/* TIMER REG Setup */
	//TA1CCTL0 = CCIE;
	TA0CTL = TASSEL_2 | MC_1 | ID_3;

	TA0CCR0 = 10000;
	// __bis_SR_register(LPM0_bits + GIE);

	/* Enable interrupts */
	TA0CCTL0 = CCIE;
	__enable_interrupt();

	for (;;)
	{
		//x = TA1R;

	}
}
#pragma vector=TIMER0_A0_VECTOR
__interrupt void ISR1 (void)
{
	P1OUT ^= BIT0;                          // Toggle P1.0
}
#endif
