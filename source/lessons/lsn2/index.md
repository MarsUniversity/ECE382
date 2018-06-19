# Reading

- [**MSP430 Family User Guide**](datasheets/msp430_msp430x2xx_family_users_guide.pdf)
    - Sections 1.1, 1.4 pgs 24 - 26 (BB pgs 1 - 3)
    - Sections 3.1, 3.2 pgs 43 - 47 (BB pgs 10 - 12)
- [**MSP430G2553 Device Specific Datasheet**](datasheets/msp430g2x53_2x13_mixed_sig_mcu.pdf)
    - Pgs 1-5 (BB pgs 105 - 106)
    - Short-Form Description (CPU) pg 9 (BB pg 108)
    - Table 8 Memory Organization pg. 13 (BB pg 110).  Compare to memory map in Section 1.4 of Family User Guide
- Barrett 1.5, 2.11, 3.1-3.4 (pp7-11, pp52-53, pp77-83)
- <a href="http://en.wikipedia.org/wiki/Assembler_(computing)#Assembler">Assembler</a>  
- <a href="https://en.wikipedia.org/wiki/Linker_(computing)">Linker</a>

# Homework

Please type all homework

1. What does the assembler do? Be specific.
1. What does the linker do? Be specific.
1. Given the code below, what is the location of each byte of the stored word, assuming big-endian byte ordering?
	```
	mov.w   #0xdfec, &0x0200        ; stores the value 0xdfec at memory location 0x0200
	```
1. What byte ordering scheme does the MSP430 use? What would be the location of each byte of the stored word?
1. What's the purpose of the program counter? Be specific.
1.

## Resources

- [ppt](Lsn2.pptx)
