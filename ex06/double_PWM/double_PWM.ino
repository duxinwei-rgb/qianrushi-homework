const int ledPin_R = 26;  
const int ledPin_G = 25; 
const int ledPin = 2; 


const int freq = 5000;       
const int resolution = 8;

void setup() {
  Serial.begin(115200);
  ledcAttach(ledPin, freq, resolution);
  ledcAttach(ledPin_R, freq, resolution);
  ledcAttach(ledPin_G, freq, resolution);

}
void loop() {
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    ledcWrite(ledPin, dutyCycle);  
    ledcWrite(ledPin_R, dutyCycle);  
    ledcWrite(ledPin_G, 255-dutyCycle); 
    delay(10);
  }
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    ledcWrite(ledPin, dutyCycle);  
    ledcWrite(ledPin_R, dutyCycle);   
    ledcWrite(ledPin_G, 255-dutyCycle);
    delay(10);
  }
   Serial.println("Breathing cycle completed");
}