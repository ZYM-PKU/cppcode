int lightPin=A0;
int soundPIn=8;
int lightForce = 0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  lightForce=600-analogRead(lightPin);
  Serial.println(lightForce);
  tone(soundPIn,1000-lightForce*1.5,lightForce);
  delay(lightForce*3);

}