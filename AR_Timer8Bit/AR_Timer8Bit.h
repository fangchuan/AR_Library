/*
*********************************************************************************************************
*
* 模块名称 : 8bit定时器类库
* 文件名称 : AR_Timer8Bit.h
* 版    本 : V1.0
* 说    明 : Atmega328P有2个8bit定时器/计数器
* 修订记录 :2017-3-14：8bit定时器最大值可定时16384us， 当F_CPU:
*
* Copyright (C), 2015-2020, 阿波罗科技 www.apollorobot.cn
*
*********************************************************************************************************
*/
#ifndef __AR_TIMER8BIT_H
#define __AR_TIMER8BIT_H

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif
#include <avr/io.h>
#include <avr/interrupt.h>

#define RESOLUTION 255    // Timer0/2 is 8 bit
#if  ATMEGA328P
	#define MAX_INSTANCES  2
#endif	

class AR_Timer8Bit
{
  private:
    // properties
    unsigned int pwmPeriod;
    unsigned char clockSelectBits;
	static  unsigned char instances;
  public:
    // methods
	AR_Timer8Bit();
	~AR_Timer8Bit();
    void initialize(long microseconds = 1000000);
    void start();
    void stop();
    void restart();
    void setPwm(char pin, int duty, long microseconds=-1);
    void disablePwm(char pin);
    void attachInterrupt(void (*isrOvf)(), long microseconds = -1);
    void detachInterrupt();
    void setPeriod(long microseconds);
    void setPwmDuty(char pin, int duty);
    void (*isrOVFCallBack)();

};



#endif
/***************************** 阿波罗科技 www.apollorobot.cn (END OF FILE) *********************************/
