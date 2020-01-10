/*
 LCD + Potentiometer + Ultrasonic Sensor + LED
*/

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int trigPin = 8, echoPin = 9;
const int ledPin = 13;
const int buzzerPin = 6;
long duration;
int distCm;
int brightness;
int frequency;

int getDist(long period) {
  return period * 0.034 / 2;
}

void displayDist(int dist) {
  lcd.setCursor(0, 1); // Starts on the 2nd line.
  lcd.print("Distance: ");
  lcd.print(distCm);
  lcd.print(" cm");
  lcd.print("                "); // Erases all remaining chars.
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
  delayMicroseconds(100);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distCm = getDist(duration);

  // Handle out-of-range scenarios:
  if (distCm > 400) {
    distCm = 400;
  }
  if (distCm < 2) {
    distCm = 2;
  }

  displayDist(distCm);

  brightness = map(distCm, 400, 2, 0, 255);
  analogWrite(ledPin, brightness);

  frequency = map(distCm, 400, 2, 100, 1000);
  tone(buzzerPin, frequency);
  
  delay(100); // Checks every 100 ms.
}
