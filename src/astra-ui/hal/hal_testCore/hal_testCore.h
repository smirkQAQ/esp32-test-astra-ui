#include "../hal.h"

class TestHALCore : public HAL {
private:
  void _esp32_init();
  void _ssd1306_init();
  void _key_init();
  void _u8g2_init();

public:
  TestHALCore() = default;

public:
  inline void init() override {
    _esp32_init();
    _ssd1306_init();
    _key_init();
    _u8g2_init();
  }


protected:
  void _ssd1306_reset(bool _state);
  void _ssd1306_set_cursor(unsigned char _x, unsigned char _y);
  void _ssd1306_fill(unsigned char _data);

public:
  void _screenOn() override;
  void _screenOff() override;

public:
  void* _getCanvasBuffer() override;
  unsigned char _getBufferTileHeight() override;
  unsigned char _getBufferTileWidth() override;
  void _canvasUpdate() override;
  void _canvasClear() override;
  void _setFont(const unsigned char * _font) override;
  unsigned char _getFontWidth(std::string& _text) override;
  unsigned char _getFontHeight() override;
  void _setDrawType(unsigned char _type) override;
  void _drawPixel(float _x, float _y) override;
  void _drawEnglish(float _x, float _y, const std::string& _text) override;
  void _drawChinese(float _x, float _y, const std::string& _text) override;
  void _drawVDottedLine(float _x, float _y, float _h) override;
  void _drawHDottedLine(float _x, float _y, float _l) override;
  void _drawVLine(float _x, float _y, float _h) override;
  void _drawHLine(float _x, float _y, float _l) override;
  void _drawBMP(float _x, float _y, float _w, float _h, const unsigned char* _bitMap) override;
  void _drawBox(float _x, float _y, float _w, float _h) override;
  void _drawRBox(float _x, float _y, float _w, float _h, float _r) override;
  void _drawFrame(float _x, float _y, float _w, float _h) override;
  void _drawRFrame(float _x, float _y, float _w, float _h, float _r) override;

public:
  bool _getKey(key::KEY_INDEX _keyIndex) override;

public:
  void _updateConfig() override;
};
