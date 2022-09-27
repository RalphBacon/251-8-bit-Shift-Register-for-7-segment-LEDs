// Clock pin 11 on 74HC595
#define clockPin 12

// Serial data on pin 14 on 74HC595
#define dataPin 11

// Latch pin on pin 12 on 74HC595
#define latchPin 8

void setup() {
  // All pins send out data
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);

  // Initially, don't send out any data
  digitalWrite(clockPin, LOW);
  digitalWrite(latchPin, LOW);

  // Just for demo
  pinMode(14, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);

  // Clear display (twice for two digits)
  {
    shiftOut(dataPin, clockPin, LSBFIRST, 0b11111111);
    digitalWrite(latchPin, HIGH);
    digitalWrite(latchPin, LOW);

    shiftOut(dataPin, clockPin, LSBFIRST, 0b11111111);
    digitalWrite(latchPin, HIGH);
    digitalWrite(latchPin, LOW);
  }
}

void loop() {
  // Zero = ON, 1 = OFF (Common Anode, so we SINK current)
  uint8_t pinValue = getPinValue();
  digitalWrite(dataPin, pinValue);

  // Toggle the clockPin so 75HC595 takes notice of data pin state
  digitalWrite(clockPin, HIGH);
  digitalWrite(clockPin, LOW);

  // Tell 74HC595 to LATCH the data into the output (so we can see it);
  digitalWrite(latchPin, HIGH);
  digitalWrite(latchPin, LOW);

  // Far too quick for a human
  delay(250);
}

uint8_t getPinValue() {
  while (1) {
    if (digitalRead(14) == LOW) return 1;
    if (digitalRead(15) == LOW) return 0;
  }
}