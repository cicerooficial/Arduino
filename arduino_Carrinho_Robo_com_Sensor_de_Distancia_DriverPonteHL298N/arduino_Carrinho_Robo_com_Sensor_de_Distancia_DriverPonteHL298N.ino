#include <Ultrasonic.h>

#define MOTOR_A           1
#define MOTOR_B           2
#define MOTOR_A_PARAR     1
#define MOTOR_B_PARAR     2
#define FRENTE            false
#define TRAS              true
#define PARAR             true
#define pino_trigger      8
#define pino_echo         9

//Variável para contar curvas
int curva = 1;

//Inicializa pinos
Ultrasonic olho(pino_trigger, pino_echo);

void setup() {

  pinMode(4,  OUTPUT);
  pinMode(5,  OUTPUT);
  pinMode(6,  OUTPUT);
  pinMode(7,  OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  Serial.begin(9600);
  Serial.println("Aguarde 10 Segundo ");
  Serial.println("Lendo dados do sensor ");
  for (int contador = 1; contador <= 10; contador += 1) {
    Serial.print(contador);
    Serial.print(" ");
    delay(1000);
  }
  Serial.println(" ");
  Serial.println(" Vamos começar!");
  delay(3000);
}

//Funcao para acionamento individual de cada motor
void acionaMotor(int motor, boolean sentido, int velocidade) {
  //FRENTE MOTOR DIREITA
  if (motor == MOTOR_A) {
    digitalWrite(4, sentido);
    digitalWrite(5, !sentido);
    analogWrite(11, velocidade);
  }
  //FRENTE MOTOR ESQUERDA
  else if (motor == MOTOR_B) {
    digitalWrite(6, sentido);
    digitalWrite(7, !sentido);
    analogWrite(10, velocidade);
  }
  //PARA MOTOR DIREITA
  else if (motor == MOTOR_A_PARAR) {
    digitalWrite(4, sentido);
    digitalWrite(5, sentido);
    analogWrite(11, velocidade);
  }
  //PARA MOTOR ESQUERDA
  else if (motor == MOTOR_B_PARAR) {
    digitalWrite(6, sentido);
    digitalWrite(7, sentido);
    analogWrite(10, velocidade);
  }

}

void loop() {

  float distancia_da_Parede = 10.00;                     //Define a distancia da parede
  float centimetros;                                    //Guarda a conversão em centímetros
  long microsec = olho.timing();                        //Converte e guarda o tempo do sensor
  centimetros = olho.convert(microsec, Ultrasonic::CM); //Guarda a conversão em centimetros
  //Exibe informacoes no serial monitor
  Serial.print("Distancia da Parede em Centimetros: ");
  Serial.println(centimetros);

  /*
    Verifica se a distancia_da_Parede está menor que 5 centimetros e está na curva 1
    Vira para Direita
  */
  if (centimetros <= distancia_da_Parede and curva == 1) {
    Serial.println("Parede Detectada!");
    acionaMotor(MOTOR_A_PARAR, PARAR, 0);
    acionaMotor(MOTOR_B_PARAR, PARAR, 0);
    delay(500);
    while (centimetros <= distancia_da_Parede) {
      acionaMotor(MOTOR_A, TRAS, 50);
      acionaMotor(MOTOR_B, TRAS, 50);
      delay(50);
      Serial.println("Virando para direita!");
      acionaMotor(MOTOR_A, TRAS, 100);
      acionaMotor(MOTOR_B, FRENTE, 100);
      delay(50);
      //Envia sinal para detectar parede
      long microsec = olho.timing();
      centimetros = olho.convert(microsec, Ultrasonic::CM);

    }
    Serial.println("Pista liberada, seguindo em frente!");
    curva = curva + 1;//Conta a primeira curva

  }
  /*
    Verifica se a distancia_da_Parede está menor que 5 centimetros e está na curva 2
    Vira para Esquerda
  */
  else if (centimetros <= distancia_da_Parede and curva == 2) {
    Serial.println("Parede Detectada!");
    acionaMotor(MOTOR_A_PARAR, PARAR, 0);
    acionaMotor(MOTOR_B_PARAR, PARAR, 0);
    delay(500);
    while (centimetros <= distancia_da_Parede) {
      acionaMotor(MOTOR_A, TRAS, 50);
      acionaMotor(MOTOR_B, TRAS, 50);
      delay(50);
      Serial.println("Virando para Esquerda!");
      acionaMotor(MOTOR_A, FRENTE, 100);
      acionaMotor(MOTOR_B, TRAS, 100);
      delay(50);
      //Envia sinal para detectar parede
      long microsec = olho.timing();
      centimetros = olho.convert(microsec, Ultrasonic::CM);
    }
    Serial.println("Pista liberada, seguindo em frente!");
    curva = curva + 1;//Conta a segunda curva

  }
  /*
    Verifica se a distancia_da_Parede está menor que 5 centimetros e está na curva 3
    Vira para Direita
  */
  else if (centimetros <= distancia_da_Parede and curva == 3) {
    Serial.println("Parede Detectada!");
    acionaMotor(MOTOR_A_PARAR, PARAR, 0);
    acionaMotor(MOTOR_B_PARAR, PARAR, 0);
    delay(500);
    while (centimetros <= distancia_da_Parede) {
      acionaMotor(MOTOR_A, TRAS, 50);
      acionaMotor(MOTOR_B, TRAS, 50);
      delay(50);
      Serial.println("Virando para direita!");
      acionaMotor(MOTOR_A, TRAS, 100);
      acionaMotor(MOTOR_B, FRENTE, 100);
      delay(50);
      //Envia sinal para detectar parede
      long microsec = olho.timing();
      centimetros = olho.convert(microsec, Ultrasonic::CM);
    }
    Serial.println("Pista liberada, seguindo em frente!");
    curva = curva + 1;//Conta a terceira curva

  }
  /*
    Verifica se a distancia_da_Parede está menor que 5 centimetros e está na curva 4
    Vira para Direita
  */
  else if (centimetros <= distancia_da_Parede and curva == 4) {
    Serial.println("Parede Detectada!");
    acionaMotor(MOTOR_A_PARAR, PARAR, 0);
    acionaMotor(MOTOR_B_PARAR, PARAR, 0);
    delay(500);
    while (centimetros <= distancia_da_Parede) {
      acionaMotor(MOTOR_A, TRAS, 50);
      acionaMotor(MOTOR_B, TRAS, 50);
      delay(50);
      Serial.println("Virando para direita!");
      acionaMotor(MOTOR_A, TRAS, 100);
      acionaMotor(MOTOR_B, FRENTE, 100);
      delay(50);
      //Envia sinal para detectar parede
      long microsec = olho.timing();
      centimetros = olho.convert(microsec, Ultrasonic::CM);
    }
    Serial.println("Pista liberada, seguindo em frente!");
    curva = curva + 1;//Conta a quarta curva

  }
  /*
    Verifica se a distancia_da_Parede está menor que 5 centimetros e está na curva 5
    Vira para Esquerda
  */
  else if (centimetros <= distancia_da_Parede and curva == 5) {
    Serial.println("Parede Detectada!");
    acionaMotor(MOTOR_A_PARAR, PARAR, 0);
    acionaMotor(MOTOR_B_PARAR, PARAR, 0);
    delay(500);
    while (centimetros <= distancia_da_Parede) {
      acionaMotor(MOTOR_A, TRAS, 50);
      acionaMotor(MOTOR_B, TRAS, 50);
      delay(50);
      Serial.println("Virando para Esquerda!");
      acionaMotor(MOTOR_A, FRENTE, 100);
      acionaMotor(MOTOR_B, TRAS, 100);
      delay(50);
      //Envia sinal para detectar parede
      long microsec = olho.timing();
      centimetros = olho.convert(microsec, Ultrasonic::CM);
    }
    Serial.println("Pista liberada, seguindo em frente!");
    curva = curva + 1;//Conta a quinta curva

  }
  /*
    Verifica se a distancia_da_Parede está menor que 5 centimetros e está na curva 6
    Vira para Direita
  */
  else if (centimetros <= distancia_da_Parede and curva == 6) {
    Serial.println("Parede Detectada!");
    acionaMotor(MOTOR_A_PARAR, PARAR, 0);
    acionaMotor(MOTOR_B_PARAR, PARAR, 0);
    delay(500);
    while (centimetros <= distancia_da_Parede) {
      acionaMotor(MOTOR_A, TRAS, 50);
      acionaMotor(MOTOR_B, TRAS, 50);
      delay(50);
      Serial.println("Virando para direita!");
      acionaMotor(MOTOR_A, TRAS, 100);
      acionaMotor(MOTOR_B, FRENTE, 100);
      delay(50);
      //Envia sinal para detectar parede
      long microsec = olho.timing();
      centimetros = olho.convert(microsec, Ultrasonic::CM);
    }
    Serial.println("Pista liberada, seguindo em frente!");
    curva = curva + 1;//Conta a sesta curva

  }
  /*
    Se não detectar distancia
    Anda para Frente
  */
  else {
    //Anda Carrinho para frente
    Serial.print("Contador " );
    Serial.println(curva);
    Serial.println("Seguindo em Frente!");
    acionaMotor(MOTOR_A, FRENTE, 100);
    acionaMotor(MOTOR_B, FRENTE, 100);

  }

}//Fim Void Loop
