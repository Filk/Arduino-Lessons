/* Ultrasound Sensor

   The circuit:
	* +V connection attached to +5V
	* GND connection attached to ground
  * TRIG connection attached to digital pin 6
	* ECHO connection attached to digital pin 7

   created 3 Nov 2008
   by David A. Mellis
   modified 30 Aug 2011
   by Tom Igoe
   modified 31 Oct 2017
   by Filipe Lopes

   This example code is in the public domain.

 */

// this constant won't change.  It's the pin number
// of the sensor's output:
const int pingPin = 6;
const int receive = 7;
const int motorPin = 8;

void setup() {

  // The Ultrasound sensor is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin, OUTPUT);
  
  // This pin is used to read the signal from the Ultrasound sensor. A HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(receive, INPUT);

  // pin to control motor.
  pinMode(motorPin, OUTPUT);

  // initialize serial communication:
  Serial.begin(9600);
}

void loop() {
  // establish variables for duration of the ping,
  // and the distance result in centimeters:
  long duration, cm;
  
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  //pulseIn calculates time between HIGH and LOW states
  duration = pulseIn(receive, HIGH);

  // convert the time into a distance
  cm = microsecondsToCentimeters(duration);

  //if distance to sensor is below 100 then motor on else motor off
  if (cm<100)
  {
    digitalWrite(motorPin, HIGH);
  }
  else
  {
    digitalWrite(motorPin, LOW);
  }

  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(100);
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return (microseconds/29)*0.5;
}
