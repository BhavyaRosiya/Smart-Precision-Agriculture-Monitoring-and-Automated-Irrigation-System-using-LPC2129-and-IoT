# 🌱 Smart Precision Agriculture Monitoring and Automated Irrigation System using LPC2129 and IoT

An 🌐 **IoT-enabled smart agriculture system** built using the **LPC2129 ARM7 Microcontroller** for real-time farm monitoring and automated irrigation. The system monitors 🌱 **soil moisture**, 💧 **water level**, 🌡️ **temperature**, 💦 **humidity**, 🌧️ **rainfall**, ☀️ **sunlight**, 🔥 **fire**, and 🚶 **motion**, and automatically controls the 💧 **water pump** based on field conditions.

Sensor data and system status are displayed on a **16×2 LCD**, stored using **AT24C256 EEPROM and SD Card**, timestamped using **DS1307 RTC**, and transmitted through 📶 **ESP8266 Wi-Fi** to ☁️ **ThingSpeak Cloud** for remote monitoring. The system also supports 🔗 **CAN communication using MCP2551** for future multi-controller agricultural applications.

---

# 🚀 Key Features

* 💧 Automatic Irrigation
* 🌱 Soil Moisture Monitoring
* 💦 Water Level Monitoring
* 🌡️ Temperature & Humidity Monitoring
* 🌧️ Rainfall Detection
* ☀️ Sunlight Monitoring
* 🔥 Fire Detection & Alerts
* 🚶 Motion Detection & Farm Security
* 📺 16×2 LCD Real-Time Display
* 📶 ESP8266 Wi-Fi Connectivity
* ☁️ ThingSpeak Cloud Monitoring
* 💾 EEPROM & SD Card Data Logging
* ⏱️ DS1307 RTC Event Tracking
* 🔗 MCP2551 CAN Communication
* 🔔 LED & Buzzer Alerts
* 🚰 Automatic Water Pump Control

---

# 🛠️ Technologies & Hardware Used

* **LPC2129 ARM7 Microcontroller**
* **ESP8266 Wi-Fi Module**
* **Soil Moisture Sensor**
* **Water Level Sensor**
* **LM35 Temperature Sensor**
* **DHT22 Temperature & Humidity Sensor**
* **Rain Sensor**
* **LDR Sensor**
* **Flame Sensor**
* **PIR Motion Sensor**
* **Relay Module & Water Pump**
* **16×2 LCD Display**
* **AT24C256 EEPROM**
* **SD Card Module**
* **DS1307 RTC**
* **MCP2551 CAN Transceiver**
* **ThingSpeak Cloud**

---

# 📡 Communication Interfaces

* **ADC** → Soil Moisture, Water Level, LM35, LDR
* **GPIO** → DHT22, Rain, Flame, PIR
* **UART** → LPC2129 ↔ ESP8266
* **I²C** → DS1307 RTC & AT24C256 EEPROM
* **SPI** → SD Card Module
* **CAN** → MCP2551 CAN Transceiver

---

# 🧠 System Working

1. 🌱 Sensors continuously collect agricultural and environmental data.
2. 🧠 LPC2129 processes the sensor readings.
3. 💧 Soil moisture is checked to determine irrigation requirements.
4. 🚰 If the soil is dry, sufficient water is available, and no rainfall is detected, the water pump is activated automatically.
5. 🌧️ Pump operation is stopped when sufficient moisture is reached or rainfall is detected.
6. 📺 Important system parameters are displayed on the 16×2 LCD.
7. 🔥 Fire and 🚶 motion detection generate safety alerts.
8. ⏱️ Important events are recorded with date and time using the DS1307 RTC.
9. 💾 Data is stored using EEPROM and SD Card.
10. 📶 ESP8266 sends system data to ☁️ ThingSpeak Cloud for remote monitoring.

---

# 📊 Monitored Parameters

