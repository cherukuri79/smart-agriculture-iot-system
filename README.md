# 🌱 Smart Agriculture IoT System

## Overview
This project is a simple smart irrigation system built using Arduino and sensors.  
It automatically waters plants based on soil condition and also shows real-time weather info.

I originally built this in 2018 during my college workshop, and later documented it properly.

---

## What it does
- Turns water pump ON when soil is dry  
- Stops watering when it detects rain  
- Shows temperature and humidity on LCD  
- Sends SMS alerts to farmer (using GSM module)

---

## How it works
Sensors collect data → Arduino checks conditions →  
Then it controls:
- Water pump (via relay)
- LCD display
- SMS alerts

---

## Tech used
- Embedded C++ (Arduino)
- Arduino Uno
- Soil moisture sensor
- DHT11 (temperature & humidity)
- Rain sensor
- 16x2 LCD display
- Relay module
- GSM module (SIM800L)

---

## 💻 Code
See `/arduino/agriculture.ino`

---

## Note
For detailed explanation, check `/docs/system_design.md`

---

## License
MIT License