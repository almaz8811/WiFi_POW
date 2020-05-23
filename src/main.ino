// ------------- Чтение значения json
String jsonRead(String &json, String name)
{
  DynamicJsonBuffer jsonBuffer;
  JsonObject &root = jsonBuffer.parseObject(json);
  return root[name].as<String>();
}

// ------------- Чтение значения json
int jsonReadtoInt(String &json, String name)
{
  DynamicJsonBuffer jsonBuffer;
  JsonObject &root = jsonBuffer.parseObject(json);
  return root[name];
}

// ------------- Чтение значения json
float jsonReadtoFloat(String &json, String name)
{
  DynamicJsonBuffer jsonBuffer;
  JsonObject &root = jsonBuffer.parseObject(json);
  char tempChar[50];
  String tempString = root[name].as<String>();
  tempString.toCharArray(tempChar, tempString.length());
  return atof(tempChar);
}

// ------------- Запись значения json String
String jsonWrite(String &json, String name, String volume)
{
  DynamicJsonBuffer jsonBuffer;
  JsonObject &root = jsonBuffer.parseObject(json);
  root[name] = volume;
  json = "";
  root.printTo(json);
  return json;
}

// ------------- Запись значения json int
String jsonWrite(String &json, String name, int volume)
{
  DynamicJsonBuffer jsonBuffer;
  JsonObject &root = jsonBuffer.parseObject(json);
  root[name] = volume;
  json = "";
  root.printTo(json);
  return json;
}

// ------------- Запись значения json float
String jsonWrite(String &json, String name, float volume)
{
  DynamicJsonBuffer jsonBuffer;
  JsonObject &root = jsonBuffer.parseObject(json);
  root[name] = volume;
  json = "";
  root.printTo(json);
  return json;
}

void saveConfig()
{
  writeFile("config.json", configSetup);
}

// ------------- Чтение файла в строку
String readFile(String fileName, size_t len)
{
  File configFile = SPIFFS.open("/" + fileName, "r");
  if (!configFile)
  {
    return "Failed";
  }
  size_t size = configFile.size();
  if (size > len)
  {
    configFile.close();
    return "Large";
  }
  String temp = configFile.readString();
  configFile.close();
  return temp;
}

// ------------- Запись строки в файл
String writeFile(String fileName, String strings)
{
  File configFile = SPIFFS.open("/" + fileName, "w");
  if (!configFile)
  {
    return "Failed to open config file";
  }
  configFile.print(strings);
  //strings.printTo(configFile);
  configFile.close();
  return "Write sucsses";
}

