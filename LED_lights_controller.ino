#include <Arduino.h>
#include "TinyIRSender.hpp"
#include "LowPower.h"

// infrared emitter pin
#define IR_SEND_PIN 5
// door switch pin
#define INTERRUPT_PIN 3

void wakeUp()
{
  // handler for interrupt
}

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(INTERRUPT_PIN, INPUT);
}

// address of lights
uint8_t sAddress = 0x55;
// lights on command
uint8_t sOnCommand = 0x2D;
// lights off command
uint8_t sOffCommand = 0xA5;
uint8_t sRepeats = 3;

void loop() {
  // create interrupt on any switch event
  attachInterrupt(1, wakeUp, CHANGE);
  // sleep device
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
  // disable interrupt after waking up
  detachInterrupt(1);
  delay(100);
  // if door closed switch off the light
  if (digitalRead(INTERRUPT_PIN)) {
    sendNEC(IR_SEND_PIN, sAddress, sOffCommand, sRepeats);
  }
  // if door opened turn on the light
  else {
    sendNEC(IR_SEND_PIN, sAddress, sOnCommand, sRepeats);
  }
}
