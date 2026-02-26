const int trigPin = 5;
const int echoPin = 4;
const int buzzer = 12;

void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long duration, cm;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  cm = microsecondsToCentimetres(duration);
  Serial.println(cm);

  if (cm < 70) {
    int buzzsound = map(cm, 0, 70, 100, 1000);
    tone(buzzer, buzzsound);
  } else {
    noTone(buzzer);             //test
  }
}
long microsecondsToCentimetres(long microseconds) {

  return microseconds / 29 / 2;
}
