#include "set.h"

void setup()
{

  Serial.begin(115200);
  delay(5);
  Serial.println("");
  //Запускаем файловую систему
  Serial.println("Start 4-FS");
  FS_init();
  Serial.println("Step7-FileConfig");
  configSetup = readFile("config.json", 4096);
  jsonWrite(configJson, "SSDP", jsonRead(configSetup, "SSDP"));
  Serial.println(configSetup);
  Serial.println("Start 1-WIFI");

  display.begin();
  display.setRotation(1);
  display.fillScreen(ILI9341_BLACK);
  display.startWrite();
  display.setTextColor(ILI9341_YELLOW);
  display.setFont(&FreeMonoBold12pt7b);
  display.setCursor(10, 16);
  display.print("PowerMeter v1.1");
  display.endWrite();
  //Запускаем WIFI
  WIFIinit();
  Serial.println("Start 8-Time");
  // Получаем время из сети
  Time_init();
  sec_init();
  //Настраиваем и запускаем SSDP интерфейс
  Serial.println("Start 3-SSDP");
  SSDP_init();
  //Настраиваем и запускаем HTTP интерфейс
  Serial.println("Start 2-WebServer");
  HTTP_init();
  DHT_init();
}

void loop()
{
  ts.update();         //планировщик задач
  HTTP.handleClient(); // Работа Web сервера
  yield();
  dnsServer.processNextRequest(); // Для работы DNS в режиме AP
}
