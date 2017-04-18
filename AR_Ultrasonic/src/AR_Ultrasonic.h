/*
*********************************************************************************************************
*
* ģ������ : ���������������
* �ļ����� : AR_Ultrasonic.h
* ��    �� : V1.0
* ˵    �� : 
*
* Copyright (C), 2015-2020, �����޿Ƽ� www.apollorobot.cn
*
*********************************************************************************************************
*/
#ifndef  __AR_ULTRASONIC_H
#define  __AR_ULTRASONIC_H

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#define  TIMEOUT_DEFAULT  24000

class AR_Ultrasonic{
public:
		AR_Ultrasonic(uint8_t trig, uint8_t echo);
				
		double getDistance();
private:
		uint8_t trig_pin;
		uint8_t echo_pin;
};



#endif
/***************************** �����޿Ƽ� www.apollorobot.cn (END OF FILE) *********************************/
