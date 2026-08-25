#include <Arduino.h>
#include "display.h"
void setup(){
  Serial.begin(115200);

  display_init();
}

void loop(){
  delay(10);
}