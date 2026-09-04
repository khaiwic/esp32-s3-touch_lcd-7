#include <Arduino.h>
#include "display.h"
void setup(){
  Serial.begin(115200);

  display_init();
  if (ui_uiTerminal != NULL) {
        lv_obj_clear_flag(ui_uiTerminal, LV_OBJ_FLAG_CLICK_FOCUSABLE);
    }
  if (ui_ImgButton3 != NULL) {
        lv_obj_clear_flag(ui_ImgButton3, LV_OBJ_FLAG_CLICK_FOCUSABLE);
    }
  if (ui_uiButtonLight != NULL) {
        lv_obj_clear_flag(ui_uiButtonLight, LV_OBJ_FLAG_CLICK_FOCUSABLE);
    }
  if (ui_uiButtonWater != NULL) {
        lv_obj_clear_flag(ui_uiButtonWater, LV_OBJ_FLAG_CLICK_FOCUSABLE);
    }
}

void loop(){
  delay(10);
}