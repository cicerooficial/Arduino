#include <SoftwareSerial.h>

#define RX 8
#define TX 9
#define LED 5

SoftwareSerial bluetooth(RX, TX);

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  bluetooth.begin(9600);
}

void verificaBluetooth() {
  if (bluetooth.available()) {
    char dados = bluetooth.read();
    Serial.print(dados);
    if (dados == '0') {
      digitalWrite(LED, LOW);
    }
    else {
      if (dados == '1') {
        digitalWrite(LED, HIGH);
      }
    }
  }
}

void loop () {
  verificaBluetooth();
}

