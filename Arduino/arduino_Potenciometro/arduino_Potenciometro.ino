//Define as variáveis e seus valores
int pot = 0;
int led = 3;
int valPot = 0;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {

  valPot =  analogRead(pot); //Faz a leitura analógica no pino do potenciômetro

  valPot = map(valPot, 0, 1023, 0, 255); //Utilizando a função map() para transformar uma escala de 0-1023 em uma escala 0 a 255

  analogWrite(led, valPot ); // Aciona o LED proporcionalmente ao valor da leitura analógica

}

