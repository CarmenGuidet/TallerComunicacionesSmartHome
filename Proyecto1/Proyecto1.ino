#define LED 12
void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);  
  delay(200);    
  digitalWrite(LED, LOW);  
  delay(200);
}
