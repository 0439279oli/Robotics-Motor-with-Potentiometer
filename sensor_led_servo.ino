#include <Servo.h>
Servo myservo; 
const int echo = 12;
const int trig = 11;
const int ledgreen = 3;
const int ledred = 5; 

void setup() {
  
  myservo.attach(6);
  pinMode(echo, INPUT); 
  pinMode(trig, OUTPUT);
  pinMode(ledgreen, OUTPUT);
  pinMode(ledred, OUTPUT); 
  Serial.begin(9600);
}

void loop() {
  long duration, cm;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH); 
  delayMicroseconds(5);
  digitalWrite(trig, LOW);
  
  duration = pulseIn(echo, HIGH); 
  
  cm = microsecondsToCentimetres(duration); 
  
  if(cm < 70) {
    myservo.write(90);
    digitalWrite(ledgreen, HIGH);
    digitalWrite(ledred, LOW);
    delay(3000);
  } else {
    myservo.write(0);
    digitalWrite(ledgreen, LOW);
    digitalWrite(ledred, HIGH);
  }
}
long microsecondsToCentimetres(long mircoseconds) {
  
  return mircoseconds / 29 / 2;
}
 
