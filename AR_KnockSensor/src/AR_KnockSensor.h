/*
*********************************************************************************************************
*
* ģ������ : �û����������
* �ļ����� : AR_KnockSensor.h
* ��    �� : V1.0
* ˵    �� : 
*
* Copyright (C), 2015-2020, �����޿Ƽ� www.apollorobot.cn
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
/***************************** �����޿Ƽ� www.apollorobot.cn (END OF FILE) *********************************/
