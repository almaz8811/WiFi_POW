// -----------------  DHT
void DHT_init()
{
  dht.setup(dhtPin);                                     //Запускаем датчик
  delay(1000); 
  int st=1;                                          // Нужно ждать иначе датчик не определится правильно
  static uint16_t test = dht.getMinimumSamplingPeriod(); // Получим минимальное время между запросами данных с датчика
  jsonWrite(configJson, "dhttime", test);                // Отправим в json переменную configJson ключ dhttime полученное значение
  dht.getTemperature();                                  // обязательно делаем пустое чтение первый раз иначе чтение статуса не сработает
  String statusDHT = dht.getStatusString();              // Определим стстус датчика
  //Serial.print("DHT = ");
  //Serial.println(statusDHT); //  и сообщим в Serial

  if (st == 1)
  {                                                             // включим задачу если датчик есть
    //jsonWrite(configJson, "temperature", dht.getTemperature()); // отправить температуру в configJson
    //jsonWrite(configJson, "humidity", dht.getHumidity());       // отправить влажность в configJson

    ts.add(
        0, 600, [&](void *) {                                        // Запустим задачу 0 с интервалом test
          //jsonWrite(configJson, "temperature", dht.getTemperature()); // отправить температуру в configJson
          //jsonWrite(configJson, "humidity", dht.getHumidity());       // отправить влажность в configJson
          //DebugSerial.println(pzem.voltage(ip));
 float u2,i2,p2,e2;
       for( int i=0; i<3; i++ ){
           u2 = pzem.voltage(ip);
           if( u2 >= 0 ){u1 = u2; u_avg+=u1; u_count++; break; }
       }
       for( int i=0; i<3; i++ ){
           i2 = pzem.current(ip);
           if( i2 >= 0 ){i1 = i2; i_avg+=i1; i_count++; break; }
       }
       for( int i=0; i<3; i++ ){
           p2 = pzem.power(ip);
           if( p2 >= 0 ){p1 = p2; p_avg+=p1; p_count++; break; }
       }
       for( int i=0; i<3; i++ ){
           e2 = pzem.energy(ip);
           if( e2 >= 0 ){e1 = e2; break; }
       }
       displayEE();
       displayGRAPH();
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
        display.setFont(&FreeMonoBold12pt8b);
        display.setTextColor(ILI9341_GREEN);
        display.fillRect(248, 0, 72, 19, ILI9341_BLACK);
        display.setCursor(248, 17);
        display.print(GetTimeHM());
        display.endWrite();
        
      },
      nullptr, true);
}


