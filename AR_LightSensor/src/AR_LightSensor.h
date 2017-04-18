/*
*********************************************************************************************************
*
* 模块名称 : 光敏传感器类库
* 文件名称 : AR_LightSensor.h
* 版    本 : V1.0
* 说    明 : 
*
* Copyright (C), 2015-2020, 阿波罗科技 www.apollorobot.cn
*
*********************************************************************************************************
*/
#ifndef  __AR_LIGHT_SENSOR_H
#define  __AR_LIGHT_SENSOR_H

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif


class AR_LightSensor{
public:
		AR_LightSensor(uint8_t p);
		
		int getLight();//0~1023
		
private:
		uint8_t pin;
};


#endif
/***************************** 阿波罗科技 www.apollorobot.cn (END OF FILE) *********************************/
