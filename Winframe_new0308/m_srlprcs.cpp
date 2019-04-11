
#include "m_init.h"
#include "m_srlprcs.h"
#include "Arduino.h"
#include "m_vardef.h"
void m_srlprcs::msrlprcs(char inNUM) 
{ 
	switch (inNUM)
	{
	case '0'...'9': data = data * 10 + inNUM - '0'; 
		break;
	case 'a':       MotorNUM = '1';
		break;
	case 'b':       MotorNUM = '2';
		break;
	case 'c':       MotorNUM = '3';
		break;
  case 'l':       MotorNUM = '4';
    break;
  case 'm':       MotorNUM = '5';
    break;
  case 'n':       MotorNUM = '6';
    break;
  case 'o':       MotorNUM = '7';
  break;
  case 'p':       MotorNUM = '8';       //Steering motor rotates about vertical axis,for camera
  break;
  case 'q':       MotorNUM = '9';       ////Steering motor rotates about horizontal axis,for camera
  break;
	case 'd':       ifrev = 1;
		break;
	case 'e':       velflag = 1;
		break;
	case 'f':       posflag = 1;
		break;
	case 'g':       dirflag = 1;//正转
		break;
	case 'h':       dirflag = 2;//反转
		break;
	case 'k':       dirflag = 0;//停转
		break;
	}
}

void m_srlprcs::motorvel()
{
  if (velflag==1)// for stepper,data should between 550 and 1400
   {
    vel=data;
    Serial.print("vel");Serial.println(vel);    
    data=0;
    velflag=0;
    data=0;
    velflag=0;
    //Serial.print("data");Serial.print(data); Serial.println(velflag);
    }
  }
void m_srlprcs::motorpos()
{
   if (posflag==1)
   {
    pos=data;
    Serial.print("pos");Serial.println(pos); 
    data=0;
    posflag=0;
    data=0;
    posflag=0;
    }
    //Serial.print("data"); Serial.print(data); Serial.println(posflag); 
 }
