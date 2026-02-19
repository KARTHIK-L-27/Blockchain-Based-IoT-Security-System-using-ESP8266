#include <ESP8266WiFi.h>
#include <DHT.h>
#include <Hash.h>

#define DHTPIN D4
#define DHTTYPE DHT11

const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD";

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi Connected");
  dht.begin();
}

void loop() {
  float temp = dht.readTemperature();
  
  String data = String(temp);
  String hashValue = sha256(data);

  Serial.print("Temperature: ");
  Serial.println(temp);
  
  Serial.print("Hash: ");
  Serial.println(hashValue);

  delay(5000);
}
