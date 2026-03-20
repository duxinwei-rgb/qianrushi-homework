const int ledPin=2;
const int ledPin_R=25;

unsigned long previousMillis=0;
const long interval=1000;

int ledState=LOW;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin,OUTPUT);
  pinMode(ledPin_R,OUTPUT);

}

void loop() {
  unsigned long currentMillis=millis();
  if(currentMillis-previousMillis>=1000){
    previousMillis=currentMillis;
    ledState=!ledState;
    digitalWrite(ledPin,ledState);
    digitalWrite(ledPin_R,ledState);

  }

}
