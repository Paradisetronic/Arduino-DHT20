     
 #include <Wire.h>
#include <DHT20.h>

DHT20 dht;  // DHT20-Sensorobjekt

void setup() {
  delay(200);
  Serial.begin(9600);      // Serielle Ausgabe
  Wire.begin();            // I2C starten

  if (dht.begin()) {
    Serial.println("DHT20 bereit.");
  } else {
    Serial.println("DHT20 nicht gefunden!");
  }
}

void loop() {
  float t = dht.getTemperature();   // Temperatur in °C
  float h = dht.getHumidity();      // relative Feuchte in %RH

  if (isnan(t) || isnan(h)) {
    Serial.println("Messfehler / Sensor?");
  } else {
    Serial.print("Temperatur: "); Serial.print(t); Serial.println(" °C");
    Serial.print("Feuchte:    "); Serial.print(h); Serial.println(" %RH");
    Serial.println("----------------------");
  }

  delay(2000);
}
