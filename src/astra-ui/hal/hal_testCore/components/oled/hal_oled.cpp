#include "../../hal_testCore.h"
#include <u8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0);

void TestHALCore::_ssd1306_reset(bool _state)
{
  if (_state) {
    u8g2.begin();
  } else {
    
  }
}

void TestHALCore::_ssd1306_set_cursor(unsigned char _x, unsigned char _y)
{
  u8g2.setCursor(_x, _y);
}

void TestHALCore::_ssd1306_fill(unsigned char _data)
{
  u8g2.clearBuffer();
  for (int y = 0; y < u8g2.getDisplayHeight(); y++) {
    for (int x = 0; x < u8g2.getDisplayWidth(); x++) {
      u8g2.drawPixel(x, y);
    }
  }
  u8g2.sendBuffer();
}

/**
 * @brief transmit token to OLED.
 *
 * @param _data data to transmit.
 * @param _cmd command, if 1, transmit command, else transmit data.
 */

void TestHALCore::_screenOn()
{
  u8g2.setPowerSave(0);
}

void TestHALCore::_screenOff()
{
  u8g2.setPowerSave(1);
}

void TestHALCore::_ssd1306_init()
{
  _ssd1306_reset(true);
}

void TestHALCore::_u8g2_init()
{
  // 初始化 u8g2 结构体
  // 根据所选的芯片进行初始化工作，初始化完成后，显示器处于关闭状态
  // 打开显示器

  // 字体模式选择
  // 字体方向选择
  // 字库选择
  // 初始化 u8g2 结构体
  u8g2.begin();
  u8g2.enableUTF8Print(); // 启用UTF-8打印，用于中文显示
  u8g2.setFontMode(1); // 设置字体模式为透明背景
  u8g2.setFontDirection(0); // 设置字体方向为从左至右
  u8g2.setFont(u8g2_font_wqy12_t_gb2312); // 设置默认字体
  u8g2.clearBuffer(); // 清除缓冲区
  u8g2.sendBuffer(); // 更新屏幕
}

void *TestHALCore::_getCanvasBuffer()
{
  // 返回 u8g2 的缓冲区指针
  return u8g2.getBufferPtr();
}

unsigned char TestHALCore::_getBufferTileHeight()
{
  // 返回 u8g2 的页高
  return u8g2.getBufferTileHeight();
}

unsigned char TestHALCore::_getBufferTileWidth()
{
  // 返回 u8g2 的页宽
  return u8g2.getBufferTileWidth();
}

void TestHALCore::_canvasUpdate()
{
  // 更新屏幕显示
  u8g2.sendBuffer();
}

void TestHALCore::_canvasClear()
{
  // 清除屏幕缓冲区
  u8g2.clearBuffer();
}

void TestHALCore::_setFont(const unsigned char *_font)
{
  // 设置字体
  u8g2.setFont(_font);
}

unsigned char TestHALCore::_getFontWidth(std::string &_text)
{
  // 获取字体宽度
  return u8g2.getUTF8Width(_text.c_str());
}

unsigned char TestHALCore::_getFontHeight()
{
  // 获取字体高度
  return u8g2.getFontAscent() - u8g2.getFontDescent();
}

void TestHALCore::_setDrawType(unsigned char _type)
{
  // 设置绘画颜色
  u8g2.setDrawColor(_type);
}

void TestHALCore::_drawPixel(float _x, float _y)
{
  // 在指定位置绘制一个像素
  u8g2.drawPixel(_x, _y);
}

void TestHALCore::_drawEnglish(float _x, float _y, const std::string &_text)
{
  // 在指定位置绘制英文文本
  u8g2.drawStr(_x, _y, _text.c_str());
}

void TestHALCore::_drawChinese(float _x, float _y, const std::string &_text)
{
  // 在指定位置绘制中文文本
  // 确保字体支持中文，并且使用了正确的编码
  u8g2.drawUTF8(_x, _y, _text.c_str());
}

void TestHALCore::_drawVDottedLine(float _x, float _y, float _h)
{
  // 在指定位置绘制垂直虚线
  for (float i = _y; i < _y + _h; i += 2) {
    u8g2.drawPixel(_x, i);
  }
}

void TestHALCore::_drawHDottedLine(float _x, float _y, float _l)
{
  // 在指定位置绘制水平虚线
  for (float i = _x; i < _x + _l; i += 2) {
    u8g2.drawPixel(i, _y);
  }
}

void TestHALCore::_drawVLine(float _x, float _y, float _h)
{
  // 在指定位置绘制垂直线
  u8g2.drawVLine(_x, _y, _h);
}

void TestHALCore::_drawHLine(float _x, float _y, float _l)
{
  // 在指定位置绘制水平线
  u8g2.drawHLine(_x, _y, _l);
}

void TestHALCore::_drawBMP(float _x, float _y, float _w, float _h, const unsigned char *_bitMap)
{
  // 在指定位置绘制位图
  u8g2.drawXBMP(_x, _y, _w, _h, _bitMap);
}

void TestHALCore::_drawBox(float _x, float _y, float _w, float _h)
{
  // 在指定位置绘制实心矩形
  u8g2.drawBox(_x, _y, _w, _h);
}

void TestHALCore::_drawRBox(float _x, float _y, float _w, float _h, float _r)
{
  // 在指定位置绘制实心圆角矩形
  u8g2.drawRBox(_x, _y, _w, _h, _r);
}

void TestHALCore::_drawFrame(float _x, float _y, float _w, float _h)
{
  // 在指定位置绘制矩形边框
  u8g2.drawFrame(_x, _y, _w, _h);
}

void TestHALCore::_drawRFrame(float _x, float _y, float _w, float _h, float _r)
{
  // 在指定位置绘制圆角矩形边框
  // 注意：u8g2 库本身不直接支持绘制圆角矩形边框，需要使用 drawRBox() 和 drawBox() 组合实现
  // 这里假设 _r 是圆角半径
  u8g2.drawRBox(_x, _y, _w, _h, _r);
  // 清除内部的矩形以形成边框
  u8g2.drawBox(_x + _r, _y, _w - 2 * _r, _r);
  u8g2.drawBox(_x + _r, _y + _h - _r, _w - 2 * _r, _r);
  u8g2.drawBox(_x, _y + _r, _r, _h - 2 * _r);
  u8g2.drawBox(_x + _w - _r, _y + _r, _r, _h - 2 * _r);
}