| Parameter        | Sensor               | Interface |
| ---------------- | -------------------- | --------- |
| 🌱 Soil Moisture | Soil Moisture Sensor | ADC       |
| 💧 Water Level   | Water Level Sensor   | ADC       |
| 🌡️ Temperature  | LM35                 | ADC       |
| 💦 Humidity      | DHT22                | GPIO      |
| 🌧️ Rainfall     | Rain Sensor          | GPIO      |
| ☀️ Sunlight      | LDR                  | ADC       |
| 🔥 Fire          | Flame Sensor         | GPIO      |
| 🚶 Motion        | PIR Sensor           | GPIO      |

---

# 🎯 Project Objectives

* 💧 Reduce water wastage
* ⚡ Reduce unnecessary electricity consumption
* 🚜 Automate irrigation activities
* 🌱 Improve crop monitoring
* 📊 Maintain accurate agricultural data
* 🔥 Improve farm safety
* 📶 Enable remote IoT monitoring
* 🤖 Reduce continuous manual supervision
* 🔗 Support future multi-controller agricultural networks

---

# 🏗️ System Architecture

```text
                🌐 ThingSpeak Cloud
                       ▲
                       │ Wi-Fi
                       │
                 📶 ESP8266
                       │ UART
                       ▼
              🧠 LPC2129 ARM7
                       │
       ┌───────────────┼────────────────┐
       │               │                │
     🌱 Sensors      💾 Storage       ⚙️ Control
       │               │                │
   Soil Moisture    EEPROM/SD       Relay + Pump
   Water Level      DS1307 RTC      LCD / LEDs
   Temperature                       Buzzer
   Humidity
   Rainfall
   Sunlight
   Fire
   Motion
```

---

# 🔮 Future Scope

* 🤖 AI-based irrigation prediction
* 📱 Dedicated mobile application
* 🌦️ Weather API integration
* 📈 Advanced agricultural data analytics
* 🔗 Multi-field CAN-based monitoring
* ⚡ Solar-powered irrigation
* 🛰️ GPS-based farm monitoring

---
# 🏗️ Project Block Diagram

The block diagram below illustrates the complete architecture of the **Smart Precision Agriculture Monitoring and Automated Irrigation System**, including sensors, LPC2129 ARM7 controller, irrigation control, IoT connectivity, data storage, RTC, and CAN communication.

![Smart Precision Agriculture Monitoring and Automated Irrigation System Block Diagram](Block_diagram.jpeg)

---

## ⚙️ How to Run the Project

### 🛠️ Software Requirements

- **Keil µVision 5**
- **ARM7 LPC2129 Device Support Package**
- **Flash Magic** for programming the LPC2129
- **Serial Terminal** such as Tera Term, PuTTY, or another UART terminal

### 🔧 Hardware Requirements

- LPC2129 ARM7 Development Board
- ESP8266 Wi-Fi Module
- Soil Moisture Sensor
- Water Level Sensor
- LM35 Temperature Sensor
- DHT22 Temperature & Humidity Sensor
- Rain Sensor
- LDR Sensor
- Flame Sensor
- PIR Motion Sensor
- Relay Module
- Water Pump
- 16×2 LCD
- AT24C256 EEPROM
- SD Card Module
- DS1307 RTC
- MCP2551 CAN Transceiver
- Buzzer and LEDs

## 📂 1. Clone the Repository

Clone the project repository using:


git clone <your-github-repository-url>
cd Smart-Precision-Agriculture

## 🖥️ 2. Open the Keil Project

Open **Keil µVision 5** and open the project file:

Project → Options for Target → Device → NXP → LPC2129

##📁 3. Project Files

Make sure all required source and header files are added to the Keil project.

##📂 Project Structure
Smart-Precision-Agriculture/
│
├── main.c
├── header.h
├── uart.c
├── adc.c
├── lcd.c
├── i2c.c
├── eeprom.c
├── rtc.c
├── dht22.c
├── soil_sensor.c
├── water_sensor.c
├── wifi.c
├── can.c
│
├── Block_diagram.jpeg
├── README.md
└── Smart_Agriculture.uvprojx
##🔨 4. Build the Project

In Keil µVision 5, select:

Project → Build Target

or press:

F7

Make sure the project compiles successfully without any errors.

