#include <uStepperS.h>

uStepperS stepper;
int vel = 0;
int current = 60;
String inputString;

void setup() {
  stepper.setup();
  Serial.begin(2000000);
  stepper.disablePid();
  stepper.disableClosedLoop();
  stepper.setCurrent(80);
  stepper.setHoldCurrent(50);
  stepper.setMaxVelocity(0);
  stepper.setMaxAcceleration(40);
  stepper.runContinous(true);
}

void loop() {
while (Serial.available()) {
    char c = Serial.read();  //gets one byte from serial buffer
    inputString += c; //makes the String readString
    delayMicroseconds(5);
  }

  if (inputString.length() > 0) {
    vel = inputString.toInt();
    Serial.println(vel);  //so you can see the captured String
    stepper.setMaxVelocity(vel);
    inputString = "";
  }
}
