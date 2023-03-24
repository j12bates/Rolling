const int ledPin = 13;

void setup() {
    pinMode(ledPin, OUTPUT);
    Serial.begin(115200);
}

void loop() {
    Serial.print("hello,");
    digitalWrite(ledPin, HIGH);
    delay(1000);

    Serial.print("world\n");
    digitalWrite(ledPin, LOW);
    delay(1000);
}
