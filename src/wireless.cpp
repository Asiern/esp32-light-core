#include "wireless.h"

void initWiFi()
{
    WiFi.mode(WIFI_STA);
    WiFi.begin(SSID, PASSWD);
    Serial.println("Connecting to WiFi");

    while (WiFi.status() != WL_CONNECTED)
        delay(1000);

#ifdef IP_STATIC
        // IPAddress ip(IP);
        // IPAddress gateway(GATEWAY);
        // IPAddress subnet(SUBNET);
        // WiFi.config(ip,GATEWAY,SUBNET),
#endif
    Serial.println(WiFi.localIP());
}
