#Jack-o-candle 2.0
This project is based on the [NeoPixel Jack-o-Latern from adafruit]
(https://learn.adafruit.com/neopixel-jack-o-lantern/)

Serial commands were added to control the states of the LEDs.  Read more about using the NeoPixel Arduino library when updating the code.
https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library

##Serial Command API
###f
Starts LED Flickering
###c
Clear to turn off LEDs
###0-9
Set the brightness of all LEDs
###rgb
Set the Red Green Blue values for the LEDs 

Example A. rgb900    -> sets LEDs to RED

Example B. rgb090    -> sets LEDs to GREEN

Example C. rgb009    -> sets LEDs to BLUE



