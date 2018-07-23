/*--------------------------------------------------------------------
Name: Capt Jeff Falkinburg
Date: 24 Oct 2016
Course: ECE 382
File: multButtonInterrupt.c
HW: Lesson 26

Purp: This program uses multiple push button interrupts to toggle an LEDs via ISR

Doc:  Lecture Notes

Academic Integrity Statement: I certify that, while others may have
assisted me in brain storming, debugging and validating this program,
the program itself is my own work. I understand that submitting code
which is the work of other individuals is a violation of the honor
code.  I also understand that if I knowingly give my original work to
another individual is also a violation of the honor code.
-------------------------------------------------------------------------*/
#include <msp430.h>

/*
 * main.c
 */
void main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    P1DIR |= BIT0|BIT6; 		// set LEDs to output

    P2DIR &= ~(BIT0|BIT1|BIT3);	// set buttons to input

    P2IE |= BIT0|BIT1|BIT3;		// enable the interrupts

    P2IES |= BIT0|BIT1|BIT3;	// config interrupt for falling edges

    P2REN |= BIT0|BIT1|BIT3;	// enable pull-up/pull-down network

    P2OUT |= BIT0|BIT1|BIT3;	// configure as pull-up

    P2IFG &= ~(BIT0|BIT1|BIT3);	// clear flags

    __enable_interrupt();

    // main program loop
    while (1) {
    	// respond
    }
}

#pragma vector=PORT2_VECTOR
__interrupt void Port_2_ISR(void) {
    if (P2IFG & BIT0)
    {
        P2IFG &= ~BIT0;  	// clear interrupt flag
        P1OUT ^= BIT6; 		// toggle LED 2
    }

    if (P2IFG & BIT1)
    {
        P2IFG &= ~BIT1;  	// clear interrupt flag
        P1OUT ^= BIT0;  	// toggle LED 1
    }

    if (P2IFG & BIT3)
    {
        P2IFG &= ~BIT3;		// clear P1.3 interrupt flag
        P1OUT ^= BIT0|BIT6;	// toggle both LEDs
    }
}
