#include <Servo.h>

Servo servo;//Define um nome ao servo motor

void setup() {
  servo.attach(2); // Define o Servo no pino 2.
}

void loop() {
  servo.write(90);//Posiciona o Servo em 90 graus(Meio)
  delay(1000);

  servo.write(0); //Posiciona o Servo em 0 graus(Direita)
  delay(1000);

  servo.write(180); //Posiciona o Servo em 180 graus(Esquerda)
  delay(1000);

  /*
    for (int gira = 0; gira <= 180; gira++) {
      servo.write(gira);
      delay(50);
    }
  */

}

