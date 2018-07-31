/*--------------------------------------------------------------------
Name: Capt Jeff Falkinburg
Date: 24 Oct 2016
Course: ECE 382
File: buttonInterrupt.c
HW: Lesson 26

Purp: This program uses push button interrupt to toggle an LEDs via ISR

Doc:  Lecture Notes

Academic Integrity Statement: I certify that, while others may have
assisted me in brain storming, debugging and validating this program,
the program itself is my own work. I understand that submitting code
which is the work of other individuals is a violation of the honor
code.  I also understand that if I knowingly give my original work to
another individual is also a violation of the honor code.
-------------------------------------------------------------------------*/
#include <msp430.h> 

char interruptFlag = 0;

/*
 * main.c
 */
void main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    P1DIR |= BIT0|BIT6;                     // set LEDs to output

    P1DIR &= ~BIT3;                            // set button to input

    P1REN |= BIT3;                          // enable internal pull-up/pull-down network
    P1OUT |= BIT3;                          // configure as pull-up

    P1IES |= BIT3;                          // configure interrupt to sense falling edges

    P1IFG &= ~BIT3;                         // clear P1.3 interrupt flag

    P1IE |= BIT3;                           // enable the interrupt for P1.3

    __enable_interrupt();

    // main program loop
    while (1) {
        //  if (interruptFlag)
        //      // respond
    }
}

#pragma vector=PORT1_VECTOR
__interrupt void Port_1_ISR(void)
{
    P1IFG &= ~BIT3;                         // clear P1.3 interrupt flag
    P1OUT ^= BIT0|BIT6;                     // toggle LEDs
    interruptFlag = 1;
}
