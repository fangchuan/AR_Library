/*
*********************************************************************************************************
*
* 模块名称 : 声音传感器类库
* 文件名称 : AR_SoundSensor.h
* 版    本 : V1.0
* 说    明 : 
*
* Copyright (C), 2015-2020, 阿波罗科技 www.apollorobot.cn
*
*********************************************************************************************************
*/
#ifndef  __AR_SOUNDSENSOR_H
#define  __AR_SOUNDSENSOR_H

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif


class AR_SoundSensor{
public:
		AR_SoundSensor(uint8_t dp, uint8_t ap);
		uint8_t ifSound();
		int getSound();
private:
		uint8_t digital_pin;
		uint8_t analog_pin;
	
};





#endif
/***************************** 阿波罗科技 www.apollorobot.cn (END OF FILE) *********************************/
