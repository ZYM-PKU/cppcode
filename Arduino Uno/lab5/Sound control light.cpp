int lightPin=4;
int soundPIn=8;

void setup() {
  // put your setup code here, to run once:
  pinMode(soundPin, INPUT);
  pinMode(lightPin, OUTPUT);
  digitalWrite(lightPin, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  int value=digitalRead(soundPIn);
  if(value==HIGH){
      digitalWrite(lightPin, HIGH);
  }

}