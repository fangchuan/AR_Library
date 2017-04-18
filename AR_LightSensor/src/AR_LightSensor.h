/*
*********************************************************************************************************
*
* ģ������ : �������������
* �ļ����� : AR_LightSensor.h
* ��    �� : V1.0
* ˵    �� : 
*
* Copyright (C), 2015-2020, �����޿Ƽ� www.apollorobot.cn
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
/***************************** �����޿Ƽ� www.apollorobot.cn (END OF FILE) *********************************/
