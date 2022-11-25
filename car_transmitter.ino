/* How to configure and pair two HC-05 Bluetooth Modules 
*               == MASTER CODE ==                
*/

#include <SoftwareSerial.h>
SoftwareSerial mySerial(8, 9); // RX, TX
 


#define button A0
#define button2 A1
#define button3 A2
#define button4 A3


int buttonstate;
int buttonstate2;
int buttonstate3;
int buttonstate4;

void setup() { // put your setup code here, to run once
 pinMode(button, INPUT_PULLUP);
 pinMode(button2, INPUT_PULLUP);
pinMode(button3, INPUT_PULLUP);
pinMode(button4, INPUT_PULLUP);

 Serial.begin(9600); // Begin serial communication with Arduino and Arduino IDE (Serial Monitor) 
 mySerial.begin(9600); // Default communication rate of the Bluetooth module

}

void loop() { 
 // Reading the button
 buttonstate = digitalRead(button);
 buttonstate2 = digitalRead(button2);
 buttonstate3 = digitalRead(button3);
 buttonstate4 = digitalRead(button4);

 if (digitalRead(button) == LOW) { //send  data to slave
  mySerial.write('1'); 
 }
 else if (digitalRead(button2) == LOW)
 {
   mySerial.write('2');
 }  
 else if (digitalRead(button3) == LOW)
 {
   mySerial.write('3');
 } 
 else if (digitalRead(button4) == LOW)
 {
   mySerial.write('4');
 }
 else
 {
   mySerial.write('0');
 }  

}

