#include <Arduino.h>
#include <WiFi.h>
#include <WebSocketsServer.h>

#include "websocket.h"
#include "wireless.h"
#include "gpio.h"
#include "led.h"

WebSocketsServer ws = WebSocketsServer(PORT);

void setup()
{
  Serial.begin(115200);

  // Init GPIO
  initGPIO();

  // Connect to WiFI
  initWiFi();

  // WebSocket
  ws.begin();
  ws.onEvent(wsEvent);

  Serial.println("Setup done");
}

void loop()
{
  ws.loop();
}