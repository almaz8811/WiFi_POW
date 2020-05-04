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
  pzem.setAddress(ip);
  DHT_init();

}

void loop()
{
  ts.update();         //планировщик задач
  HTTP.handleClient(); // Работа Web сервера
  yield();
  dnsServer.processNextRequest(); // Для работы DNS в режиме AP

if( ms1 == 0 || ms < ms1 || (ms - ms1)>500 ){
       ms1    = ms;
       t_cur  = ms/1000;
       tm     = t_cur + t_correct;

      
       if( p_max < p1 )p_max = p1;
       if( p_min > p1 )p_min = p1;
   
       
       

   }

   if( ms2 == 0 || ms < ms2 || (ms - ms2)>m_tm ){
       ms2 = ms;
    
   }
}
