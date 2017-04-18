/*
*********************************************************************************************************
*
* 模块名称 : 编码器类库
* 文件名称 : AR_Encoder.h
* 版    本 : V1.0
* 说    明 : 
*
* Copyright (C), 2015-2020, 阿波罗科技 www.apollorobot.cn
*
*********************************************************************************************************
*/
#ifndef  __AR_ENCODER_H
#define  __AR_ENCODER_H

#include <Arduino.h>
#include <stdbool.h>
#include <avr/interrupt.h>

#define DIRECT_MODE       0x00
#define PID_MODE          0x01
#define PWM_MODE          0x02

#define MOTION_WITH_POS        0x00
#define MOTION_WITHOUT_POS     0x01

#define PWM_MIN_OFFSET                 25
#define ENCODER_POS_DEADBAND           10
#define DECELERATION_DISTANCE_PITCH    6 

class AR_Encoder{
public:
		AR_Encoder(uint8_t s1, uint8_t s2);
		
		int16_t calcMotorSpeed();
		int16_t calcMotorAverageSpeed();
		int calcMotorMileaga();
private:
		uint8_t s1_pin;
		uint8_t s2_pin;
	
};
//
//
//
typedef struct
{
  float P, I, D;
  float Setpoint, Output, Integral, differential, last_error;
} PID_internal;

typedef struct
{
  uint8_t mode;
  uint8_t motionState;

  int16_t pulseEncoder;
  int16_t currentPwm;
  int16_t targetPwm;
  int16_t previousPwm;

  float currentSpeed;
  float targetSpeed;
  float previousSpeed;
  float ratio;

  long currentPos;
  long targetPos;
  long previousPos;
  long pulsePos;
 
  PID_internal  PID_speed;
  PID_internal  PID_pos;
}Me_Encoder_type;

typedef struct
{
  uint8_t port_A;   //ENABLE
  uint8_t port_B;   //DIR
  uint8_t port_PWM; //PWM
  uint8_t port_H1;
  uint8_t port_H2;
} Encoder_port_type;

extern Encoder_port_type encoder_Port[6];  // encoder_Port[0] is nonsense
typedef void (*cb)(int16_t,int16_t); 


class MeEncoderOnBoard 
{
public:
  MeEncoderOnBoard();

  MeEncoderOnBoard(uint8_t slot);

  void reset(uint8_t slot);

  uint8_t getSlotNum(void);

  uint8_t getIntNum(void);

  uint8_t getPortA(void);

  uint8_t getPortB(void);

  long getPulsePos(void);

  void setPulsePos(long pulse_pos);

  void pulsePosPlus(void);

  void pulsePosMinus(void);

  void setCurrentSpeed(float speed);

  float getCurrentSpeed(void);

  int16_t getCurPwm(void);

  void setTarPWM(int16_t pwm_value);

  void setMotorPwm(int16_t pwm);
  
  void updateSpeed(void);

  void updateCurPos(void);

  long getCurPos(void);

  void runSpeed(float speed);

  void setSpeed(float speed);

  void move(long position,float speed = 100,int16_t extId=0,cb callback=NULL);

  void moveTo(long position,float speed = 100,int16_t extId=0,cb callback=NULL);
  
  long distanceToGo();

  void setSpeedPid(float p,float i,float d);

  void setPosPid(float p,float i,float d);

  void setPulse(int16_t pulseValue);

  void setRatio(int16_t RatioValue);

  void setMotionMode(int16_t motionMode);

  int16_t pidPositionToPwm(void);

  int16_t speedWithoutPos(void);

  void encoderMove(void);

  void pwmMove(void);

  boolean isTarPosReached(void);

  void loop(void);

private:
   volatile Me_Encoder_type encode_structure;
   boolean _Lock_flag;
   boolean _Dir_lock_flag;
   uint8_t _extId;
   uint8_t _Port_A;
   uint8_t _Port_B;
   uint8_t _Port_PWM;
   uint8_t _Port_H1;
   uint8_t _Port_H2;
   uint8_t _IntNum;
   uint8_t _Slot;
   int16_t _Encoder_output;
   long _Measurement_speed_time;
   long _Encoder_move_time;
   cb _callback;
};
#endif
#endif
/***************************** 阿波罗科技 www.apollorobot.cn (END OF FILE) *********************************/
