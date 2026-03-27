#define TOUCH_PIN 4
#define LED_PIN 2
#define THRESHOLD 500 // 需要根据实际测试修改此阈值

bool ledState = false;
int count=0;



// 中断服务函数 (ISR)
void gotTouch() {
  delay(100);
  count++;
  if(count%2==1){
  ledState = !ledState;
  digitalWrite(LED_PIN, ledState);
  Serial.print("中断\n");}
  
  
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  pinMode(LED_PIN, OUTPUT);

  
  // 绑定中断函数
  touchAttachInterrupt(TOUCH_PIN, gotTouch, THRESHOLD);
}

void loop() {
  delay(100);
}