#include <Arduino.h>
#include <FastAccelStepper.h>

union floatUnion {
  byte floatBytes[16];  // Array size is 4 floats * 4 bytes each
  float floatNumbers[4];
};

floatUnion data;

void setup() {
  Serial.begin(115200);
  Serial.println("Setup complete, waiting for data...");
}

void loop() {
  if (Serial.available() >= 16) {  // Check if at least 16 bytes are available
    Serial.readBytes(data.floatBytes, 16);
    Serial.print("Received floats: ");
    for (int i = 0; i < 4; i++) {
      Serial.print(data.floatNumbers[i], 4);
      if (i < 3) Serial.print(", ");
    }
    Serial.println();
  }
}