// Перегрузка функций
// ------------- Создание данных для графика
String graf(int datas)
{
  String root = "{}"; // Формировать строку для отправки в браузер json формат
  // {"data":[1]}
  // Резервируем память для json обекта буфер может рости по мере необходимти, предпочтительно для ESP8266
  DynamicJsonBuffer jsonBuffer;
  // вызовите парсер JSON через экземпляр jsonBuffer
  JsonObject &json = jsonBuffer.parseObject(root);
  // Заполняем поля json
  JsonArray &data = json.createNestedArray("data");
  data.add(datas);
  // Помещаем созданный json в переменную root
  root = "";
  json.printTo(root);
  return root;
}
// ------------- Создание данных для графика
String graf(float datas)
{
  String root = "{}"; // Формировать строку для отправки в браузер json формат
  // {"data":[1]}
  // Резервируем память для json обекта буфер может рости по мере необходимти, предпочтительно для ESP8266
  DynamicJsonBuffer jsonBuffer;
  // вызовите парсер JSON через экземпляр jsonBuffer
  JsonObject &json = jsonBuffer.parseObject(root);
  // Заполняем поля json
  JsonArray &data = json.createNestedArray("data");
  data.add(datas);
  // Помещаем созданный json в переменную root
  root = "";
  json.printTo(root);
  return root;
}
// ------------- Создание данных для графика
String graf(int datas, int datas1)
{
  String root = "{}"; // Формировать строку для отправки в браузер json формат
  // {"data":[1]}
  // Резервируем память для json обекта буфер может рости по мере необходимти, предпочтительно для ESP8266
  DynamicJsonBuffer jsonBuffer;
  // вызовите парсер JSON через экземпляр jsonBuffer
  JsonObject &json = jsonBuffer.parseObject(root);
  // Заполняем поля json
  JsonArray &data = json.createNestedArray("data");
  JsonArray &data1 = json.createNestedArray("data1");
  data.add(datas);
  data1.add(datas1);
  // Помещаем созданный json в переменную root
  root = "";
  json.printTo(root);
  return root;
}
// ------------- Создание данных для графика
String graf(float datas, float datas1)
{
  String root = "{}"; // Формировать строку для отправки в браузер json формат
  // {"data":[1]}
  // Резервируем память для json обекта буфер может рости по мере необходимти, предпочтительно для ESP8266
  DynamicJsonBuffer jsonBuffer;
  // вызовите парсер JSON через экземпляр jsonBuffer
  JsonObject &json = jsonBuffer.parseObject(root);
  // Заполняем поля json
  JsonArray &data = json.createNestedArray("data");
  JsonArray &data1 = json.createNestedArray("data1");
  data.add(datas);
  data1.add(datas1);
  // Помещаем созданный json в переменную root
  root = "";
  json.printTo(root);
  return root;
}
// ------------- Создание данных для графика
String graf(float datas, float datas1, float datas2)
{
  String root = "{}"; // Формировать строку для отправки в браузер json формат
  // {"data":[1]}
  // Резервируем память для json обекта буфер может рости по мере необходимти, предпочтительно для ESP8266
  DynamicJsonBuffer jsonBuffer;
  // вызовите парсер JSON через экземпляр jsonBuffer
  JsonObject &json = jsonBuffer.parseObject(root);
  // Заполняем поля json
  JsonArray &data = json.createNestedArray("data");
  JsonArray &data1 = json.createNestedArray("data1");
  JsonArray &data2 = json.createNestedArray("data2");
  data.add(datas);
  data1.add(datas1);
  data2.add(datas2);
  // Помещаем созданный json в переменную root
  root = "";
  json.printTo(root);
  return root;
}
// ------------- Создание данных для графика
String graf(int datas, int datas1, int datas2)
{
  String root = "{}"; // Формировать строку для отправки в браузер json формат
  // {"data":[1]}
  // Резервируем память для json обекта буфер может рости по мере необходимти, предпочтительно для ESP8266
  DynamicJsonBuffer jsonBuffer;
  // вызовите парсер JSON через экземпляр jsonBuffer
  JsonObject &json = jsonBuffer.parseObject(root);
  // Заполняем поля json
  JsonArray &data = json.createNestedArray("data");
  JsonArray &data1 = json.createNestedArray("data1");
  JsonArray &data2 = json.createNestedArray("data2");
  data.add(datas);
  data1.add(datas1);
  data2.add(datas2);
  // Помещаем созданный json в переменную root
  root = "";
  json.printTo(root);
  return root;
}

