#include <WiFi.h>
#include <Husarnet.h>

WiFiServer server(80);

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);

  WiFi.begin("[ssid]", "[password]");

  while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
  }
  Serial.println("connected to wifi!");

  // setup the Husarnet
  WebSetup::start();
  delay(2000);

  server.begin();
  if (!server) {
    Serial.println("server failed");
  }
}

void loop() {
  WiFiClient client = server.available();
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
