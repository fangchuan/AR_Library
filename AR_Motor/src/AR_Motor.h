/*
*********************************************************************************************************
*
* 模块名称 : 直流电机类库
* 文件名称 : AR_Motor.h
* 版    本 : V1.0
* 说    明 : 
*
* Copyright (C), 2015-2020, 阿波罗科技 www.apollorobot.cn
*
*********************************************************************************************************
*/
#ifndef  __AR_MOTOR_H
#define  __AR_MOTOR_H

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#define  AR_MOTORS_MAX_NUM         3
#define  AR_MOTORS_SPEED_MAX       255 
#define  AR_MOTORS_SPEED_DEFAULT   100
#define  AR_MOTOR_SPEED_MIN        50

typedef  struct _MotorPin{
         uint8_t directionPin;
         uint8_t PWMPin;
  }_MotorPin;
  
class AR_Motor{
public:
	  AR_Motor(uint8_t dir_pin, uint8_t pwm_pin);
      // AR_Motor(uint8_t dir_pin, uint8_t pwm_pin, uint8_t s1_pin, uint8_t s2_pin);
      ~AR_Motor();
      // void setDesiredSpeed(int tar);
      // void setDesiredDistance(int tar);
      // int getSpeed();
      // int getDistance();
      void run(int tar= AR_MOTORS_SPEED_DEFAULT);
	  
	  uint8_t pwm_out;
private:
      // int  cur_speed;//unit cm/s
      int  tar_speed;//unit cm/s
      // int  cur_distance;//unit cm
      // int  tar_distance;//unit cm
      
      
      // AR_Encoder* encoder;
      _MotorPin    motorPin;
};


#endif
/***************************** 阿波罗科技 www.apollorobot.cn (END OF FILE) *********************************/

