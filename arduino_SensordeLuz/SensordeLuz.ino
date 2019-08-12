#define sensordeLuz     A0
#define lampadaSala     3
#define lampadaCozinha  4
#define lampadaQuarto   5
int brilhodaLuz;


void setup() {
  //Define os pinos da slampadas como saída
  pinMode(lampadaSala,    OUTPUT);
  pinMode(lampadaCozinha, OUTPUT);
  pinMode(lampadaQuarto,  OUTPUT);
  //Define as lampadas como desligadas
  digitalWrite(lampadaSala,     LOW);
  digitalWrite(lampadaCozinha,  LOW);
  digitalWrite(lampadaQuarto,   LOW);
  Serial.begin(9600);
}//Fim do Setup


void loop() {
  //Lê o brilho de luz atual e guarda o valor n a variavel
  brilhodaLuz = analogRead(sensordeLuz);
  Serial.println(brilhodaLuz);
  //Se tiver escuro, ascende as luzes
  if (brilhodaLuz > 700) {
    digitalWrite(lampadaSala,     HIGH);
    digitalWrite(lampadaCozinha,  HIGH);
    digitalWrite(lampadaQuarto,   HIGH);
    Serial.println("Lampadas Liagdas!");
  } else {
    digitalWrite(lampadaSala,     LOW);
    digitalWrite(lampadaCozinha,  LOW);
    digitalWrite(lampadaQuarto,   LOW);
    Serial.println("Lampadas Liagdas!");
  }
}//Fim do Loop
