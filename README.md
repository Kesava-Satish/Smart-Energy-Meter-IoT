# Smart Energy Meter using IoT & Blynk Interface

## 📌 Project Overview
[cite_start]This project addresses the inefficiencies of conventional electricity billing by automating data collection and providing real-time usage transparency[cite: 55, 56]. [cite_start]The system tracks voltage, current, and power consumption, calculating the estimated bill and displaying it on a mobile dashboard (Blynk)[cite: 58].

## 🛠 Hardware Architecture
[cite_start]The system is built around the **ESP32 Microcontroller** due to its integrated Wi-Fi and analog processing capabilities[cite: 113].
* [cite_start]**Controller:** ESP32 WROOM (Interfaced with Arduino IDE)[cite: 63].
* [cite_start]**Voltage Sensor:** ZMPT101B (Connected to GPIO 35)[cite: 105].
    * [cite_start]*Capability:* Transformer-based isolation sensing up to 250V AC[cite: 116].
* [cite_start]**Current Sensor:** SCT-013 Split Core Transformer (Connected to GPIO 34)[cite: 107].
    * [cite_start]*Capability:* Non-invasive sensing up to 30A[cite: 118].
* [cite_start]**Display:** 16x2 LCD & Blynk Mobile App[cite: 109].

## ⚙️ Methodology & Logic
The system utilizes the sampling theory to calculate RMS values for AC signals.
1.  **Data Acquisition:** The ESP32 samples the analog output from the ZMPT101B and SCT-013.
2.  **Processing:** Using the sampling window method, the code calculates Root Mean Square (RMS) voltage and current.
3.  **Billing Algorithm:**
    $$\text{Cost} = (\text{Power (kW)} \times \text{Time (h)}) \times \text{Unit Rate}$$
4.  [cite_start]**IoT Transmission:** Data is pushed to the Blynk cloud via Wi-Fi for remote monitoring[cite: 59].

## 📸 Prototype
![Circuit Prototype](schematics/circuit_image.jpg)
*(Note: Upload the image from Slide 12 of your PPT to the schematics folder)*

## 📂 Repository Structure
* `/src`: Firmware code for ESP32 (Energy calculation and Blynk logic).
* `/docs`: Project synopsis and presentation slides.

## 🚀 Future Scope
* Integration with 3-Phase systems for industrial application.
* [cite_start]Implementation of "Theft Detection" algorithms by monitoring neutral line current[cite: 382].

## 👤 Author
**Kesava Satish Boppana**
