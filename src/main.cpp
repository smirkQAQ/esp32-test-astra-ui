#include "Arduino.h"
#include <u8g2lib.h>
#include "./astra-ui/astra/ui/launcher.h"
#include "./astra-ui/hal/hal.h"
#include "./astra-ui/hal/hal_testCore/hal_testCore.h"

astra::Launcher* astraLauncher = new astra::Launcher();
astra::Menu* rootPage = new astra::Menu("root");

std::vector<uint8_t> pic_0 = {
    0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xF1, 0x3F,
    0xFF, 0xFF, 0xC3, 0x3F, 0xFF, 0xFF, 0x87, 0x3F, 0xFF, 0xFF, 0x07, 0x3F, 0xFF, 0xFF, 0x0F, 0x3E,
    0xFF, 0xFF, 0x0F, 0x3E, 0xFF, 0xFF, 0x0F, 0x3C, 0xFF, 0xFF, 0x0F, 0x3C, 0xFF, 0xFF, 0x0F, 0x38,
    0xFF, 0xFF, 0x0F, 0x38, 0xFF, 0xFF, 0x0F, 0x38, 0xFF, 0xFF, 0x07, 0x38, 0xFF, 0xFF, 0x07, 0x38,
    0xFF, 0xFF, 0x03, 0x38, 0xF7, 0xFF, 0x01, 0x38, 0xE7, 0xFF, 0x00, 0x3C, 0x87, 0x3F, 0x00, 0x3C,
    0x0F, 0x00, 0x00, 0x3E, 0x0F, 0x00, 0x00, 0x3E, 0x1F, 0x00, 0x00, 0x3F, 0x3F, 0x00, 0x80, 0x3F,
    0x7F, 0x00, 0xC0, 0x3F, 0xFF, 0x01, 0xF0, 0x3F, 0xFF, 0x07, 0xFC, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F,
    0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F
};

std::vector<uint8_t> pic_1 = {
    0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xF9, 0xE7, 0x3F,
    0xFF, 0xF9, 0xE7, 0x3F, 0xFF, 0xF9, 0xE7, 0x3F, 0xFF, 0xF0, 0xE7, 0x3F, 0x7F, 0xE0, 0xE7, 0x3F,
    0x7F, 0xE0, 0xC3, 0x3F, 0x7F, 0xE0, 0xC3, 0x3F, 0x7F, 0xE0, 0xC3, 0x3F, 0x7F, 0xE0, 0xE7, 0x3F,
    0xFF, 0xF0, 0xE7, 0x3F, 0xFF, 0xF9, 0xE7, 0x3F, 0xFF, 0xF9, 0xE7, 0x3F, 0xFF, 0xF9, 0xE7, 0x3F,
    0xFF, 0xF9, 0xE7, 0x3F, 0xFF, 0xF9, 0xC3, 0x3F, 0xFF, 0xF9, 0x81, 0x3F, 0xFF, 0xF0, 0x81, 0x3F,
    0xFF, 0xF0, 0x81, 0x3F, 0xFF, 0xF0, 0x81, 0x3F, 0xFF, 0xF9, 0x81, 0x3F, 0xFF, 0xF9, 0xC3, 0x3F,
    0xFF, 0xF9, 0xE7, 0x3F, 0xFF, 0xF9, 0xE7, 0x3F, 0xFF, 0xF9, 0xE7, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F,
    0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F
};

std::vector<uint8_t> pic_2 = {
    0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F, 0xEF, 0xFF, 0xFF, 0x3F, 0xC7, 0xFF, 0xFF, 0x3F,
    0xC7, 0xF3, 0xFF, 0x3F, 0x83, 0xC0, 0xFF, 0x3F, 0xEF, 0xCC, 0xFF, 0x3F, 0x6F, 0x9E, 0xFF, 0x3F,
    0x6F, 0x9E, 0xFF, 0x3F, 0x2F, 0x3F, 0xFF, 0x3F, 0x2F, 0x3F, 0xFF, 0x3F, 0x8F, 0x7F, 0xFE, 0x3F,
    0x8F, 0x7F, 0xFE, 0x39, 0x8F, 0x7F, 0xFE, 0x39, 0xCF, 0xFF, 0xFC, 0x3C, 0xCF, 0xFF, 0xFC, 0x3C,
    0xEF, 0xFF, 0xFC, 0x3C, 0xEF, 0xFF, 0x79, 0x3E, 0xEF, 0xFF, 0x79, 0x3E, 0xEF, 0xFF, 0x33, 0x3F,
    0xEF, 0xFF, 0x33, 0x3F, 0xEF, 0xFF, 0x87, 0x3F, 0xEF, 0xFF, 0xCF, 0x3F, 0xEF, 0xFF, 0x7F, 0x3E,
    0xEF, 0xFF, 0x7F, 0x38, 0x0F, 0x00, 0x00, 0x30, 0xFF, 0xFF, 0x7F, 0x38, 0xFF, 0xFF, 0x7F, 0x3E,
    0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F
};

std::vector<uint8_t> pic_3 = {
    0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F,
    0xFF, 0x1F, 0xFE, 0x3F, 0xFF, 0x1F, 0xFE, 0x3F, 0xFF, 0x0C, 0xCC, 0x3F, 0x7F, 0x00, 0x80, 0x3F,
    0x3F, 0x00, 0x00, 0x3F, 0x3F, 0xE0, 0x01, 0x3F, 0x7F, 0xF8, 0x87, 0x3F, 0x7F, 0xFC, 0x8F, 0x3F,
    0x3F, 0xFC, 0x0F, 0x3F, 0x0F, 0x3E, 0x1F, 0x3C, 0x0F, 0x1E, 0x1E, 0x3C, 0x0F, 0x1E, 0x1E, 0x3C,
    0x0F, 0x3E, 0x1F, 0x3C, 0x3F, 0xFC, 0x0F, 0x3F, 0x7F, 0xFC, 0x8F, 0x3F, 0x7F, 0xF8, 0x87, 0x3F,
    0x3F, 0xE0, 0x01, 0x3F, 0x3F, 0x00, 0x00, 0x3F, 0x7F, 0x00, 0x80, 0x3F, 0xFF, 0x0C, 0xCC, 0x3F,
    0xFF, 0x1F, 0xFE, 0x3F, 0xFF, 0x1F, 0xFE, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F,
    0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F
};

astra::Menu* secondPage = new astra::Menu("secondPage", pic_3);

void setup() {
  HAL::inject(new TestHALCore);

  rootPage->addItem(new astra::Menu("test1", pic_0));
  rootPage->addItem(new astra::Menu("测试2", pic_1));
  rootPage->addItem(new astra::Menu("测试测试3", pic_2));
  rootPage->addItem(secondPage);

  secondPage->addItem(new astra::Menu("-测试1"));
  secondPage->addItem(new astra::Menu("-测试2"));
  secondPage->addItem(new astra::Menu("-测试测试3"));
  secondPage->addItem(new astra::Menu("-测试测试测试4"));
  secondPage->addItem(new astra::Menu("-测试测试测试5"));
  secondPage->addItem(new astra::Menu("-测试测试测试6"));

  astraLauncher->init(rootPage);
}
void loop() {
  astraLauncher->update();
}
