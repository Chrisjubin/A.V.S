// Include RadioHead Amplitude Shift Keying Library
#include <RH_ASK.h>
// Include dependant SPI Library
#include <SPI.h>

const byte front = 6;
const byte back = 7;
const byte right = 8;
const byte left = 9;

byte motonum = 0;

// Create Amplitude Shift Keying Object
RH_ASK rf_driver;

void setup() {
  pinMode(front, INPUT_PULLUP);
  pinMode(back, INPUT_PULLUP);
  pinMode(right, INPUT_PULLUP);
  pinMode(left, INPUT_PULLUP);


  // Initialize ASK Object
  rf_driver.init();
}

void loop() {

  if (digitalRead(front) == LOW) {
    motonum = 1;
  }




  if (digitalRead(back) == LOW) {
    motonum = 2;
  }




  if (digitalRead(right) == LOW) {
    motonum = 3;
  }



  if (digitalRead(left) == LOW) {
    motonum = 4;
  }

  if (digitalRead(left) == HIGH && digitalRead(right) == HIGH && digitalRead(back) == HIGH && digitalRead(front) == HIGH) {
    motonum = 0;
  }





  char *msg = motonum;
  rf_driver.send((uint8_t *)&motonum, sizeof motonum);
  rf_driver.waitPacketSent();
  delay(50);
}