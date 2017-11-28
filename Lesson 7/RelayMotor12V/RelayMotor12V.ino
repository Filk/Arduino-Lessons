int controlRelay = 2;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(controlRelay, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(controlRelay, HIGH);
  delay(2500);        // delay
  digitalWrite(pushButton, LOW);
  delay(5000);        // delay
}



