//-----------------------------------------------------------------
// Your header here
//-----------------------------------------------------------------
// #include <msp430g2553.h>
// #include <stdint.h>
#include "start5.h"

bool newIrPacket = FALSE;
uint16_t packetData[48];
uint8_t packetIndex = 0;

// -----------------------------------------------------------------------
// In order to decode IR packets, the MSP430 needs to be configured to
// tell time and generate interrupts on positive going edges.  The
// edge sensitivity is used to detect the first incoming IR packet.
// The P2.6 pin change ISR will then toggle the edge sensitivity of
// the interrupt in order to measure the times of the high and low
// pulses arriving from the IR decoder.
//
// The timer must be enabled so that we can tell how long the pulses
// last.  In some degenerate cases, we will need to generate a interrupt
// when the timer rolls over.  This will indicate the end of a packet
// and will be used to alert main that we have a new packet.
// -----------------------------------------------------------------------
// -----------------------------------------------------------------------
// -----------------------------------------------------------------------
void main(void){

    WDTCTL=WDTPW+WDTHOLD;  // stop WDT

    BCSCTL1 = CALBC1_8MHZ;
    DCOCTL = CALDCO_8MHZ;

                        // Set up P2.6 as GPIO not XIN
                        // as before

    P2IFG &= ~BIT6;     // Clear any interrupt flag on P2.3
    P2IE  |= BIT6;      // Enable P2.3 interrupt

    HIGH_2_LOW;         // check the header out.  P2IES changed.
                        // Set LEDs as outputs
                        // And turn the LEDs off

                        // create a 16ms roll-over period
                        // clear flag before enabling interrupts = good practice
                        // Use 1:8 prescalar off SMCLK and enable interrupts

    _enable_interrupt();

    while(1){
        if (packetIndex > 33) {
            packetIndex = 0;
        } // end if new IR packet arrived
    } // end infinite loop
} // end main



// -----------------------------------------------------------------------
// Since the IR decoder is connected to P2.6, we want an interrupt
// to occur every time that the pin changes - this will occur on
// a positive edge and a negative edge.
//
// Negative Edge:
// The negative edge is associated with end of the logic 1 half-bit and
// the start of the logic 0 half of the bit.  The timer contains the
// duration of the logic 1 pulse, so we'll pull that out, process it
// and store the bit in the global irPacket variable. Going forward there
// is really nothing interesting that happens in this period, because all
// the logic 0 half-bits have the same period.  So we will turn off
// the timer interrupts and wait for the next (positive) edge on P2.6
//
// Positive Edge:
// The positive edge is associated with the end of the logic 0 half-bit
// and the start of the logic 1 half-bit.  There is nothing to do in
// terms of the logic 0 half bit because it does not encode any useful
// information.  On the other hand, we going into the logic 1 half of the bit
// and the portion which determines the bit value, the start of the
// packet, or if the timer rolls over, the end of the ir packet.
// Since the duration of this half-bit determines the outcome
// we will turn on the timer and its associated interrupt.
// -----------------------------------------------------------------------
#pragma vector = PORT2_VECTOR          // This is from the MSP430G2553.h file

__interrupt void pinChange (void) {

    uint8_t    pin;
    uint16_t   pulseDuration;          // The timer is 16-bits

    if (IR_PIN)        pin=1;    else pin=0;

    switch (pin) {                    // read the current pin level
        case 0:                        // !!!!!!!!!NEGATIVE EDGE!!!!!!!!!!
            pulseDuration = TA0R;    //**Note** If you don't specify TA1 or TA0 then TAR defaults to TA0R
            packetData[packetIndex++] = pulseDuration;
            LOW_2_HIGH;                 // Set up pin interrupt on positive edge
            break;

        case 1:                            // !!!!!!!!POSITIVE EDGE!!!!!!!!!!!
            TA0R = 0x0000;                        // time measurements are based at time 0
            HIGH_2_LOW;                         // Set up pin interrupt on falling edge
            break;
    } // end switch

    P2IFG &= ~BIT6;            // Clear the interrupt flag to prevent immediate ISR re-entry

} // end pinChange ISR

// -----------------------------------------------------------------------
//            0 half-bit    1 half-bit        TIMER A COUNTS        TIMER A COUNTS
//    Logic 0    xxx
//    Logic 1
//    Start
//    End
//
// -----------------------------------------------------------------------
#pragma vector = TIMER0_A1_VECTOR            // This is from the MSP430G2553.h file
__interrupt void timerOverflow (void) {

    TA0CTL &= ~TAIFG;
}
