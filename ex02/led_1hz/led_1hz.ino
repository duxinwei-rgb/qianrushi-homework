const int ledPin=2;
unsigned long previousMillis=0;
const long interval=1000;

int ledState=LOW;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin,OUTPUT);
}

void loop() {
  unsigned long currentMillis=millis();
  if(currentMillis-previousMillis>=1000){
    previousMillis=currentMillis;
    ledState=!ledState;
    digitalWrite(ledPin,ledState);
  }

}
