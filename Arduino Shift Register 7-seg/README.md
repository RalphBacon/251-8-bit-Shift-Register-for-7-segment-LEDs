### Please note

In the sketch here, the binary value to turn on each segment (eg 0b01111111 to turn on the 'A' segment) are for **COMMON ANODE** LEDs. 

If you want to control **COMMON CATHODE** LEDs then you must invert the value (eg 0b01111111 becomes 0b10000000 to light up the "A" segment).

If you don't know which type of LED you have try the sketch as-is. If you get weird results (not the segments lighting up you expect) carry out the inversion as described above - it will take a few seconds to do!
