

// LCD INCLUDES
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>

// ACCELEROMETER SENSOR INCLUDES
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>





// Arduino Wire library is required if I2Cdev I2CDEV_ARDUINO_WIRE implementation
// is used in I2Cdev.h
#if SPI_IMPLEMENTATION == SPI_ARDUINO_WIRE
    #include "Wire.h"
#endif



int16_t ax, ay, az;
float dx, dy, dz = 0;
int16_t gx, gy, gz;





#define LED_PIN 13
bool blinkState = false;

void setup() {
    // join I2C bus (I2Cdev library doesn't do this automatically)
    //#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
        Serial.begin(38400);
ax = analogRead(A2);
ay =analogRead(A3);
az =analogRead(A4);
   
}

void loop() {

    //finding depth
        
        dx=dx+(float)(((float)ax/(float)16384)*9.8*0.05*0.05);
        dy=dy+(float)(((float)ay/(float)16384)*9.8*0.05*0.05);
        dz=dz+(float)(((float)az/(float)16384)*9.8*0.05*0.05);
        Serial.print(dx); Serial.print("\t");
        Serial.print(dy); Serial.print("\t");
        Serial.print(dz); Serial.print("\t\n");

   
delay(1000);
    // blink LED to indicate activity
    blinkState = !blinkState;
    digitalWrite(LED_PIN, blinkState);
}
