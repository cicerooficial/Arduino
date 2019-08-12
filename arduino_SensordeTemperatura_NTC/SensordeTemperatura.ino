#include <Thermistor.h> //INCLUSÃO DA BIBLIOTECA

//Variavel sensor de tipo Thermistor ligado ao pino A0
Thermistor sensor(A0);
//variável ligada ao rele do ventilador
#define ventilador  2

void setup() {
  pinMode(ventilador, OUTPUT);//Define o pino do ventilador como saída
  Serial.begin(9600); //Inicia a comunicação Serial em taxa de 9600
  delay(1000); //Pausa 1 segundo
  digitalWrite(ventilador, LOW);//Define o ventilador como desligado
}
void loop() {
  //Variavel temperatura recebe o valor do calcula da funçção getTemp() da biblioteca
  float temperatura = sensor.getTemp();
  Serial.print("Temperatura: "); //Imprime o texto no minitor Serial
  Serial.print(temperatura); //Immprime o valor calculado no monitor Serial
  Serial.println("*C"); //Imprime o texto no minitor Serial
  delay(1000); //Pausa 1 segundo
  if (temperatura >= 28.00) {
    digitalWrite(ventilador, HIGH);//Ascende ventilador
  } else {
    digitalWrite(ventilador, LOW); //Ascende ventilador
  }

}
