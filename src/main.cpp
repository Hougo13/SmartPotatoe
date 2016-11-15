
#include "Arduino.h"
#include <CapacitiveSensor.h>

CapacitiveSensor cs = CapacitiveSensor(4, 2);

long res = 0;
int secu[100];
int i;
int f = 0;
int preState = -1;

void setup(){
  Serial.begin(9600);
}

void loop(){
  for (i = 0; i < 100; i++) {
    secu[i] = cs.capacitiveSensor(15);
  }
  res = 0;
  for (i = 0; i < 100; i++) {
    res = res + secu[i];
  }
  res = res / 100;
  // Serial.println(res);
  f = 0;
  if (res > 50) {
    f = 1;
    if (res > 150) {
      f = 2;
      if (res > 300) {
        f = 3;
      }
    }
  }
  if (preState != f) {
    Serial.print("Doigts: ");
    Serial.println(f);
    preState = f;
  }
}
