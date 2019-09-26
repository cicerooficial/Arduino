/*
  Projeto:Automação de Iluminação, Projeto SPMAKERWEEK29
  Autor: Cícero Henrique
  Data: 12/08/2019
  Descrição: O desenvolvimento abaixo é parte de um projeto colaborativo entre rede pública de laboratórios Fab Lab LIVRE SP,
  para o evento SPMAKERWEEK2019 com tema Cidades Inteligentes. 
*/

//Define portas dos Potenciometros
#define potenciometro1 A0

//Cria variaveis para armazenar os valores dos potenciometros para intensidade e velocidade
int velocidadePotenciometro;

void setup() {

  //Faz um loop de repetição para formata os pinos de 2 à 9 como saida de energia (OUTPUT)
  for (int contador = 2; contador <= 11; contador++) {
    pinMode(contador, OUTPUT);
  }

}

void loop() {

  velocidadePotenciometro = analogRead(potenciometro1);
  velocidadePotenciometro = map(velocidadePotenciometro, 0, 1023, 0, 1000);

  //CONTROLE DE IDA E VOLTA E VELOCIDADE

  //IDA
  for (int contador = 2; contador <= 11; contador++) {
    analogWrite(contador, HIGH);
    delay(velocidadePotenciometro);
    analogWrite(contador, LOW);
    delay(velocidadePotenciometro);
  }
  
  //Faz loop de repetição das fitas de led passando de uma em uma ida e volta com valores a partir das posições já convertidas dos potenciometros
  //VOLTA
  for (int contador = 11; contador >= 2; contador--) {

    analogWrite(contador, HIGH);
    delay(velocidadePotenciometro);
    analogWrite(contador, LOW);
    delay(velocidadePotenciometro);
  }
  
}
