#include <Wire.h>     // Bibliothek für die I2C-Kommunikation
#include <DHT20.h>    // Bibliothek für den DHT20-Temperatur- und Feuchtigkeitssensor

// DHT20-Sensorobjekt erstellen
DHT20 dht;

void setup() {
  delay(200);                 // Kurze Startverzögerung
  Serial.begin(9600);         // Serielle Ausgabe aktivieren
  Wire.begin();               // I2C-Bus starten

  // Überprüfen, ob der Sensor erkannt wird
  if (dht.begin()) {
    Serial.println("DHT20 bereit.");   // Sensor erfolgreich initialisiert
  } else {
    Serial.println("DHT20 nicht gefunden!");  // Fehler beim Erkennen des Sensors
  }
}

void loop() {
  // Messwerte vom Sensor auslesen
  float t = dht.getTemperature();   // Temperatur in °C
  float h = dht.getHumidity();      // relative Luftfeuchtigkeit in %RH

  // Überprüfen, ob gültige Messwerte vorliegen
  if (isnan(t) || isnan(h)) {
    Serial.println("Messfehler / Sensorproblem?");
  } else {
    // Ausgabe der Messwerte in der seriellen Konsole
    Serial.print("Temperatur: ");
    Serial.print(t);
    Serial.println(" °C");

    Serial.print("Feuchte:    ");
    Serial.print(h);
    Serial.println(" %RH");

    Serial.println("----------------------");
  }

  delay(2000);  // 2 Sekunden warten bis zur nächsten Messung
}


