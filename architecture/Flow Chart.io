                         ┌───────────────────────────────┐
                         │        SENSOR LAYER           │
                         ├───────────────────────────────┤
                         │ Soil Moisture Sensor          │
                         │ DHT11 (Temp & Humidity)       │
                         │ Rainfall Sensor               │
                         └───────────────┬───────────────┘
                                         ↓
                         ┌───────────────────────────────┐
                         │     EDGE CONTROLLER LAYER     │
                         │        (Arduino Uno)          │
                         ├───────────────────────────────┤
                         │ - Sensor Data Collection      │
                         │ - Analog/Digital Processing   │
                         │ - Signal Conditioning         │
                         └───────────────┬───────────────┘
                                         ↓
                         ┌───────────────────────────────┐
                         │     DECISION LOGIC LAYER      │
                         ├───────────────────────────────┤
                         │ - Irrigation Decision         │
                         │ - Rain Condition Check        │
                         │ - Threshold Evaluation        │
                         │ - Temperature Monitoring      │
                         └───────┬───────────┬───────────┘
                                 ↓           ↓           ↓

     ┌──────────────────────┐   ┌──────────────────────┐   ┌────────────────────────┐
     │   ACTUATION LAYER    │   │   DISPLAY LAYER      │   │  NOTIFICATION LAYER    │
     ├──────────────────────┤   ├──────────────────────┤   ├────────────────────────┤
     │ Relay Module         │   │ 16x2 LCD Display     │   │ SMS Alert System       │
     │ Water Pump           │   │ Temp & Humidity      │   │ Farmer Notification    │
     └───────────┬──────────┘   └───────────┬──────────┘   └───────────┬────────────┘
                 ↓                          ↓                          ↓

     ┌──────────────────────┐   ┌──────────────────────┐   ┌────────────────────────┐
     │   Water Irrigation   │   │ Real-time Display    │   │ Farmer Mobile Device   │
     │   (Sprinkler Flow)   │   │ (Field Monitoring)   │   │ (SMS Alerts)           │
     └──────────────────────┘   └──────────────────────┘   └────────────────────────┘