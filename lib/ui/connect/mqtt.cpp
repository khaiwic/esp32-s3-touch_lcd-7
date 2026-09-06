#include "mqtt.h"

const char* WiFi_ssid = "TP-Link_612A";
const char* WiFi_password = "19308326";
String mqtt_broker = "Mqtt.mysignage.vn";
int32_t port = 1883;
String mqtt_username = "admin";
String mqtt_password = "admin";
String mqtt_topic_sub = "down_data";
String mqtt_topic_pub = "send_data";

void init_WiFi(void){
    WiFi.mode(WIFI_STA);
    WiFi.begin(WiFi_ssid, WiFi_password);

    while(WiFi.status() != WL_CONNECTED){
        WiFi.begin(WiFi_ssid, WiFi_password);
        delay(10);
    }

    Serial.println("[WiFi]: Ket noi thanh cong");

    Serial.print("Local IP: ");
    Serial.println(WiFi.localIP());

    Serial.print("MacAdress: ");
    String macA = WiFi.macAddress();
    Serial.println(macA);

    Serial.print("SSID: "); Serial.println(WiFi_ssid);
    Serial.print("Password: "); Serial.println(WiFi_password);

    vTaskDelay(pdMS_TO_TICKS(100));
    
}