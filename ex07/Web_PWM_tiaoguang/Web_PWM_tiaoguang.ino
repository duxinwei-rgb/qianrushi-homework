#include <WiFi.h>
#include <WebServer.h>

// ====================== 请修改你的WiFi信息 ======================
const char* ssid = "dxw9253";
const char* password = "dxw250628";
// ================================================================

WebServer server(80);

const int LED_PIN = 2;  // 板载LED

// 网页（滑动条 + 实时发送数据）
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML>
<html>
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>LED控制</title>
</head>
<body style="text-align:center; font-size:22px;">
    <h2>LED亮度调节</h2>
    <p>当前值：<span id="val">128</span></p>
    <input type="range" min="0" max="255" value="128" id="slider" style="width:300px;">

<script>
let s = document.getElementById("slider");
let v = document.getElementById("val");

s.addEventListener("input", function(){
    let value = s.value;
    v.innerText = value;
    fetch("/set?brightness="+value);
});
</script>
</body>
</html>
)rawliteral";

// 首页
void handleRoot() {
  server.send(200, "text/html", index_html);
}

// 设置亮度（最简单方式）
void handleSet() {
  if (server.hasArg("brightness")) {
    int val = server.arg("brightness").toInt();
    
    // ====================== 关键：只用 analogWrite ======================
    analogWrite(LED_PIN, val);
    
    server.send(200, "text/plain", String(val));
  } else {
    server.send(400);
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);     // 输出模式
  analogWrite(LED_PIN, 128);    // 初始亮度

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi OK！");
  Serial.println("IP地址: " + WiFi.localIP().toString());

  server.on("/", handleRoot);
  server.on("/set", handleSet);  // 亮度接口
  server.begin();
}

void loop() {
  server.handleClient();
}