void displayEE()
{
  display.startWrite();
  display.fillRect(1, 28, 157, 14, ILI9341_BLACK);
  display.setTextColor(ILI9341_GREEN);
  display.setFont(&FreeMonoBold9pt8b);
  sprintf(s, "%d.%02d", (int)u1, ((int)(u1 * 100)) % 100);
  display.setCursor(2, 40);
  display.print(s);
  display.setFont(&FreeMono7pt8b);
  display.print(" В");

  display.fillRect(161, 28, 157, 14, ILI9341_BLACK);
  display.setFont(&FreeMonoBold9pt8b);
  sprintf(s, "%d.%02d", (int)i1, ((int)(i1 * 100)) % 100);
  display.setCursor(162, 40);
  display.print(s);
  display.setFont(&FreeMono7pt8b);
  display.print(" А");

  display.fillRect(1, 44, 157, 14, ILI9341_BLACK);
  display.setFont(&FreeMonoBold9pt8b);
  sprintf(s, "%d.%02d", (int)p1, ((int)(p1 * 100)) % 100);
  display.setCursor(2, 56);
  display.print(s);
  display.setFont(&FreeMono7pt8b);
  display.print(" Вт");

  display.fillRect(161, 44, 157, 14, ILI9341_BLACK);
  display.setFont(&FreeMonoBold9pt8b);
  sprintf(s, "%d.%02d", (int)e1, ((int)(e1 * 100)) % 100);
  display.setCursor(162, 56);
  display.print(s);
  display.setFont(&FreeMono7pt8b);
  display.print(" кВт/ч");

  display.fillRect(1, 60, 157, 14, ILI9341_BLACK);
  display.setFont(&FreeMonoBold9pt8b);
  sprintf(s, "%d.%02d", (int)kWhDayAll, ((int)(kWhDayAll * 100)) % 100);
  display.setCursor(2, 72);
  display.print(s);
  display.setFont(&FreeMono7pt8b);
  display.print(" кВт/д");

  display.fillRect(161, 60, 157, 14, ILI9341_BLACK);
  display.setFont(&FreeMonoBold9pt8b);
  sprintf(s, "%d.%02d", (int)e1, ((int)(e1 * 100)) % 100);
  display.setCursor(162, 72);
  display.print("999.00");
  display.setFont(&FreeMono7pt8b);
  display.print(" кВт/м");

  display.fillRect(1, 76, 157, 14, ILI9341_BLACK);
  display.setFont(&FreeMonoBold9pt8b);
  sprintf(s, "%d.%02d", (int)p1, ((int)(p1 * 100)) % 100);
  display.setCursor(2, 88);
  display.print("9999.00");
  display.setFont(&FreeMono7pt8b);
  display.print(" цена/д");

  display.fillRect(161, 76, 157, 14, ILI9341_BLACK);
  display.setFont(&FreeMonoBold9pt8b);
  sprintf(s, "%d.%02d", (int)e1, ((int)(e1 * 100)) % 100);
  display.setCursor(162, 88);
  display.print("9999.00");
  display.setFont(&FreeMono7pt8b);
  display.print(" цена/м");

  display.fillRect(1, 92, 157, 14, ILI9341_BLACK);
  display.setFont(&FreeMonoBold9pt8b);
  sprintf(s, "%d.%02d", (int)p1, ((int)(p1 * 100)) % 100);
  display.setCursor(2, 104);
  display.print("9999.00");
  display.setFont(&FreeMono7pt8b);
  display.print(" В/min");

  display.fillRect(161, 92, 157, 14, ILI9341_BLACK);
  display.setFont(&FreeMonoBold9pt8b);
  sprintf(s, "%d.%02d", (int)e1, ((int)(e1 * 100)) % 100);
  display.setCursor(162, 104);
  display.print("9999.00");
  display.setFont(&FreeMono7pt8b);
  display.print(" В/max");

  display.fillRect(1, 108, 157, 14, ILI9341_BLACK);
  display.setFont(&FreeMonoBold9pt8b);
  sprintf(s, "%d.%02d", (int)p1, ((int)(p1 * 100)) % 100);
  display.setCursor(2, 120);
  display.print("9999.00");
  display.setFont(&FreeMono7pt8b);
  display.print(" Вт/min");

  display.fillRect(161, 188, 157, 14, ILI9341_BLACK);
  display.setFont(&FreeMonoBold9pt8b);
  sprintf(s, "%d.%02d", (int)e1, ((int)(e1 * 100)) % 100);
  display.setCursor(162, 120);
  display.print("9999.00");
  display.setFont(&FreeMono7pt8b);
  display.print(" Вт/max");

  display.endWrite();
}

