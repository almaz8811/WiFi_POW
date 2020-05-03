#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266SSDP.h>
#include <FS.h>
#include <ArduinoJson.h>    // Установить из менеджера библиотек. Версия 5.13.0
#include <ESP8266HTTPUpdateServer.h>
#include <DNSServer.h>
#include <TickerScheduler.h>    // https://github.com/Toshik/TickerScheduler
// Библиотеки устройств
#include <DHT.h>          // https://github.com/markruys/arduino-DHT
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <Adafruit_STMPE610.h>
#include "Fonts/FreeMono7pt8b.h"
#include "Fonts/FreeMono9pt8b.h"
//#include "Fonts/FreeMonoBold7pt8b.h"
#include "Fonts/FreeMonoBold12pt8b.h"

// Объект для обнавления с web страницы
ESP8266HTTPUpdateServer httpUpdater;
// Web интерфейс для устройства
ESP8266WebServer HTTP(80);
// Для файловой системы
File fsUploadFile;
// Для работы символьных имен в режиме AP
DNSServer dnsServer;
//Планировщик задач (Число задач)
TickerScheduler ts(3);

// Датчик DHT
DHT dht;
#define dhtPin 2

// Дисплей
#define PIN_DC 4
#define PIN_RESET 5
#define PIN_CS 15

#define M_PAGE_SIZE 150

Adafruit_ILI9341 display = Adafruit_ILI9341(PIN_CS, PIN_DC, PIN_RESET);

String configSetup = "{}"; // данные для config.setup.json
String configJson = "{}";  // данные для config.live.json

char s[100];
float u1=0.0,i1=0.0,p1=0.0,e1=0.0;
float p_max = 0, p_min = 99999999;
float u_avg=0.0,i_avg=0.0,p_avg=0.0;
int u_count=0,i_count=0,p_count=0;
long t_correct = 0;
uint32_t tm = 0;
int m_page0[M_PAGE_SIZE];
int m_page_count0 = 0;