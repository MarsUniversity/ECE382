;-------------------------------------------------------------------------------
; Lesson 14 - Polling. Debouncing. Software Delay Routines.
;
; Purpose: Expose SMCLK on P1.4 for capture on logic analyzer
;
;-------------------------------------------------------------------------------
            .cdecls C,LIST,"msp430.h"       ; Include device header file

;-------------------------------------------------------------------------------
            .def    RESET                   ; Export program entry-point to
                                            ; make it known to linker.
;-------------------------------------------------------------------------------
            .text                           ; Assemble into program memory.
            .retain                         ; Override ELF conditional linking
                                            ; and retain current section.
            .retainrefs                     ; And retain any sections that have
                                            ; references to current section.

;-------------------------------------------------------------------------------
RESET       mov.w   #__STACK_END,SP         ; Initialize stackpointer
StopWDT     mov.w   #WDTPW|WDTHOLD,&WDTCTL  ; Stop watchdog timer


;-------------------------------------------------------------------------------
; Main loop here
;-------------------------------------------------------------------------------
            ; Measure button bouncing time
            ; Set up active-low button for input
            bic.b  #BIT3, &P1SEL   ; GPIO
            bic.b  #BIT3, &P1SEL2  ; GPIO
            bic.b  #BIT3, &P1DIR   ; pin set to input
            bis.b  #BIT3, &P1REN   ; resistor enabled
            bis.b  #BIT3, &P1OUT   ; pull-up

            ; DCO calibration
            bis.b #BIT4, &P1DIR ; show SMCLK on P1.4
            bis.b #BIT4, &P1SEL

forever     jmp forever
;-------------------------------------------------------------------------------
;           Stack Pointer definition
;-------------------------------------------------------------------------------
            .global __STACK_END
            .sect     .stack

;-------------------------------------------------------------------------------
;           Interrupt Vectors
;-------------------------------------------------------------------------------
            .sect   ".reset"                ; MSP430 RESET Vector
            .short  RESET
