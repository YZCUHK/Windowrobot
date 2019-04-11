#include "m_motor.h"
#include "m_vardef.h"
#include "Arduino.h"
/******************************************/
void m_motor::mmotor(int ifrev, char MotorNUM, int dirflag, long pos, long vel)
{
	if (ifrev == 1)
	{
		switch (MotorNUM)
		{
		case '1':
		m_motor::mstepperLin(dirflag,pos,vel);
		break;
		case '2': 
    m_motor::mstepperRot(dirflag,pos,vel);
    break;
		case '3':
		m_motor::mDCmotor(dirflag);
		break;
    case '4':
    m_motor::mDCmotorclean(dirflag);
    break;
    case '5':
    m_motor::mDCmotorPumpclean(dirflag);
    break;
    case '6':
    m_motor::mDCmotorPumpsewage(dirflag);
    break;
    case '7':
    m_motor::mRopeClimb(dirflag,pos,vel); //A DC servo motor actuated using CAN bus
    break;
    case '8':
    m_motor::mSteeringGearV(dirflag,pos);
    break;
    case '9':
    m_motor::mSteeringGearH(dirflag,pos);
    break;
		}
	}
  MotorNUM = '0';
  ifrev = 0;
}
/******************************************/
  void m_motor::mstepperRot(int dirflag, long pos, long vel)//0.05°/pul
{
  switch (dirflag)
  {
      case 1://正转
      digitalWrite(dir2, HIGH);
      for (int i = 0; i < pos; i++)
      {
   
        digitalWrite(pls2, HIGH);
        delayMicroseconds(vel);
        digitalWrite(pls2, LOW);
        delayMicroseconds(vel);
      }
      lastposRot=lastposRot+pos;
      Serial.println("motor positive");
      delay(500);
      MotorNUM = '0';
      ifrev = 0;
      break;
      
      case 2:
      digitalWrite(dir2, LOW);//
      for (int i = 0; i < pos; i++)
      {
        
        digitalWrite(pls2, HIGH);
        delayMicroseconds(vel);
        digitalWrite(pls2, LOW);
        delayMicroseconds(vel);
      }
      lastposRot=lastposRot-pos;
      Serial.println("motor negative");
      delay(500);
      MotorNUM = '0';
      ifrev = 0;
      break;
      
      case 0:
      Serial.println("motor stop");
      delay(500);
      MotorNUM = '0';
      ifrev = 0;
      break;
    }
      MotorNUM = '0';
      ifrev = 0;
  }
/******************************************/
  void m_motor::mstepperLin(int dirflag, long pos, long vel)//0.05mm/pul
{
  
  switch (dirflag)
  {
      case 1:
      digitalWrite(dir1, HIGH);//
      for (int i = 0; i < pos; i++)
      {
      
        digitalWrite(pls1, HIGH);
        delayMicroseconds(vel);
        digitalWrite(pls1, LOW);
        delayMicroseconds(vel);
      }
      lastposLin=lastposLin+pos;
      Serial.println("motor positive");
      delay(500);
      MotorNUM = '0';
      ifrev = 0;      
      break;
      
      case 2:
      digitalWrite(dir1, LOW);//
      for (int i = 0; i < pos; i++)
      {
        
        digitalWrite(pls1, HIGH);
        delayMicroseconds(vel);
        digitalWrite(pls1, LOW);
        delayMicroseconds(vel);
      }
      lastposLin=lastposLin-pos;
      Serial.println("motor negative");
      delay(500);
      MotorNUM = '0';
      ifrev = 0;      
      break;
      
      case 0:
      Serial.println("motor stop");
      delay(500);
      MotorNUM = '0';
      ifrev = 0;   
      break;
  }
      MotorNUM = '0';
      ifrev = 0;
}
/******************************************/
void m_motor::mDCmotor(int dirflag)
{
  if (dirflag == 1)//正转
    {
      m_motor::mDCmotorstop();
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, HIGH);
      Serial.println("motor positive");
    }
  else if (dirflag == 2)//反转
    {
      m_motor::mDCmotorstop();
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, HIGH);
      Serial.println("motor negative");
    }
  else//停止
    {
      m_motor::mDCmotorstop();
      Serial.println("motor stop");
    }
  MotorNUM = '0';
  ifrev = 0;
  }
/******************************************/
void m_motor::mDCmotorstop()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(500);
  }
