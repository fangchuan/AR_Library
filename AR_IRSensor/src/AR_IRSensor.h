/*
*********************************************************************************************************
*
* 模块名称 : 红外传感器类库
* 文件名称 : AR_IRSensor.h
* 版    本 : V1.0
* 说    明 : 
*
* Copyright (C), 2015-2020, 阿波罗科技 www.apollorobot.cn
*
*********************************************************************************************************
*/
#ifndef  __AR_IRSENSOR_H
#define  __AR_IRSENSOR_H

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

class AR_IRSensor{
public:
		AR_IRSensor(uint8_t p);
		
		uint8_t getStatu();
	
private:
		uint8_t pin;
};


#endif
/***************************** 阿波罗科技 www.apollorobot.cn (END OF FILE) *********************************/
