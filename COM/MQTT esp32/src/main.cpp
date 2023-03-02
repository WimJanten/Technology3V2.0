#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "H369A08BC8E";
const char* password = "543DAFED2EEF";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
}

void loop() {
  // put your main code here, to run repeatedly:
}