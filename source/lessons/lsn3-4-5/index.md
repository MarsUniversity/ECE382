# Reading

- [**MSP430 Family User Guide**](/382/datasheets/msp430_msp430x2xx_family_users_guide.pdf)
    - Sections 3.3 Addressing Modes
    - Section 3.4 Instruction Set
- [Debuggers](http://en.wikipedia.org/wiki/Debugger)  
- [MSP430 Instruction Set](http://mspgcc.sourceforge.net/manual/x223.html)

# Homework

**Note:** These questions are based on both the class slides and the reading above.

1. What for single operand instruction, what is the Opcode and how many bits is it?
1. For a jump instruction, how many bits is the PC offset and what is your jump
  range? (Hint: is the PC offset signed or unsigned?)
1. What are emulated instructions and how do they differ from the 3 other
  instruction types?
1. For the instruction `mov r10, r11`, if r10 initially contained `0xa023`,
  what is the value of r10 and r11 after the instruction is executed?
1. Also, for the above question, what is the new value of the PC if it was
  initially `0x2000`?
1. What is the formula for the new PC in a jump instruction?
    1. *hint:* PC_new = ____ + _____ + _____ x ______
1. Identify the addressing modes for each of the following:
    1. `mov r8, r9`
    1. `mov @r8, r9`
    1. `mov @r8+, r9`
    1. `mov @r8, r9`
1. Convert the following assembly in to machine code: `mov.b #0x75, r10`
1. Convert the following assembly in to machine code: `mov #170, r10`
1. Convert the following assembly in to machine code: `mov @r7, r8`
1. Convert the following assembly in to machine code: `swpb r10`
1. What does the command `clrc` do?
1. What is the command `jn` and what status bit does it look at?
1. For `jnc` if the status bit C=0, what value gets put into PC?
1. For `jlo` if the status bit C=0, what value gets put into PC?
1. How are the commands `rra` and `rrc` different?
1. For `subc`, what is the destination register equal to?
1. For `tst`, what are the status registers set to?
1. If you did `tst r9`, is the value of r9 changed?
1. How does `tst` and `tst.b` differ in operation?

## Resources

- [ppt](Lsn3-4-5.pptx)