void displayGRAPH()
{
  // Стираем область графика
  display.startWrite();
  display.fillRect(0, 140, 320, 120, ILI9341_WHITE);

  // Рисуем сетку
  for (int i = 0; i < 15; i++)
  {
    int x = 18 + i * 20;
    display.drawLine(x, 138, x, 238, ILI9341_BLACK);
  }
  for (int i = 0; i < 5; i++)
  {
    int y = 138 + i * 20;
    display.drawLine(18, y, 318, y, ILI9341_BLACK);
  }
  // Формируем график
  int n = 0;
  sprintf(s, "Pmax=%d.%02d Pmin=%d.%02d", (int)p_max, ((int)(p_max * 100)) % 100, (int)p_min, ((int)(p_min * 100)) % 100);
  // Пишем минимум максимум
  display.setFont(&FreeMono9pt8b); // устанавливаем маленький шрифт
  display.setTextColor(ILI9341_RED);
  display.setCursor(30, 135);
  display.print(s);

  for (int i = 0; i < m_page_count0; i++)
  {
    float yf = 1;
    if (p_max > 0)
      yf = m_page0[i] * 100 / (p_max);
    int y = 238 - (int)yf;
    int x = 19 + n * 2;
    n++;
    display.drawLine(x, y, x, 237, ILI9341_RED);
  }

  display.endWrite();
}

/* void stringToFloat(string s){ 
  char ch[10];
  s.toCharArray(ch, s.length());
  return atof(ch);
} */

void MomentCost(){
  float tarifM;
  if(DN == 1) {tarifM = tarifD;} else {tarifM = tarifN;}
  float cost = (p1 / 1000) * tarifM;
  jsonWrite(configJson, "momentCost", cost);
}

void kWhDayUpdate(){
  uint32_t kWhDay = e1;
  kWhDayAll = kWhDayAllERROM + kWhDay;
  jsonWrite(configJson, "kWhDayAll", kWhDayAll / 1000);
}

void kWhNightUpdate(){
  uint32_t kWhNight = e1;
  kWhNightAll = kWhNightAllERROM + kWhNight;
  jsonWrite(configJson, "kWhNightAll", kWhNightAll / 1000);
}

void kWh_All(){
  kWhAll = kWhNightAll + kWhDayAll;
  jsonWrite(configJson, "kWhAll", kWhAll / 1000);
}

void Money(){
  float mnight = kWhNightAll * tarifN / 1000;
  float mday = kWhDayAll * tarifD / 1000;
  jsonWrite(configJson, "mnight", mnight);
  jsonWrite(configJson, "mday", mday);
  jsonWrite(configJson, "mDayAll", mnight + mday);
}

void NightToDay()
{
  if ((TimeN > hour() && hour() >= TimeD) && DN == 0)
  {
    DN = 1;
    //memset(vipe, 0,sizeof(vipe)); // заполняем нулями при переходе. Так как функция подсчёта находится ниже и при смене DN посчитает день за ночь и наоборот
    kWhNightAllERROM = kWhNightAll;
    jsonWrite(configJson, "kWhNightAll", kWhNightAll / 1000);
    jsonWrite(configJson, "DN", DN);
    //Serial.println("Go to day time");
    ResetWh = 1;
    LstRdWh = millis();
  }
}

void DayToNight()
{
  if ((TimeN <= hour() || hour() < TimeD) && DN == 1)
  {
    //Blynk.virtualWrite(22,float(kWhDayAll)/1000);
    DN = 0;
    jsonWrite(configJson, "kWhDayAll", kWhDayAll / 1000);
    kWhDayAllERROM = kWhDayAll;
    jsonWrite(configJson, "DN", DN);
    //Serial.println("Go to night time");
    ResetWh = 1;
    LstRdWh = millis();
  }
}

