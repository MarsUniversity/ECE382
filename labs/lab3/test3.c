//-----------------------------------------------------------------
// Name:    Walchko
// Purp:    This is the first code you will run. It measures the IR
//          pulses. You will use this data to fill in the spreadsheet
//          and figure out the needed timings for your IR remote.
//-----------------------------------------------------------------
#include <msp430.h>
#include <stdint.h>

// macro
#define IR_DECODER_PIN  (P2IN & BIT6)  // macro magic: bit.b #BIT6, &P2IN

// -----------------------------------------------------------------------
// -----------------------------------------------------------------------

/*
 * MSP430:  Flash/FRAM usage is 212 bytes. RAM usage is 80 bytes.
 * I get a warning, but it doesn't seem to be an issue:
 *   MSP430: Trouble Setting Breakpoint with the Action "Finish Auto Run" at 0xc000: Software
 *   breakpoint conflicts with one or more enabled hardware triggers
 *
 * */
void main(void) {
    const uint8_t SAMPLE_SIZE = 48;  // this can never change!
    uint16_t time1[SAMPLE_SIZE];
    uint16_t time0[SAMPLE_SIZE];
    uint8_t  i = 0;

    IFG1=0;                     // clear interrupt flag1
    WDTCTL=WDTPW+WDTHOLD;       // stop WD

    // Since we don't have a real crystal oscillator on our board, we can
    // set different clock speeds ... let's make it 8 MHz
    BCSCTL1 = CALBC1_8MHZ;
    DCOCTL = CALDCO_8MHZ;
                                            // Fill in the next six lines of code.
                                            // ensure TAR is clear
                                            // create a ~65 ms roll-over period with TA0CCR0
                                            // Use 1:8 prescalar off SMCLK

                                            // Set up P2.6 as GPIO not XIN
                                            // This action takes
                                            // five lines of code.

    while(1){

        while(IR_DECODER_PIN != 0);          // IR input is nominally logic 1

        for(i=0; i<SAMPLE_SIZE; i++) {
            //**Note** If you don't specify TA1 or TA0 then TAR defaults to TA0R
            TAR = 0;                        // reset timer and
            while(IR_DECODER_PIN == 0);     // wait while IR is logic 0
            time0[i] = TAR;                 // and store timer A

            TAR = 0;                        // reset timer and
            while(IR_DECODER_PIN != 0);     // wait while IR is logic 1
            time1[i] = TAR;                 // and store timer A

        } // end for
    } // end while
} // end main
