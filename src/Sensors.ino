// -----------------  DHT
void DHT_init()
{
  dht.setup(dhtPin);                                     //Запускаем датчик
  delay(1000);                                           // Нужно ждать иначе датчик не определится правильно
  static uint16_t test = dht.getMinimumSamplingPeriod(); // Получим минимальное время между запросами данных с датчика
  jsonWrite(configJson, "dhttime", test);                // Отправим в json переменную configJson ключ dhttime полученное значение
  dht.getTemperature();                                  // обязательно делаем пустое чтение первый раз иначе чтение статуса не сработает
  String statusDHT = dht.getStatusString();              // Определим стстус датчика
  //Serial.print("DHT = ");
  //Serial.println(statusDHT); //  и сообщим в Serial

  if (statusDHT == "OK")
  {                                                             // включим задачу если датчик есть
    jsonWrite(configJson, "temperature", dht.getTemperature()); // отправить температуру в configJson
    jsonWrite(configJson, "humidity", dht.getHumidity());       // отправить влажность в configJson

    ts.add(
        0, test, [&](void *) {                                        // Запустим задачу 0 с интервалом test
          jsonWrite(configJson, "temperature", dht.getTemperature()); // отправить температуру в configJson
          jsonWrite(configJson, "humidity", dht.getHumidity());       // отправить влажность в configJson
          //Serial.print(".");
        },
        nullptr, true);
  }
}

// -----------------  Вывод времени и даты в /config.live.json каждую секунду
void sec_init()
{
  ts.add(
      1, 1000, [&](void *) { // Запустим задачу 1 с интервалом 1000ms
        // поместим данные для web страницы в json строку configJson
        // Будем вызывать эту функцию каждый раз при запросе /config.live.json
        // jsonWrite(строка, "ключ", значение_число); Так можно дабавить или обнавить json значение ключа в строке
        // jsonWrite(строка, "ключ", "значение_текст");
        jsonWrite(configJson, "time", GetTime()); // отправить время в configJson
        jsonWrite(configJson, "date", GetDate()); // отправить дату в configJson
      },
      nullptr, true);
}

void disp_time()
{
  ts.add(
      2, 60000, [&](void *) { // Запустим задачу 2 с интервалом 60000ms
        display.startWrite();
        display.setFont(&FreeMono7pt8b);
        display.setTextColor(ILI9341_GREEN);
        display.fillRect(275, 0, 45, 15, ILI9341_BLACK);
        display.setCursor(275, 10);
        display.print(GetTimeHM());
        display.endWrite();
        displayEE();
      },
      nullptr, true);
}


