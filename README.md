# Smart Energy Meter using IoT & Blynk Interface

## Project Overview
This project addresses the inefficiencies of conventional electricity billing systems by automating data collection and providing real-time usage transparency to the user. The system tracks voltage, current, and power consumption in real-time, calculates the estimated bill based on unit cost, and displays the data on a mobile dashboard via the Blynk application.

## Objectives
* To automate the electricity billing process and reduce manual errors.
* To provide users with real-time access to energy consumption data via a smartphone.
* To promote energy conservation through increased usage awareness.

## Hardware Architecture
The system is built around the **ESP32 Microcontroller** due to its integrated Wi-Fi capabilities and high processing speed for analog sampling.

* **Microcontroller:** ESP32 WROOM (Interfaced via Arduino IDE).
* **Voltage Sensor:** ZMPT101B (Connected to GPIO 35).
    * Used for precise AC voltage sensing (up to 250V).
* **Current Sensor:** SCT-013 Split Core Transformer (Connected to GPIO 34).
    * Non-invasive current sensing (up to 30A).
* **Display Interface:** Blynk Mobile App (IoT Dashboard).

## Technical Implementation
The system utilizes sampling theory to calculate the Root Mean Square (RMS) values for AC signals, ensuring accurate power readings.

1.  **Data Acquisition:** The ESP32 samples the analog output from the ZMPT101B and SCT-013 sensors.
2.  **Signal Processing:** The raw analog data is processed to filter noise and calculate Vrms and Irms.
3.  **Billing Logic:** The system applies a "Cost per Unit" factor to the calculated power usage to generate a real-time estimated bill.
    * *Formula:* Cost = (Power in kW * Time in Hours) * Unit Rate
4.  **IoT Transmission:** The processed data is transmitted via Wi-Fi to the Blynk Cloud, allowing the user to view voltage, current, power, and total cost from anywhere.

## Key Contributions
* Interfaced the ESP32 WROOM with high-precision analog sensors.
* Developed the firmware logic for real-time price calculation based on energy consumption.
* Implemented the Wi-Fi communication stack to ensure stable data transmission to the Blynk application.

## Repository Structure
* `/src`: Contains the main firmware code (`.ino`) for the ESP32.
* `/docs`: Includes the project synopsis and presentation slides used for review.

## Future Scope
* Integration with 3-Phase systems for industrial-grade monitoring.
* Implementation of theft detection algorithms by monitoring neutral line current.
* Adding a local OLED display for backup reading when Wi-Fi is unavailable.

## Author
**Kesava Satish Boppana**
