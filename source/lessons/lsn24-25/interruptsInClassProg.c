/*--------------------------------------------------------------------
Name: Capt Jeff Falkinburg
Date: 26 Oct 2016
Course: ECE 382
File: interruptsInClassProg.c
HW: Lesson 26

Purp: 	1. This C program utilizes interrupts to Blink the Green LED using Timer A
		2. Then create another interrupt from a button press to toggle the Red LED

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
    WDTCTL = WDTPW | WDTHOLD;		// Stop watchdog timer

//    P1DIR |= BIT6;				// Set P1.6 (Green LED) as an output
    P1DIR |= BIT0|BIT6;				//2 Set P1.0 & P1.6 (Green and Red LEDs) as an output

    								//2 Set up button
    P1DIR &= ~BIT3;					//2 Set up our P1.3 button
    P1REN |= BIT3;					//2 Enable pull up/down resistor
    P1OUT |= BIT3;					//2 Set as pull up yellow book (pp 39 or pp 329)

    								//2 Configure interrupt
    P1IES |= BIT3;					//2 Configure rising/falling edge triggered
    P1IFG &= ~BIT3;					//2 Clear P1.3 interrupt flag
    P1IE |= BIT3;					//2 Enable interrupts on BIT3 Port 1

    TA0CTL &= ~TAIFG;				// Turn off Timer A interrupt flag
    TA0CTL |= ID_3 | TASSEL_2 | MC_1 | TAIE;
    								// Setting all our bits count up to TA0CCR0
    TA0CCR0 = 0xFFFF;				// Set Timer A 0 TA0CCR0 value
    __enable_interrupt();			// Enable Interrupts and then write function

    while (1);						// cpu trap

}

#pragma vector = TIMER0_A1_VECTOR
__interrupt void timerOverFlow (void){
	P1OUT ^= BIT6;					// XOR Toggles our green LED on/off after timer
	TA0CTL &= ~TAIFG;				// Clears the interrupt flag to return
}

#pragma vector = PORT1_VECTOR
__interrupt void Port_1_ISR (void){
	P1OUT ^= BIT0;					// XOR Toggles our red LED on/off after button press
	P1IFG &= ~BIT3;					// Clears interrupt flag
}




