#include "set.h"

void setup()
{
  //DebugSerial.begin(115200);
  delay(5);
  //Serial.println("");
  //Запускаем файловую систему
  //Serial.println("Start 4-FS");
  FS_init();
  //Serial.println("Step7-FileConfig");
  configSetup = readFile("config.json", 4096);
  jsonWrite(configJson, "SSDP", jsonRead(configSetup, "SSDP"));
  //Serial.println(configSetup);
  //Serial.println("Start 1-WIFI");

  display.begin();
  display.setRotation(1);
  display.fillScreen(ILI9341_BLACK);
  display.startWrite();
  display.setTextColor(ILI9341_YELLOW);
  display.setFont(&FreeMono7pt8b);
  display.setCursor(5, 10);
  display.print("AlmazPoWer v1.0");
  //display.fillRect(0, 27, 320, 80, ILI9341_YELLOW);  
  display.drawRect(0, 27, 159, 16, ILI9341_WHITE);  
  display.drawRect(160, 27, 159, 16, ILI9341_WHITE);  
  display.drawRect(0, 43, 159, 16, ILI9341_WHITE);  
  display.drawRect(160, 43, 159, 16, ILI9341_WHITE);  
  display.drawRect(0, 59, 159, 16, ILI9341_WHITE);
  display.drawRect(160, 59, 159, 16, ILI9341_WHITE);
  display.drawRect(0, 75, 159, 16, ILI9341_WHITE);
  display.drawRect(160, 75, 159, 16, ILI9341_WHITE);
  display.drawRect(0, 91, 159, 16, ILI9341_WHITE);
  display.drawRect(160, 91, 159, 16, ILI9341_WHITE);
  display.drawRect(0, 107, 159, 16, ILI9341_WHITE);
  display.drawRect(160, 107, 159, 16, ILI9341_WHITE);
  display.endWrite();
  //Запускаем WIFI
  WIFIinit();
  //Serial.println("Start 8-Time");
  // Получаем время из сети
  Time_init();
  sec_init();
  disp_time();
  //Настраиваем и запускаем SSDP интерфейс
  //Serial.println("Start 3-SSDP");
  SSDP_init();
  //Настраиваем и запускаем HTTP интерфейс
  //Serial.println("Start 2-WebServer");
  HTTP_init();
    // Запуск модуля измерения ЭЭ

  PZEM_init();

  DN = jsonRead(configSetup, "DN").toInt();
  firstRun(DN);
  kWhDayAllERROM = jsonReadtoFloat(configSetup, "kWhDayAllERROM");  //считаем  из памяти количество Вт за дни
  kWhNightAllERROM = jsonReadtoFloat(configSetup, "kWhNightAllERROM");
  kWhNightUpdate(); // разовая сработка при запуске. Чтобы считаные из памяти показания засчитались. А то если день, то ночные не считались и наоборот
  kWhDayUpdate();  

}

void loop()
{
  ts.update();         //планировщик задач
  HTTP.handleClient(); // Работа Web сервера
  yield();
  dnsServer.processNextRequest(); // Для работы DNS в режиме AP
  readEnergy();
}
