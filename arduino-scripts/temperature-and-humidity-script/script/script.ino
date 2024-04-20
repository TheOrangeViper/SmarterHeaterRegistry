#include <DHT.h>
#include <Servo.h>
#define Type DHT11
int sensePin = 2;
DHT HT(sensePin, Type);
float humidity;;
float tempC;

int setTime = 500; // 500 ms

int servoPin = 3;
int servoPos = 0;
Servo myServo;

String command_arduino = "";
int commandsListSize = 4;
String commandsList[] = {"fullturn", "halfturn", "noturn", "getEnvironment"};

bool stringExistsInList(String target, String list[], int size) {
  for (int i = 0; i < size; i++) {
    if (target.equals(list[i])) {
      return true;  // String found in the list
    }
  }
  return false;  // String not found in the list
}

void setup() {
  Serial.begin(9600);
  HT.begin();
  delay(setTime); //delayed time for setup
  myServo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  humidity = HT.readHumidity();
  tempC = HT.readTemperature();
//  Serial.print(tempC, 1); // 1 for 1 decimal point
//  Serial.print(" ");
//  Serial.println(humidity, 1); // 1 for 1 decimal point

//  if (servoPos == 0) {
//    myServo.write(180);
//    servoPos = 180;  
//  }
//  else if (servoPos == 180) {
//    myServo.write(0);
//    servoPos = 0;  
//  }
  if (Serial.available() > 0){
    command_arduino = Serial.readStringUntil('\n');
    Serial.flush();
  }

  if (command_arduino == "fullturn"){
    myServo.write(180);
    Serial.println("Success");
    command_arduino = "";
  }
  else if(command_arduino == "halfturn"){
    myServo.write(90);
    Serial.println("Success");
    command_arduino = "";
  }
  else if(command_arduino == "noturn"){
    myServo.write(0);
    Serial.println("Success");
    command_arduino = "";
  }
  else if(command_arduino == "getEnvironment"){
    Serial.print(tempC, 1); // 1 for 1 decimal point
    Serial.print(" ");
    Serial.println(humidity, 1); // 1 for 1 decimal point
    command_arduino = "";
  }
  else {
    if (command_arduino != ""){
      Serial.println("Fail");
      command_arduino = ""; 
    }
  }

//  delay(1000);

}
