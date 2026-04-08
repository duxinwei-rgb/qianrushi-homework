#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "aeiou";
const char* password = "dxw250628";

WebServer server(80);

void handleRoot() {
  String html = R"rawliteral(
<!DOCTYPE html>
<html lang="zh-CN">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>实验1</title>
</head>
<body style="font-family:Arial; text-align:center; margin-top:50px;">
  <h1>ESP32 Web服务器实验</h1>
  <h2>第一部分：静态页面显示</h2>
  <p>如果你能看到这个页面，说明实验成功。</p>
</body>
</html>
)rawliteral";
  server.send(200, "text/html; charset=UTF-8", html);
}

void setup() {
  Serial.begin(115200);
  delay(1000); // 给系统上电稳定时间

  // 🔧 终极WiFi重置：彻底清除旧配置，避免残留冲突
  WiFi.disconnect(true, true);
  delay(500);
  WiFi.mode(WIFI_OFF);
  delay(500);
  
  // 强制设置为纯STA客户端模式
  WiFi.mode(WIFI_STA);
  delay(100);

  // 发起连接
  WiFi.begin(ssid, password);
  Serial.print("正在连接WiFi");

  // 增加超时，避免无限循环
  int retry = 0;
  const int maxRetry = 40;
  while (WiFi.status() != WL_CONNECTED && retry < maxRetry) {
    delay(500);
    Serial.print(".");
    retry++;
  }

  // 连接结果判断
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\n✅ WiFi连接成功！");
    Serial.print("访问地址: http://");
    Serial.println(WiFi.localIP());

    // 启动Web服务器
    server.on("/", handleRoot);
    server.begin();
    Serial.println("✅ Web服务器已启动");
  } else {
    Serial.println("\n❌ WiFi连接失败！");
    Serial.print("状态码: ");
    Serial.println(WiFi.status());
    Serial.println("请检查：1.热点已开启 2.密码正确 3.手机未休眠");
    return;
  }
}

void loop() {
  server.handleClient();
}