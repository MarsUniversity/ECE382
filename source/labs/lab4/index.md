# Lab 4: Servo Calibrator

# Objectives

- Interface with an RC Servo motor using PWM
- Read a potentiometer using the ADC of the uC
- Talk to external peripherals using the serial bus

# Directions

You will write a couple of functions to set up your uC to talk to the servo motor.
Note: there is no standard (really) in RC servos, thus, different servos could give
you different angles with the same pwm signal. They will be *ballpark* the same,
but that isn't always good enough depending on the application.

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
