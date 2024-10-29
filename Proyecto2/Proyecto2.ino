#include <DHT11.h>
// - For ESP32: Connect the sensor to pin GPIO2 or P2.

DHT11 dht11(17);

void setup() {
    Serial.begin(9600);
}

void loop() {
    int temperatura = 0;
    int humedad = 0;
    dht11.readTemperatureHumidity(temperatura, humedad);

    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.print(" °C\tHumedad: ");
    Serial.print(humedad);
    Serial.println(" %");

    delay(1000);
}