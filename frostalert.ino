#include <ESP8266HTTPClient.h>

#include <EEPROM.h>

#include "WiFiManager.h"

#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>


#include <DNSServer.h>
#include <ESP8266WebServer.h> 

#include <OneWire.h>
#include <DallasTemperature.h>

#define WIRE_PIN D3
#define BTN_PIN D2
#define LED_PIN D1
#define LIGHT_PIN A0
#define DEVICE "FA0001"

bool setup_mode = 0;
unsigned long send_time = 0;
const long send_interval = 900000;
String request;

OneWire oneWire(WIRE_PIN);
DallasTemperature sensors(&oneWire);
DeviceAddress ds18;
HTTPClient http;

