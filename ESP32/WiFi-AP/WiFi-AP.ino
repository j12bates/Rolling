#include <WiFi.h>

const char *ssid = "funny room";
const char *passwd = NULL;

void setup() {
    Serial.begin(115200);
    Serial.println("Creating AP");

    WiFi.mode(WIFI_AP);
    WiFi.softAP(ssid, passwd);

    Serial.print("Created with Gateway ");
    Serial.println(WiFi.softAPIP());
}

void loop() {
}
