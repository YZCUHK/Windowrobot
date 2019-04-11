#include "m_vardef.h"//global veriable declaration
#include "m_init.h"//Pin function and variable initialization
#include "m_srlprcs.h"//Serial data processing function
#include "m_motor.h"
#include "m_sensor.h"
void setup() {
  Serial.begin(9600);
  Serial1.begin(115200);//for CAN bus
  //This is for PWM drive for RMDS.
  //TCCR0B = TCCR0B & B11111000 | B00000100;    // set timer 0 divisor to   256 for PWM frequency of   244.14 Hz,too lower frequency is not workable,this wil also influent delay() function
  //TCCR0B = TCCR0B & B11111000 | B00000011;      // set timer 0 divisor to    64 for PWM frequency of   976.56 Hz (Default)
  m_init::minit();
  g_init();
}
void loop() {
  //distance mesurement using ultrasonic sensor
  m_sensor::multrasonic();
  //one dimension force
  m_sensor::mone_dimforce();
  
  if (Serial.available()) 
  {
  inNUM = Serial.read();
  m_srlprcs::msrlprcs(inNUM);
  m_srlprcs::motorpos();
  m_srlprcs::motorvel(); 
  }
  m_motor::mmotor(ifrev, MotorNUM, dirflag, pos, vel);
  //Serial.print(ifrev);  Serial.print(MotorNUM);  Serial.print(dirflag);  Serial.print(pos);Serial.print(vel);Serial.println();
}
