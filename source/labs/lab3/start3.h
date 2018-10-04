//-----------------------------------------------------------------
// your header here
//-----------------------------------------------------------------

#ifndef __LAB3_H__
#define __LAB3_H__

//-----------------------------------------------------------------
// Function prototypes found in lab3.c
//-----------------------------------------------------------------
// void initMSP430();
__interrupt void pinChange (void);
__interrupt void timerOverflow (void);


//-----------------------------------------------------------------
// Each PxIES bit selects the interrupt edge for the corresponding I/O pin.
//    Bit = 0: The PxIFGx flag is set with a low-to-high transition
//    Bit = 1: The PxIFGx flag is set with a high-to-low transition
//-----------------------------------------------------------------

// macros to make things easier
#define IR_PIN     (P2IN & BIT6)
#define HIGH_2_LOW P2IES |= BIT6
#define LOW_2_HIGH P2IES &= ~BIT6

// change these for your remote
const uint16_t averageLogic0Pulse = 0;
const uint16_t averageLogic1Pulse = 0;
const uint16_t averageStartPulse = 0;
const uint16_t minLogic0Pulse = averageLogic0Pulse - 100;  // stdev??
const uint16_t maxLogic0Pulse = averageLogic0Pulse + 100;
const uint16_t minLogic1Pulse = averageLogic1Pulse - 100;
const uint16_t maxLogic1Pulse = averageLogic1Pulse + 100;
const uint16_t minStartPulse = averageStartPulse - 100;
const uint16_t maxStartPulse = averageStartPulse + 100;

const uint32_t ONE = 0x00000000
const uint32_t TWO = 0x00000000
const uint32_t THREE = 0x00000000

#endif // __LAB3_H__
