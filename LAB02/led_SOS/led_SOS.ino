// 定义LED引脚，ESP32通常板载LED连接在GPIO 2
const int ledPin = 2; 
const int ledPin_R=25;
const int ledPin_G=33;
const int ledPin_Y=32;

void setup(){
  Serial.begin(115200);
  pinMode(ledPin,OUTPUT);
  pinMode(ledPin_R,OUTPUT);
  pinMode(ledPin_G,OUTPUT);
  pinMode(ledPin_Y,OUTPUT);
}

void loop(){
  // S: 短闪3次
  for(int i=0; i<3; i++) { digitalWrite(ledPin, HIGH); delay(200); digitalWrite(ledPin, LOW); delay(200); }
  delay(500); // 字母间隔
// O: 长闪3次
  for(int i=0; i<3; i++) { digitalWrite(ledPin, HIGH); delay(600); digitalWrite(ledPin, LOW); delay(200); }
  delay(500);
// S: 短闪3次
  for(int i=0; i<3; i++) { digitalWrite(ledPin, HIGH); delay(200); digitalWrite(ledPin, LOW); delay(200); }
  delay(2000); // 单词间隔
   for(int i=0; i<3; i++) { digitalWrite(ledPin_R, HIGH); delay(200); digitalWrite(ledPin_R, LOW); delay(200); }
  delay(500); // 字母间隔
// O: 长闪3次
  for(int i=0; i<3; i++) { digitalWrite(ledPin_R, HIGH); delay(600); digitalWrite(ledPin_R, LOW); delay(200); }
  delay(500);
// S: 短闪3次
  for(int i=0; i<3; i++) { digitalWrite(ledPin_R, HIGH); delay(200); digitalWrite(ledPin_R, LOW); delay(200); }
  delay(2000); // 单词间隔
  for(int i=0;i<3;i++){digitalWrite(ledPin_G,HIGH);delay(200);digitalWrite(ledPin_G,LOW);delay(200);}
  delay(500);
  for(int i=0;i<3;i++){digitalWrite(ledPin_G,HIGH);delay(500);digitalWrite(ledPin_G,LOW);delay(500);}
  delay(500);
  for(int i=0;i<3;i++){digitalWrite(ledPin_G,HIGH);delay(200);digitalWrite(ledPin_G,LOW);delay(200);}
  delay(2000);
   for(int i=0;i<3;i++){digitalWrite(ledPin_Y,HIGH);delay(200);digitalWrite(ledPin_Y,LOW);delay(200);}
  delay(500);
  for(int i=0;i<3;i++){digitalWrite(ledPin_Y,HIGH);delay(500);digitalWrite(ledPin_Y,LOW);delay(500);}
  delay(500);
  for(int i=0;i<3;i++){digitalWrite(ledPin_Y,HIGH);delay(200);digitalWrite(ledPin_Y,LOW);delay(200);}
  delay(2000);


}