/******************************************/
void m_motor::mDCmotorclean(int dirflag)
{
  if (dirflag==1)
  {
   digitalWrite(IN5, HIGH);
   }
  else
  {
   digitalWrite(IN5, LOW);
   }
   MotorNUM = '0';
   ifrev = 0;
  }
 /******************************************/ 
  void m_motor::mDCmotorPumpclean(int dirflag)
{
  if (dirflag==1)
  {
   digitalWrite(IN6, HIGH);
   }
  else
  {
   digitalWrite(IN6, LOW);
   }
   MotorNUM = '0';
   ifrev = 0;
  }
  /******************************************/
    void m_motor::mDCmotorPumpsewage(int dirflag)
{
  if (dirflag==1)
  {
   digitalWrite(IN7, HIGH);
   }
  else
  {
   digitalWrite(IN7, LOW);
   }
   MotorNUM = '0';
   ifrev = 0;
  }
  /*********************************************************************/
    void m_motor::mRopeClimb(int dirflag,long pos, long vel)//Rope climbing,CAN bus
{
  byte reset[14];//reset the motor
  delay(500);
  reset[0]=0x00;
  reset[1]=0x00;
  reset[2]=0x00;
  reset[3]=0x00;
  reset[4]=0x10;
  reset[5]=0x08;
  reset[6]=0x55;
  reset[7]=0x55;
  reset[8]=0x55;
  reset[9]=0x55;
  reset[10]=0x55;
  reset[11]=0x55;
  reset[12]=0x55;
  reset[13]=0x55;
  Serial1.write(reset,14);
  delay(500);
  byte setmode[14];//set mode for actuator
  setmode[0]=0x00;  
  setmode[1]=0x00;
  setmode[2]=0x00;
  setmode[3]=0x00;
  setmode[4]=0x11;
  setmode[5]=0x08;
  setmode[6]=0x05;
  setmode[7]=0x55;
  setmode[8]=0x55;
  setmode[9]=0x55;
  setmode[10]=0x55;
  setmode[11]=0x55;
  setmode[12]=0x55;
  setmode[13]=0x55;
  Serial1.write(setmode,14);
  delay(500);
  
  byte command[14];//command for motor
  int temp_pwm=5000;
  int temp_velocity=0;//unit,rpm
  long temp_position=0;//unit,qc
  if (dirflag==1)//positive direction
  {
    temp_velocity=vel;//3000 is OK for vel when debugging
    temp_position=pos;//100000 is OK for pos when debugging
    command[0]=0x00;
    command[1]=0x00;
    command[2]=0x00;
    command[3]=0x00;
    command[4]=0x16;
    command[5]=0x08;
    command[6]=(unsigned char)((temp_pwm>>8)&0xff);
    command[7]=(unsigned char)(temp_pwm&0xff);
    command[8]=(unsigned char)((temp_velocity>>8)&0xff);
    command[9]=(unsigned char)(temp_velocity&0xff);
    command[10]=(unsigned char)((temp_position>>24)&0xff);
    command[11]=(unsigned char)((temp_position>>16)&0xff);
    command[12]=(unsigned char)((temp_position>>8)&0xff);
    command[13]=(unsigned char)(temp_position&0xff);
    Serial1.write(command,14);
    delay(100);//no less than 1ms.Here is 100 ms
   }
  else//negative direction
  {
    temp_velocity=vel;//3000 is OK for vel when debugging
    temp_position=-pos;//100000 is OK for pos when debugging
    command[0]=0x00;
    command[1]=0x00;
    command[2]=0x00;
    command[3]=0x00;
    command[4]=0x16;
    command[5]=0x08;
    command[6]=(unsigned char)((temp_pwm>>8)&0xff);
    command[7]=(unsigned char)(temp_pwm&0xff);
    command[8]=(unsigned char)((temp_velocity>>8)&0xff);
    command[9]=(unsigned char)(temp_velocity&0xff);
    command[10]=(unsigned char)((temp_position>>24)&0xff);
    command[11]=(unsigned char)((temp_position>>16)&0xff);
    command[12]=(unsigned char)((temp_position>>8)&0xff);
    command[13]=(unsigned char)(temp_position&0xff);
    Serial1.write(command,14);
    delay(100);//no less than 1ms.Here is 100 ms
   }

   MotorNUM = '0';
   ifrev = 0;
  }
  /**************************************************************************/
/*PWM steering gear motor,rotate about vertical axis,pos from 0~900, represents 0~90 degree,
direction from rignt hand theory*/
void m_motor::mSteeringGearV(int dirflag,long pos)             
{
    if (dirflag==1)       //postive direction
  {
   analogWrite(STV,pos);//analogWrite(pin, value),value:0~255
   }
  else                    //negative direction
  {
  analogWrite(STV,pos);//analogWrite(pin, value),value:0~255
   }
   MotorNUM = '0';
   ifrev = 0;
  Serial.print("Vp");
 }
/*PWM steering gear motor,rotate about horizontal axis,pos from 0~900, represents 0~90 degree,
direction from rignt hand theory*/
void m_motor::mSteeringGearH(int dirflag,long pos)             //PWM steering gear motor,rotate about vertical axis
{
    if (dirflag==1)       //postive direction
  {
   analogWrite(STH,pos);//analogWrite(pin, value),value:0~255
   }
  else                    //negative direction
  {
  analogWrite(STH,pos);//analogWrite(pin, value),value:0~255
   }
   MotorNUM = '0';
   ifrev = 0;  
  Serial.print("Hq");
  }
