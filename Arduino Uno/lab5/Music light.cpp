int lightPin = 5;
int soundPin = A0;

int soundForce = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(lightPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  soundForce=analogRead(soundPin);//读取声压（整型，0-1023）
  Serial.println(soundForce);
  analogWrite(lightPin,soundPin/1023*255);
  delay(50);
}