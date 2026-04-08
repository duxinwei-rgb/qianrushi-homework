#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "dxw9253";
const char* password = "dxw250628";

WebServer server(80);
#define TOUCH_PIN 4  


const char HTML[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML>
<html>
<head>
    <meta charset="UTF-8">
    <title>触摸实时监测</title>
    <style>
        body {
            text-align: center;
            margin-top: 100px;
            font-family: Arial;
        }
        #value {
            font-size: 80px;
            color: #2196F3;
            font-weight: bold;
        }
        p {
            font-size: 24px;
        }
    </style>
</head>
<body>
    <p>ESP32 触摸传感器实时值</p>
    <div id="value">--</div>

<script>
// 实时获取数值
function update() {
    fetch("/get").then(res => res.text()).then(data => {
        document.getElementById("value").innerText = data;
    });
}

// 每 100ms 刷新一次
setInterval(update, 100);
update();
</script>
</body>
</html>
)rawliteral";


void handleRoot() {
  server.send(200, "text/html", HTML);
}

void getTouch() {
  int value = touchRead(TOUCH_PIN);
  server.send(200, "text/plain", String(value));
}

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(500);

  Serial.println("WiFi 连接成功");
  Serial.println("IP: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/get", getTouch); 
  server.begin();
}

void loop() {
  server.handleClient();
}