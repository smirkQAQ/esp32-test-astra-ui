//
// Created by Fir on 2024/2/2.
//

#include "launcher.h"

namespace astra {

void Launcher::popInfo(std::string _info, uint16_t _time) {
  static bool init = false;
  static unsigned long long int beginTime = this->time;;
  static bool onRender = false;

  if (!init) {
    init = true;
    beginTime = this->time;
    onRender = true;
  }

  float wPop = HAL::getFontWidth(_info) + 2 * getUIConfig().popMargin;  //宽度
  float hPop = HAL::getFontHeight() + 2 * getUIConfig().popMargin;  //高度
  float yPop = 0 - hPop - 8; //从屏幕上方滑入
  float yPopTrg = (HAL::getSystemConfig().screenHeight - hPop) / 3;  //目标位置 中间偏上
  float xPop = (HAL::getSystemConfig().screenWeight - wPop) / 2;  //居中

  while (onRender) {
    time++;

    HAL::canvasClear();
    /*渲染一帧*/
    currentMenu->render(camera->getPosition());
    selector->render(camera->getPosition());
    camera->update(currentMenu, selector);
    /*渲染一帧*/

    HAL::setDrawType(0);
    HAL::drawRBox(xPop - 4, yPop - 4, wPop + 8, hPop + 8, getUIConfig().popRadius + 2);
    HAL::setDrawType(1);  //反色显示
    HAL::drawRFrame(xPop - 1, yPop - 1, wPop + 2, hPop + 2, getUIConfig().popRadius);  //绘制一个圆角矩形
    HAL::drawEnglish(xPop + getUIConfig().popMargin,
                     yPop + getUIConfig().popMargin + HAL::getFontHeight(),
                     _info);  //绘制文字

    HAL::canvasUpdate();

    Animation::move(&yPop, yPopTrg, getUIConfig().popSpeed);  //动画

    //这里条件可以加上一个如果按键按下 就滑出
    if (time - beginTime >= _time) yPopTrg = 0 - hPop - 8;  //滑出

    HAL::keyScan();
    if (HAL::getAnyKey()) {
      for (unsigned char i = 0; i < key::KEY_NUM; i++)
        if (HAL::getKeyMap()[i] == key::CLICK) yPopTrg = 0 - hPop - 8;  //滑出
      std::fill(HAL::getKeyMap(), HAL::getKeyMap() + key::KEY_NUM, key::INVALID);
    }

    if (yPop == 0 - hPop - 8) {
      onRender = false;  //退出条件
      init = false;
    }
  }
}

void Launcher::init(Menu *_rootPage) {
  currentMenu = _rootPage;

  camera = new Camera(0, 0);
  _rootPage->childPosInit(camera->getPosition());

  selector = new Selector();
  selector->inject(_rootPage);

  camera->init(_rootPage->getType());
}

/**
 * @brief 打开选中的页面
 *
 * @return 是否成功打开
 * @warning 仅可调用一次
 */
bool Launcher::open() {

  //如果当前页面指向的当前item没有后继 那就返回false
  if (currentMenu->getNextMenu() == nullptr) {
    popInfo("unreferenced page!", 600);
    return false;
  }
  if (currentMenu->getNextMenu()->getItemNum() == 0) {
    popInfo("empty page!", 600);
    return false;
  }

  currentMenu->rememberCameraPos(camera->getPositionTrg());

  currentMenu->deInit();  //先析构（退场动画）再挪动指针

  currentMenu = currentMenu->getNextMenu();
  currentMenu->forePosInit();
  currentMenu->childPosInit(camera->getPosition());

  selector->inject(currentMenu);
  //selector->go(currentPage->selectIndex);

  return true;
}

/**
 * @brief 关闭选中的页面
 *
 * @return 是否成功关闭
 * @warning 仅可调用一次
 */
bool Launcher::close() {
  if (currentMenu->getPreview() == nullptr) {
    popInfo("unreferenced page!", 600);
    return false;
  }
  if (currentMenu->getPreview()->getItemNum() == 0) {
    popInfo("empty page!", 600);
    return false;
  }

  currentMenu->rememberCameraPos(camera->getPositionTrg());

  currentMenu->deInit();  //先析构（退场动画）再挪动指针

  currentMenu = currentMenu->getPreview();
  currentMenu->forePosInit();
  currentMenu->childPosInit(camera->getPosition());

  selector->inject(currentMenu);
  //selector->go(currentPage->selectIndex);

  return true;
}

void Launcher::update() {
  HAL::canvasClear();

  currentMenu->render(camera->getPosition());
  if (currentWidget != nullptr) currentWidget->render(camera->getPosition());
  selector->render(camera->getPosition());
  camera->update(currentMenu, selector);

  // 按键去抖动处理
  static unsigned long lastDebounceTime = 0;
  const unsigned long debounceDelay = 50; // 去抖动延时，根据需要调整

  // 按键扫描频率优化
  const unsigned long keyScanInterval = 10; // 按键扫描间隔，根据需要调整
  static unsigned long lastKeyScanTime = 0;

  unsigned long currentTime = millis();
  if (currentTime - lastKeyScanTime >= keyScanInterval) {
    lastKeyScanTime = currentTime;
    HAL::keyScan();

    if (*HAL::getKeyFlag() == key::KEY_PRESSED) {
      if (currentTime - lastDebounceTime >= debounceDelay) {
        lastDebounceTime = currentTime;
        for (unsigned char i = 0; i < key::KEY_NUM; i++) {
          if (HAL::getKeyMap()[i] == key::CLICK) {
            if (i == 0) { selector->goPreview(); }
            else if (i == 1) { selector->goNext(); }
          }
        }
        std::fill(HAL::getKeyMap(), HAL::getKeyMap() + key::KEY_NUM, key::INVALID);
        *HAL::getKeyFlag() = key::KEY_NOT_PRESSED;
      }
    }
  }

  HAL::canvasUpdate();

  time = currentTime / 1000;
}
}