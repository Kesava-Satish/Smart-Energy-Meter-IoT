/*
 * Project: Smart Energy Meter using IoT (Blynk Interface)
 * Author: Kesava Satish Boppana
 * Hardware: ESP32, ZMPT101B (Voltage), SCT-013 (Current)
 * * Description:
 * This system samples AC voltage and current to calculate Real Power, 
 * Energy consumption (kWh), and estimated billing cost. Data is 
 * transmitted to the Blynk mobile app for real-time monitoring.
 */

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "EmonLib.h" // Standard library for OpenEnergyMonitor

// Network Credentials
char auth[] = "YourAuthToken";
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";

// Sensor Objects
EnergyMonitor emon1;

// Pin Definitions (Based on Project Synopsis)
#define VOLT_PIN 35  // ZMPT101B Output
#define CURR_PIN 34  // SCT-013 Output

// Calibration Constants (Derived from testing)
// specific calibration requires a multimeter comparison
float vCalibration = 234.26; 
float cCalibration = 60.60;

// Energy Variables
float kWh = 0.0;
unsigned long lastMillis = millis();
float billAmount = 0.0;
float unitCost = 0.12; // Cost per unit in local currency

void setup() {
  Serial.begin(115200);
  
  // Initialize Blynk
  Blynk.begin(auth, ssid, pass);
  
  // Initialize Energy Monitor
  // Voltage: input pin, calibration, phase_shift
  emon1.voltage(VOLT_PIN, vCalibration, 1.7); 
  // Current: input pin, calibration
  emon1.current(CURR_PIN, cCalibration);     
}

void loop() {
  Blynk.run();
  
  // Calculate Power
  // CalculateIrms(number of samples)
  // calcVI(number of crossings, timeout)
  emon1.calcVI(20, 2000); 

  float realPower       = emon1.realPower;
  float apparentPower   = emon1.apparentPower;
  float powerFactor     = emon1.powerFactor;
  float supplyVoltage   = emon1.Vrms;
  float Irms            = emon1.Irms;

  // Calculate Energy (kWh)
  // Energy = Power (kW) * Time (hours)
  unsigned long currentMillis = millis();
  float timeElapsed = (currentMillis - lastMillis) / 3600000.0; // convert ms to hours
  kWh += (realPower / 1000.0) * timeElapsed;
  lastMillis = currentMillis;

  // Calculate Bill
  billAmount = kWh * unitCost;

  // Send data to Blynk App (Virtual Pins)
  Blynk.virtualWrite(V0, realPower);
  Blynk.virtualWrite(V1, kWh);
  Blynk.virtualWrite(V2, billAmount);
  Blynk.virtualWrite(V3, supplyVoltage);
  
  // Serial Debugging
  Serial.print("Power: "); Serial.print(realPower); Serial.println(" W");
  Serial.print("Bill: $"); Serial.println(billAmount);
}