# Reading

- **MSP430 Family User Guide**
    - Sections 3.3 Addressing Modes
    - Section 3.4 Instruction Set
- [Debuggers](http://en.wikipedia.org/wiki/Debugger)  
- [MSP430 Instruction Set](http://mspgcc.sourceforge.net/manual/x223.html)

# Homework

Please **type** all homework.

**Integrity:** Your honor is extremely important.  This academic security policy is designed to help you succeed in meeting academic requirements while practicing the honorable behavior our country rightfully demands of its military.  Do not compromise your integrity by violating academic security or by taking unfair advantage of your classmates.


**Note:** These questions are based on both the class slides and the reading above.

**Note:** This is due the beginning of lesson 6.

1. Not due until lesson 6, but you need to start on it before it is due:
    - Make an account at www.codecademy.com and take the "Learn Git" class.
    - You are taking the free version, so you don't have to pay for anything
      and don't try to do anything labelled "Pro"
    - There are several lessons for the "Pro" version, but you have to pay for
      those, *don't take them*. The system *should* automatically skip you over
      them although there are several pop-ups to get you to join.
    - Please pay attention to this lesson, you will be quizzed and tested on
      **this** material.
        - You might want to keep some notes on what the commands do so you
        can review for the quiz or test
        - When you are done, turn in a screenshot of your progress, it should
          look like this, but read 100% complete (ignore the other courses in
          the picture) ![](codecademy-git.png){width=75%}
1. For a jump instruction, how many bits is the PC offset and what is your jump
  range? (Hint: is the PC offset signed or unsigned?)
1. What are emulated instructions and how do they differ from the 3 other
  instruction types?
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
1. Convert the following assembly in to machine code: `xor @r12+, 0(r6)`
1. What does the command `clrc` do?
1. What is the command `jn` and what status bit does it look at?
1. For `jnc` if the status bit C=0, what value gets put into PC?
1. For `jlo` if the status bit C=0, what value gets put into PC?
1. How are the commands `rra` and `rrc` different?
1. For `subc`, what is the destination register equal to?
1. For `tst`, what are the status registers set to?
1. If you did `tst r9`, is the value of r9 changed?
1. How does `tst` and `tst.b` differ in operation?
1. Which command produces *larger* code and why? `add #200, r10` or `add r3, r4`
1. Is the instruction `add #200, #5000` valid? Why or why not?
1. Which status register flags affect the following jump commands?
    1. JNE
    1. JN
    1. JMP


## Resources

- [ppt](Lsn3-4-5.pptx)
