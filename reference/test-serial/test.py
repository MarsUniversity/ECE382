#!/usr/bin/env python2

import serial
import time

def cmd(ser, c):
    ser.write(c)
    time.sleep(0.1)


ser = serial.Serial()
# ser.port = '/dev/tty.usbserial-AL034G2K'
ser.port = '/dev/tty.usbserial-A904MISU'
ser.buadrate = 9600
ser.open()

cmd(ser, b'\xfe\x01')  # clear
cmd(ser, b'\xfe\x80')  # cursor at start
ser.write(b'here we go!')
# cmd(ser, b'\x7c\x80')  # backlight off
# time.sleep(1)
# cmd(ser, b'\x7c\x9d')  # backlight on
# ser.write(b'\x7c\x80')
# ser.write(b'\x12')
cmd(ser, b'\xfe\x08')  # display off
time.sleep(1)
cmd(ser, b'\xfe\x0c')  # display on
time.sleep(1)

ser.write(b'hello')

for _ in range(20):
    time.sleep(0.5)
    cmd(ser, b'\xfe\x1c')  # scroll right 1 space

time.sleep(1)

ser.close()
