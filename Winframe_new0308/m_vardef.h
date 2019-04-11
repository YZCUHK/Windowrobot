/*------------------------------------------------------------------------------------------------------------
IN1~IN4:positive or reversal motion of the motor,here, it controls the rope climbing robot to climb up an down
IN5:Motor of the cleaning head,can not change direction.
IN6:Motor of the diaphragm pump for clean water
IN7:Motor of the diaphragm pump for sewage
------------------------------------------------------------------------------------------------------------*/
#pragma once
#ifndef m_vardef_h
#define m_vardef_h
#define STV 6               //steering motor,rotate about vertical axis,for upper camera.'white,red,black'for signal,power,ground 
#define STH 7               //steering motor,rotate about horizontal axis,for upper camera.'orange,red,brown'for signal,power,ground
#define IN1 8               //IN1~IN4: control the rope climbing robot to climb up an down in old hardware version 
#define IN2 9
#define IN3 10
#define IN4 11
#define IN5 12              //Motor of the cleaning head , can not change direction.

#define IN7 14              //Motor of the diaphragm pump for sewage
#define IN6 15              //Motor of the diaphragm pump for clean water
#define CTL1 16             //Direction of the RopeClimb
#define TrigPin 4          //distance measurement by ultrasonic sensor,4,5,'brown,red,orange,yellow'for vcc,trig,echo,gnd'
#define EchoPin 5
#define pls1 19              //For translational degree of the window frame
#define dir1 20
#define ena1 21
#define pls2 22              //For rotational degree of the window frame
#define dir2 23
#define ena2 24
#define OneForce A0
extern int ifrev;
extern int velflag;
extern int posflag;
extern int dirflag;
extern long pos;
extern int lastposLin;
extern int lastposRot;
extern long vel;
extern long data;
extern char inNUM;
extern char MotorNUM;
extern float distance;       //measured by the ultrasonic sensor
extern float force;       //measured by the one dimension force sensor

void g_init();//用于初始化全局变量的全局函数；

#endif
