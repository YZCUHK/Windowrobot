#include "m_vardef.h"
#include "m_init.h"
#include "Arduino.h"
void m_init::minit()
{
	pinMode(pls1, OUTPUT);
	pinMode(dir1, OUTPUT);
	pinMode(ena1, OUTPUT);
	pinMode(pls2, OUTPUT);
	pinMode(dir2, OUTPUT);
	pinMode(ena2, OUTPUT);
	pinMode(IN1, OUTPUT);
	pinMode(IN2, OUTPUT);
	pinMode(IN3, OUTPUT);
	pinMode(IN4, OUTPUT);
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(CTL1, OUTPUT);
  digitalWrite(ena1,LOW);//enable
  digitalWrite(ena2,LOW);//enable
  pinMode(TrigPin, OUTPUT);          //ultrasonic sensor
  pinMode(EchoPin, INPUT);           //ultrasonoc sensor
  pinMode(OneForce, INPUT);           //one dimensional force
}
