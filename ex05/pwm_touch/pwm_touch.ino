#define TOUCH_PIN 4
#define LED_PIN 2
#define THRESHOLD 500
const int freq = 5000;          // 频率 5000Hz
const int resolution = 8;       // 分辨率 8位 (0-255)

volatile bool ledState=false;
volatile int step=0;
volatile int count=0;
volatile int sum=0;


// 中断服务函数 (ISR)
void gotTouch() {
  count++;
  if(count%2==1)
  {
      sum++;
      if(sum==1||sum==2||sum==3){
      ledState=true;
      step=sum*2;}
      if(sum==4) {sum=0;ledState=false;}
  }
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  pinMode(LED_PIN, OUTPUT);
  ledcAttach(LED_PIN, freq, resolution);
  ledcWrite(LED_PIN,0);
  touchAttachInterrupt(TOUCH_PIN, gotTouch, THRESHOLD);
}

void loop() {
  delay(100);
  int dutyCycle=0;
  if(ledState==true){
    delay(100);
    for(dutyCycle = 0; dutyCycle <= 255; dutyCycle=dutyCycle+step){   
        ledcWrite(LED_PIN, dutyCycle);   
        delay(10);
    } 
    for(dutyCycle = 255; dutyCycle >=0; dutyCycle=dutyCycle-step){   
        ledcWrite(LED_PIN, dutyCycle);   
        delay(10);
    } 
  }
  else{ledcWrite(LED_PIN,0);}
}