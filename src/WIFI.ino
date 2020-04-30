void WIFIinit()
{
  // --------------------Получаем SSDP со страницы
  HTTP.on("/ssid", HTTP_GET, []() {
    jsonWrite(configSetup, "ssid", HTTP.arg("ssid"));
    jsonWrite(configSetup, "password", HTTP.arg("password"));
    saveConfig();                       // Функция сохранения данных во Flash
    HTTP.send(200, "text/plain", "OK"); // отправляем ответ о выполнении
  });
  // --------------------Получаем SSDP со страницы
  HTTP.on("/ssidap", HTTP_GET, []() {
    jsonWrite(configSetup, "ssidAP", HTTP.arg("ssidAP"));
    jsonWrite(configSetup, "passwordAP", HTTP.arg("passwordAP"));
    saveConfig();                       // Функция сохранения данных во Flash
    HTTP.send(200, "text/plain", "OK"); // отправляем ответ о выполнении
  });

  // Попытка подключения к точке доступа
  WiFi.mode(WIFI_STA);
  byte tries = 11;
  String _ssid = jsonRead(configSetup, "ssid");
  String _password = jsonRead(configSetup, "password");
  if (_ssid == "" && _password == "")
  {
    WiFi.begin();
  }
  else
  {
    WiFi.begin(_ssid.c_str(), _password.c_str());
  }
  // Делаем проверку подключения до тех пор пока счетчик tries
  // не станет равен нулю или не получим подключение
  while (--tries && WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(1000);
  }
  if (WiFi.status() != WL_CONNECTED)
  {
    // Если не удалось подключиться запускаем в режиме AP
    Serial.println("");
    Serial.println("WiFi up AP");
    StartAPMode();
    display.startWrite();
   display.setFont(&FreeMono9pt7b);                           // устанавливаем маленький шрифт
   display.setTextColor(ILI9341_WHITE);
//sprintf(s,"AP: %s", jsonRead(configSetup, "ssidAP").c_str());
      display.setCursor(10,32);
      display.print(String("Сеть AP: ") + String("192.168.4.1"));
      //display.print(s);
      //sprintf(s,"http://192.168.4.1"); 
      //display.setCursor(10,48);
      //display.print(s);
   display.endWrite();
  }
  else
  {
    // Иначе удалось подключиться отправляем сообщение
    // о подключении и выводим адрес IP
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    // Выводим на дисплей
    display.startWrite();
    //display.setFont(&FreeMono9pt7b); // устанавливаем маленький шрифт
    display.setFont(&FreeMono9pt7b); // устанавливаем маленький шрифт
    display.setTextColor(ILI9341_WHITE);
    //sprintf(s,"Connect: %s", jsonRead(configSetup, "SSDP").c_str());
    display.setCursor(10,32);
    IPAddress my_ip = WiFi.localIP();
    display.print(String("Сеть WIFI: ") + String(my_ip[0]) + "." + String(my_ip[1]) + "." + String(my_ip[2]) + "." + String(my_ip[3]));
//      sprintf(s,"http://%d.%d.%d.%d",my_ip[0],my_ip[1],my_ip[2],my_ip[3]); 
//      display.setCursor(10,48);
//      display.print(s);
    display.endWrite();
  }
}

bool StartAPMode()
{
  IPAddress apIP(192, 168, 4, 1);
  IPAddress staticGateway(192, 168, 4, 1);
  IPAddress staticSubnet(255, 255, 255, 0);
  // Отключаем WIFI
  WiFi.disconnect();
  // Меняем режим на режим точки доступа
  WiFi.mode(WIFI_AP);
  // Задаем настройки сети
  WiFi.softAPConfig(apIP, staticGateway, staticSubnet);
  //Включаем DNS
  dnsServer.start(53, "*", apIP);
  // Включаем WIFI в режиме точки доступа с именем и паролем
  // хронящихся в переменных _ssidAP _passwordAP
  String _ssidAP = jsonRead(configSetup, "ssidAP");
  String _passwordAP = jsonRead(configSetup, "passwordAP");
  WiFi.softAP(_ssidAP.c_str(), _passwordAP.c_str());
  return true;
  
}
