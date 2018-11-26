/*--------------------------------------------------------------------
Name: Maj Kevin Walchko
Date: 25 Oct 2018
Course: ECE382
-------------------------------------------------------------------------*/
#include <msp430.h>
#include <stdint.h>
#include <stdbool.h>

// The following array of tones assumes the
// Frequency Calculation Example for 440 Hz:
//
// Period of 440Hz: 1/(440Hz/2) = 4.545 msec
//
// 8 *10^6 clks   1 cnt      4.545 ms
// ------------ * ------ * ---------------   = 4545 (0x11C1) cnts ==> (440hz)
//     1 s         8 clk    1 TAR roll over
//
// Counts go from middle C and increments up two octaves
// This is an array, so the index goes from 0 to 24
// All tones assume the same calculation above, but are for different freqs
uint16_t tones[25] = {0x1DDC,0x1C30,0x1A9B,0x191C,0x17B3,0x165F,0x151E,0x13EE,0x12D0,0x11C1,0x10C2,0x0FD2,0x0EEE,0x0E18,0x0D4D,0x0C8E,0x0BDA,0x0B2F,0x0A8F,0x09F7,0x0968,0x08E1,0x0861,0x07E9,0x0777};

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;       // Stop watchdog timer

    BCSCTL1 = CALBC1_8MHZ;          // Set SMCLK 8 MHz
    DCOCTL = CALDCO_8MHZ;

    // Configure LEDs
                                    // Set P1.0 and P1.6 as an output

    // Configure button
                                    // Setup P1.3 button
                                    // Enable pull up/down resistor
                                    // Set as pull-up resistor

    // Configure interrupts
    P1IES |= BIT3;                  // Configure falling edge triggered
                                    // Clear P1.3 interrupt flag
                                    // Enable interrupts on P1.3

                                    // Turn off Timer A interrupt flag
                                    // Setting all our bits count up to TA0CCR0
    TA0CCR0 = tones;                // Set Timer A 0 TA0CCR0 value
                                    // Enable general interrupts

    while (1);                      // cpu trap

}

#pragma vector = TIMER0_A1_VECTOR
__interrupt void timerOverFlow(void){
    TA0CTL &= ~TAIFG;       // Clears the interrupt flag to return
    P1OUT ^= BIT6;          // Toggles Green LED and speaker signal on/off
}

// change this to toggle the red led and
#pragma vector = PORT1_VECTOR
__interrupt void buttonPress(void){
    P1IFG &= ~BIT3;         // Clears interrupt flag
                            // Toggle Red LED after button press
                            // Set TA0CCR0 to next tone value, make sure it wrapps
                            // back around to 0 when you get to the end of the
                            // array
}
