#include "Arduino.h"
#include "./astra-ui/astra/setup.h"

void setup() {
  astraCoreInit();
}

void loop() {
  astraCoreRun();
}
