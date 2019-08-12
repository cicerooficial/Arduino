/*
********************************************************************************
  Autor:Cícero Henrique
  Data:26/07/2019
  Descrição:Teste com módulo I2C e LCD 20X4 com efeito escrevendo

  Links de Ajuda:
  https://www.arduino.cc/en/Reference/LiquidCrystal
  https://www.arduinoecia.com.br/2014/12/modulo-i2c-display-16x2-arduino.html
  http://blog.baudaeletronica.com.br/conhecendo-biblioteca-liquidcrystal/
********************************************************************************
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
int tempo = 65;//Define uma vaeriável para tempo do delay
// Inicializa o display no endereco 0x27
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup()
{
  lcd.begin (20, 4); //Define qual tamanho do Display
}

void loop()
{
  lcd.setBacklight(HIGH);//Ascende Display
  lcd.setCursor(1, 0); //Inicia cursor na primeira linha
  //Define letra iniciar na segunda coluna, cursor pisca e um delay para a próxima letra
  lcd.print("F");  lcd.blink(); delay(tempo);
  lcd.setCursor(2, 0);
  lcd.print("a");  lcd.blink(); delay(tempo);
  lcd.setCursor(3, 0);
  lcd.print("b");  lcd.blink(); delay(tempo);
  lcd.setCursor(4, 0);
  lcd.print(" ");  lcd.blink(); delay(tempo);
  lcd.setCursor(5, 0);
  lcd.print("L");  lcd.blink(); delay(tempo);
  lcd.setCursor(6, 0);
  lcd.print("a");  lcd.blink(); delay(tempo);
  lcd.setCursor(7, 0);
  lcd.print("b");  lcd.blink(); delay(tempo);
  lcd.setCursor(8, 0);
  lcd.print(" ");  lcd.blink(); delay(tempo);
  lcd.setCursor(9, 0);
  lcd.print("L");  lcd.blink(); delay(tempo);
  lcd.setCursor(10, 0);
  lcd.print("I");  lcd.blink(); delay(tempo);
  lcd.setCursor(11, 0);
  lcd.print("V");  lcd.blink(); delay(tempo);
  lcd.setCursor(12, 0);
  lcd.print("R");  lcd.blink(); delay(tempo);
  lcd.setCursor(13, 0);
  lcd.print("E");  lcd.blink(); delay(tempo);
  lcd.setCursor(14, 0);
  lcd.print(" ");  lcd.blink(); delay(tempo);
  lcd.setCursor(15, 0);
  lcd.print("S");  lcd.blink(); delay(tempo);
  lcd.setCursor(16, 0);
  lcd.print("P");  lcd.blink(); delay(tempo);
  lcd.setCursor(17, 0);
  lcd.print("!");  lcd.blink(); delay(tempo);
  delay(1000);//espera 1 segundo
  lcd.setCursor(2, 1); lcd.blink(); delay(tempo);
  lcd.print("V");
  lcd.setCursor(3, 1); lcd.blink(); delay(tempo);
  lcd.print("e");
  lcd.setCursor(4, 1); lcd.blink(); delay(tempo);
  lcd.print("m");
  lcd.setCursor(5, 1); lcd.blink(); delay(tempo);
  lcd.print(" ");
  lcd.setCursor(6, 1); lcd.blink(); delay(tempo);
  lcd.print("a");
  lcd.setCursor(7, 1); lcd.blink(); delay(tempo);
  lcd.print("p");
  lcd.setCursor(8, 1); lcd.blink(); delay(tempo);
  lcd.print("r");
  lcd.setCursor(9, 1); lcd.blink(); delay(tempo);
  lcd.print("e");
  lcd.setCursor(10, 1); lcd.blink(); delay(tempo);
  lcd.print("n");
  lcd.setCursor(11, 1); lcd.blink(); delay(tempo);
  lcd.print("d");
  lcd.setCursor(12, 1); lcd.blink(); delay(tempo);
  lcd.print("e");
  lcd.setCursor(13, 1); lcd.blink(); delay(tempo);
  lcd.print("r");
  lcd.setCursor(14, 1); lcd.blink(); delay(tempo);
  lcd.print(".");
  lcd.setCursor(15, 1); lcd.blink(); delay(tempo);
  lcd.print(".");
  lcd.setCursor(16, 1); lcd.blink(); delay(tempo);
  lcd.print(".");
  delay(1000);
  lcd.setCursor(5, 3); lcd.blink(); delay(tempo);
  lcd.print("A");
  lcd.setCursor(6, 3); lcd.blink(); delay(tempo);
  lcd.print("r");
  lcd.setCursor(7, 3); lcd.blink(); delay(tempo);
  lcd.print("d");
  lcd.setCursor(8, 3); lcd.blink(); delay(tempo);
  lcd.print("u");
  lcd.setCursor(9, 3); lcd.blink(); delay(tempo);
  lcd.print("i");
  lcd.setCursor(10, 3); lcd.blink(); delay(tempo);
  lcd.print("n");
  lcd.setCursor(11, 3); lcd.blink(); delay(tempo);
  lcd.print("o");
  lcd.setCursor(12, 3); lcd.blink(); delay(tempo);
  lcd.print(" ");
  lcd.setCursor(13, 3); lcd.blink(); delay(tempo);
  lcd.print(":");
  lcd.setCursor(14, 3); lcd.blink(); delay(tempo);
  lcd.print(")");
  lcd.setCursor(15, 3); lcd.blink(); delay(tempo);
  delay(1000);
  lcd.clear();//LImpa o display
  //lcd.setBacklight(LOW);//apaga o display
  //delay(1000);
}
