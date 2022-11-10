  #include <RH_ASK.h>
  #include <SPI.h>

  byte switchpin = 12;
  
  byte irf = 10;
  byte irl = 9;
  byte irr = 8;
  byte buzz = 25;
  byte pir = 23;
  
  byte rightfront = 2;
  byte rightback = 3;
  byte leftfront = 4;
  byte leftback = 5;
  byte cb;

  bool switchon;
  RH_ASK driver;
  
  void setup()
  {
    pinMode(switchpin,INPUT_PULLUP);

    pinMode(irf, INPUT);
    pinMode(irl, INPUT);
    pinMode(irr, INPUT);

    pinMode(rightfront, OUTPUT);
    pinMode(rightback, OUTPUT);
    pinMode(leftfront, OUTPUT);
    pinMode(leftback, OUTPUT);
    
    driver.init();
  }
  
  void loop()
  {
      
     if(digitalRead(switchpin) == LOW)
     {
       switchon = true;
     }
     else
     {
       switchon = false;
     }



   if(switchon == true)
   {
    uint8_t data;
    uint8_t datalen = sizeof(data);
    
  
    if(data == 1)
    {
      //switch on motor driver front pins
      
      digitalWrite(rightfront,HIGH);
      digitalWrite(leftfront,HIGH);
      
      //switch off other back pins
      
      digitalWrite(rightback,LOW);
      digitalWrite(leftback,LOW);
      
      }
  
     else if(data == 2)
    {
      //switch on motor driver back pins
      
      digitalWrite(rightback,HIGH);
      digitalWrite(leftback,HIGH);
      
    //switch off other front pins
    
       digitalWrite(rightfront,LOW);
      digitalWrite(leftfront,LOW);
      
    }
  
    else if(data == 3)
    {
      //switch on right back and left front pins to turn right
      
     digitalWrite(rightback,HIGH);
      digitalWrite(leftfront,HIGH); 
      
     //set left back and front back to off
     
      digitalWrite(rightfront,LOW);
      digitalWrite(leftback,LOW);
     
      }
      
     else if(data == 4)
    {
      //switch on right front and left back pins to turn right
      
     digitalWrite(rightfront,HIGH);
      digitalWrite(leftback,HIGH); 
      
     //set left front and right back to off
     
      digitalWrite(rightback,LOW);
      digitalWrite(leftfront,LOW);
      }
      
     else if(data == 0) 
     {
      digitalWrite(rightfront,LOW);
      digitalWrite(leftfront,LOW);
       digitalWrite(rightback,LOW);
      digitalWrite(leftback,LOW);
      }

   }


    if(switchon = false)
    {
      Serial.begin(9600);


       if(digitalRead(pir) == HIGH)
       {
          digitalWrite(buzz,HIGH); 
          delay(30000);
          digitalWrite(buzz,LOW); 
       }

       if (digitalRead(irf) == LOW && digitalRead(irl) == LOW && digitalRead(irr) == LOW) {
    digitalWrite(rightfront, HIGH);
    digitalWrite(rightback, LOW);
    digitalWrite(leftfront, HIGH);
    digitalWrite(leftback, LOW);
    Serial.println("no obstacle , going front");
     if(digitalRead(pir) == HIGH)
       {
          digitalWrite(buzz,HIGH); 
          delay(30000);
          digitalWrite(buzz,LOW); 
       }

  } else if (digitalRead(irf) == LOW && digitalRead(irl) == LOW && digitalRead(irr) == HIGH) {
    digitalWrite(rightfront, HIGH);
    digitalWrite(rightback, LOW);
    digitalWrite(leftfront, HIGH);
    digitalWrite(leftback, LOW);
    Serial.println("right is near obstacle , going front");
     if(digitalRead(pir) == HIGH)
       {
          digitalWrite(buzz,HIGH); 
          delay(30000);
          digitalWrite(buzz,LOW); 
       }

  } else if (digitalRead(irf) == LOW && digitalRead(irl) == HIGH && digitalRead(irr) == LOW) {
    digitalWrite(rightfront, HIGH);
    digitalWrite(rightback, LOW);
    digitalWrite(leftfront, HIGH);
    digitalWrite(leftback, LOW);
    Serial.println("left is near obstacle , going front");
     if(digitalRead(pir) == HIGH)
       {
          digitalWrite(buzz,HIGH); 
          delay(30000);
          digitalWrite(buzz,LOW); 
       }

  } else if (digitalRead(irf) == LOW && digitalRead(irl) == HIGH && digitalRead(irr) == HIGH) {
    digitalWrite(rightfront, HIGH);
    digitalWrite(rightback, LOW);
    digitalWrite(leftfront, HIGH);
    digitalWrite(leftback, LOW);
    Serial.println("right and left is near obstacle , going front");
     if(digitalRead(pir) == HIGH)
       {
          digitalWrite(buzz,HIGH); 
          delay(30000);
          digitalWrite(buzz,LOW); 
       }

  } else if (digitalRead(irf) == HIGH && digitalRead(irl) == LOW && digitalRead(irr) == LOW) {
    digitalWrite(rightfront, LOW);
     digitalWrite(rightback,HIGH);
     digitalWrite(leftfront,HIGH);
     digitalWrite(leftback,LOW);
     Serial.println("obstacle infront ! , turning right");
      if(digitalRead(pir) == HIGH)
       {
          digitalWrite(buzz,HIGH); 
          delay(30000);
          digitalWrite(buzz,LOW); 
       }

     delay(600);
  } else if (digitalRead(irf) == HIGH && digitalRead(irl) == LOW && digitalRead(irr) == HIGH) {
    digitalWrite(rightfront, HIGH);
     digitalWrite(rightback,LOW);
     digitalWrite(leftfront,LOW);
     digitalWrite(leftback,HIGH);
     Serial.println("obstacle infront and on right , turning left");
      if(digitalRead(pir) == HIGH)
       {
          digitalWrite(buzz,HIGH); 
          delay(30000);
          digitalWrite(buzz,LOW); 
       }

     delay(600);
  } else if (digitalRead(irf) == HIGH && digitalRead(irl) == HIGH && digitalRead(irr) == LOW) {
    digitalWrite(rightfront, LOW);
     digitalWrite(rightback,HIGH);
     digitalWrite(leftfront,HIGH);
     digitalWrite(leftback,LOW);
     Serial.println("obstacle infront and on left , turning right");
      if(digitalRead(pir) == HIGH)
       {
          digitalWrite(buzz,HIGH); 
          delay(30000);
          digitalWrite(buzz,LOW); 
       }

     delay(600);
  } else if (digitalRead(irf) == HIGH && digitalRead(irl) == HIGH && digitalRead(irr) == HIGH) {
    digitalWrite(rightfront, LOW);
     digitalWrite(rightback,HIGH);
     digitalWrite(leftfront,LOW);
     digitalWrite(leftback,HIGH);
     delay(3500);
     cb = random(0,2);
     Serial.println("obstacle in front & right & left, going back and turning");
      if(digitalRead(pir) == HIGH)
       {
          digitalWrite(buzz,HIGH); 
          delay(30000);
          digitalWrite(buzz,LOW); 
       }

    
    if(cb == 0)
    {
     digitalWrite(rightfront, HIGH);
     digitalWrite(rightback,LOW);
     digitalWrite(leftfront,LOW);
     digitalWrite(leftback,HIGH);
     delay(600);
    } 
    else if(cb == 1)
    {
     digitalWrite(rightfront, LOW);
     digitalWrite(rightback,HIGH);
     digitalWrite(leftfront,HIGH);
     digitalWrite(leftback,LOW);
     delay(600);
    } 
  }

  delay(100);
    }


  }
