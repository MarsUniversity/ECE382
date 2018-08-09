# Reading

- **MSP430 Family Users Guide**
    - Section 3.2 CPU Registers
- [Stacks](http://en.wikipedia.org/wiki/Stack_(abstract_data_type)  
- [Stack Overflow](http://en.wikipedia.org/wiki/Stack_overflow)
- [Stack Example in CCS](Lesson10_Stack_Example_in_CCS.pptx)
    - [Stack Example code](Lesson10_Stack_Example.asm)

# Homework

Please **type** all homework and homework assigned this lesson is due at the
beginning of lesson 11.

**Integrity:** Your honor is extremely important.  This academic security policy is designed to help you succeed in meeting academic requirements while practicing the honorable behavior our country rightfully demands of its military.  Do not compromise your integrity by violating academic security or by taking unfair advantage of your classmates.

1. What do you use the stack for?
1. What is the SP used for?
1. When you do a `push`, how does the value of the stack pointer change?
1. When you do a `pop`, which of the following 2 things does it do:
    1. write data to destination, then change SP value
    1. change SP value, then write data to destination
1. How can I use the stack to swap the values in two registers (say r10, r11)?
1. Can we push too much to the stack? If so, how is this bad?
1. How can you avoid subroutines from destroying registers? Be specific.
1. What is the difference between pass-by-value and pass-by-reference?
1. When would you use pass-by-reference?

## Resources

- [ppt](Lsn9-10.pptx)
- [Example subroutine asm](ex_subroutine.asm)
- [Stack example](stack_example.asm)
