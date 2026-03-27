// 全局变量定义
#define TOUCH_PIN 4
#define EXT_ISR_MODE 0
#define LED_PIN 
const int ledPin = 2;           // 使用板载 LED
int ledState = LOW;             // 记录 LED 状态
unsigned long previousMillis = 0;
const long interval = 500;      // 500ms 翻转一次
int threshold = 500; 
// 触摸值
int touchValue;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);      // 初始化引脚
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis(); // 获取当前时间

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;       // 更新基准时间
    
    // 翻转 LED 状态逻辑
    ledState = (ledState == LOW) ? HIGH : LOW;
    digitalWrite(ledPin, ledState);
  }
  
  // 这里可以放置其他任务，不会受到闪烁的影响
  touchValue = touchRead(TOUCH_PIN);
  Serial.print("Touch Value: ");
  Serial.println(touchValue);

  // 简单的阈值判断逻辑
  if (touchValue < threshold) {
    digitalWrite(LED_PIN, HIGH); // 触摸时，值变小，LED亮
  } else {
    digitalWrite(LED_PIN, LOW);  // 未触摸，LED灭
  }
  
  delay(100);
}