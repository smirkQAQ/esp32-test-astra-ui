#include "Arduino.h"
#include <u8g2lib.h>
// #include "./astra-ui/astra/ui/launcher.h"
#include "./astra-ui/hal/hal.h"
#include "./astra-ui/hal/hal_testCore/hal_testCore.h"
// #include "icons.hpp"

#include "./astra-ui/astra/astra_logo.h"

// auto *astraLauncher = new astra::Launcher();
// auto *rootPage = new astra::Tile("root");

// bool test = false;
// unsigned char testIndex = 0;
// unsigned char testSlider = 60;

// auto *secondPage = new astra::List("secondPage");

void setup() {
  HAL::inject(new TestHALCore);

  delay(350);

  astra::drawLogo(1000);

  // HAL::printInfo("loading...");
  // rootPage->addItem(new astra::List("测试1"));
  // rootPage->addItem(new astra::List("测试2"));
  // rootPage->addItem(new astra::List("测试测试3"));
  // rootPage->addItem(new astra::List("测试测试3"));
  // rootPage->addItem(secondPage);

  // secondPage->addItem(new astra::List());
  // secondPage->addItem(new astra::List("-测试2"), new astra::CheckBox(test));
  // secondPage->addItem(new astra::Tile("-测试测试3"), new astra::PopUp(1, "测试", {"测试"}, testIndex));
  // secondPage->addItem(new astra::Tile("-测试测试测试4"), new astra::Slider("测试", 0, 100, 50, testSlider));
  // secondPage->addItem(new astra::List("-测试测试测试5"));
  // secondPage->addItem(new astra::List("-测试测试测试6"));
  // secondPage->addItem(new astra::List("-测试测试测试6"));
  // secondPage->addItem(new astra::List("-测试测试测试6"));
  // secondPage->addItem(new astra::List("-测试测试测试6"));

  // astraLauncher->init(rootPage);
}

void loop() {
  // astraLauncher->update();
}
