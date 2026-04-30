# 🌱 System Design – Smart Agriculture

## Overview
This system helps automate watering using sensors.  
It checks soil, weather, and rain conditions, and then decides whether to water the plants or not.

---

## How the system is structured

### 1. Sensors
We use:
- Soil sensor → checks if soil is dry or wet  
- DHT11 → gives temperature and humidity  
- Rain sensor → checks if it's raining  

---

### 2. Arduino (main controller)
Arduino reads all sensor values and makes decisions.  
It acts like the brain of the system.

---

### 3. Decision logic
Simple rules are used:

- If soil is dry AND no rain → start watering  
- If soil is wet OR raining → stop watering  

---

### 4. Outputs (all happen together)

#### Water pump
- Controlled using a relay  
- Turns ON/OFF based on conditions  

#### LCD display
- Shows temperature and humidity  
- Helps monitor system without internet  

#### SMS alerts
- Sends message when:
  - Rain is detected  
  - Soil becomes dry  

---

## Data flow
1. Sensors read data  
2. Arduino processes it  
3. Based on conditions:
   - Pump is controlled  
   - LCD is updated  
   - SMS is sent  

---

## Design choices
- Kept it simple so it works reliably  
- Used low-cost components  
- No internet required  

---

## Limitations
- Uses fixed thresholds (not smart/adaptive)  
- No mobile app or dashboard  
- Works best for small setups  

---

## Future improvements
- Add weather API  
- Make it smarter using AI  
- Build a mobile app  
- Improve accuracy  

---

## Summary
This is a basic but complete system where sensors → Arduino → actions.  
It shows how automation can help in simple farming use cases.