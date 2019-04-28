//Importa biblioteca SoftwareSerial para comunicação com porta serial
#include <SoftwareSerial.h>
//Define portas a serem criadas para comunicação RX e TX
#define rx        7
#define tx        6
//Define pino da cafeteira à porta 5 digital
#define cafeteira 5

//Cria novas portas Seriais para comunicação bluetooth
SoftwareSerial bluetooth(tx, rx);

void setup() {
  Serial.begin(9600); //Define taxa de comunicação serial
  bluetooth.begin(9600);//Define taxa de comunicação serial também para o bluetooth
  pinMode(cafeteira, OUTPUT);//Define o pino da cafeteira como saída
  digitalWrite(cafeteira, LOW);//Define a cafeteira como desligada
}

void verificaBluetooth() {
  //Se as portas seriais do bluetooth receber algum sinal lê a letra/numero e guarda na variável dados
  if (bluetooth.available()) {
    char dados = bluetooth.read();
    Serial.print(dados); //Mostra a letra que recebeu no monitor Serial
    //Se receber 0 desliga a cafeteira
    if (dados == '0') {
      digitalWrite(cafeteira, LOW);
    }
    //Se reber 1 liga a cafeteira
    else if dados == '1') {
    digitalWrite(cafeteira, HIGH);
    }
  }
}


void loop () {
  verificaBluetooth();
}
