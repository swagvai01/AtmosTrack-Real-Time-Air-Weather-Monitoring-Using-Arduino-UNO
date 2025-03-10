# AtmosTrack: Real-Time Air & Weather Monitoring

## Introduction
**AtmosTrack** is a real-time air and weather monitoring system designed to measure **temperature, humidity, and air quality** using an **Arduino**, a **DHT11 sensor**, and an **MQ-135 gas sensor**. The system continuously collects environmental data, processes it, and displays real-time updates on the **Serial Monitor**.

This project can be used for **pollution tracking, climate analysis, and smart automation applications**.

---

## How It Works

### Sensors Collect Data
- The **DHT11 sensor** measures **temperature and humidity**.
- The **MQ-135 gas sensor** detects **air quality** by measuring gas concentration.

### Arduino Processes the Data
- The **DHT11 sensor** provides **digital data** directly to the Arduino.
- The **MQ-135 sensor** outputs **analog voltage**, which is converted into **digital values** using the **Arduino's ADC (Analog-to-Digital Converter)**.

### Data Classification
The system classifies **air quality** into four categories based on gas concentration:

| Air Quality | Gas Level (MQ-135 Sensor) |
|-------------|---------------------------|
| **Good** | Less than 300 |
| **Poor** | Between 300-599 |
| **Very Bad** | Between 600-899 |
| **Toxic** | 900 and above |

### Data Display
- The processed values are displayed in **real-time** on the **Serial Monitor**, updating **every 2 seconds**.

---

## Pin Diagram

| Component  | Arduino Pin |
|------------|------------|
| **DHT11 Data** | D2 |
| **MQ-135 Output** | A0 |
| **VCC (Both Sensors)** | 5V |
| **GND (Both Sensors)** | GND |

---

## Code Breakdown

### Required Library
- **DHT.h**: This library is used to communicate with the **DHT11 sensor**. It must be installed from the **Arduino Library Manager**.

---

### Code Explanation

#### 1. Library and Sensor Initialization
```cpp
#include <DHT.h>

#define DHTPIN 2       // DHT11 sensor connected to digital pin 2
#define DHTTYPE DHT11  // Define sensor type
DHT dht(DHTPIN, DHTTYPE);

#define MQ135_PIN A0   // MQ135 sensor connected to analog pin A0
```
- Includes the **DHT sensor library** for temperature and humidity readings.
- Defines **pin connections** for the **DHT11** and **MQ-135 sensors**.
- Creates a **DHT object** for handling the sensor data.

#### 2. Setup Function
```cpp
void setup() {
    Serial.begin(9600);  // Start serial communication
    dht.begin();
}
```
- Initializes **Serial Communication** at **9600 baud rate**.
- Starts **DHT11 sensor communication**.

#### 3. Loop Function - Reading Sensor Data
```cpp
void loop() {
    int gasValue = analogRead(MQ135_PIN);
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();
```
- Reads **gas concentration** from the **MQ-135 sensor**.
- Reads **temperature** and **humidity** from the **DHT11 sensor**.

#### 4. Air Quality Classification
```cpp
    String airQuality;
    if (gasValue < 300) {
        airQuality = "Good";
    } else if (gasValue < 600) {
        airQuality = "Poor";
    } else if (gasValue < 900) {
        airQuality = "Very Bad";
    } else {
        airQuality = "Toxic";
    }
```
- **Classifies air quality** based on the **MQ-135 sensor's readings**.

#### 5. Displaying Data on Serial Monitor
```cpp
    Serial.print("Air Quality: ");
    Serial.print(airQuality);
    Serial.print(" | Gas Level: ");
    Serial.print(gasValue);
    Serial.print(" | Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C | Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    delay(2000);  // Wait for 2 seconds before next reading
}
```
- Displays **air quality, gas level, temperature, and humidity** on the **Serial Monitor**.
- **Waits 2 seconds** before taking the next reading.

---

## Advantages
✅ **Real-time Monitoring**: Updates values **every 2 seconds**.  
✅ **Simple & Cost-Effective**: Uses **affordable sensors** for air and weather tracking.  
✅ **Expandable & Scalable**: Can be integrated with **more sensors** or **IoT platforms** for remote monitoring.  

---

## Possible Improvements
📌 **Cloud Integration**: Send data to **IoT platforms** like **ThingSpeak** for remote access.  
📌 **LCD Display**: Add an **LCD screen** for offline monitoring without using the **Serial Monitor**.  
📌 **Wireless Connectivity**: Use **ESP8266** or **ESP32** to make the system **WiFi-enabled**.  

---

## Conclusion
**AtmosTrack** provides a **real-time, accurate, and low-cost** solution for monitoring **temperature, humidity, and air quality**. By continuously **updating environmental data**, it helps in **pollution control, weather tracking, and automation systems**.

With further improvements, this project can be expanded into a **fully IoT-enabled smart monitoring system**, making it useful for **smart homes, industrial safety, and environmental research**.
