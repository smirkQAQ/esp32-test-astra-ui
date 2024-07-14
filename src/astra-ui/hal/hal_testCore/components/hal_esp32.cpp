#include "../hal_testCore.h"
#include <Arduino.h>

void TestHALCore::_esp32_init() {
  Serial.begin(115200);

  Serial.println("ESP32 init");
}
