#ifndef _MQTT_H_
#define _MQTT_H_

#include <Arduino.h>
#include <ArduinoJson.h>
#include <PubSubClient.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>

void init_WiFi(void);
void init_Mqtt(void);
void Reconnect_Mqtt(void);
#endif