#include <ESP8266WiFi.h>      //Содержится в пакете. Видео с уроком http://esp8266-arduinoide.ru/step1-wifi
#include <ESP8266WebServer.h> //Содержится в пакете. Видео с уроком http://esp8266-arduinoide.ru/step2-webserver
#include <ESP8266SSDP.h>      //Содержится в пакете. Видео с уроком http://esp8266-arduinoide.ru/step3-ssdp
#include <FS.h>               //Содержится в пакете. Видео с уроком http://esp8266-arduinoide.ru/step4-fswebserver
//                    ПЕРЕДАЧА ДАННЫХ НА WEB СТРАНИЦУ. Видео с уроком http://esp8266-arduinoide.ru/step5-datapages/
//                    ПЕРЕДАЧА ДАННЫХ С WEB СТРАНИЦЫ.  Видео с уроком http://esp8266-arduinoide.ru/step6-datasend/
#include <ArduinoJson.h> //Установить из менеджера библиотек. https://arduinojson.org/
//                    ЗАПИСЬ И ЧТЕНИЕ ПАРАМЕТРОВ КОНФИГУРАЦИИ В ФАЙЛ. Видео с уроком http://esp8266-arduinoide.ru/step7-fileconfig/
#include <ESP8266HTTPUpdateServer.h> //Содержится в пакете.  Видео с уроком http://esp8266-arduinoide.ru/step8-timeupdate/
#include <DNSServer.h>               //Содержится в пакете.  // Для работы символьных имен в режиме AP отвечает на любой запрос например: 1.ru
#include <TickerScheduler.h>         //https://github.com/Toshik/TickerScheduler
// Библиотеки устройств
#include <DHT.h>          //https://github.com/markruys/arduino-DHT   Support for DHT11 and DHT22/AM2302/RHT03
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <Adafruit_STMPE610.h>
#include "Fonts/FreeMono9pt7b.h"
#include "Fonts/FreeMonoBold12pt7b.h"
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