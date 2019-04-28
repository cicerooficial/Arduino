#define ledOlhoDireita 2
#define ledOlhoEsquerda 3

#include <AFMotor.h>

AF_DCMotor rodadireita(1);
AF_DCMotor rodaesquerda(2);
AF_DCMotor rodadireita2(4);
AF_DCMotor rodaesquerda2(3);


void setup() {
  rodadireita.setSpeed(255);
  rodaesquerda.setSpeed(255);
  rodadireita2.setSpeed(255);
  rodaesquerda2.setSpeed(255);
  pinMode(ledOlhoDireita, OUTPUT);
  pinMode(ledOlhoEsquerda, OUTPUT);

  for (int pisca = 0; pisca < 5; pisca++) {
    digitalWrite(ledOlhoDireita, HIGH);
    digitalWrite(ledOlhoEsquerda, HIGH);
    delay(200);
    digitalWrite(ledOlhoEsquerda, LOW);
    digitalWrite(ledOlhoEsquerda, LOW);
    delay(200);
  }
  digitalWrite(ledOlhoDireita, HIGH);
  digitalWrite(ledOlhoEsquerda, HIGH);

}

void loop () {

  rodadireita.run(FORWARD);
  rodaesquerda.run(FORWARD);
  rodadireita2.run(FORWARD);
  rodaesquerda2.run(FORWARD);
  delay(2000);

  rodadireita.run(FORWARD);
  rodaesquerda.run(BACKWARD);
  rodadireita2.run(FORWARD);
  rodaesquerda2.run(FORWARD);
  delay(2000);

  rodadireita.run(BACKWARD);
  rodaesquerda.run(FORWARD);
  rodadireita2.run(BACKWARD);
  rodaesquerda2.run(BACKWARD);
  delay(2000);

  rodadireita.run(BACKWARD);
  rodaesquerda.run(BACKWARD);
  rodadireita2.run(BACKWARD);
  rodaesquerda2.run(BACKWARD);
  delay(2000);

}



