#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

const int dry = 624;
const int wet = 324;

void setBits(uint8_t bits[8][12], int n) {
  if (n < 0) n = 0;
  if (n > 96) n = 96;

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 12; j++) {
      int index = i * 12 + j;
      bits[i][j] = (index < n) ? 1 : 0;
    }
  }
}

int Pin1 = A2; // ANALOG IN
int IN1 = 2; // DIGITAL
float sensorVal = 0;

void setup() {
  Serial.begin(9600);
  matrix.begin();

  pinMode(IN1, OUTPUT);
  pinMode(Pin1, INPUT);
  digitalWrite(IN1, HIGH);
  delay(500);
}

void loop() {
  sensorVal = analogRead(A2);
  int percentageHumidity = map(sensorVal, wet, dry, 100, 0);

  uint8_t bits[8][12];
  setBits(bits, percentageHumidity);
  matrix.renderBitmap(bits, 8, 12);

  Serial.print(percentageHumidity);
  Serial.println("%");

  if(percentageHumidity > 40) {
    digitalWrite(IN1, LOW);
  } else {
    digitalWrite(IN1, HIGH);
  }

  delay(500);
}