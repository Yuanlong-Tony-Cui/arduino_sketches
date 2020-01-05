/*
 LCD + Potentiometer + Ultrasonic Sensor
*/

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int trigPin = 8, echoPin = 9;

long duration;
int distCm;

void setup() {
  lcd.begin(16, 2);
  lcd.print("LCD + US");
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, HIGH);
  delay(1);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distCm = duration * 0.034 / 2;

  lcd.setCursor(0, 1); // Starts on the 2nd line.
  lcd.print("Distance: ");
  lcd.print(distCm);
  lcd.print(" cm");
  lcd.print("                "); // Erases all remaining chars.
  delay(500); // Checks every 500 ms.
}
