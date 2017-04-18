/*
*********************************************************************************************************
*
* 模块名称 : 敲击传感器类库
* 文件名称 : AR_KnockSensor.h
* 版    本 : V1.0
* 说    明 : 
*
* Copyright (C), 2015-2020, 阿波罗科技 www.apollorobot.cn
*
*********************************************************************************************************
*/
#ifndef  __AR_KNOCKSENSOR_H
#define  __AR_KNOCKSENSOR_H

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

class AR_KnockSensor{
public:
		AR_KnockSensor(uint8_t p);
		
		uint8_t getStatu();
private:
		uint8_t pin;
};


#endif
/***************************** 阿波罗科技 www.apollorobot.cn (END OF FILE) *********************************/
