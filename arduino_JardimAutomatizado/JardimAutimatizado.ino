
/*
  Basedo em projeto Teste LCD 20x4 Arduino e Temperatura e Umidade de Solo
  Autor: Cícero Henrique
  Data: 03/08/2018
  Descrição: Projeto desenvolvido para auxiliar em atividade de Semana da Primeira Infância
  com objetivo de conscientizar as crianças da importancia do cuidado do meio ambiente e
  incluir tecnologia no processo de irrigação.

*/

//Inclui Biblioteza Wire
#include <Wire.h>
//Inclui Biblioteza LiquidCrustal_I2C (para comunicação com LCD através do Módulo I2C que ajuda na redução de portas no Arduino)
#include <LiquidCrystal_I2C.h>
//Inclui Biblioteca do leitor de temperatura e ambiente
#include <dht.h>

//Inicializa o sensor de temperatura e ambiente DHT criando um objeto de nome dht
dht DHT;

//Definie sensor de temperatuda DHT ligado no pino digital 8
#define sensordeTemperaturaDHT 8

// Inicializa o display no endereco 0x3F
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

//Inicia uma variável para guardar futuramente os valores que forem capturados do sensore de solo
int niveldeUmidade;

//Definie sensor de solo ligado no pino analogico A0
#define sensordeSolo A0

//Define leds ligados nos pinos digitais 2,4e7
#define ledvermelho 2
#define ledamarelo 4
#define ledazul 7
//Define um módulo relé ligado no pino digital 12
#define rele 12

//Inicia a configuração de SETUP ao ligar o Arduino
void setup() {
  //Define a taxa de transmissão com a comunicação Serial
  Serial.begin(9600);
  //Aguarda 1 seg antes de acessar as informações do sensor
  delay(1000);
  /*
    Define o LCD com 16 colunas e 2 linhas
    Obs: Para Displays de 20/4 só alterar os valorea abaixo
  */
  lcd.begin(16, 2);

  //Define os modos de conexão dos pinos INPUT (ENTRADA DE DADOS) | OUTPUT (SAIDA DE DADOS)
  pinMode(sensordeSolo, INPUT);
  pinMode(ledvermelho, OUTPUT);
  pinMode(ledamarelo, OUTPUT);
  pinMode(ledazul, OUTPUT);

  //Define os leds como desligados
  digitalWrite(ledvermelho, LOW);
  digitalWrite(ledamarelo, LOW);
  digitalWrite(ledazul, LOW);
  //Define relé como desligado
  pinMode(rele, OUTPUT);

}
//Fim do SETUP

//Inicia comandos principais do Arduino
void loop() {
  //Define a função da biblioteca DHT para leitura do sensor de tipo DHT11 se for DHT22 favor alterar
  DHT.read11(sensordeTemperaturaDHT);
  //Inicia o cursos do Display na posição coluna 0 e linha 0
  lcd.setCursor(0, 0);
  //Escreve a partir da posição de cima a frase Temp Ar
  lcd.print("Temp Ar");
  //Inicia o cursos do Display na posição coluna 0 e linha 1
  lcd.setCursor(0, 1);
  //Mostra a partir da posição de cima o valor de umidade captado do sensor de temperatura e ambiente DHT
  lcd.print(DHT.humidity);
  //Inicia o cursos do Display na posição coluna 4 e linha 1
  lcd.setCursor(4, 1);
  //Escreve a partir da posição de cima o caracter especial %
  lcd.print("%");
  //Inicia o cursos do Display na posição coluna 10 e linha 0
  lcd.setCursor(10, 0);
  //Escreve a partir da posição de cima a frase Temp C
  lcd.print("Temp C");
  //Inicia o cursos do Display na posição coluna 10 e linha 1
  lcd.setCursor(10, 1);
  //Mostra a partir da posição de cima o valor de temperatura captado do sensor de temperatura e ambiente DHT
  lcd.print(DHT.temperature);
  //Escreve ao lado da temperatura a palavra Celsius com espaço no incio e fim da palavra
  Serial.println(" Celsius  ");

  //Não diminuir o valor abaixo. O ideal é a leitura mínima a cada 2 segundos (Pode Aumentar caso prefira)
  delay(2000);

  //Inicia o cursos do Display na posição coluna 0 e linha 0
  lcd.setCursor(0, 0);
  //Escreve a partir da posição de cima a frase Umidade do Solo
  lcd.print("Umidade do Solo");
  //Inicia o cursos do Display na posição coluna 0 e linha 2
  lcd.setCursor(0, 2);
  //Le o valor do pino A0 do sensor de solo e guarda na variável niveldeUmidade
  niveldeUmidade = analogRead(sensordeSolo);


  //Inicia condição para verificar as condições do solo

  /*Se o solo estiver umido, acende o led verde, apaga os demais leds e acioa o módulo relé para liberar a solenoide
    Obs>=: Deve-se testar o nível de umidade que deseja e alterar os valores após os símbolos de > ou <
  */
  if (niveldeUmidade < 500)
  {
    digitalWrite(ledazul, HIGH);
    digitalWrite(ledamarelo, LOW);
    digitalWrite(ledvermelho, LOW);
    lcd.print("Solo umido");
    digitalWrite(rele, LOW);

  }
  //Fim da condição de solo Umido

  /*Se não estiver umido verifica se o solo estiver moderado, acende o led amarelo, apaga os demais leds e acioa o módulo relé para liberar a solenoide
    Obs>=: Deve-se testar o nível de umidade que deseja e alterar os valores após os símbolos de > ou <
  */  else if (niveldeUmidade > 500 && niveldeUmidade < 700)
  {
    digitalWrite(ledazul, LOW);
    digitalWrite(ledamarelo, HIGH);
    digitalWrite(ledvermelho, LOW);
    lcd.print("Umidade moderada");
    digitalWrite(rele, LOW);
  }
  //Fim da condição de solo moderado

  /*Se não estiver moderado verifica se o solo estiver seco, acende o led vermelho, apaga os demais leds e acioa o módulo relé para liberar a solenoide
    Obs>=: Deve-se testar o nível de umidade que deseja e alterar os valores após os símbolos de > ou <
  */
  else if (niveldeUmidade > 700 && niveldeUmidade < 1023)
  {
    digitalWrite(ledvermelho, HIGH);
    digitalWrite(ledamarelo, LOW);
    digitalWrite(ledazul, LOW);
    lcd.print("Solo seco");
    lcd.setCursor(0, 3);
    lcd.print("Hora de regar");
    delay(2000);
    digitalWrite(rele, HIGH);
  }

  //Fim da condição de solo seco

  //Limpa a tela do LCD
  lcd.clear();

  /*Aguarda 10 segundos até a próxima verificação
    Esse tempo pode ser alterado conforme o desejo de verificação (não deixar abaixo de 2 segundos)
  */
  delay(10000);


}

