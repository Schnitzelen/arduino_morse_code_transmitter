# arduino_morse_code_transmitter
Arduino project that converts a serial input to morse code and transmits it back through the onboard activity led.

The input is given through the serial monitor and may be a simple space (' ') or any of the characters and numbers that are defined by the "International Morse Code" (https://en.wikipedia.org/wiki/Morse_code).

The code converts the input string, letter for letter, and responds in the serial monitor with each individual letter and morse code as it is transmitted through the onboard activity led.
