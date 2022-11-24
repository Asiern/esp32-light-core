#include "wireless.h"

#ifdef _STATIC_IP
IPAddress ip(192, 168, 1, 3);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);
#endif

void initWiFi()
{
    WiFi.mode(WIFI_STA);
    WiFi.begin(SSID, PASSWD);

#ifdef _STATIC_IP
    WiFi.config(ip, gateway, subnet);
#endif

    Serial.println("Connecting to WiFi");

    while (WiFi.status() != WL_CONNECTED)
        delay(1000);

    // #endif
    Serial.println(WiFi.localIP());
}
