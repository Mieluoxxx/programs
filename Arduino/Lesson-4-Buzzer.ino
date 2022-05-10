int BuzzerPin = 5;
int Potentiometer = A0;

void setup() {
  pinMode(BuzzerPin, OUTPUT); 
  Serial.begin(9600);  
}

void loop() {
  int potentioValue, Value;
  potentioValue = analogRead(Potentiometer);
  Serial.println(potentioValue); 
  Value = map(potentioValue, 0, 1023, 0, 255); //Mapping potentiometer value to PWM signal value
  Serial.println(Value);
  analogWrite(BuzzerPin, Value);
}
