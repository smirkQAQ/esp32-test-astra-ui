#include "../hal_testCore.h"
#include <Arduino.h>

void TestHALCore::_key_init() {
  pinMode(34, INPUT);
  pinMode(35, INPUT);
  pinMode(32, INPUT);
}

bool TestHALCore::_getKey(key::KEY_INDEX _keyIndex) {
  if (_keyIndex == key::KEY_0) return !digitalRead(34);
  if (_keyIndex == key::KEY_1) return !digitalRead(35);
  if (_keyIndex == key::KEY_2) return !digitalRead(32);
  return false;
}
