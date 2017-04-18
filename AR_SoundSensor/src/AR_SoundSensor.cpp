/*
*********************************************************************************************************
*
* 模块名称 : 声音传感器类库
* 文件名称 : AR_SoundSensor.cpp
* 版    本 : V1.0
* 说    明 : 
* 修订记录 :

* Copyright (C), 2015-2020, 阿波罗科技 www.apollorobot.cn
*
*********************************************************************************************************
*/
#include "AR_SoundSensor.h"

/*
*********************************************************************************************************
*	函 数 名: AR_SoundSensor()构造函数
*	功能说明:  
*	形    参: dp: digital port to sound sensor
*			  ap: analog port to sound sensor
*	返 回 值: 无
*********************************************************************************************************
*/
AR_SoundSensor::AR_SoundSensor(uint8_t dp, uint8_t ap)
{
	digital_pin = dp;
	analog_pin = ap;
	pinMode(digital_pin, INPUT_PULLUP);
}
/*
*********************************************************************************************************
*	函 数 名: ifSound
*	功能说明: if there is sound or not
*	形    参: 无
*	返 回 值: 0: no
*			  1: yes
*********************************************************************************************************
*/
uint8_t  AR_SoundSensor::ifSound()
{
	pinMode(digital_pin, INPUT_PULLUP);
	if( digitalRead(digital_pin) == HIGH)
		return 0;
	else
		return 1;
}
/*
*********************************************************************************************************
*	函 数 名: getSound
*	功能说明: get sound intensity
*	形    参: 无
*	返 回 值: 0~1023
*********************************************************************************************************
*/
int AR_SoundSensor::getSound()
{
	switch(analog_pin){
	case 0:
		return analogRead(A0);
	case 1:
		return analogRead(A1);
	case 2:
		return analogRead(A2);
	case 3:
		return analogRead(A3);
	}
	
}

/***************************** 阿波罗科技 www.apollorobot.cn (END OF FILE) *********************************/
