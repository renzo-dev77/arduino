
void setup() {
  pinMode(13, OUTPUT);
  pinMode(3, OUTPUT);
}


void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);   
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);

  analogWrite(3,0);
  delay(500);
  analogWrite(3,30);
  delay(500);
  analogWrite(3,60);
  delay(500);
  analogWrite(3,90);
  delay(500);
  
}
