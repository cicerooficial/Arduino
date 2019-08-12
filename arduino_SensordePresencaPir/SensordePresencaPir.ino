#include <Servo.h>
Servo servo;//Define um nome ao servo motor

#define servo     2 //Pino ligado ao rele
#define pinopir   7 //Pino ligado ao sensor PIR
int acionamento; //Variavel para guardar valor do sensor

void setup() {
  servo.attach(2); // Define o Servo no pino 2.
  pinMode(pinopir,  INPUT); //Define pino sensor como entrada
  Serial.begin(9600); //Velocidade de comunicacao Serial
  servo.write(90);//Posiciona o Servo em 90 graus(Meio)
}

void loop() {
  acionamento = digitalRead(pinopir); //Le o valor do sensor PIR
  Serial.println(acionamento);
  if (acionamento == LOW) { //Sem movimento, mantem rele desligado
    servo.write(90);//Posiciona o Servo em 90 graus(Meio)
    Serial.println("Parado");
  } else { //Caso seja detectado um movimento, aciona o rele
    servo.write(180);//Posiciona o Servo em 180 graus(Esquerda)
    Serial.println("Movimento !!!");
    delay(5000);
  }
}
