/*--------------------------------------------------------------------
Name: Capt Jeff Falkinburg
Date: 24 Oct 2016
Course: ECE 382
File: flashLEDs_w_Int.c
HW: Lesson 25

Purp: This program used Timer A to create delay that generates an
	interrupt to toggle an LED.  Enabling the program to do something
	else while not handling the flag

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
char flag = 0;                  // global variable to share info between main and ISR

void main(void)
{
    WDTCTL = WDTPW|WDTHOLD;     // stop the watchdog timer

    P1DIR |= BIT0|BIT6;         // set LEDs to output

    TA0CTL &= ~(MC1|MC0);        // stop timer

    TA0CTL |= TACLR;             // clear TAR

    TA0CTL |= TASSEL1;           // configure for SMCLK - what's the frequency (roughly)?

    TA0CTL |= ID1|ID0;           // divide clock by 8 - what's the frequency of interrupt?

    TA0CTL &= ~TAIFG;            // clear interrupt flag

    TA0CTL |= MC1;               // set count mode to continuous

    TA0CTL |= TAIE;              // enable interrupt

    __enable_interrupt();       // enable maskable interrupts

    int count = 0;

    while(1)
    {
        // do other useful stuff

        // respond to interrupt if it occurred
        // flag is global variable used to share information between main and the ISR
        if (flag)
        {
            flag = 0;
            P1OUT ^= BIT0;
            if (count)
            {
                P1OUT ^= BIT6;
                count = 0;
            } else
                count++;
        }
    }

}

// Flag for continuous counting is TAIFG
#pragma vector=TIMER0_A1_VECTOR
__interrupt void TIMER0_A1_ISR()
{
	TA0CTL &= ~TAIFG;            // clear interrupt flag
    flag = 1;
}
