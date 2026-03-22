#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define TRIG 9
#define ECHO 10

LiquidCrystal_I2C lcd(0x27, 16, 2);

bool aiTriggered = false;

void setup() {
  Serial.begin(9600);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("AIDB");
}

long getDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH, 30000);
  if (duration == 0) return -1;
  return duration * 0.034 / 2;
}

void loop() {
  long d = getDistance();

  // Hand detected → tell Pi ONCE
  if (d > 0 && d < 20 && !aiTriggered) {
    aiTriggered = true;
    Serial.println("CAPTURE");
  }

  // Listen for Pi response
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();

    if (cmd == "DROP") {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("DROP");
    }
  }

  // Reset when hand goes away
  if (d > 40) {
    aiTriggered = false;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("AIDB");
  }

  delay(200);
}