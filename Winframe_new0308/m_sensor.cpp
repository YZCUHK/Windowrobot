#include "m_sensor.h"
#include "m_vardef.h"
#include "Arduino.h"
/*ultrasonic sensor----used for the measurement of the distance between the base and the window*/
void m_sensor::multrasonic()
{   
  //generate a 10us-high pulse to trig TrigPin 
        digitalWrite(TrigPin, LOW); 
        delayMicroseconds(2); 
        digitalWrite(TrigPin, HIGH); 
        delayMicroseconds(10);
        digitalWrite(TrigPin, LOW); 
   //check pulse width, measure the distance 
        distance = pulseIn(EchoPin, HIGH) / 58.00;
        Serial.print('s'); 
        Serial.print('u');                        //ultrasonic
        Serial.print(distance);                   //unit cm
        Serial.println('z'); 
        delay(1000); 
  }
/*one dimension force sensor----used to measure the contact force between the cleaning head and the window*/
void m_sensor::mone_dimforce()
{
        int ForceSensorValue=0;
        ForceSensorValue=analogRead(OneForce);
        force=map(ForceSensorValue, 0, 1023, 0, 255);
        Serial.print('s'); 
        Serial.print('t');                         //toutch
        Serial.print(force);                       //unit N
        Serial.println('z'); 
        delay(1000); 
  }
