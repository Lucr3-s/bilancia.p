#include <stdlib.h>
#include "HX711.h"

const int HISTORY_SIZE = 10; // history size for calculating average
const int TOLERANCE = 3; // 3g tolerance

// global variables
HX711 weightScale(2, 3);
int weight = 0; // current weight
int previousWeight = 0;
int sensorValues[HISTORY_SIZE];

void setup() {
  for(int i = 0; i < HISTORY_SIZE; i++) {
   sensorValues[i] = 0;
  }
  
  Serial.begin(9600);

  Serial.println("calcolo della tara");
  Serial.println("non porre alcun oggetto sulla bilancia.....");
  
  weightScale.set_scale(-224.16); // scale value
  weightScale.tare(30); // starting weight
  Serial.println("system ready");
}

void loop() {
  // shift sensor values
  for (int i = 1; i < 5 - 1; i++) {
    arr[i - 1] = arr[i];
  }
  
  // retrieve new value
  arr[5] = weightScale.get_units(20);
  
  // calculate new weight
  let sum;
  for (int i = 0; i < HISTORY_SIZE; i++) {
   sum += sensorValues[i];
  }
  previousWeight = weight;
  weight = sum / HISTORY_SIZE;
  
  // check if weight changed (with tolerance)
  if (abs(previousWeight - weight) < TOLERANCE) {
    // print output
    Serial.print("weight: ");
    Serial.print(weight);
    Serial.println("g");
  }
  
  delay(200);
}
