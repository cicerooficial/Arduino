#include <dht.h> //Importa biblioteca do módulo de temperatura e umidade DHT11

#define dht_dpin A1 //Pino DATA do Sensor ligado na porta Analogica A1
dht DHT; //Inicializa o sensor

void setup()
{
  Serial.begin(9600);
  delay(1000);//Aguarda 1 seg
}

void loop()
{
  DHT.read11(dht_dpin); //Lê as informações do sensor
  Serial.print("Umidade = ");
  Serial.print(DHT.humidity); //Pega o valor da umidade
  Serial.print(" %  ");
  Serial.print("Temperatura = ");
  Serial.print(DHT.temperature); //Pega o valor da temperatura
  Serial.println(" Celsius  ");

  //Não diminuir o valor abaixo. O ideal é a leitura a cada 2 segundos
  delay(2000);  
}

