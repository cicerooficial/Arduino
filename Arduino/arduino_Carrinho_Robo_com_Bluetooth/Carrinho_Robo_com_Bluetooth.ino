/*
  Projeto: Carrinho Robô com Arduino
  Autor: Cícero Henrique
  Descrição: Código simples para uso em oficina de introdução à robótica com arduino.
  Utilizando Arduino, Shiled Ponte H L293 (para 4 motores) e Módulo Bluetooth
  Data: 14/01/219
*/


//Inclui biblioteca de comunicação Serial
#include <SoftwareSerial.h>
//Inicia uma nova prota d ecomunicação Serial (pois a 0 e 1 já está sendo usada pela shield) primeiro numero de porta para TX e segundo para RX
//                         TX, RX
SoftwareSerial MinhaSerial(14, 15);
//Inclui biblioteca para comunicação da Shield com os motores
#include <AFMotor.h>
//Instancia 2 motores indicando as suas conexões
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
//Inicia um varivável que irá guardar as letras/numeros recebidos pelo bluetooth
char valorRecebido;

void setup()
{
  //inicia a taxa de comunicação serial padrão
  Serial.begin(9600);
  MinhaSerial.begin(9600);
  //Defini as velocidade dos motores Min. 0 - 255 Max.
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  //Inicializa com os motores desligados
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}

void loop()
{
  //verifica se recebeu algum dado
  if (MinhaSerial.available() > 0) {
    //Se recebido algum dado, lê e guarda na variável
    valorRecebido = MinhaSerial.read();
    //Caso seja recebido 1, gira os dois motores para frente
    if (valorRecebido == '1')
    {
      motor1.run(FORWARD);
      motor2.run(FORWARD);
      MinhaSerial.println("Motores para frente");
    }
    //Caso seja recebido 2, gira os dois motores para frente
    if (valorRecebido == '2')
    {
      motor1.run(BACKWARD);
      motor2.run(BACKWARD);
      MinhaSerial.println("Motores para tras");
    }
    //Caso seja recebido 3, gira os dois motores para frente
    if (valorRecebido == '3')
    {
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      MinhaSerial.println("Motores para para");
    }

  }
}
