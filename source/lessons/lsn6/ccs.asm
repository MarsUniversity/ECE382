;-------------------------------------------------------------------------------
; Lesson 7
; Capt Jeff Falkinburg, USAF / 25 Aug 2016 /
;
; This program shows the solution the the Lesson 7 Miniquiz and
; 	writes your name 6 times in RAM
;-------------------------------------------------------------------------------
            .cdecls C,LIST,"msp430.h"       ; Include device header file

;-------------------------------------------------------------------------------
            .def    RESET                   ; Export program entry-point to
                                            ; make it known to linker.
;-------------------------------------------------------------------------------
            .text                           ; Assemble into program memory.
myName:		.string	"Jeff Falkinburg!"
NumNames:	.equ	0x0006
NumWords:	.equ	0x0008
MemLoc:		.equ	0x0200
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
;                   						; | V | N | Z | C |
											; |---|---|---|---|
            mov.w 	#0x7fff, r5				; | - | - | - | - |
			add.w	#1, r5					; | 1 | 1 | 0 | 0 |
			mov.b	#0x80, r6				; | - | - | - | - |
			add.b	#0x80, r6				; | 1 | 0 | 1 | 1 |
			mov.b	#0x7f, r7				; | - | - | - | - |
			sub.b	#0x80, r7				; | 1 | 1 | 0 | 0 |
			xor.w	r3, r7					; | 0 | 0 | 0 | 1 |
; Logical instructions set C to the opposite of Z - i.e. C is set if the result is NOT 0.

main:		mov		#NumNames, r4			; Initializes registers
			mov		#MemLoc, r6
NextName:	mov		#myName, r5				; Set up registers to write name again
			mov		#NumWords, r7
WriteName:	mov		@r5, 0(r6)				; Write word to memory
			incd 	r6						; Increment RAM destination memory
			incd 	r5						; Increment name (ROM) memory
			dec		r7						; Decrement counter for number of words
			jnz		WriteName				; Keep writing until the end of name
			dec		r4
			jnz		NextName
forever: 	jmp		forever
;-------------------------------------------------------------------------------
; Stack Pointer definition
;-------------------------------------------------------------------------------
            .global __STACK_END
            .sect   .stack

;-------------------------------------------------------------------------------
; Interrupt Vectors
;-------------------------------------------------------------------------------
            .sect   ".reset"                ; MSP430 RESET Vector
            .short  RESET
