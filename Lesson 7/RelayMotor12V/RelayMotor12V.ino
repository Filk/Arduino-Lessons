int controlRelay = 2;

// the setup routine runs once when you press reset:
void setup() {
  // make the pushbutton's pin an input:
  pinMode(controlRelay, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(controlRelay, HIGH);
  delay(2500);        // delay
  digitalWrite(controlRelay, LOW);
  delay(5000);        // delay
}



