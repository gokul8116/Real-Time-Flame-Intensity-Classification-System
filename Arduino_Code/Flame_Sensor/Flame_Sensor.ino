// === Flame Sensor Arduino Code for Microampere Output ===
const int analogPin = A0;             // Flame sensor analog output pin
const float resistor = 10000.0;       // Resistor value in Ohms (10kΩ)
const float supplyVoltage = 5.0;      // Arduino supply voltage

float voltage = 0.0;
float currentMicroA = 0.0;
bool headerPrinted = false;

void setup() {
  Serial.begin(9600);  // Start serial communication at 9600 baud
}

void loop() {
  int sensorValue = analogRead(analogPin);  // Read analog pin (0–1023)
  
  // Convert analog reading to voltage
  voltage = sensorValue * (supplyVoltage / 1023.0);
  
  // Use Ohm's Law: I = V / R, convert to microamperes (µA)
  currentMicroA = (voltage / resistor) * 1e6;

  // Optional: classify flame level (not needed for ML model, but useful for logs)
  String flameLevel;
  if (currentMicroA <= 15.0) {
    flameLevel = "High Flame";
  } else if (currentMicroA <= 30.0) {
    flameLevel = "Mid Flame";
  } else if (currentMicroA <= 50.0) {
    flameLevel = "Low Flame";
  } else {
    flameLevel = "No Flame";
  }

  // Print header once
  if (!headerPrinted) {
    Serial.println("Flame Current (uA),Flame Level");
    headerPrinted = true;
  }

  // Print CSV line for Raspberry Pi
  Serial.print(currentMicroA, 2);  // Microampere value with 2 decimal places
  Serial.print(",");
  Serial.println(flameLevel);

  delay(400);  // Wait 400 ms before next reading
}
