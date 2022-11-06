#ifndef _WIRELESS_H
#define _WIRELESS_H

#include <WiFi.h>

#define SSID ""
#define PASSWD ""

// Static IP
#define IP 192.168.1.3
#define GATEWAY 192.168.1.0
#define SUBNET 255.255.255.0

void initWiFi();

#endif