/*
*********************************************************************************************************
*
* ģ������ : ���⴫�������
* �ļ����� : AR_IRSensor.h
* ��    �� : V1.0
* ˵    �� : 
*
* Copyright (C), 2015-2020, �����޿Ƽ� www.apollorobot.cn
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
/***************************** �����޿Ƽ� www.apollorobot.cn (END OF FILE) *********************************/
