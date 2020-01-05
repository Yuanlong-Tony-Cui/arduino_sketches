/*
 LCD + Potentiometer + Ultrasonic Sensor + LED
*/

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int trigPin = 8, echoPin = 9;
const int ledPin = 13;

long duration;
int distCm;

void ledBlink(int numMs) {
  digitalWrite(ledPin, HIGH);
  delay(numMs*10);
  digitalWrite(ledPin, LOW);
  delay(numMs*10);
}

void setup() {
  lcd.begin(16, 2);
  lcd.print("LCD + US + LED");
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
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

  ledBlink(distCm);
  
  // delay(500); // Checks every 500 ms.
}