void readEnergy()
{
  ms = millis();
  if (ms1 == 0 || ms < ms1 || (ms - ms1) > 500)
  {
    ms1 = ms;
    t_cur = ms / 1000;
    tm = t_cur + t_correct;

    float u2, i2, p2, e2;
    for (int i = 0; i < 3; i++)
    {
      u2 = pzem.voltage(ip);
      if (u2 >= 0)
      {
        u1 = u2;
        u_avg += u1;
        u_count++;
        break;
      }
    }
    for (int i = 0; i < 3; i++)
    {
      i2 = pzem.current(ip);
      if (i2 >= 0)
      {
        i1 = i2;
        i_avg += i1;
        i_count++;
        break;
      }
    }
    for (int i = 0; i < 3; i++)
    {
      p2 = pzem.power(ip);
      if (p2 >= 0)
      {
        p1 = p2;
        p_avg += p1;
        p_count++;
        break;
      }
    }
    for (int i = 0; i < 3; i++)
    {
      e2 = pzem.energy(ip);
      if (e2 >= 0)
      {
        e1 = e2;
        break;
      }
    }

    if (p_max < p1)
      p_max = p1;
    if (p_min > p1)
      p_min = p1;
  }

  if (ms2 == 0 || ms < ms2 || (ms - ms2) > m_tm)
  {
    ms2 = ms;
    //WriteMFile(false);
  }

  if (ms4 == 0 || ms < ms4 || (ms - ms4) > 2000)
  {
    ms4 = ms;
    if (m_page_count0 >= M_PAGE_SIZE - 1)
    {
      p_max = 0;
      p_min = 99999999;
      // Сдвигаем график
      for (int i = 0; i < M_PAGE_SIZE - 1; i++)
      {
        m_page0[i] = m_page0[i + 1];
        if (p_max < m_page0[i])
          p_max = m_page0[i];
        if (p_min > m_page0[i])
          p_min = m_page0[i];
      }
      m_page0[M_PAGE_SIZE - 1] = p1;
      if (p_max < p1)
        p_max = p1;
      if (p_min > p1)
        p_min = p1;
    }
    else
    {
      m_page0[m_page_count0++] = p1;
    }
  }
  if (DN == 1){
    //kWhDayUpdate();
  // if(DN == 0)kWhNightUpdate();
}

void firstRun(byte DD)
{

  if (DD > 1)
  {
    jsonWrite(configSetup, "DN", 1);
    jsonWrite(configSetup, "dAdresse", 0);
    jsonWrite(configSetup, "nAdresse", 0);
    jsonWrite(configSetup, "TarrifAdresseD", 0);
    jsonWrite(configSetup, "TarrifAdresseN", 0);
    DN = 1;
  }
}

/* void NightToDay(){
  if((TimeN>hour() && hour()>=TimeD) && DN == 0){
  DN = 1;
  memset(vipe, 0,sizeof(vipe)); // заполняем нулями при переходе. Так как функция подсчёта находится ниже и при смене DN посчитает день за ночь и наоборот
  Serial.println(kWhNightAll);
  kWhNightAllERROM = kWhNightAll;
  EEPROM.put(nAdresse,kWhNightAll);
  EEPROM.update(DNAdresse,DN);
  //Serial.print("DN -> "); Serial.println(DN);
  Serial.print(hour());Serial.print(":");Serial.println(minute());
  Serial.println("Go to day time");
  ResetWh = 1; 
  LstRdWh = millis();
  //Serial.println("---------------------------");
      }
}

void DayToNight(){
    
    
      if((TimeN<=hour() || hour()<TimeD) && DN == 1){ 
      Serial.println(kWhDayAll);
      //Blynk.virtualWrite(22,float(kWhDayAll)/1000);
      DN = 0;
      memset(vipe, 0,sizeof(vipe)); 
      EEPROM.put(dAdresse,kWhDayAll);
      kWhDayAllERROM = kWhDayAll;
      EEPROM.update(DNAdresse,DN);
      //Serial.print("DN -> "); Serial.println(DN);                                   
      Serial.print(hour());Serial.print(":");Serial.println(minute());
      Serial.println("Go to night time");
      ResetWh = 1; 
      LstRdWh = millis();
      //Serial.println("---------------------------");
  } 
  
} */