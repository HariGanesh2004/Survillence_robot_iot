#include <WiFi.h>
#include <WebServer.h>

// Wi-Fi credentials for ESP32 Access Point
const char* ssid = "ESP32_ROBOT";
const char* password = "12345678";

// Motor pins
const int motor1Pin1 = 5;
const int motor1Pin2 = 18;
const int motor2Pin1 = 19;
const int motor2Pin2 = 21;

WebServer server(80);

void setup() {
  Serial.begin(115200);

  // Set motor pins as output
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);

  // Start Wi-Fi in Access Point mode
  WiFi.softAP(ssid, password);
  Serial.println("Access Point started");
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());

  // Define routes
  server.on("/", handleRoot);
  server.on("/forward", handleForward);
  server.on("/backward", handleBackward);
  server.on("/left", handleLeft);
  server.on("/right", handleRight);
  server.on("/stop", handleStop);

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}

// Serve the control page
void handleRoot() {
  String page = "<html><head><title>ESP32 Robot</title></head><body>";
  page += "<h1>ESP32 Robot Control</h1>";
  page += "<a href='/forward'><button style='width:100px;height:50px;'>Forward</button></a><br><br>";
  page += "<a href='/left'><button style='width:100px;height:50px;'>Left</button></a>";
  page += "<a href='/stop'><button style='width:100px;height:50px;'>Stop</button></a>";
  page += "<a href='/right'><button style='width:100px;height:50px;'>Right</button></a><br><br>";
  page += "<a href='/backward'><button style='width:100px;height:50px;'>Backward</button></a>";
  page += "</body></html>";
  server.send(200, "text/html", page);
}

// Movement functions
void handleForward() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  server.send(200, "text/html", "Moving Forward");
}

void handleBackward() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  server.send(200, "text/html", "Moving Backward");
}

void handleLeft() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  server.send(200, "text/html", "Turning Left");
}

void handleRight() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  server.send(200, "text/html", "Turning Right");
}

void handleStop() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  server.send(200, "text/html", "Stopped");
}
