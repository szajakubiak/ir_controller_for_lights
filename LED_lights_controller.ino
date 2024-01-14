#include <Arduino.h>
#include "TinyIRSender.hpp"
#include "LowPower.h"

#define IR_SEND_PIN 5
#define INTERRUPT_PIN 3

void wakeUp()
{
    // Just a handler for the pin interrupt.
}

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(INTERRUPT_PIN, INPUT);
}

uint8_t sAddress = 0x55;
uint8_t sOnCommand = 0x2D;
uint8_t sOffCommand = 0xA5;
uint8_t sRepeats = 3;

void loop() {
  attachInterrupt(1, wakeUp, CHANGE);
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF); 
  detachInterrupt(1);
  delay(100);
  if (digitalRead(INTERRUPT_PIN)) {
    sendNEC(IR_SEND_PIN, sAddress, sOffCommand, sRepeats);
  }
  else {
    sendNEC(IR_SEND_PIN, sAddress, sOnCommand, sRepeats);
  }
}
