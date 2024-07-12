#include "../hal_testCore.h"
#include <Arduino.h>

void TestHALCore::_esp32_init() {
  Serial.begin(115200);

  pinMode(36, INPUT);
  pinMode(39, INPUT);
  
  Serial.println("ESP32 init");
}
