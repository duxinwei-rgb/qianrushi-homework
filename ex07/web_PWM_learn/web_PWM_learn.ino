#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "dxw9253";
const char* password = "dxw250628";

WebServer server(80);

const int ledPin = 2;
const int freq = 5000;
const int resolution = 8;

const char HTML[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML>
<html>
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>LED 亮度控制</title>
  <style>
    body{text-align:center; margin-top:50px; font-size:22px;}
    #slider{width:320px; height:25px;}
    #num{font-size:30px; color:red;}
  </style>
</head>
<body>
  <h2>ESP32 LED 亮度调节</h2>
  <input type="range" min="0" max="255" value="0" id="slider"><br>
  <p>亮度值：<span id="num">0</span></p>

<script>
  let slider = document.getElementById("slider");
  let num = document.getElementById("num");

  slider.addEventListener("input", function(){
    let val = this.value;
    num.innerText = val;
    fetch("/set?value=" + val);
  });
</script>
</body>
</html>
)rawliteral";


void handleRoot() {
  server.send(200, "text/html", HTML);
}

void setBrightness() {
  if (server.hasArg("value")) {
    int val = server.arg("value").toInt();
    ledcWrite(ledPin, val); 
    server.send(200, "text/plain", String(val));
  } else {
    server.send(400);
  }
}


void setup() {
  Serial.begin(115200);

  ledcAttach(ledPin, freq, resolution);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  Serial.println("WiFi OK");
  Serial.println("IP: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/set", setBrightness);
  server.begin();
}

void loop() {
  server.handleClient();
}