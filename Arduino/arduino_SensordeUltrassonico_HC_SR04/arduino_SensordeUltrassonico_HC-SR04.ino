#include "Ultrasonic.h"
//Importa a biblioteca Ultrassonica
Ultrasonic ultrasonic(2,3);

float distancia; //Cria variavel para guardar a distancia
void setup() {
Serial.begin(9600);//configura a comunicação para 96000
}

void loop()
{
  distancia = ultrasonic.Ranging(CM);//Converte e salva a distancia convertida em CM
  Serial.print(distancia); //Imprime a distancia no monitor serial
  Serial.println(" cm"); //Adicionar cm 
  delay(100);
}
