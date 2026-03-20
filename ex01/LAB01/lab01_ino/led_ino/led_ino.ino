#define LED_PIN 2
#define LED_PIN_R 25
#define LED_PIN_G 33
#define LED_PIN_Y 32
//初始化硬件设备串行通信
void setup() {
  Serial.begin(115200);            //波特率 bps 每秒传输多少个比特
  pinMode(LED_PIN, OUTPUT);   
  pinMode(LED_PIN_R, OUTPUT);  
  pinMode(LED_PIN_G, OUTPUT); 
  pinMode(LED_PIN_Y, OUTPUT);     
}
//循环执行
void loop() {
  Serial.println("Hello ESP32!");
  digitalWrite(LED_PIN, HIGH);
  digitalWrite(LED_PIN_R, HIGH);
  digitalWrite(LED_PIN_G, HIGH);
  digitalWrite(LED_PIN_Y, HIGH);

  delay(1000);
  digitalWrite(LED_PIN, LOW);
  digitalWrite(LED_PIN_R, LOW);
  digitalWrite(LED_PIN_G, LOW);
  digitalWrite(LED_PIN_Y, LOW);
  delay(1000);
}

