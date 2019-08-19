/*
 *Projeto: Casa Automatizada SPMAKERWEEK 
 *Autor:Cícero Henrique
 *Data: 19/08/2019
 *Descrição: Prorgamação de automação de casa inteligente com Arduino. Com exemplos de automação por sensores e controle de área de uma residência 
 *utilizando placa Arduino Mega - 2560. O propósito é incentivar o uso da plataforma para atrair público em resolução de problemas reais com uso
 *da plataforma Arduino.
 */
//Importação de bibliotecas
#include <Servo.h>

//Define objetos
Servo servoPortavaranda;

//Definição de portas de sensores
#define sensordeLDR A0
#define luzdaVaranda 22
#define luzdoCorredor1 23
#define luzdoCorredor2 24
#define luzdoCorredor3 25
#define apito 26
#define botao 27
#define sensorIR 2

//Definição de variáveis
int valordoSensordeLuz;
int valordoSensorIR;
int posicaoServo;
int contador = 0;
int campainhaApertada;

void setup() {
  Serial.begin(9600);
  pinMode(luzdaVaranda, OUTPUT);
  pinMode(luzdoCorredor1, OUTPUT);
  pinMode(luzdoCorredor2, OUTPUT);
  pinMode(luzdoCorredor3, OUTPUT);
  pinMode(apito, OUTPUT);
  pinMode(sensorIR, INPUT);
  pinMode(botao, INPUT);

  servoPortavaranda.attach(3);
  servoPortavaranda.write(180);

  digitalWrite(luzdaVaranda, LOW);
  digitalWrite(luzdoCorredor1, LOW);
  digitalWrite(luzdoCorredor2, LOW);
  digitalWrite(luzdoCorredor3, LOW);
  digitalWrite(apito, LOW);

}

void loop() {
  sensordeLuz();
  sensordePorta();
  campainha();
  //delay(200);
}

void sensordeLuz() {
  valordoSensordeLuz = analogRead(sensordeLDR);
  Serial.println(valordoSensordeLuz);

  if ( valordoSensordeLuz >= 800 ) {
    digitalWrite(luzdaVaranda, LOW);
    digitalWrite(luzdoCorredor1, LOW);
    digitalWrite(luzdoCorredor2, LOW);
    digitalWrite(luzdoCorredor3, LOW);
    Serial.println("Luz da varanda está apagada!");
  }
  else if (valordoSensordeLuz < 800) {
    digitalWrite(luzdaVaranda, HIGH);
    digitalWrite(luzdoCorredor1, HIGH);
    digitalWrite(luzdoCorredor2, HIGH);
    digitalWrite(luzdoCorredor3, HIGH);
    Serial.println("Luz da varanda está Ligada!");
  }

}

void sensordePorta() {
  //Le as informações do sensor Infravermelho
  valordoSensorIR = digitalRead(sensorIR);
  Serial.println(valordoSensorIR);

  if (valordoSensorIR == 0) //Verifica se o objeto foi detectado
    contador = contador + 1;

  // Serial.println(contador);
  if (contador == 1) {
    Serial.println("Porta da varada está aberta!");
    servoPortavaranda.write(75);
    delay(1000);
  }
  else if (contador == 2) {
    Serial.println("Porta da varada está fechada!");
    servoPortavaranda.write(180);
    delay(1000);
    contador = 0;
  }

}

void campainha() {

  campainhaApertada = digitalRead(botao);
  Serial.println(campainhaApertada);
  if (campainhaApertada == HIGH) {
    digitalWrite(apito, HIGH);
  }
  else if (campainhaApertada == LOW) {
    digitalWrite(apito, LOW);
  }
}