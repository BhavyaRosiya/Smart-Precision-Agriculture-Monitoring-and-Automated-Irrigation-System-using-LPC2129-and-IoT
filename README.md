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

# 📂 1. Clone the Repository

Clone the project repository using Git:

git clone <your-github-repository-url>
cd Smart-Precision-Agriculture

Replace <your-github-repository-url> with the actual GitHub repository URL.

# 🖥️ 2. Open the Keil Project

Open Keil µVision 5 and open the project file:

Smart_Agriculture.uvprojx

Make sure that the correct microcontroller is selected.

Go to:

Project
   ↓
Options for Target
   ↓
Device
   ↓
NXP
   ↓
LPC2129

Select LPC2129 as the target device.

### 📁 3. Check Project Files
```text
Make sure that all required source files and header files are added to the Keil project.

The project structure is:

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
📄 Important Files
File	Description
main.c	Main application program
header.h	Common declarations and macros
uart.c	UART communication
adc.c	ADC configuration and sensor reading
lcd.c	16×2 LCD control
i2c.c	I²C communication
eeprom.c	EEPROM read/write operations
rtc.c	DS1307 RTC communication
dht22.c	DHT22 temperature and humidity
soil_sensor.c	Soil moisture monitoring
water_sensor.c	Water level monitoring
wifi.c	ESP8266 Wi-Fi communication
can.c	CAN communication
Block_diagram.jpeg	System block diagram
Smart_Agriculture.uvprojx	Keil project file
```
# 🔨 4. Build the Project

After opening the project, build the application in Keil µVision 5.

Go to:

Project → Build Target

or press:

F7

Make sure that the project compiles successfully.

The build should complete with:

0 Errors

Warnings should also be reviewed and resolved wherever possible.

# 📦 5. Generate the HEX File

To generate the HEX file, open:

Project
   ↓
Options for Target
   ↓
Output

Enable:

☑ Create HEX File

Then build the project again:

Project → Build Target

After a successful build, the generated .hex file will normally be available in the project's:

Objects/

folder.

Example:

Objects/
└── Smart_Agriculture.hex
### 🔌 6. Connect the LPC2129

Connect the LPC2129 development board to the computer using the supported programming interface.

Connect the required sensors and peripherals according to the project's circuit diagram and configured GPIO/ADC pins.

🔧 Main Hardware Connections
```text
Module	Interface
Soil Moisture Sensor	ADC
Water Level Sensor	ADC
LM35 Temperature Sensor	ADC
LDR Sensor	ADC
DHT22	GPIO
Rain Sensor	GPIO
Flame Sensor	GPIO
PIR Sensor	GPIO
ESP8266	UART
DS1307 RTC	I²C
AT24C256 EEPROM	I²C
SD Card	SPI
MCP2551	CAN
16×2 LCD	GPIO
Relay + Water Pump	GPIO
```
# ⚡ 7. Flash the Program

Open Flash Magic and configure the required programming settings.

Configure:

COM Port
Baud Rate
Device: LPC2129
Oscillator Frequency

Select the generated HEX file:

Objects/Smart_Agriculture.hex

Start the programming process and wait until Flash Magic reports that programming has completed successfully.

# ▶️ 8. Run the System

After programming is completed:

Reset the LPC2129 development board.
Power ON the connected sensors and peripherals.
The LPC2129 initializes the required hardware.
Sensor values are continuously monitored.
Sensor information is displayed on the 16×2 LCD.
System status can also be transmitted through UART.
The controller checks soil moisture and water level.
The rain sensor is checked before irrigation.
The relay controls the water pump automatically.
ESP8266 communicates with the LPC2129 through UART.
Sensor data can be transmitted to ThingSpeak.
EEPROM and SD card can be used for data logging.
DS1307 provides date and time information.
LEDs and buzzer provide system alerts.
# 🌱 9. Automatic Irrigation Logic

The automatic irrigation system uses soil moisture, water level, and rain detection to decide whether the water pump should operate.

                 ┌─────────────────────┐
                 │  Read Soil Moisture  │
                 └──────────┬──────────┘
                            │
                            ▼
                  ┌─────────────────┐
                  │   Is Soil Dry?  │
                  └───────┬─────────┘
                      YES │ NO
                          │
                          └──────────────► Pump OFF
                          │
                          ▼
                  ┌─────────────────┐
                  │ Check Water     │
                  │     Level       │
                  └───────┬─────────┘
                      YES │ NO
                          │
                          └──────────────► Pump OFF
                          │
                          ▼
                  ┌─────────────────┐
                  │   Check Rain     │
                  └───────┬─────────┘
                      YES │ NO
                          │
                          └──────────────► Pump OFF
                          │
                          ▼
                  ┌─────────────────┐
                  │     Pump ON     │
                  └─────────────────┘
💧 Irrigation Conditions

The water pump is turned ON only when all required conditions are satisfied:

Soil is DRY
     +
Water is AVAILABLE
     +
No RAIN detected
     ↓
  PUMP ON

The water pump is turned OFF when any of the following conditions occurs:

Soil is WET
      OR
Water is NOT AVAILABLE
      OR
Rain is DETECTED
      ↓
   PUMP OFF

This prevents unnecessary irrigation and helps conserve water.

# 📺 10. Expected Output

The 16×2 LCD and UART terminal can display the system status.

Example LCD output:

SMART AGRICULTURE
SYSTEM STARTED

Example sensor status:

Soil  : DRY
Water : AVAILABLE
Pump  : ON
Rain  : NO

IoT status:

WiFi  : CONNECTED
Cloud : UPDATED
# 🖥️ Example UART System Output
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
🌐 IoT and Cloud Monitoring

The ESP8266 Wi-Fi module provides wireless communication between the LPC2129-based agricultural system and the cloud platform.

Sensor information can be transmitted to ThingSpeak, allowing the collected agricultural data to be monitored remotely.

The general communication flow is:

Sensors
   ↓
LPC2129
   ↓
UART
   ↓
ESP8266
   ↓
Wi-Fi
   ↓
ThingSpeak Cloud
💾 Data Storage

The system can use different storage devices for maintaining agricultural data.

AT24C256 EEPROM

Used for storing permanent configuration or important system information.

# 👨‍💻 Author

**Bhavya Rosiya**
