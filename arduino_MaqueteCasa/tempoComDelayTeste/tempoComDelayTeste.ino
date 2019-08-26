long ultimoTempo = 0;
long intervalodeTempo = 500;
#define led13 13

int estadoLed = LOW;

void setup() {
  Serial.begin(115200);
}

void loop() {
  unsigned long tempoAtual = millis();

  if (tempoAtual - ultimoTempo > intervalodeTempo) {
    ultimoTempo = tempoAtual;
    Serial.println("Bateu o tempo");
  }
  
  if (estadoLed == LOW) {
    estadoLed = HIGH;
  } else {
    estadoLed = LOW;
  }
  digitalWrite(led13, estadoLed);

}
