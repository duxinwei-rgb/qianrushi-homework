const int ledPin=2;
const int ledPin_R=25;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin,OUTPUT);
  pinMode(ledPin_R,OUTPUT);
}

void loop() {
  digitalWrite(ledPin,HIGH);
  digitalWrite(ledPin_R,LOW);
  delay(1000);

  digitalWrite(ledPin,LOW);
  digitalWrite(ledPin_R,HIGH);
  delay(1000);

}
