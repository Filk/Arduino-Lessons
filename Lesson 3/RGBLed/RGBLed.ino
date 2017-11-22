/*
Adafruit Arduino - Lesson 3. RGB LED
https://learn.adafruit.com/adafruit-arduino-lesson-3-rgb-leds/overview
*/

int redPin = 11;
int greenPin = 10;
int bluePin = 9;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
}

void loop()
{
  setColor(255, 255, 255);  // red
  delay(100);
  setColor(90, 255, 0);  // green
  delay(100);
  setColor(100, 0, 255);  // blue
  delay(100);
  setColor(13, 13, 0);  // yellow
  delay(100);  
  setColor(80, 90, 8);  // purple
  delay(100);
  setColor(0, 32, 200);  // aqua
  delay(100);
}

void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
