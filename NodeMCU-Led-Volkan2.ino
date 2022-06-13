void setup() {
  pinMode(2, OUTPUT);     // Initialize GPIO2 pin as an output
}

void loop() {
  digitalWrite(2, LOW);   // Turn the LED on by making the voltage LOW
  delay(5000);            // Wait for a second
  digitalWrite(2, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(2000);            // Wait for two seconds
}
