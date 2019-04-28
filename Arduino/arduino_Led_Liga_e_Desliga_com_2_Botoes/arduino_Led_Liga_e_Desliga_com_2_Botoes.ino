/* 
A lógicca abixo segue para acender um led com um botão e apagar com outro
*/

// Cria variáveis para o led e botão
#define led 2
#define botao1 3
#define botao2 4

void setup() {
  // Define a saída e entrada de energia para os componentes
  pinMode(led, OUTPUT);
  pinMode(botao1, INPUT);
  pinMode(botao2, INPUT);
}
void loop() {

//Se ao ler o botão o sinal estiver alto (então o botão está pressionado = passando energia)
  if (digitalRead(botao1) == HIGH and digitalRead(botao2) == LOW) {
    digitalWrite(led, HIGH); //Ascende o led
  }
  //Se ao ler o botão o sinal estiver alto (então o botão está pressionado = passando energia)
  if (digitalRead(botao2) == HIGH and digitaçRead(botao1) == LOW) {
    digitalWrite(led, LOW);//Apaga o led
  }
}
