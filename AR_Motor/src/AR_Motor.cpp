/*
*********************************************************************************************************
*
* 模块名称 : 直流电机类库
* 文件名称 : AR_Motor.cpp
* 版    本 : V1.0
* 说    明 : 
*
* Copyright (C), 2015-2020, 阿波罗科技 www.apollorobot.cn
*
*********************************************************************************************************
*/
#include "AR_Motor.h"
#include <math.h>
/*
*********************************************************************************************************
*	函 数 名: AR_Motor()构造函数
*	功能说明:  
*	形    参: dir_pin: direction control pin
*			  pwm_pin: pwm control pin
*			  s1_pin:  encoder signal 1 pin
*			  s2_pin:  encoder signal 2 pin
*	返 回 值: 无
*********************************************************************************************************
*/
AR_Motor::AR_Motor(uint8_t dir_pin, uint8_t pwm_pin)
{
      motorPin.directionPin = dir_pin;
      motorPin.PWMPin = pwm_pin;
	  tar_speed = 0;
	  pwm_out = 0;
	  
	  pinMode(motorPin.directionPin, OUTPUT);
	  pinMode(motorPin.PWMPin, OUTPUT);
}

// AR_Motor::AR_Motor(uint8_t dir_pin, uint8_t pwm_pin, uint8_t s1_pin, uint8_t s2_pin)
// {
      // motorPin.directionPin = dir_pin;
      // motorPin.PWMPin = pwm_pin;
      // encoder = new AR_Encoder(s1_pin, s2_pin);
      // cur_speed = 0;  
      // tar_speed = 0;
      // cur_distance = 0;
      // tar_distance = 0;
      // pwm_out = 0;
	  
	  // pinMode(motorPin.directionPin, OUTPUT);
	  // pinMode(motorPin.PWMPin, OUTPUT);
// }
AR_Motor::~AR_Motor()
{
    // delete encoder;
    // encoder = NULL;
}
/*
*********************************************************************************************************
*	函 数 名: setDesiredSpeed
*	功能说明:  
*	形    参: tar: target speed
*	返 回 值: 无
*********************************************************************************************************
*/
// void AR_Motor::setDesiredSpeed(int tar)
// {
    // tar_speed  =  (tar > AR_MOTORS_SPEED_MAX) ? AR_MOTORS_SPEED_MAX : tar;
// }
/*
*********************************************************************************************************
*	函 数 名: setDesiredDistance
*	功能说明:  
*	形    参: tar: target distance
*	返 回 值: 无
*********************************************************************************************************
*/
// void AR_Motor::setDesiredDistance(int tar)
// {
    // tar_distance  =  tar;
// }
/*
*********************************************************************************************************
*	函 数 名: getSpeed
*	功能说明: get current speed 
*	形    参: 
*	返 回 值: cur_speed
*********************************************************************************************************
*/
// int8_t AR_Motor::getSpeed()
// {
    // cur_speed = encoder.calcMotorAverageSpeed();
    // return cur_speed;
// }
/*
*********************************************************************************************************
*	函 数 名: getDistance
*	功能说明: get current meleaga 
*	形    参: 
*	返 回 值: cur_distance
*********************************************************************************************************
*/
// int AR_Motor::getDistance()
// {
    // cur_distance = encoder.calcMotorMileaga();
    // return cur_distance;
// }
/*
*********************************************************************************************************
*	函 数 名: run
*	功能说明: motor run  
*	形    参: tar:目标速度
*	返 回 值: 
*********************************************************************************************************
*/
void AR_Motor::run(int tar)
{	  
	tar_speed = (tar > AR_MOTORS_SPEED_MAX) ? AR_MOTORS_SPEED_MAX : tar;
    
	if(tar >= 0 )
    {
      pwm_out = tar_speed;
      digitalWrite(motorPin.directionPin, LOW);
      analogWrite(motorPin.PWMPin, pwm_out);
    }else{
	  pwm_out = -tar_speed;
	  digitalWrite(motorPin.directionPin, HIGH);
	  analogWrite(motorPin.PWMPin, pwm_out);
	}
}


/***************************** 阿波罗科技 www.apollorobot.cn (END OF FILE) *********************************/
