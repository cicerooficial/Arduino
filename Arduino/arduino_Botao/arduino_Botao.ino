int led = 2;
int botao = 4;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(botao, INPUT);
}
void loop() {

  if (digitalRead(botao) == HIGH) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}

