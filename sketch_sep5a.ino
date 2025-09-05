//Capacitor Timer Reader on Esp32

const int capPin = 32; //Analog pin

void setup() {
 Serial.begin(115200);
}

void loop() {
  int capValue = analogRead(capPin);

  Serial.print("Capacitor Voltage Reading: ");
  Serial.println(capValue);

  delay(200);

}
