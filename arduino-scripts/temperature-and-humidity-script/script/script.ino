#include <DHT.h>
#define Type DHT11
int sensePin = 2;
DHT HT(sensePin, Type);
int setTime = 500; // 500 ms

float humidity;;
float tempC;

void setup() {
  Serial.begin(9600);
  HT.begin();
  delay(setTime); //delayed time for setup
}

void loop() {
  // put your main code here, to run repeatedly:
  humidity = HT.readHumidity();
  tempC = HT.readTemperature();
  Serial.print(tempC, 1); // 1 for 1 decimal point
  Serial.print(" ");
  Serial.println(humidity, 1); // 1 for 1 decimal point
  delay(1000);
}
