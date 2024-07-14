#include "setup.h"
#include "icons.hpp"

auto *astraLauncher = new astra::Launcher();
auto *rootPage = new astra::Tile("root");
auto *secondPage = new astra::List("设置列表", pic_3);

void astraCoreInit(void) {
  HAL::inject(new TestHALCore);

  delay(350);

  // astra::drawLogo(1000);
  rootPage->addItem(new astra::List("测试1", pic_0));
  rootPage->addItem(new astra::List("测试2", pic_1));
  rootPage->addItem(new astra::List("测试3", pic_2));
  rootPage->addItem(secondPage);

  secondPage->addItem(new astra::List("-测试测试测试5"));
  secondPage->addItem(new astra::List("-测试测试测试6"));
  secondPage->addItem(new astra::List("-测试测试测试6"));
  secondPage->addItem(new astra::List("-测试测试测试6"));
  secondPage->addItem(new astra::List("-测试测试测试6"));

  astraLauncher->init(rootPage);
}

void astraCoreRun(void) {
  astraLauncher->update();
}

void astraCoreDestroy(void) {
  HAL::destroy();
  delete astraLauncher;
}