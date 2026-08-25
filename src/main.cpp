#include <Arduino.h>
#include <lvgl.h>

extern "C" {
#include "ui.h"
}

namespace {
constexpr uint16_t ScreenWidth = 800;
constexpr uint16_t ScreenHeight = 480;
constexpr uint32_t TickPeriodMs = 5;

lv_disp_draw_buf_t displayBuffer;
lv_color_t buffer[ScreenWidth * 20];
lv_disp_drv_t displayDriver;

void flushDisplay(lv_disp_drv_t *driver, const lv_area_t *area, lv_color_t *color) {
  (void)area;
  (void)color;
  lv_disp_flush_ready(driver);
}
}

void setup() {
  Serial.begin(115200);
  lv_init();

  lv_disp_draw_buf_init(&displayBuffer, buffer, nullptr, ScreenWidth * 20);
  lv_disp_drv_init(&displayDriver);
  displayDriver.hor_res = ScreenWidth;
  displayDriver.ver_res = ScreenHeight;
  displayDriver.flush_cb = flushDisplay;
  displayDriver.draw_buf = &displayBuffer;
  lv_disp_drv_register(&displayDriver);

  ui_init();
}

void loop() {
  static uint32_t lastTick = millis();
  uint32_t now = millis();
  lv_tick_inc(now - lastTick);
  lastTick = now;
  lv_timer_handler();
  delay(TickPeriodMs);
}