#include "m_vardef.h"
#include "Arduino.h"
int ifrev;
int velflag;
int posflag;
int dirflag;
int lastposLin;
int lastposRot;
long pos;
long vel;
long data;
char inNUM;
char MotorNUM;
float distance;
float force; 

void g_init()
{
  ifrev = 0;
  velflag = 0;
  posflag = 0;
  dirflag = 0;
  lastposLin=0;
  lastposRot=0;
  pos=0;
  vel = 833;//for stepper,vel=833 corresponds to 3r/s
  data = 0;//
  inNUM = ' ';
  MotorNUM = '0';
  distance=0;
  force=0;
  }

