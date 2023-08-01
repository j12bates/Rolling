#include <WiFi.h>

const char *ssid = "funny room";
const char *passwd = NULL;

void setup() {
    Serial.begin(115200);
    Serial.println();

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, passwd);

    Serial.println("Connecting to WiFi Network");
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(100);
    }
    Serial.println();

    Serial.println("Connected to WiFi Network");
    Serial.println(WiFi.localIP());
}

void loop() {
}
