#define ECG_PIN 34  // AD8232 Output connected to GPIO 34
#define LO_PLUS 26  // Lead-off detection (optional)
#define LO_MINUS 27 // Lead-off detection (optional)

void setup() {
  Serial.begin(115200);
  pinMode(ECG_PIN, INPUT);
  pinMode(LO_PLUS, INPUT);
  pinMode(LO_MINUS, INPUT);
}

void loop() {
  int ecgValue = analogRead(ECG_PIN);
  
  if (digitalRead(LO_PLUS) == 1 || digitalRead(LO_MINUS) == 1) {
    Serial.println("Leads Off!"); // Electrodes are disconnected
  } else {
    Serial.println(ecgValue);
  }
  
  delay(100);  // Small delay to stabilize readings
}
