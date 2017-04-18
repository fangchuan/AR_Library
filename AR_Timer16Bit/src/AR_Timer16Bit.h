/*
*********************************************************************************************************
*
* 模块名称 : 16bit定时器类库
* 文件名称 : AR_Timer16Bit.h
* 版    本 : V1.0
* 说    明 : Atmega328P只有一个16bit定时器/计数器
* 修订记录 :2017-3-13:本考虑采用Singleton，但考虑到向后兼容，采用instance计数方式
*			2017-3-14:16bit定时器可以最大定时4194240us,当F_CPU=16MHZ,1024分频
*					  而8bit定时器最大值可定时16384us
*
* Copyright (C), 2015-2020, 阿波罗科技 www.apollorobot.cn
*
*********************************************************************************************************
*/
#ifndef __AR_TIMER16BIT_H
#define __AR_TIMER16BIT_H

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif
#include <avr/io.h>
#include <avr/interrupt.h>

#define RESOLUTION 65536    // Timer1 is 16 bit
#if  ATMEGA328P
	#define MAX_INSTANCES  1
#endif	

class AR_Timer16Bit
{
  private:
    // properties
    unsigned int pwmPeriod;
    unsigned char clockSelectBits;
	static  unsigned char instances;
  public:
    // methods
	AR_Timer16Bit();
	~AR_Timer16Bit();
    void initialize(long microseconds = 1000000);
    void start();
    void stop();
    void restart();
    void setPwm(char pin, int duty, long microseconds=-1);
    void disablePwm(char pin);
    void attachInterrupt(void (*isrOvf)(), void (*isrCapt)(), long microseconds = -1);
    void detachInterrupt();
    void setPeriod(long microseconds);
    void setPwmDuty(char pin, int duty);
    void (*isrOVFCallBack)();
	void (*isrCAPTCallBack)();
};

extern AR_Timer16Bit Timer16Bit;


#endif
/***************************** 阿波罗科技 www.apollorobot.cn (END OF FILE) *********************************/
