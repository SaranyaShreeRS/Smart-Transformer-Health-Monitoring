⚡ Smart Transformer Health Monitoring System

## 📖 Overview
The Smart Transformer Health Monitoring System is a hardware-based solution designed to monitor key parameters of a transformer and prevent damage due to overheating, overload, or abnormal conditions.

The system continuously measures temperature, voltage, and current, and automatically activates protective mechanisms like cooling and load control to ensure safe operation.

---

## 🚀 Key Features
- 🌡️ Real-time temperature monitoring using DHT11
- ⚡ Voltage sensing using voltage sensor module
- 🔌 Current monitoring using ACS712 sensor
- 🌀 Automatic cooling system (fan control)
- 🔔 Fault indication using LED / relay switching
- 📟 Live parameter display on 16x2 LCD
- 🛡️ Basic transformer protection system

---

## 🛠️ Components Used
- Arduino UNO
- DHT11 Temperature Sensor
- Voltage Sensor Module
- ACS712 Current Sensor
- 16x2 LCD Display
- Relay Module
- Cooling Fan
- Step-down Transformer (Power Supply)
- Breadboard & Connecting Wires
- LED Indicators
- Soil Moisture Sensor *(optional – used for oil level simulation)*

---

## ⚙️ Working Principle
The system works by continuously monitoring transformer conditions through sensors:

- The **DHT11 sensor** measures temperature
- The **voltage sensor** tracks input/output voltage levels
- The **ACS712 sensor** measures load current
- All sensor data is processed by the Arduino UNO

### 🔁 Control Logic:
- If temperature exceeds a threshold → **Cooling fan turns ON**
- If current/voltage exceeds limits → **Relay triggers protection**
- All real-time values are displayed on the **LCD screen**

---

## 🔄 System Architecture
1. Sensors collect real-time data (Temperature, Voltage, Current)  
2. Arduino UNO processes the sensor inputs  
3. LCD displays live readings  
4. Relay controls load/fault conditions  
5. Cooling fan activates during overheating  

---

## 📊 Applications
- Transformer monitoring (educational prototype)
- Substation safety systems (basic level)
- Industrial equipment monitoring
- Electrical lab demonstrations

---

## 🎯 Advantages
- Prevents overheating using automatic cooling
- Simple and cost-effective implementation
- Real-time monitoring with display
- Easy to expand with IoT features

## 🔮 Future Enhancements
- IoT integration (ESP8266 / Blynk / ThingSpeak)
- GSM alert system for faults
- Oil level and gas detection sensors
- Mobile app monitoring
- Data logging for analysis

---

## 👩‍💻 Author
Saranya Shree R S  
Sai Samicsha Shri D  
Dharini S  
Electrical and Electronics Engineering

