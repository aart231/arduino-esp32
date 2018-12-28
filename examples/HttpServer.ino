#include <WiFi.h>
#include <Husarnet.h>
HusarnetServer server(80);

void setup() {
  Serial.begin(115200);

  // you need to change this to you wifi login data
  WiFi.begin("[ssid]", "[pass]");

  while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
  }
  Serial.println("connected to wifi!");

  Husarnet.start();

  server.begin();
  if (!server) {
    Serial.println("server failed");
  }
}

void loop() {
  auto client = server.available();
  if (client) {
    Serial.println("new client");

    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("Connection: close");
    client.println();
    client.println("<!DOCTYPE HTML>");
    client.println("<html>hello");
    delay(100);
    client.stop();
  }
}
