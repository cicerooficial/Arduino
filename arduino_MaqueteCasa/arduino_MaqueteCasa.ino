/*
  Projeto: Casa Automatizada SPMAKERWEEK
  Autor:Cícero Henrique
  Data: 19/08/2019
  Descrição: Prorgamação de automação de casa inteligente com Arduino. Com exemplos de automação por sensores e controle de área de uma residência
  utilizando placa Arduino Mega - 2560. O propósito é incentivar o uso da plataforma para atrair público em resolução de problemas reais com uso
  da plataforma Arduino.
*/
//Importação de bibliotecas
#include <Servo.h>
#include <dht.h>

//Define objeto Servo
Servo servoPortavaranda;
//Define objeto dht
dht DHT;

//Definição de portas de sensores
#define sensordeLDR     A0
#define sensordeSom     A1
#define sensorIR        2
#define luzdaVaranda    22
#define luzdoCorredor1  23
#define luzdoCorredor2  24
#define luzdoCorredor3  25
#define apito           26
#define botao           27
#define luzdaSala       30
#define ventilador      33
#define DHT22_PIN       29

//Define contador do sensor
struct {
  uint32_t total;
}
stat = { 0 };

//Definição de variáveis
int valordoSensordeLuz;
int valordoSensorIR;
int posicaoServo;
int contador = 0;
int campainhaApertada;
int palma;
float temperatura;
boolean ligar = HIGH;

void setup() {
  Serial.begin(115200);
  pinMode(luzdaVaranda,     OUTPUT);
  pinMode(luzdoCorredor1,   OUTPUT);
  pinMode(luzdoCorredor2,   OUTPUT);
  pinMode(luzdoCorredor3,   OUTPUT);
  pinMode(apito,            OUTPUT);
  pinMode(luzdaSala,        OUTPUT);
  pinMode(sensorIR,         INPUT);
  pinMode(botao,            INPUT);

  servoPortavaranda.attach(3);
  servoPortavaranda.write(180);

  Serial.println("Humidity (%) | \tTemperature (C)");


  digitalWrite(luzdaVaranda,    LOW);
  digitalWrite(luzdoCorredor1,  LOW);
  digitalWrite(luzdoCorredor2,  LOW);
  digitalWrite(luzdoCorredor3,  LOW);
  digitalWrite(luzdaSala,       LOW);
  digitalWrite(apito,           LOW);

}

void loop() {
  // sensordeLuz();
  // sensordePorta();
  // campainha();
  // sensordePalma();
  sensorDHT();
   //delay(200);
}

/*

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

void sensordePalma() {
  palma = analogRead(sensordeSom); //Le o valor do sensor de Som
  Serial.println(palma); //Mostra no monitor Serial o valor lido
  if (palma >= 100 ) { //Inverte o rele
    ligar = !ligar;
    digitalWrite(luzdaSala,  ligar);
    delay(100);
  }

*/



void sensorDHT() {
    
    // READ DATA
    uint32_t start = micros();
    int chk = DHT.read22(DHT22_PIN);
    uint32_t stop = micros();

    //Contador
    stat.total++;

    // DISPLAY DATA
    Serial.print(DHT.humidity, 1);
    Serial.print("\t\t");
    Serial.print(DHT.temperature, 1);
    Serial.print("\t");
    Serial.println();

    delay(2000);

    temperatura = DHT.temperature;


    if (temperatura >= 25.00) {
      digitalWrite(ventilador, HIGH);
    }
    else if (temperatura < 25.00) {
      digitalWrite(ventilador, LOW);
    }


  }

}
