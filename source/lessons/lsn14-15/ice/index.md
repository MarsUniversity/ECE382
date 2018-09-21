# In Class Exercise (ICE) 3

By the end of class, you will:

1. Know the speed of your clock
1. Know how long your button bounces for

# Calibrate DCO

1. Load `clock.asm` on to your uC and disconnect from laptop
1. Login to Logic Analyzer (LA) as EIT if not already logged in
    - These run Windoze 7
1. Connect POD1 to uC
    - Gnd (black wire) to uC GND
    - Bit 0 (gray wire) to pin 1.4
    - Connect USB cable to Logic Analyzer and uC (just needed for power)
1. From Overview Tab, click Buses/Signals
    - Hovering over the Logic Analyzer-1 box buttons will give pop ups
1. Only have bit 0 checked in POD 1
1. In Sampling, you should be good with 2 ns and Acquisition of 4M samples
    - 2E-9 (nsec) * 4E6 (M samples) = 8 msec run time
1. Select Waveform tab
1. Press Run Single button (should be lite green before press and off after press and the stop button will light up red)
1. Hit stop button when you see data on the screen

## Show Instructor

- Clock aveform
- What is your clock period in nsec (or whatever the appropriate time unit is)

# Button Debouncing

**I added the button setup to** `clock.asm`

1. Load `clock.asm` on to your uC and disconnect from laptop
1. Connect POD1 to uC
    - Gnd (black wire) to uC GND
    - Bit 0 (gray wire) to pin 1.3
    - Connect USB cable to Logic Analyzer and uC (just needed for power)
1. Start off with the same setup as DCO calibration
1. On the waveform tab, change Simple Trigger from an X to rising
1. Press Run Single
1. Use markers to determine time bouncing stops
1. Repeat 5 times and take average length of bounces
    - Only look at rising edge (button release), it seems to be worse than button press (falling edge)
    - Don't count times where you see no bouncing ... press slow, not fast :)

## Show Instructor

- Final bouncing waveform on logic analyzer
- The 5 button press times and the average

# Lab 2

You now have some of the basic data to properly do Lab 2, which involves button
presses! If you did not finish this, then I suggest you have it done before
we start Lab 2.
