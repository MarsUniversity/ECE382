/*--------------------------------------------------------------------
Name: Capt Jeff Falkinburg
Date: 24 Oct 2016
Course: ECE 382
File: pollingTAIFG.c
HW: Lesson 25

Purp: This program used Timer A to create delay to toggle an LED
	while polling the TAIFG

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
    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer

    BCSCTL1 = CALBC1_8MHZ;      // Set SMCLK 8 MHz
    DCOCTL = CALDCO_8MHZ;

    P1DIR = BIT6;               // Set the green LED as an output

    TA0CCR0 = 0xFFFF;                    // Set the interval to 2^16 - 1
    TA0CTL &= ~TAIFG;                     // Clear any rollover flag
    TA0CTL |= ID_3 | TASSEL_2 | MC_1;     // Important Timer stuff!

// ID_0 Divide by 1
//    1 sec        1 clks      65535 cnts
// ------------ * ------ * --------------- = 8.19 ms
//  8 *10^6 clks   1 cnt    1 TAR roll over

// ID_3 Divide by 8
//    1 sec        8 clks      65535 cnts
// ------------ * ------ * --------------- = 65.535 ms
//  8 *10^6 clks   1 cnt    1 TAR roll over

	while(1) {
		while ((TA0CTL & TAIFG) == 0); // Polling timer flag?         Would this be good for pong game?
		TA0CTL &= ~TAIFG;              // Clear rollover flag
		P1OUT ^= BIT6;                // toggle LED
		} // end infinite loop
}



