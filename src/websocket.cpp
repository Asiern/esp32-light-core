#include "websocket.h"
#include <Preferences.h>

void wsEvent(uint8_t num, WStype_t type, uint8_t *payload, size_t length)
{
    switch (type)
    {
    case WStype_DISCONNECTED:
        Serial.println("Client disconnected from server");
        break;
    case WStype_CONNECTED:
        Serial.println("Client connected to server");
        break;
    case WStype_TEXT:
        handleText(num, payload, length);
        break;
    }
}

void handleText(uint8_t num, uint8_t *payload, size_t length)
{
    char ip[15];
    Serial.printf("Text: %s\n", payload);
    RGB color;

    switch (payload[0])
    {
    case 'C': // Change color
        Serial.println("Received color command");
        color = getColorFromMsg((char *)(payload + 1), length - 1);
        setColor(color);
        break;
    case 'P': // Ping
        Serial.println("Received ping command");
        WiFi.localIP().toString().toCharArray(ip, 15);
        ws.sendTXT(num, ip, 15);
        break;
    case 'R': // Restart
        ESP.restart();
        break;
    }
}

RGB getColorFromMsg(char *msg, size_t length)
{
    RGB resp;
    char c;
    BYTE color;

    for (int i = 0; i < length; i++)
    {
        switch ((c = msg[i]))
        {
        case 'R':
            color = 0;
            continue;
        case 'G':
            resp.R = color;
            color = 0;
            continue;
        case 'B':
            resp.G = color;
            color = 0;
            continue;
        }
        color = color * 10 + atoi(&c);
    }
    resp.B = color;
    return resp;
}