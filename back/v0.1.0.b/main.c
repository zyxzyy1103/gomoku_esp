#include <Arduino.h>
#include <stdint.h>

#include "display.h"

void setup() {
  SetupDisplayIO();
}

void loop() {
  Display();
}
