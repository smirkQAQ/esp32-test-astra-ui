#include "../../hal_testCore.h"
#include <u8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif

#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

#define OLED_MOSI  23
#define OLED_SDA   21
#define OLED_CLK   22
#define OLED_CS    14
#define OLED_DC    27
#define OLED_RESET 26

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0);
// U8G2_SSD1306_128X64_VCOMH0_F_4W_SW_SPI u8g2(U8G2_R2, OLED_CLK, OLED_MOSI, OLED_CS, OLED_DC, OLED_RESET);

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

// void TestHALCore::_ssd1306_init()
// {
//   _ssd1306_reset(true);
// }

void TestHALCore::_u8g2_init()
{
  // SPI.begin(OLED_CLK, OLED_MOSI, OLED_CS);
  // SPI.setFrequency(1000000); // 设置SPI时钟频率，可以根据实际情况调整

  Wire.begin(OLED_SDA, OLED_CLK); //SDA SCL
  u8g2.setBusClock(800000); //800KHZ
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
  u8g2.drawRFrame((int16_t)std::round(_x), (int16_t)std::round(_y), (int16_t)std::round(_w), (int16_t)std::round(_h), (int16_t)std::round(_r));
}