/*
*********************************************************************************************************
*
* ģ������ : �������������
* �ļ����� : AR_SoundSensor.h
* ��    �� : V1.0
* ˵    �� : 
*
* Copyright (C), 2015-2020, �����޿Ƽ� www.apollorobot.cn
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
/***************************** �����޿Ƽ� www.apollorobot.cn (END OF FILE) *********************************/
