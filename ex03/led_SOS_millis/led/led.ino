const int ledPin = 2;

const unsigned long shortOn = 200;   
const unsigned long longOn = 600;    
const unsigned long gap = 200;       
const unsigned long endPause = 2000; 

unsigned long lastTime = 0;
int step = 0; 

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  unsigned long currentTime = millis();
  if (currentTime - lastTime >= getStepTime(step)) {
    lastTime = currentTime;
    digitalWrite(ledPin, (step % 2 == 0) ? HIGH : LOW);
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

