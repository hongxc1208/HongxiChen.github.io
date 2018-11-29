/*
  Using the BH1749NUC -- RGB/IR Monitoring
  By: Jim Lindblom
  SparkFun Electronics
  Date: May 4, 2018
  License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).
  Feel like supporting our work? Buy a board from SparkFun!
  https://www.sparkfun.com/products/14733
  This example demonstrates how to initialize and configure the BH1749NUC color sensor.
  Then check for new data and print the RGB and IR color data to the Serial Monitor at 115200
  
  Hardware Connections:
  Attach the Qwiic Shield to your Arduino/Photon/ESP32 or other
  Plug the Qwiic RGB Sensor onto the shield
  Watch each LED turn on one-at-a-time
*/
// #include <SparkFun_BH1749NUC_Arduino_Library.h>
#include "my_BH1749NUC_Arduino_Library.h"

BH1749NUC_Address_t BH1749NUC_ADDRESS_DEFAULT = BH1749NUC_ADDRESS_OPEN;
BH1749NUC rgb0;
BH1749NUC rgb1;



void setup() {

  BH1749NUC_ADDRESS_DEFAULT = BH1749NUC_ADDRESS_CLOSED;
  BH1749NUC tmpObj;
  rgb1 = tmpObj;

  Serial.begin(115200);

  if (rgb0.begin() != BH1749NUC_SUCCESS)
  {
    Serial.println("Error initializing the rgb sensor.");
    while (1) ;
  }

  if (rgb1.begin() != BH1749NUC_SUCCESS)
  {
    Serial.println("Error initializing the rgb sensor.");
    while (1) ;
  }
  
  // IR and RGB gain can be set to either BH1749NUC_GAIN_X1 or
  // BH1749NUC_GAIN_X32
  rgb0.setIRGain(BH1749NUC_GAIN_X1);
  rgb0.setRGBGain(BH1749NUC_GAIN_X1);
  rgb1.setIRGain(BH1749NUC_GAIN_X1);
  rgb1.setRGBGain(BH1749NUC_GAIN_X1);
  // Measurement mode can be set to either BH1749NUC_MEASUREMENT_MODE_35_MS,
  // BH1749NUC_MEASUREMENT_MODE_120_MS, or BH1749NUC_MEASUREMENT_MODE_240_MS
  // (35ms, 120ms, 240ms between measurements).
  rgb0.setMeasurementMode(BH1749NUC_MEASUREMENT_MODE_240_MS);
  rgb1.setMeasurementMode(BH1749NUC_MEASUREMENT_MODE_240_MS);
}

void loop() {
  Serial.println("rgb0:");
  Serial.println("Red: " + String(rgb0.red()));
  Serial.println("Green: " + String(rgb0.green()));
  Serial.println("Blue: " + String(rgb0.blue()));
  Serial.println("IR: " + String(rgb0.ir()));
  Serial.println("Green2: " + String(rgb0.green2()));
  Serial.println();

  
  Serial.println("rgb1:");
  Serial.println("Red: " + String(rgb1.red()));
  Serial.println("Green: " + String(rgb1.green()));
  Serial.println("Blue: " + String(rgb1.blue()));
  Serial.println("IR: " + String(rgb1.ir()));
  Serial.println("Green2: " + String(rgb1.green2()));
  Serial.println();
  delay(100);

}
