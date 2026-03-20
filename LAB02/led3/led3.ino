// 定义LED引脚，ESP32通常板载LED连接在GPIO 2
const int ledPin = 2; 
const int ledPin_R = 25; 
const int ledPin_G = 33; 
const int ledPin_Y = 32; 


void setup() {
  // 初始化串口通信，设置波特率为115200
  Serial.begin(115200);
  // 将LED引脚设置为输出模式
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin_R, OUTPUT);
  pinMode(ledPin_G, OUTPUT);
  pinMode(ledPin_Y, OUTPUT);

  
}

void loop() {
   // 点亮LED
  digitalWrite(ledPin, HIGH);
  digitalWrite(ledPin_R, HIGH);
  digitalWrite(ledPin_G, HIGH);
  digitalWrite(ledPin_Y, HIGH);
  Serial.println("LED ON");    // 串口输出提示
  delay(1000);                 // 保持1秒（1000毫秒）
  
     // 熄灭LED
  digitalWrite(ledPin,LOW);
  digitalWrite(ledPin_R, LOW);
  digitalWrite(ledPin_G, LOW);
  digitalWrite(ledPin_Y, LOW);
  Serial.println("LED OFF");   // 串口输出提示
  delay(1000);                 // 保持1秒

  

}
