#include <Joystick.h>
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_JOYSTICK,  12);
const int pins[12]={10,14,15,16,5,6,4,7,3,2,1,0};//UDLR ABXY select start ShoulderL,ShoulderR

void setup() {
  for(int i=0; i<sizeof(pins)/sizeof(pins[0]); i++) {
    pinMode(pins[i], INPUT_PULLUP);
  }
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A8, INPUT);
  pinMode(A9, INPUT);
  Joystick.begin();
}

void loop() {
  //joystickRight
  Joystick.setXAxis(map(analogRead(A0), 0, 1023, 0, 255));
  Joystick.setYAxis(map(analogRead(A1), 0, 1023, 0, 255));
  //joystickLeft
  Joystick.setRxAxis(map(analogRead(A2), 1023, 0, 255, 0));
  Joystick.setRyAxis(map(analogRead(A3), 1023, 0, 255, 0));
  //Analog trigger left
  Joystick.setZAxis(map(analogRead(A8), 0, 1023, 255, 0));//values here should be diff
  //Analog trigger Right
  Joystick.setRzAxis(map(analogRead(A9), 0, 1023, 255, 0));//values here should be diff
  //digital buttons(all 12)
  for(int i=0; i<sizeof(pins)/sizeof(pins[0]); i++) {
    if(!digitalRead(pins[i])) {
      Joystick.pressButton(i);
    } else {
      Joystick.releaseButton(i);
    }
  }
  delay(10);
}