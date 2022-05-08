#include <MotorDriver>

#define leftPWM  5
#define rightPWM 6
#define leftIN1  
#define leftIN2  
#define rightIN1 
#define rightIN2 

MotorDriver leftDriver(leftPWM, leftIN1, leftIN2),
            rightDriver(rightPWM, rightIN1, rightIN2);

void setup() {
  Serial.begin(9600);
  leftDriver.setPins();
  rightDriver.setPins();
}

void loop() {
  // put your main code here, to run repeatedly:

}
