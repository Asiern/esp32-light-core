#ifndef _WEBSOCKET_H
#define _WEBSOCKET_H

#include "led.h"
#include <WebSocketsServer.h>

#define PORT 3951

extern WebSocketsServer ws;

// WebSocketsServer *initWS();
void wsEvent(uint8_t num, WStype_t type, uint8_t *payload, size_t length);
void handleText(uint8_t num, uint8_t *payload, size_t length);
RGB getColorFromMsg(char *msg, size_t length);

#endif