int pot = 0;
int valPot = 0;

void setup() {
  // put your setup code here, to run once:
  for (int led = 2; led < 14; led++) {
    pinMode(led, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  valPot = analogRead(pot);
  valPot = map(valPot, 0, 1023, 0, 255);

  for (int led = 2; led < 14; led++) {
    digitalWrite(led, HIGH);
    delay(valPot);
    digitalWrite(led, LOW);
  }
  for (int led = 13; led >= 2; led--) {
    digitalWrite(led, HIGH);
    delay(valPot);
    digitalWrite(led, LOW);
  }

}
