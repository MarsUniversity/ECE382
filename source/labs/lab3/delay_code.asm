
		.cdecls C,LIST,"msp430.h"       ; Include device header file

;-------------------------------------------------------------------------------
;-------------------------------------------------------------------------------
        .text                           ; Assemble into program memory
        .retain                         ; Override ELF conditional linking
                                        ; and retain current section
        .retainrefs                     ; Additionally retain any sections
                                        ; that have references to current
                                        ; section

		; need to declare our subroutine functions so C can access them
		.global		Delay160ms
		.global		Delay40ms
;-------------------------------------------------------------------------------
;	Name: Delay40ms - updated for 8MHz clock
;	Inputs: none
;	Outputs: none
;	Purpose: this is a 40ms delay.
;	Registers: r7 preserved
;-------------------------------------------------------------------------------
Delay40ms:
	push	r7
	mov		#0xD154, r7		;should be ~20ms, based on 8MHz clock - plenty of room for error
delay:
	dec		r7
	jnz		delay
	mov		#0xD154, r7		;should be ~20ms, based on 8MHz clock - plenty of room for error
delay2:
	dec		r7
	jnz		delay2
	pop		r7
	ret

;-------------------------------------------------------------------------------
;	Name: Delay160ms - updated for 8 MHz clock
;	Inputs: none
;	Outputs: none
;	Purpose: creates ~160ms delay
;	Registers: r7 preserved
;-------------------------------------------------------------------------------
Delay160ms:
		push	r7
		call	#Delay40ms
		call	#Delay40ms
		call	#Delay40ms
		call	#Delay40ms
		pop		r7
		ret
