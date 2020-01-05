/*
  LCD + Potentiometer
*/

#include <LiquidCrystal.h>

const int rs = 12, enable = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, enable, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  lcd.print("The Continent");
}

void loop() {
  lcd.noDisplay();
  delay(1000);
  lcd.display();
  delay(1000);
}
