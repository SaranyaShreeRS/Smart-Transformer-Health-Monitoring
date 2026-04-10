#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// -------- DHT --------
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// -------- LCD --------
LiquidCrystal_I2C lcd(0x27, 16, 2);

// -------- PINS --------
int fanPin = 9;
int buttonPin = 3;

int redPin = 8;
int greenPin = 7;

// Sensors
int voltagePin = A0;
int currentPin = A1;
int moisturePin = A3;

// -------- VARIABLES --------
bool faultMode = false;
bool lastButtonState = HIGH;

void setup() {
  lcd.init();
  lcd.backlight();

  dht.begin();

  pinMode(fanPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  // -------- READ BUTTON (FIXED) --------
  bool currentButtonState = digitalRead(buttonPin);

  // Detect press (HIGH → LOW)
  if (lastButtonState == HIGH && currentButtonState == LOW) {
    faultMode = !faultMode;   // TOGGLE mode
    delay(200); // debounce
  }

  lastButtonState = currentButtonState;

  // -------- READ SENSORS --------
  int voltageValue = analogRead(voltagePin);
  int currentValue = analogRead(currentPin);
  int moistureValue = analogRead(moisturePin);
  float temp = dht.readTemperature();

  // -------- NORMAL MODE --------
  if (!faultMode) {

    digitalWrite(greenPin, HIGH);
    digitalWrite(redPin, LOW);
    digitalWrite(fanPin, LOW);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("NORMAL");

    lcd.setCursor(0, 1);
    lcd.print("T:");
    lcd.print(temp);
    lcd.print(" M:");
    lcd.print(moistureValue);

    delay(1000);
  }

  // -------- FAULT MODE --------
  else {

    digitalWrite(greenPin, LOW);
    digitalWrite(redPin, HIGH);
    digitalWrite(fanPin, HIGH);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("FAULT DETECTED");

    lcd.setCursor(0, 1);
    lcd.print("Cooling ON");

    delay(1500);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("V:");
    lcd.print(voltageValue);

    lcd.setCursor(0, 1);
    lcd.print("I:");
    lcd.print(currentValue);

    delay(1500);
  }
}