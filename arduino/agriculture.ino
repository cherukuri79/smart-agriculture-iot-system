#include <DHT.h>
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

// ---------------- DHT11 ----------------
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// ---------------- Pins ----------------
const int soilPin = A0;
const int rainPin = A1;
const int relayPin = 7;

// ---------------- LCD ----------------
LiquidCrystal lcd(12, 11, 5, 4, 3, 6);

// ---------------- GSM ----------------
SoftwareSerial gsm(9, 10); // RX, TX

// ---------------- Buffers ----------------
char line1[17];
char line2[17];

// ---------------- Thresholds ----------------
int soilThreshold = 500;
int rainThreshold = 400;

// ---------------- Flags ----------------
bool rainAlertSent = false;
bool dryAlertSent = false;

// ---------------- Phone ----------------
String phoneNumber = "+10000000000"; // Placeholder

// ---------------- Setup ----------------
void setup() {
  Serial.begin(9600);
  gsm.begin(9600);

  dht.begin();
  lcd.begin(16, 2);

  pinMode(relayPin, OUTPUT);

  lcd.print("Smart Agri Sys");
  delay(2000);
  lcd.clear();
}

// ---------------- SMS Function ----------------
void sendSMS(String message) {
  gsm.println("AT+CMGF=1"); // Text mode
  delay(1000);

  gsm.println("AT+CMGS=\"" + phoneNumber + "\"");
  delay(1000);

  gsm.print(message);
  delay(500);

  gsm.write(26); // CTRL+Z
  delay(3000);
}

// ---------------- Loop ----------------
void loop() {
  int soilValue = analogRead(soilPin);
  int rainValue = analogRead(rainPin);

  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  // Error handling
  if (isnan(temp) || isnan(hum)) {
    lcd.clear();
    lcd.print("Sensor Error");
    Serial.println("DHT Error");
    delay(2000);
    return;
  }

  // ---------------- Logic ----------------
  bool isSoilDry = soilValue < soilThreshold;
  bool isRaining = rainValue < rainThreshold;

  // ---------------- Irrigation ----------------
  if (isSoilDry && !isRaining) {
    digitalWrite(relayPin, HIGH);  // Pump ON
  } else {
    digitalWrite(relayPin, LOW);   // Pump OFF
  }

  // ---------------- SMS Alerts ----------------

  // Rain alert
  if (isRaining && !rainAlertSent) {
    sendSMS("Alert: Rain detected. Irrigation stopped.");
    rainAlertSent = true;
  }

  if (!isRaining) {
    rainAlertSent = false;
  }

  // Soil dry alert
  if (isSoilDry && !dryAlertSent) {
    sendSMS("Alert: Soil is dry. Irrigation started.");
    dryAlertSent = true;
  }

  if (!isSoilDry) {
    dryAlertSent = false;
  }

  // ---------------- LCD Display ----------------
  sprintf(line1, "Temp: %.1f C", temp);
  sprintf(line2, "Hum: %.1f %%", hum);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(line1);

  lcd.setCursor(0, 1);
  lcd.print(line2);

  // ---------------- Debug ----------------
  Serial.print("Soil: ");
  Serial.print(soilValue);
  Serial.print(" | Rain: ");
  Serial.print(rainValue);
  Serial.print(" | Temp: ");
  Serial.print(temp);
  Serial.print(" | Hum: ");
  Serial.println(hum);

  delay(3000);
}