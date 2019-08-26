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
#define sensorMQ2       A2
#define sensorUmidade   A3
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
#define pinoPir         37
#define banheiro        41
#define umidadeBaixa    42              //LED UMIDADE BAIXA
#define umidadeMedia    44              //LED UMIDADE MEDIA
#define umidadeAlta     46              //LED UMIDADE ALTA

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
int acionamento;
float temperatura;
boolean ligar = HIGH;
int limitedoSensordeGAS = 300;                      //DEFININDO UM VALOR LIMITE (NÍVEL DE GÁS NORMAL)
long ultimoTempo = 0;
long intervalodeTempoSensorPalma = 200;

void setup() {
  Serial.begin(9600);
  pinMode(luzdaVaranda,     OUTPUT);
  pinMode(luzdoCorredor1,   OUTPUT);
  pinMode(luzdoCorredor2,   OUTPUT);
  pinMode(luzdoCorredor3,   OUTPUT);
  pinMode(apito,            OUTPUT);
  pinMode(luzdaSala,        OUTPUT);
  pinMode(ventilador,       OUTPUT);
  pinMode(banheiro,         OUTPUT);
  pinMode(sensorIR,         INPUT);
  pinMode(botao,            INPUT);
  pinMode(sensorMQ2,        INPUT);                 //DEFINE O PINO DO SENSOR COMO ENTRADA
  pinMode(sensorUmidade,    INPUT);             //DEFINE O PINO DO SENSOR COMO ENTRADA
  pinMode(umidadeBaixa,     OUTPUT);
  pinMode(umidadeMedia,     OUTPUT);
  pinMode(umidadeAlta,      OUTPUT);
  pinMode(pinoPir,          INPUT);
  pinMode(sensordeSom,      INPUT);

  servoPortavaranda.attach(3);
  servoPortavaranda.write(180);

  Serial.println("Umidade (%) | \tTemperatura (C)");

  digitalWrite(luzdaVaranda,    LOW);
  digitalWrite(luzdoCorredor1,  LOW);
  digitalWrite(luzdoCorredor2,  LOW);
  digitalWrite(luzdoCorredor3,  LOW);
  digitalWrite(luzdaSala,       LOW);
  digitalWrite(apito,           LOW);
  digitalWrite(ventilador,      LOW);
  digitalWrite(banheiro,        LOW);

}

void loop() {
  unsigned long tempoAtual = millis();

  if (tempoAtual - ultimoTempo > intervalodeTempoSensorPalma) {
    ultimoTempo = tempoAtual;
    sensordeGAS();
    sensordeLuz();
    sensordePorta();
    campainha();
    sensorDHT();
    sensorMovimento();
    sensordeGAS();
    sensordeUmidadeSolo();
  }
  sensordePalma();

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

void sensordePalma() {

  palma = analogRead(sensordeSom); //Le o valor do sensor de Som
  Serial.println(palma); //Mostra no monitor Serial o valor lido

  if (palma > 200 ) {
    ligar = !ligar;
    digitalWrite(luzdaSala,  ligar);
    delay(200);
  }


}

void sensorDHT() {

  // Lê os dados so sensor de temperatura e umidade
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

  temperatura = DHT.temperature;

  if (temperatura >= 25.00) {
    digitalWrite(ventilador, HIGH);
  }
  else if (temperatura < 25.00) {
    digitalWrite(ventilador, LOW);
  }
}

void sensorMovimento() {
  acionamento = digitalRead(pinoPir); //Le o valor do sensor PIR
  Serial.println(acionamento);

  if (acionamento == LOW) { //Sem movimento, mantem rele desligado
    digitalWrite(banheiro, LOW);
  } else { //Caso seja detectado um movimento, aciona o rele
    digitalWrite(banheiro, HIGH);
  }
}

void  sensordeGAS() {
  Serial.print("Nível de Gás Ambiente: ");             //EXIBE O TEXTO NO MONITOR SERIAL
  Serial.println(analogRead(sensorMQ2));               //MOSTRA NO MONITOR SERIAL O VALOR LIDO DO PINO ANALÓGICO
  if (analogRead(sensorMQ2) > limitedoSensordeGAS) {   //SE VALOR LIDO NO PINO ANALÓGICO FOR MAIOR QUE O VALOR LIMITE, FAZ
    digitalWrite(apito, HIGH);                         //ATIVA O BUZZER E O MESMO EMITE O SINAL SONORO
  } else {                                             //SENÃO, FAZ
    digitalWrite(apito, LOW);                          //BUZZER DESLIGADO
  }
  //  delay(100);                                          //INTERVALO DE 100 MILISSEGUNDOS
}

void sensordeUmidadeSolo() {
  int valorUmidade;               //VARIÁVEL QUE ARMAZENA O PERCENTUAL DE UMIDADE DO SOLO
  int umidadeMin = 600;           //VALOR MEDIDO COM O SOLO SECO
  int umidadeMax = 900;           //VALOR MEDIDO COM O SOLO ENXARCADO

  valorUmidade = constrain(analogRead(sensorUmidade), umidadeMin , umidadeMax); //MANTÉM valorUmidade DENTRO DO INTERVALO
  valorUmidade = map(valorUmidade, umidadeMin, umidadeMax, 100, 0);             //EXECUTA A FUNÇÃO "map" DE ACORDO COM OS PARÂMETROS PASSADOS
  Serial.print("Umidade do solo: ");                                            //IMPRIME O TEXTO NO MONITOR SERIAL
  Serial.print(valorUmidade);                                                    //IMPRIME NO MONITOR SERIAL O PERCENTUAL DE UMIDADE DO SOLO
  Serial.println("%");                                                          //IMPRIME O CARACTERE NO MONITOR SERIAL
  //delay(100);

  if (valorUmidade < 30) {
    digitalWrite(umidadeBaixa, HIGH);
    digitalWrite(umidadeMedia, LOW);
    digitalWrite(umidadeAlta, LOW);
  }
  else if (valorUmidade > 30 && valorUmidade < 70) {
    digitalWrite(umidadeMedia, HIGH);
    digitalWrite(umidadeBaixa, LOW);
    digitalWrite(umidadeAlta, LOW);
  }
  else if (valorUmidade > 70) {
    digitalWrite(umidadeAlta, HIGH);
    digitalWrite(umidadeBaixa, LOW);
    digitalWrite(umidadeMedia, LOW);
  }
}
