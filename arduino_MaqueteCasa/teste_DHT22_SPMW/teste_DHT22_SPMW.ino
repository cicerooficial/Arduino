#include <dht.h>

dht DHT;

#define DHT22_PIN 5

struct
{
  uint32_t total;
}
stat = { 0 };

void setup()
{
  Serial.begin(115200);
  Serial.println("Humidity (%) | \tTemperature (C)");
}

void loop()
{
  // READ DATA
  uint32_t start = micros();
  int chk = DHT.read22(DHT22_PIN);
  uint32_t stop = micros();

  stat.total++;

  // DISPLAY DATA
  Serial.print(DHT.humidity, 1);
  Serial.print("\t\t");
  Serial.print(DHT.temperature, 1);
  Serial.print("\t");
  Serial.println();

  delay(2000);
}
