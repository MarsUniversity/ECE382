# Reading

- **MSP430 Family User Guide**
    - Sections 1.1, 1.4 pgs 24 - 26
    - Sections 3.1, 3.2 pgs 43 - 47
- **MSP430G2553 Device Specific Datasheet**
    - Overview Pgs 1-5
    - Short-Form Description (CPU) pg 9
    - Table 8 Memory Organization pg. 13.
- <a href="http://en.wikipedia.org/wiki/Assembler_(computing)#Assembler">Assembler</a>  
- <a href="https://en.wikipedia.org/wiki/Linker_(computing)">Linker</a>

# Homework

Please **type** all homework and homework assigned this lesson is due at the
beginning of class next lesson.

**Integrity:** Your honor is extremely important.  This academic security policy is designed to help you succeed in meeting academic requirements while practicing the honorable behavior our country rightfully demands of its military.  Do not compromise your integrity by violating academic security or by taking unfair advantage of your classmates.

1. Install Code Composer Studio
1. What does the assembler do? Be specific.
1. What does the linker do? Be specific.
1. Given the code below, what is the location of each byte of the stored word, assuming big-endian byte ordering?
    ```
    mov.w   #0xdfec, &0x0200        ; stores the value 0xdfec at memory location 0x0200
    ```
1. What byte ordering scheme does the MSP430 use? (big or little endian)
1. What are the 3 types (families) of instructions for our processor?
1. What's the purpose of the program counter?
1. How many and what are the "general purpose registers"?
1. When you write to an invalid area of memory, what will happen? Be specific.

## Resources

- [ppt](Lsn2.pptx)
