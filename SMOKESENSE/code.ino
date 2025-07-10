const int tempPin = A0;       // TMP36 temp sensor
const int gasPin = A1;        // MQ2 gas sensor
const int ledPin = 13;        // LED
const int buzzerPin = 7;      // Buzzer

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Read and convert temperature
  int tempRaw = analogRead(tempPin);
  float voltage = tempRaw * (5.0 / 1023.0);
  float temperatureC = (voltage - 0.5) * 100.0;

  // Check if temperature is valid
  bool tempIsValid = (temperatureC >= 10 && temperatureC <= 150);
  bool tempIsDanger = (tempIsValid && temperatureC > 45);

  // Read gas sensor
  int gasValue = analogRead(gasPin);
  bool gasIsDanger = gasValue > 400;

  // Decide alert based on both
  bool fireDetected = tempIsDanger || gasIsDanger;

  // Debug output
  Serial.print("Temp: ");
  Serial.print(tempIsValid ? temperatureC : -999);  // shows -999 for fake temp
  Serial.print(" °C | Gas: ");
  Serial.print(gasValue);
  Serial.print(" | Temp Danger: ");
  Serial.print(tempIsDanger);
  Serial.print(" | Gas Danger: ");
  Serial.print(gasIsDanger);
  Serial.print(" | FIRE DETECTED: ");
  Serial.println(fireDetected);

  // Alert output
  digitalWrite(ledPin, fireDetected ? HIGH : LOW);
  digitalWrite(buzzerPin, fireDetected ? HIGH : LOW);

  delay(500);
}