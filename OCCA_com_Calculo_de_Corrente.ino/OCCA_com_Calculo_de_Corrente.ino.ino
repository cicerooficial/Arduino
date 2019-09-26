/*
  Projeto:Automação de Iluminação, Projeto SPMAKERWEEK29
  Autor: Cícero Henrique
  Data: 12/08/2019
  Descrição: O desenvolvimento abaixo é parte de um projeto colaborativo entre rede pública de laboratórios Fab Lab LIVRE SP,
  para o evento SPMAKERWEEK2019 com tema Cidades Inteligentes.
*/
//Carrega as bibliotecas
#include "EmonLib.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

EnergyMonitor emon1;
// Inicializa o display no endereco 0x27
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

//Tensao da rede eletrica
int           rede = 110.0;
//Pino do sensor SCT
#define           sensorCorrente A1
//Valor da potencia acumulada
float         totalPotencia;
//Valor fixo da tarifa de Kwh de São Paulo de acordo com a ENEL
double  tarifaKWh = 0.48;
//Variável para alocar os cursos do valor em R$/Kwh
float         totalCustoKwh;

long ultimoTempo;
long intervalodeTempoParaSalvarnaMemoria = 3600000;

//Define portas dos Potenciometros
#define potenciometro1 A0

int velocidadePotenciometro;

void setup() {

  //Faz um loop de repetição para formata os pinos de 2 à 9 como saida de energia (OUTPUT)
  for (int contador = 2; contador <= 11; contador++) {
    pinMode(contador, OUTPUT);
  }

  lcd.begin(16, 2);
  lcd.clear();
  Serial.begin(9600);
  //Pino, calibracao - Cur Const= Ratio/BurdenR. 1800/62 = 29.
  emon1.current(sensorCorrente, 29);
  //Informacoes iniciais display
  lcd.setCursor(0, 0);
  lcd.print("R$/Hr: ");
  lcd.setCursor(0, 1);
  lcd.print("Pot.(W): ");

}

void loop() {
  long tempoAtual = millis();

  //Calcula a corrente
  float Irms = emon1.calcIrms(1480);
  totalPotencia = Irms * rede;

  if (tempoAtual - ultimoTempo > intervalodeTempoParaSalvarnaMemoria ) {
    ultimoTempo = tempoAtual;
    totalCustoKwh = totalCustoKwh + ((totalPotencia * 1.00) / 1000) * tarifaKWh;
  }

  //Mostra o valor da corrente
  Serial.print("R$/Hr: ");
  Serial.print(totalCustoKwh); // Irms
  lcd.setCursor(10, 0);
  lcd.print(totalCustoKwh);

  //Calcula e mostra o valor da potencia
  Serial.print(" Pote.(W): ");
  Serial.println(totalPotencia);
  lcd.setCursor(10, 1);
  lcd.print("      ");
  lcd.setCursor(10, 1);
  lcd.print(totalPotencia, 1);

  efeitoLuzes();

}


void efeitoLuzes() {
  velocidadePotenciometro = analogRead(potenciometro1);
  velocidadePotenciometro = map(velocidadePotenciometro, 0, 1023, 0, 1000);

  //CONTROLE DE IDA E VOLTA E VELOCIDADE

  //IDA
  for (int contador = 2; contador <= 11; contador++) {
    digitalWrite(contador, HIGH);
    delay(velocidadePotenciometro);
    digitalWrite(contador, LOW);
    delay(velocidadePotenciometro);
  }

  //Faz loop de repetição das fitas de led passando de uma em uma ida e volta com valores a partir das posições já convertidas dos potenciometros
  //VOLTA
  for (int contador = 11; contador >= 2; contador--) {

    digitalWrite(contador, HIGH);
    delay(velocidadePotenciometro);
    digitalWrite(contador, LOW);
    delay(velocidadePotenciometro);
  }

}
