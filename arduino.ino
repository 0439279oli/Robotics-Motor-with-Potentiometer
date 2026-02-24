const int In1 = 9;
const int In2 = 8;
const int ena = 10;
const int pot = A0;
void setup()
{
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(pot, INPUT);
  Serial.begin(9600);
}
void loop()
{
int input = analogRead(pot);
input = map(input, 0, 1023, 0, 255); 
Serial.println(input);

  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  analogWrite(ena, input);
  if(input<15){
    digitalWrite(In1, LOW);
    digitalWrite(In2, LOW);
  }
}
