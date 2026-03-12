#define LED_PIN 2
//初始化硬件设备串行通信
void setup() {
  Serial.begin(115200);            //波特率 bps 每秒传输多少个比特
  pinMode(LED_PIN, OUTPUT);        
}
//循环执行
void loop() {
  Serial.println("Hello ESP32!");
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  delay(1000);
}

