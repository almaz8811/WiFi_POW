#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266SSDP.h>
#include <FS.h>
#include <ArduinoJson.h> // Установить из менеджера библиотек. Версия 5.13.0
#include <ESP8266HTTPUpdateServer.h>
#include <DNSServer.h>
#include <TickerScheduler.h> // https://github.com/Toshik/TickerScheduler
#include <time.h>
// Библиотеки устройств
#include <DHT.h> // https://github.com/markruys/arduino-DHT
#include <PZEM004T.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <Adafruit_STMPE610.h>
#include "Fonts/FreeMono7pt8b.h"
#include "Fonts/FreeMono9pt8b.h"
#include "Fonts/FreeMonoBold9pt8b.h"
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

PZEM004T pzem(&Serial);
IPAddress ip(192, 168, 1, 1);

// Датчик DHT
DHT dht;
#define dhtPin 2

// Дисплей
#define PIN_DC 4
#define PIN_RESET 5
#define PIN_CS 15

#define M_PAGE_SIZE 150

#define NTP_TIMEOUT 600000 //10 минут

Adafruit_ILI9341 display = Adafruit_ILI9341(PIN_CS, PIN_DC, PIN_RESET);

String configSetup = "{}"; // данные для config.setup.json
String configJson = "{}";  // данные для config.live.json


char s[100];
char m_file[16];
int u_count = 0, i_count = 0, p_count = 0;
int m_page0[M_PAGE_SIZE];
int m_page_count0 = 0;
float u1 = 0.0, i1 = 0.0, p1 = 0.0, e1 = 0.0;
float p_max = 0, p_min = 99999999;
float u_avg = 0.0, i_avg = 0.0, p_avg = 0.0;
long t_correct = 0;
uint32_t tm = 0;
uint32_t t_cur = 0;
uint32_t ms, ms1 = 0, ms2 = 0, ms3 = 0, ms4 = 0, ms_ok = 0;
uint32_t m_tm = 10000;
uint16_t m_count = 0;

byte DN; // параметр День1, ночь0
byte DNAdresse = 0; //! Адрес для хранения параметра День1, ночь0
byte dAdresse = 1; // *начала адресса куда буду писать показаня за день там тип данных int32_t 4 байта занимает
byte nAdresse = 5; // ?начала адресса куда буду писать показаня за ночь там тип данных int32_t 4 байта занимает
byte TarrifAdresseD = 9; // начала адресса куда буду писать время перехода на день
byte TarrifAdresseN = 11; // начала адресса куда буду писать время перехода на ночь
int TimeD = 7;  // время перехода на день
int TimeN = 23;  // время перехода на ночь
float kWhAll;
float kWhDayAll;
float kWhNightAll;
float kWhDayAllERROM;
float kWhNightAllERROM;
float tarifD; // цена на дневное ЭЭ введённая на телефоне
float tarifN; // цена на ночное ЭЭ введённая на телефоне