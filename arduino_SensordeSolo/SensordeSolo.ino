//Define portas a serem usadas
#define sensordeSolo  A0
#define ledVermelho   2
#define ledAmarelo    3
#define ledVerde      4
#define apito     5
//Variavel para recever o valor de umidade
float niveldeUmidade;

void setup(){
  Serial.begin(9600); //taxa de comunicação Serial
  //Define pinos como saída
  pinMode(ledVermelho,  OUTPUT);
  pinMode(ledAmarelo,   OUTPUT);
  pinMode(ledVerde,     OUTPUT);
  pinMode(apito,        OUTPUT);
  //Define pinos como desligados
  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledAmarelo,  LOW);
  digitalWrite(ledVerde,    LOW);
  digitalWrite(apito,       LOW);
}

void loop(){
  //Le o valor do pino A0 do sensor
  niveldeUmidade = analogRead(sensordeSolo);
  //Mostra o valor da porta analogica no serial monitor
  Serial.print("Nível de Umdiade: ");
  Serial.print(niveldeUmidade);

  //Solo umido, acende o led verde e desliga os demais
  if (niveldeUmidade >= 800 && niveldeUmidade < 1024) {
    Serial.println(" Status: Solo umido");
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo,  LOW);
    digitalWrite(apito,       LOW);
  }

  //Solo com umidade moderada, acende led amarelo e desliga os demais
  else if (niveldeUmidade >= 400 && niveldeUmidade < 800) {
    Serial.println(" Status: Umidade moderada");
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledVerde,    LOW);
    digitalWrite(apito,       LOW);
  }

  //Solo seco, acende led vermelho, o apito e desliga os demais
  else if (niveldeUmidade > 0 && niveldeUmidade < 400) {
    Serial.println(" Status: Solo seco");
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(apito,       HIGH);
    digitalWrite(ledAmarelo,  LOW);
    digitalWrite(ledVerde,    LOW);
  }
  delay(100);
}
