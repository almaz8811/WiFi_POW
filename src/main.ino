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
  display.fillRect(1, 28, 157, 18, ILI9341_YELLOW);
  display.setTextColor(ILI9341_GREEN);
  display.setFont(&FreeMonoBold12pt8b);
  sprintf(s, "%d.%02d", (int)u1, ((int)(u1 * 100)) % 100);
  display.setCursor(2, 44);
  display.print(s);
  display.setFont(&FreeMono7pt8b);
  display.print(" В");
  
  display.fillRect(161, 28, 157, 18, ILI9341_YELLOW);
  display.setFont(&FreeMonoBold12pt8b);
  sprintf(s, "%d.%02d", (int)i1, ((int)(i1 * 100)) % 100);
  display.setCursor(162, 44);
  display.print(s);
  display.setFont(&FreeMono7pt8b);
  display.print(" А");

  display.fillRect(1, 48, 157, 18, ILI9341_YELLOW);
  display.setFont(&FreeMonoBold12pt8b);
  sprintf(s, "%d.%02d", (int)p1, ((int)(p1 * 100)) % 100);
  display.setCursor(2, 64);
  display.print(s);
  display.setFont(&FreeMono7pt8b);
  display.print(" Вт");

  display.fillRect(161, 48, 157, 18, ILI9341_YELLOW);
  display.setFont(&FreeMonoBold12pt8b);
  sprintf(s, "%d.%02d", (int)e1, ((int)(e1 * 100)) % 100);
  display.setCursor(162, 64);
  display.print(s);
  display.setFont(&FreeMono7pt8b);
  display.print(" Вт/ч");

  display.endWrite();
}

void displayGRAPH()
{
  // Стираем область графика
  display.startWrite();
  display.fillRect(0, 120, 320, 120, ILI9341_WHITE);

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