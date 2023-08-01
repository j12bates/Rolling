#include "WiFi.h"

void setup() {
    Serial.begin(115200);

    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);

    Serial.println("Setup Done");
}

void loop() {
    Serial.println("Beginning Scan");

    int n = WiFi.scanNetworks();
    Serial.println("Scan Finished");
    if (n == 0) Serial.println("No Networks Found");
    else {
        Serial.print(n);
        Serial.println(" Networks Found");
        for (int i = 0; i < n; i++) {
            Serial.print(i);
            Serial.print(": ");
            Serial.print(WiFi.SSID(i));
            Serial.print(" (");
            Serial.print(WiFi.RSSI(i));
            Serial.print(")");
            Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)
                    ? " " : "*");
            delay(10);
        }
    }
    Serial.println("");

    delay(5000);
}
