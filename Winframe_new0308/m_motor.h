#pragma once
#ifndef m_motor_h
#define m_motor_h

class m_motor
{

  
  public:
	static void mmotor(int ifrev, char MotorNUM, int dirflag,long pos, long vel);
  static void mstepperLin(int dirflag, long pos, long vel);
  static void mstepperRot(int dirflag, long pos, long vel);
  static void mDCmotor(int dirflag);
  static void mDCmotorstop();
  static void mDCmotorclean(int dirflag);//cleaning head
  static void mDCmotorPumpclean(int dirflag);//pump for clean water
  static void mDCmotorPumpsewage(int dirflag);//pump for sewage
  static void mRopeClimb(int dirflag, long pos, long vel);//DC servo for rope climbing,CAN bus
  static void mSteeringGearV(int dirflag,long pos);//PWM steering gear motor rotate about vertical axis
  static void mSteeringGearH(int dirflag,long pos);//PWM steering gear motor rotate about horizontal axis

};




#endif // !m_motor_h

