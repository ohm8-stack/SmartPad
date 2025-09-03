#include <HX711.h>

const int DOUT_PIN = 0;  // Data pin
const int SCK_PIN = 1;   // Clock pin

HX711 scale;
float scaleFactor = 335.2;  // Replace with your calculated scale factor

void setup() {
  Serial.begin(460800);
  scale.begin(DOUT_PIN, SCK_PIN);
  scale.set_scale(scaleFactor); // Set the calculated scale factor
  scale.tare();  // Reset the scale to 0
  Serial.println("Calibration complete. Place weights to measure.");
}

void loop()
 {
  if (scale.is_ready()) {
    long reading = scale.get_units(32); // Average of 10 readings
       // Convert negative readings to positive
    Serial.print("Weight: ");
    Serial.print(reading);
    Serial.println(" grams");  // Adjust units if necessary
  } else {
    Serial.println("HX711 not reading lower baud rate.");
  }
  delay(100); // Delay for a bit
}
