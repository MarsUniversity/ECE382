# Lab 4: Servo Motor

![](servo.jpg){width=300px}

# Objectives

- Interfacing a microcontroller with external HW
    - You will need to figure out how to do this lab without example/starter code
    - You have all the knowledge (lessons) and hands-on-experience (ICEs) to do this
    - There are many different ways to accomplish this lab, pick which ever way
    you like ... there is no right answer for hooking things up or coding.
- Interface with an RC Servo motor using PWM
- Read a potentiometer using the ADC of the uC
- Talk to an LCD using the UART serial bus
- Write modular code

# References

- [Servo motor datasheet](servo.pdf)
- [LCD datasheet](SerLCD_v2_5ApplicationNote.pdf)
- Class lessons
- Class ICEs

# Directions

The goal of this lab is to read a potentiometer (use your ADC) and command a
servo motor using PWM. Note, there is no standard (really) in RC servos, thus,
different servos could give you different angles with the same PWM signal. They
will be *ballpark* the same, but that isn't always good enough depending on
the application.

For the LCD read out of the angular position, integers is fine: 0, 1, 2, 3, ...
180 degrees.

For each peripheral write its own header/implementation file: PWM, serial, and
ADC. You will write a lot of code and it is cleaner if they are in multiple files
rather than one really one `main.c`.

# Prelab

- You will hand-in a flow chart of your program.
- Hand in a wiring diagram (you can use PowerPoint, Visio or equivalent)
- Identify what ports/pins (Px.y) you are using for this lab and what you will
use them for in the table below:

| Px.y | Use |
|------|-----|
| P1.0 | Set as output, red LED for debugging the ...  |
|      | *add more lines as needed for you table* |

# Demonstration

1. When your MSP430 boots up, it should clear the LCD and then print:
    - Line 1: `ECE 382, Fall 2018`
    - Line 2: `C2C First Last` (obviously fill in your rank and name)
    - Wait about 3 seconds, then clear the screen and show the servo angle

1. Show your instructor that your setup works. You should be able to turn the
pot knob and see both the servo move and the LCD print out the angle it turned
too.
    1. Servo should turn from ~0 to ~180 deg when the pot is turned
        1. If you are off by a 1-2 degrees, that is ok
        1. Show your instructor the angles: ~0, ~90, ~180 deg
    1. LCD line 1 should show the current angle, example `Servo: 25 deg`
    1. Don't try to turn the servo less than 0 deg or more than 180 deg
1. Show the logic analyzer displaying your PWM signal at the 2 extremes of your
servo's movement.
    1. Identify the period of your PWM signal
    1. Show the pulse width (msec) of your signal for an angle of ~0 deg
    1. Show the pulse width (msec) of your signal for an angle of ~180 deg

# Bonus

1. Go back to lab 3 and control the servo with your IR remote. Select 3 buttons
which correspond to 0, 90, and 180 deg.

# Rubric

- [10 pts] Prelab
- [20 pts] Code organization, comments, and good programming practices
- [70 pts] Demonstration in class
- [15 pts] **Bonus**
