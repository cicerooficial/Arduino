#define rele        2 //Pino ligado ao rele
#define sensordeSom A0//Pino ligado ao sensor
int palma; //Variavel para guardar valor do sensor
boolean ligar = HIGH; //Variavel para inverter o ligar e desligar


void setup() {
  pinMode(rele,         OUTPUT); //Define rele como saida
  pinMode(sensordeSom,  INPUT); //Define sensor como entrada
  Serial.begin(9600); //Velocidade de comunicacao Serial
}

void loop() {
  palma = analogRead(sensordeSom); //Le o valor do sensor de Som
  Serial.println(palma); //Mostra no monitor Serial o valor lido
  if (palma >= 100 ) { //Inverte o rele
    ligar = !ligar;
    digitalWrite(rele,  ligar);
    delay(100);
  }
}
