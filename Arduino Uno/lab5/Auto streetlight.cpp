int ledPin=4;
int lightPin=A0;

int threshold =250;
int lightForce = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  lightForce=1023-analogRead(lightPin);
  Serial.println(lightForce);
  if(lightForce <= threshold){
      digitalWrite(ledPin, HIGH);
  }
  else{
      digitalWrite(ledPin, LOW);
  }
  delay(50);
}