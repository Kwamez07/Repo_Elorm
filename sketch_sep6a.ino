[style-adruino, caption-ESP32 Back EMF Measurement Code]
//ESP32 Back EMF Measurement Tool
//Pins
const int emfPin = 35;     //Analog pin connected to voltage divider

// Configuration
const int sampleDelay = 1; //Delay between sample (ms) for speed
const int threshold = 2500; // ADC threshold to detect spike (12-bit scale: 0-4095)

//Variables 
int emfValue = 0;
float measuredVoltage = 0.0;

void setup() {
  Serial.begin(115200);
  pinMode(emfPin, INPUT);
  Serial.println("ESP32 Back EMF Measurement Tool Ready.");
  Serial.println("Waiting for spike...");
}

void loop() {
  // Read the voltage at the divider
  emfValue = analogRead(emfPin);

  // Check if the reading exceeds the threshold 
  if (emfValue > threshold) {
    //Convert ADC value to actual voltage at the ESP32 pin 
    measuredVoltage = (emfValue / 4095.0) * 3.3;

    //Print the result
    Serial.print("Back EMF Spike Detected! Value: ");
    Serial.print(emfValue);
    Serial.print(" | Pin Voltage: ");
    Serial.print(measuredVoltage);
    Serial.println(" V");

    //Simple delay to avoid printing too many times per spike
    delay(100);
  }
  // Small delay for stability between readings 
  delay(sampleDelay);

}
