#include "../hal_testCore.h"
#include <Arduino.h>

void TestHALCore::_key_init() {

}

bool TestHALCore::_getKey(key::KEY_INDEX _keyIndex) {
  if (_keyIndex == key::KEY_0) return !digitalRead(36);
  if (_keyIndex == key::KEY_1) return !digitalRead(39);
  return false;
}
