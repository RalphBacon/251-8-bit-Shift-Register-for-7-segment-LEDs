// 74HC595 8-bit Shift Register (with latch) demo for 7-segment displays
#include "charSet.h"

// Clock pin 11 on 74HC595
#define clockPin 12

// Serial data on pin 14 on 74HC595
#define dataPin 11

// Latch pin on pin 12 on 74HC595
#define latchPin 8

void setup() {
  Serial.begin(115200);

  // All pins send out data
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);

  // Initially, don't send out any data
  digitalWrite(clockPin, LOW);
  digitalWrite(latchPin, LOW);
  Serial.println("Setup completed.");
}

void loop() {

  // Clear all
  {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, 255);
    shiftOut(dataPin, clockPin, LSBFIRST, 255);
    digitalWrite(latchPin, HIGH);
    digitalWrite(latchPin, LOW);
    delay(500);
  }

  // Send segments A → G sequentially
  shiftOut(dataPin, clockPin, LSBFIRST, B01111111);  //a
  digitalWrite(latchPin, HIGH);
  delay(500);
  digitalWrite(latchPin, LOW);

  shiftOut(dataPin, clockPin, LSBFIRST, B00111111);  //b
  digitalWrite(latchPin, HIGH);
  delay(500);
  digitalWrite(latchPin, LOW);

  shiftOut(dataPin, clockPin, LSBFIRST, B00011111);  //c
  digitalWrite(latchPin, HIGH);
  delay(500);
  digitalWrite(latchPin, LOW);

  shiftOut(dataPin, clockPin, LSBFIRST, B00001111);  //d
  digitalWrite(latchPin, HIGH);
  delay(500);
  digitalWrite(latchPin, LOW);

  shiftOut(dataPin, clockPin, LSBFIRST, B00000111);  //e
  digitalWrite(latchPin, HIGH);
  delay(500);
  digitalWrite(latchPin, LOW);

  shiftOut(dataPin, clockPin, LSBFIRST, B00000011);  //f
  digitalWrite(latchPin, HIGH);
  delay(500);
  digitalWrite(latchPin, LOW);

  shiftOut(dataPin, clockPin, LSBFIRST, B00000001);  //g
  digitalWrite(latchPin, HIGH);
  delay(500);
  digitalWrite(latchPin, LOW);

  shiftOut(dataPin, clockPin, LSBFIRST, B00000000);  //dp
  digitalWrite(latchPin, HIGH);
  delay(500);
  digitalWrite(latchPin, LOW);

  shiftOut(dataPin, clockPin, LSBFIRST, B11111111);  // all off
  digitalWrite(latchPin, HIGH);
  delay(500);
  digitalWrite(latchPin, LOW);

  //Send Data out - 2 but don't show anything yet (no latch)
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, 0b00100101);

  //Send Data out - 4
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, 0b10011001);
  digitalWrite(latchPin, HIGH);
  delay(1000);

  // Clear all
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, 255);
  shiftOut(dataPin, clockPin, LSBFIRST, 255);
  digitalWrite(latchPin, HIGH);
  digitalWrite(latchPin, LOW);
  delay(500);

  // ---------------------
  // Simple counter 0 - 99
  // ---------------------

  // Outer loop is 'tens'
  for (auto outer = 0; outer < 10; outer++) {

    // Inner loop is 'units'
    for (auto inner = 0; inner < 10; inner++) {

      // Don't update the display at this stage
      digitalWrite(latchPin, LOW);

      // Send out the digits, rightmost ('units') first
      shiftOut(dataPin, clockPin, LSBFIRST, _digits[inner]);
      shiftOut(dataPin, clockPin, LSBFIRST, _digits[outer]);

      // Show the digits by toggling the LATCH pin
      digitalWrite(latchPin, HIGH);
      digitalWrite(latchPin, LOW);

      // Just for fun: if it's 42 flash the number!
      if (inner == 2 && outer == 4) flashNumber(inner, outer);
      delay(150);
    }
  }
}

// Just flash the number 42 to show we can do this
void flashNumber(int inner, int outer) {
  // Flash five times
  for (auto cnt = 0; cnt < 5; cnt++) {
    // Send two 'blank' digits
    shiftOut(dataPin, clockPin, LSBFIRST, _digits[10]);
    shiftOut(dataPin, clockPin, LSBFIRST, _digits[10]);

    // Show the blank digits by toggling the LATCH pin
    digitalWrite(latchPin, HIGH);
    digitalWrite(latchPin, LOW);
    delay(150);

    // Re-send out the previous numbers, rightmost first
    shiftOut(dataPin, clockPin, LSBFIRST, _digits[inner]);
    shiftOut(dataPin, clockPin, LSBFIRST, _digits[outer]);

    // Show the digits by toggling the LATCH pin
    digitalWrite(latchPin, HIGH);
    digitalWrite(latchPin, LOW);
    delay(150);
  }
}