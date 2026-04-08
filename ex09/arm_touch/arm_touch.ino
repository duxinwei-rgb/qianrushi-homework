#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "dxw9253";
const char* password = "dxw250628";

WebServer server(80);

#define TOUCH_PIN 4    
#define LED_PIN   2    
#define THRESHOLD 500   


bool isArmed    = false;  
bool isAlarming = false; 

void gotTouch() {
  if (isArmed) {
    isAlarming = true;
  }
}

const char HTML[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML>
<html>
<head>
    <meta charset="UTF-8">
    <title>触摸实时监控</title>
    <style>
        body{text-align:center; font-size:24px; font-family:Arial;}
        .value{
            font-size:60px;
            color:blue;
            margin:50px 0;
        }
        button{
            padding:15px 30px;
            font-size:22px;
            margin:10px;
            border:none;
            border-radius:10px;
            cursor:pointer;
        }
        .arm{background:red; color:white;}
        .disarm{background:green; color:white;}
    </style>
</head>
<body>
    <h2>ESP32 触摸传感器实时值</h2>
    <div class="value" id="touchValue">--</div>

    <button class="arm" onclick="fetch('/arm')">布防 (Arm)</button>
    <button class="disarm" onclick="fetch('/disarm')">撤防 (Disarm)</button>

<script>
// ==================== AJAX 实时获取数值 ====================
function updateValue() {
    fetch("/getTouchValue")
    .then(res => res.text())
    .then(data => {
        document.getElementById("touchValue").innerText = data;
    });
}

// 每 100ms 刷新一次（实时显示）
setInterval(updateValue, 100);
updateValue();
</script>

</body>
</html>
)rawliteral";

//服务器路由
void handleRoot() {
  server.send(200, "text/html", HTML);
}

// 返回触摸模拟值（上报功能）
void getTouchValue() {
  int val = touchRead(TOUCH_PIN);
  server.send(200, "text/plain", String(val));
}

// 布防
void handleArm() {
  isArmed = true;
  isAlarming = false;
  digitalWrite(LED_PIN, LOW);
  server.send(200, "text/plain", "ARMED");
}

// 撤防
void handleDisarm() {
  isArmed = false;
  isAlarming = false;
  digitalWrite(LED_PIN, LOW);
  server.send(200, "text/plain", "DISARMED");
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  touchAttachInterrupt(TOUCH_PIN, gotTouch, THRESHOLD);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi OK");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  // 路由
  server.on("/", handleRoot);
  server.on("/getTouchValue", getTouchValue);  // 数值上报
  server.on("/arm", handleArm);
  server.on("/disarm", handleDisarm);

  server.begin();
}

void loop() {
  server.handleClient();

  // 报警闪烁（锁定）
  if (isAlarming) {
    digitalWrite(LED_PIN, HIGH);
    delay(100);
    digitalWrite(LED_PIN, LOW);
    delay(100);
  }

  delay(10);
}