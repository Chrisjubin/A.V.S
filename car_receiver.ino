#include <SPI.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX

byte switchpin = 33;
long duration;
int distance;
int safedist = 17;
int safefalldist = 3; 
byte usltrig = 13;
byte uslecho = 12;
//pin 10 and 11 for bt rx(10) and tx(11)
byte usrtrig = 7;
byte usrecho = 6;
byte usftrig = 23;
byte usfecho = 25;
byte usledgtrig = 8;
byte usledgecho = 9;
int leftdist;
int leftdur;
int frontdist;
int frontdur;
int rightdist;
int rightdur;

int ledgedist;
int ledgedur;
byte buzz = 27;
byte pir = 29;

byte rightfront = 2;
byte rightback = 3;
byte leftfront = 4;
byte leftback = 5;
byte cb;
int state = 0;

bool switchon;


void setup() {
  pinMode(switchpin, INPUT_PULLUP);

  pinMode(usfecho, INPUT);
  pinMode(usftrig, OUTPUT);
  pinMode(usrecho, INPUT);
  pinMode(usrtrig, OUTPUT);
  pinMode(uslecho, INPUT);
  pinMode(usltrig, OUTPUT);

  pinMode(rightfront, OUTPUT);
  pinMode(rightback, OUTPUT);
  pinMode(leftfront, OUTPUT);
  pinMode(leftback, OUTPUT);

   Serial.begin(9600); 
 mySerial.begin(9600);
}

void loop() {

  if (digitalRead(switchpin) == LOW) {
    switchon = true;
  } else {
    switchon = false;
  }



  if (switchon == true) {
    if(mySerial.available() > 0){ // Checks whether data is comming from the serial port
    state = mySerial.read(); // Reads the data from the serial port
 }
 // Controlling the motors
 if (state == '1') {
  digitalWrite(rightfront, HIGH);
  digitalWrite(rightback, LOW);
  digitalWrite(leftfront, HIGH);
  digitalWrite(leftback, LOW); 
 }
 else if (state == '2') {
  digitalWrite(rightfront, LOW);
  digitalWrite(rightback, HIGH);
  digitalWrite(leftfront, LOW);
  digitalWrite(leftback, HIGH);
 }
 else if (state == '3') {
  digitalWrite(rightfront, LOW);
  digitalWrite(rightback, HIGH);
  digitalWrite(leftfront, HIGH);
  digitalWrite(leftback, LOW);  
 }
  else if (state == '4') {
  digitalWrite(rightfront, HIGH);
  digitalWrite(rightback, LOW);
  digitalWrite(leftfront, LOW);
  digitalWrite(leftback, HIGH);
 }
 else
 {
   Serial.println("0 or unidentified");
   digitalWrite(rightfront, LOW);
  digitalWrite(rightback, LOW);
  digitalWrite(leftfront, LOW);
  digitalWrite(leftback, LOW);
 }

  }

  if (switchon = false) {

    digitalWrite(usftrig, LOW);
    digitalWrite(usltrig, LOW);
    digitalWrite(usrtrig, LOW);
    digitalWrite(usledgtrig, LOW);

    delayMicroseconds(2);

    digitalWrite(usftrig, HIGH);
    digitalWrite(usltrig, HIGH);
    digitalWrite(usrtrig, HIGH);
    digitalWrite(usledgtrig, HIGH);

    delayMicroseconds(10);

    digitalWrite(usftrig, LOW);
    digitalWrite(usltrig, LOW);
    digitalWrite(usrtrig, LOW);
    digitalWrite(usledgtrig, LOW);

    frontdur = pulseIn(usfecho, HIGH);
    leftdur = pulseIn(uslecho, HIGH);
    rightdur = pulseIn(usrecho, HIGH);
    ledgedur = pulseIn(usledgecho, HIGH);
    frontdist = frontdur * 0.034 / 2;
    leftdist = leftdur * 0.034 / 2;
    rightdist = rightdur * 0.034 / 2;
    ledgedist = ledgedur * 0.034 / 2;

    if (digitalRead(pir) == HIGH) {
      digitalWrite(buzz, HIGH);
      delay(30000);
      digitalWrite(buzz, LOW);
    }



    if (frontdist <= safedist && leftdist >= safedist && rightdist >= safedist) {

      //  Serial.println("obstacle infront ! , turning");
      cb = random(0, 2);
      if (cb == 0) {
        digitalWrite(rightfront, HIGH);
        digitalWrite(rightback, LOW);
        digitalWrite(leftfront, LOW);
        digitalWrite(leftback, HIGH);
        delay(600);
      } else if (cb == 1) {
        digitalWrite(rightfront, LOW);
        digitalWrite(rightback, HIGH);
        digitalWrite(leftfront, HIGH);
        digitalWrite(leftback, LOW);
        delay(600);
      }

      if (digitalRead(pir) == HIGH) {
        digitalWrite(buzz, HIGH);
        delay(30000);
        digitalWrite(buzz, LOW);
      }


    } if (frontdist <= safedist && leftdist >= safedist && rightdist <= safedist) {
      digitalWrite(rightfront, HIGH);
      digitalWrite(rightback, LOW);
      digitalWrite(leftfront, LOW);
      digitalWrite(leftback, HIGH);
      //  Serial.println("obstacle infront and on right , turning left");
      if (digitalRead(pir) == HIGH) {
        digitalWrite(buzz, HIGH);
        delay(30000);
        digitalWrite(buzz, LOW);
      }

      delay(600);
      
    } 
            
      else if (frontdist <= safedist && leftdist <= safedist && rightdist >= safedist) {
      digitalWrite(rightfront, LOW);
      digitalWrite(rightback, HIGH);
      digitalWrite(leftfront, HIGH);
      digitalWrite(leftback, LOW);
      delay(600);
      //   Serial.println("obstacle infront and on left , turning right");
      if (digitalRead(pir) == HIGH) {
        digitalWrite(buzz, HIGH);
        delay(30000);
        digitalWrite(buzz, LOW);
      }

      delay(600);
    } else if (frontdist <= safedist && leftdist <= safedist && rightdist <= safedist) {
      digitalWrite(rightfront, LOW);
      digitalWrite(rightback, HIGH);
      digitalWrite(leftfront, LOW);
      digitalWrite(leftback, HIGH);
      delay(3500);
      //  Serial.println("obstacle in front & right & left, going back and turning");
      if (digitalRead(pir) == HIGH) {
        digitalWrite(buzz, HIGH);
        delay(30000);
        digitalWrite(buzz, LOW);
      }

      cb = random(0, 2);

      if (cb == 0) {
        digitalWrite(rightfront, HIGH);
        digitalWrite(rightback, LOW);
        digitalWrite(leftfront, LOW);
        digitalWrite(leftback, HIGH);
        delay(600);
      } else if (cb == 1) {
        digitalWrite(rightfront, LOW);
        digitalWrite(rightback, HIGH);
        digitalWrite(leftfront, HIGH);
        digitalWrite(leftback, LOW);
        delay(600);
      }
    } else {
    digitalWrite(rightfront, HIGH);
    digitalWrite(rightback, LOW);
    digitalWrite(leftfront, HIGH);
    digitalWrite(leftback, LOW);
    }
  }
}