#include <Servo.h>
#include<SoftwareSerial.h>

Servo myservo;
SoftwareSerial bSerial(2, 3);

int state;

void setup() {
  myservo.attach(9);
  bSerial.begin(9600);
  myservo.write(0);
  delay(1000);
}

void loop() {

  if (bSerial.available() > 0) {
    state = bSerial.read();

  } // if the state is '0' the DC motor will turn off 

  if (state == '0') {
    myservo.write(180);
    delay(1000);
    bSerial.println("Door Locked");
  } else if (state == '1') {
    myservo.write(0);
    delay(1000);
    bSerial.println("Door UnLocked");
  } else if (state != '1' || state != '0') {
    myservo.write(180);
    delay(1000);
    bSerial.println("Door Locked");
  }

}