##📦 5. Generate the HEX File

Open:

Project → Options for Target → Output

Enable:

☑ Create HEX File

Then build the project again using:

Project → Build Target

The generated .hex file will normally be available inside the:

Objects/

folder.

##🔌 6. Connect the LPC2129

Connect the LPC2129 development board to the computer using the supported programming interface.

Connect the required sensors and peripherals according to the project's circuit diagram and pin configuration.

🔧 Main Connections
Module	Interface
Soil Moisture Sensor	ADC
Water Level Sensor	ADC
LM35	ADC
LDR	ADC
DHT22	GPIO
Rain Sensor	GPIO
Flame Sensor	GPIO
PIR Sensor	GPIO
ESP8266	UART
DS1307 RTC	I²C
AT24C256 EEPROM	I²C
SD Card	SPI
MCP2551	CAN
LCD	GPIO
Relay + Pump	GPIO
##⚡ 7. Flash the Program

Open Flash Magic and configure the required programming settings:

COM Port
Baud Rate
LPC2129 Device
Oscillator Frequency

Select the generated .hex file from the Objects/ folder.

Then start the programming process and wait until the flashing operation is completed successfully.

##▶️ 8. Run the System

After programming is complete:

Reset the LPC2129 development board.
Power ON the connected sensors and modules.
The LPC2129 starts reading the sensor data.
Sensor values and system status are displayed on the 16×2 LCD.
The controller checks the soil moisture and water level.
The water pump is automatically controlled according to the field conditions.
ESP8266 communicates with the LPC2129 through UART.
Sensor data can be transmitted to ThingSpeak Cloud.
EEPROM and SD Card can be used for data logging.
DS1307 RTC provides date and time information.
LEDs and buzzer provide system alerts.
##🌱 9. Automatic Irrigation Logic

The irrigation system operates according to the following logic:

              ┌─────────────────────┐
              │  Read Soil Moisture  │
              └──────────┬──────────┘
                         │
                         ▼
                 ┌───────────────┐
                 │  Is Soil Dry? │
                 └───────┬───────┘
                    YES  │  NO
                         │
              ┌──────────┘
              │
              │ NO
              ▼
        ┌──────────────┐
        │   Pump OFF   │
        └──────────────┘


                    YES
                     │
                     ▼
            ┌─────────────────┐
            │ Check Water     │
            │     Level       │
            └────────┬────────┘
                     │
                     ▼
             ┌─────────────────┐
             │ Water Available?│
             └───────┬─────────┘
                 YES │  NO
                     │
                     │       ┌──────────────┐
                     └──────►│   Pump OFF   │
                             └──────────────┘


                     YES
                      │
                      ▼
              ┌──────────────┐
              │ Check Rain   │
              └──────┬───────┘
                     │
                     ▼
                ┌───────────┐
                │  No Rain? │
                └─────┬─────┘
                  YES │  NO
                      │
                      │       ┌──────────────┐
                      └──────►│   Pump OFF   │
                              └──────────────┘
                      │
                      ▼
                ┌──────────────┐
                │    Pump ON   │
                └──────────────┘
💧 Irrigation Conditions

The water pump is turned ON when:

Soil is Dry
      +
Water is Available
      +
No Rain Detected
      ↓
   Pump ON

The water pump is turned OFF when:

Soil is Wet
      OR
Water is Not Available
      OR
Rain is Detected
      ↓
   Pump OFF
##📺 10. Expected Output

The 16×2 LCD and UART terminal can display system information such as:

SMART AGRICULTURE
SYSTEM STARTED

Example sensor and system status:

Soil: DRY
Water: AVAILABLE
Pump: ON
Rain: NO

IoT status:

WiFi: CONNECTED
Cloud: UPDATED
##🖥️ Example System Output
================================
      SMART AGRICULTURE
================================


Soil       : DRY
Water      : AVAILABLE
Pump       : ON
Rain       : NO


WiFi       : CONNECTED
Cloud      : UPDATED
================================


# 👨‍💻 Author

**Bhavya Rosiya**
