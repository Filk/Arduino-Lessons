const int motorPin = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  // pin to control motor.
  pinMode(motorPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int x=analogRead(0);
  x= map(x,0,1023,0,255);
  //leitura do pin analógico 0 (entre 0 e 1023 = 10 bits)
  Serial.println(x);
  //leitura do mesmo pin mas mapeada para valores entre 0 e 255
  Serial.println(map(x,0,1023,0,255));

  if(x>50)
  {
    analogWrite(motorPin,x);
  }
  else
  {
    analogWrite(motorPin,0);
  }
  
  delay(100);
}
