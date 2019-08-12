//Carrega a biblioteca SoftwareSerial
#include <SoftwareSerial.h>
char recebido = 0;
#define rele 2

void setup() {
  Serial.begin(9600);
  pinMode(rele, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    recebido = Serial.read();

    if (recebido == 'a') {
      digitalWrite(rele , HIGH);
    }
    if (recebido == 'b') {
      digitalWrite(rele , LOW);
    }
  }
}

