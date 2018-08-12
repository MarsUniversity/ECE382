# Lab 1 - Assembly Language - "A Simple Calculator"

## Objectives

You'll write your first complete assembly language program using what you've
learned in class.  You **will** use the following in your program:

- the instruction set
- addressing modes
- flow control
  - conditional jumps
  - status register flags
- assembly directives
- subroutines

## Directions

You'll write a program that interprets a series of operands and operations and
stores the results - an assembly language calculator!

Your program will start reading at the location in ROM where you stored the
calculator instructions.  It will read the first byte as the first operand.  
The next byte will be an operation.  The third byte will be the second operand.  
Your program will execute the expected operation and store the result starting
at `0x0200`.  The result will then be the first operand for the next operation.  
The next byte will be an operation.  The following will be the second operand.  
Your program will execute the requested operation and store the result at `0x0201`.
Your program will continue doing this until you encounter an `END_OP` - at which
point, your program will cease execution.

## Functionality

- The input and output for the calculator will be in memory locations.  The
calculator operations and operands will be stored in ROM - any location in ROM
is acceptable.  The results of the calculations will be stored in RAM starting
at `0x0200`.  
- Labels shall be used in the program to refer to the location of your instructions
and results.
- The input operands and output results will be positive integers between 0
and 255 (an unsigned byte). If you are passed a value greater than 255, then
you *must* set it to 255.
- Good coding standards (labels, .`equ` where appropriate) must be used throughout
(review the lessons if you are unclear on what this means)
- Comment code to others can easily follow your code
- Break your code up into logical blocks of code (subroutines) so it is easy to
debug and check

## Calculator Instruction Set

Your program will implement the following operations:

**ADD_OP**  
An addition operation is coded by the value 0x11.  It adds two numbers and
stores the result. The calculator program `0x14 0x11 0x12` is equivalent to
`0x14 + 0x12`.  It would store the result `0x26`.

**SUB_OP**  
An subtraction operation is coded by the value 0x22.  It subtracts two numbers
and stores the result. The calculator program `0x21 0x22 0x01` is equivalent to
`0x21 - 0x1`.  It would store the result `0x20`.

**MUL_OP**  
An multiplication operation is coded by the value `0x33`.  It multiplies two
numbers and stores the result. The calculator program `0x02 0x33 0x04` is
equivalent to `0x02 * 0x04`.  It would store the result `0x08`.

The MSP430G2553 that you're using does not have a hardware multiplier, so think
how multiplication works and implement an algorithm. It doesn't has to be the
fastest algorithm, just has to work. Also, we are only working with whole
numbers.

**CLR_OP**  
A clear operation, represented by the value `0x44`, clears the result by storing
`00` to memory.  It then uses the second operand as the initial value for the
next operation. The calculator program `0x21 0x22 0x01 0x44 0x14 0x11 0x12` is
equivalent to `0x21 - 0x1 CLR 0x14 + 0x12`.  It would store `0x20 0x00 0x26`.

**END_OP**  
The end operation terminates execution of the calculator.  It is coded by the
value `0x55`.

Example calculator program: `0x14 0x11 0x32 0x22 0x08 0x44 0x04 0x11 0x08 0x55`  
It's equivalent to: `0x14 + 0x32 - 0x08 CLR 0x04 + 0x08 0x55`. The result should
be, stored at `0x0200`: `0x46 0x3e 0x00 0x0c`

If your program gets an byte that is not in the above instruction set, it will reset.
Any values already stored in the `0x0200` output location will be retained, but
any operands pushed into a register will be cleared (or just forgotten) and your
program will start back through its flowchart for reading inputs.

## Use Subroutines!

Although some of these operations are really simple, you need to start thinking
about how to break up a program into logical chunks.

## Document Your Code!

Proper documentation is important. If another programmer needs to maintain your
code (or in our case, grade your code) and they cannot easily follow it, because
you failed to properly document it, then that is a failure.

## Use Assembler Directives!

Your program is going to be reading a series of operands and operations from memory.  Use the `.byte` directive to store them!

```
                .text
myProgram:      .byte      0x13,0x22,0x14,0x11,0x37
```

Your program is going to be storing results to memory.  Use the `.space` directive to store space for them!

```
                .data
myResults:      .space      20                          ; reserving 20 bytes of space
```

Hex values code for operations.  I better not see any magic numbers!
```
ADD_OP:         .equ        0x11
SUB_OP:         .equ        0x22
```

# Prelab

**This is due at the beginning of class**

You will hand in a flow diagram of how your program will work (use PowerPoint).
Your flow chart must start from when the program starts running until your program
receives an **END_OP**

Answer the following questions:

1. What should your program do if an input is out of range?
1. How do you know if an input is out of range?
1. What should your program do if an operator is unknown?
1. Are there any bytes that you *cannot* use as an operand?
1. What happens if you do not find and `0x55` (**END_OP**) command?

# Demonstration

Here are the test cases you must demonstrate to your instructor before the end
of the class:

1. `0x11, 0x11, 0x11, 0x11, 0x11, 0x44, 0x22, 0x22, 0x22, 0x11, 0xCC, 0x55`
    - Result: `0x22, 0x33, 0x00, 0x00, 0xCC`
2. `0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0xDD, 0x44, 0x08, 0x22, 0x09, 0x44, 0xFF, 0x22, 0xFD, 0x55`
    - Result: `0x22, 0x33, 0x44, 0xFF, 0x00, 0x00, 0x00, 0x02`
3. `0x22, 0x11, 0x22, 0x22, 0x33, 0x33, 0x08, 0x44, 0x08, 0x22, 0x09, 0x44, 0xff, 0x11, 0xff, 0x44, 0xcc, 0x33, 0x02, 0x33, 0x00, 0x44, 0x33, 0x33, 0x08, 0x55`
    - Result: `0x44, 0x11, 0x88, 0x00, 0x00, 0x00, 0xff, 0x00, 0xff, 0x00, 0x00, 0xff`
4. An additional input/result pair will be given on the last day of the lab

When you demo, due to time limitations, you only get *one* chance to demo for full
credit, so make sure it works (repeatedly) before you show the instructor. Any
follow-on demos will result in a 10% penalty each time. Also, **demos will only
be done in class.** The exception to this is, if you are late and need to demo
**after** the lab is done. Then you are subjected to a 25% penalty.

## Rubric

- [25 pts] Prelab (15 flowchart, 10 questions)
- [25 pts] Code organization, comments, and good programming practices
- [50 pts] Demonstration in class
