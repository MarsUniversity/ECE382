# Lab 4: Servo Calibrator

![](servo.jpg)

# Objectives

- Interface with an RC Servo motor using PWM
- Read a potentiometer using the ADC of the uC
- Talk to external peripherals using the serial bus

# References

- [Servo motor datasheet](../../references/servo.pdf)

# Directions

![](lab-setup.png)

The goal of this lab is to read a potentiometer (use your ADC) and command a
servo motor using PWM. You will write a couple of functions to set up your uC
to talk to the servo motor. The standard timing for RC servos is:

![](servos.png)

Note: there is no standard (really) in RC servos, thus, different servos could
give you different angles with the same PWM signal. They will be *ballpark*
the same, but that isn't always good enough depending on the application.

```c
const int max_pwm = ?;
const int min_pwm = ?;

void servo_attach(int pin){
  /*
  Setup the pwm subsystem to control the servo using pin
  */
}

void servo_write(int angle){
  /*
  Turn the servo to the desired angle.
  input: angle [0-180 deg], if outside range, the input is saturated
  */
  // code
}
```
