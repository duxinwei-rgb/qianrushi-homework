const int ledPin = 2;
const int ledPin_R = 25;
const int ledPin_G = 33;
const int ledPin_Y = 32;

const unsigned long shortOn = 200;   
const unsigned long longOn = 600;    
const unsigned long gap = 200;       
const unsigned long endPause = 2000; 

unsigned long lastTime = 0;
int step = 0; 

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin_R, OUTPUT);
  pinMode(ledPin_G, OUTPUT);
  pinMode(ledPin_Y, OUTPUT);
}

void loop() {
  unsigned long currentTime = millis();
  if (currentTime - lastTime >= getStepTime(step)) {
    lastTime = currentTime;
    digitalWrite(ledPin, (step % 2 == 0) ? HIGH : LOW);
    digitalWrite(ledPin_R, (step % 2 == 0) ? HIGH : LOW);
    digitalWrite(ledPin_G, (step % 2 == 0) ? HIGH : LOW);
    digitalWrite(ledPin_Y, (step % 2 == 0) ? HIGH : LOW);

    step++;
    if (step > 12) step = 0;
  }
}


unsigned long getStepTime(int s) {
  if (s < 6) { 
    return (s % 2 == 0) ? shortOn : gap;
  } 
  else if (s < 12) {  
    return (s % 2 == 0) ? longOn : gap;
  } 
  else {
    return endPause;
  }
}

