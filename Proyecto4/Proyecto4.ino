#include "BluetoothSerial.h"
#include <DHT11.h>

BluetoothSerial SerialBT;  // Inicializamos el Bluetooth
#define LED_PIN 12          // Pin donde está conectado el LED (GPIO2 en ESP32)
DHT11 dht11(17);           // Sensor DHT11 conectado al pin GPIO17
char command;
void setup() {
  Serial.begin(115200);             // Inicializamos la comunicación serie
  SerialBT.begin("Taller Smart Home");  // Nombre del dispositivo Bluetooth
  pinMode(LED_PIN, OUTPUT);         // Configuramos el pin del LED como salida
  digitalWrite(LED_PIN, LOW);       // Aseguramos que el LED empieza apagado
}

void loop() {
  if (SerialBT.available()) {       // Si hay datos disponibles por Bluetooth]#
    command = SerialBT.read();  // Leemos el comando como texto

    if (command == '1') {          // Si el comando es 1 encendemos
      digitalWrite(LED_PIN, HIGH);  // Encendemos el LED
      SerialBT.println("LED encendido");
    } 
    else if (command == '2') {    // Si el comando es 'OFF'
      digitalWrite(LED_PIN, LOW);   // Apagamos el LED
      SerialBT.println("LED apagado");
    } 
    else if (command == '3') {   // Si el comando es 'TEMP', leemos el sensor
      int temperatura = 0;
      int humedad = 0;
      int resultado = dht11.readTemperatureHumidity(temperatura, humedad);
      SerialBT.println("Temperatura: ");
      SerialBT.print(temperatura);
      SerialBT.print("ºC");
    } 
    else if (command == '4') {   // Si el comando es 'HUME', leemos el sensor
      int temperatura = 0;
      int humedad = 0;
      int resultado = dht11.readTemperatureHumidity(temperatura, humedad);
      SerialBT.println("Humedad: ");
      SerialBT.print(humedad);
      SerialBT.print("%");
    } 
    else {
      SerialBT.println("Usa (1)ON, (2)OFF, (3)TEMP, (4)HUME.");
    }
  }
  delay(100);  // Pequeño retardo para evitar sobrecargar el loop
}