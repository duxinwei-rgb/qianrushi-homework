// 定义LED引脚
const int ledPin = 2;    // 板载LED
const int ledPin_R = 25; // 红色LED
const int ledPin_G = 33; // 绿色LED
const int ledPin_Y = 32; // 黄色LED

// PWM配置
const int freq = 5000;
const int resolution = 8;
const int breathSpeed = 15; // 呼吸速度（数值越小越快）

void setup() {
  Serial.begin(115200);
  // 绑定所有引脚到PWM
  ledcAttach(ledPin, freq, resolution);
  ledcAttach(ledPin_R, freq, resolution);
  ledcAttach(ledPin_G, freq, resolution);
  ledcAttach(ledPin_Y, freq, resolution);
  // 初始全部熄灭
  ledcWrite(ledPin, 0);
  ledcWrite(ledPin_R, 0);
  ledcWrite(ledPin_G, 0);
  ledcWrite(ledPin_Y, 0);
}

// 单个LED的非线性呼吸函数
void breathOneLed(int pin) {
  // 正弦呼吸：从灭→亮→灭
  for (float angle = 0; angle < 2 * PI; angle += 0.05) {
    // 映射到[5, 255]，避免完全熄灭的跳变感
    int dutyCycle = 125 * sin(angle) + 130;
    ledcWrite(pin, dutyCycle);
    delay(breathSpeed);
  }
  // 呼吸结束后彻底熄灭
  ledcWrite(pin, 0);
  delay(100); // 灯与灯之间的间隔（可选）
}

void loop() {
  // 依次呼吸：板载LED → 红色 → 绿色 → 黄色
  breathOneLed(ledPin);
  breathOneLed(ledPin_R);
  breathOneLed(ledPin_G);
  breathOneLed(ledPin_Y);
}
