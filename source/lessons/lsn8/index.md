# Reading

- [MSP430 Family Users Guide](/382/datasheets/msp430_msp430x2xx_family_users_guide.pdf)
    - Section 3.2 CPU Registers
- [Control Flow](http://en.wikipedia.org/wiki/Control_flow)
- [Overflow Flag](http://en.wikipedia.org/wiki/Overflow_flag)
- [Status Register](https://en.wikipedia.org/wiki/Status_register)

# Homework

1. What is the purpose of the following registers:
    1. PC
    1. SR
    1. SP
1. Within the SR, what are the following bits used for:
    1. bit 3
    1. bit 1
    1. bit 8
    1. bit 0
1. Which registers (*hint:* there are 2) are used for generating constant numbers?
    1. What are the 6 constants they can generate?
1. What is overflow?
1. Write an assembly code snippet for the following code:
```c++
int m = 0;
for (int i=0; i <10; i++){
    m += 2;
}
```

## Resources

- [ppt](Lsn8.pptx)
