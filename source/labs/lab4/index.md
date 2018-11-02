# Lab 4: Servo Calibrator

![](servo.jpg)

# Objectives

- Figure out how to interface a microcontroller to various sensors and actuators
without much information
    - You will need to figure out how to do this lab without example/starter code
    - You have all the knowledge (lessons) and hands-on-experience (ICEs) to do this
    - There are many different ways to accomplish this lab, pick which ever way
    you like ... there is no right answer for hooking things up or coding.
- Interface with an RC Servo motor using PWM
- Read a potentiometer using the ADC of the uC
- Talk to an LCD using the UART serial bus
- Write modular code

# References

- [Servo motor datasheet](../../references/servo.pdf){width=75%}
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

Answer the following questions:

- Given your Launchpad operates at 3.3V, is there anything you need to worry
about with this setup? If so, what will you do to mitigate the issues? If not,
why not?
- Identify what ports/pins (Px.y) you are using for this lab and what you will configure
them for?

| Px.y | Use |
|------|-----|
|      |     |
|      | *add more lines as needed for you table* |

# Demonstration

1. Show your instructor that your setup works. You should be able to turn the
pot knob and see both the servo move and the LCD print out the angle it turned
too.
1. Show the logic analyzer displaying your PWM signal at the 2 extremes of your
servo's movement.
1. Identify the period of your PWM signal.

# Rubric

- [25 pts] Prelab (15 pts flowchart, 10 pts questions)
- [25 pts] Code organization, comments, and good programming practices
- [50 pts] Demonstration in class
