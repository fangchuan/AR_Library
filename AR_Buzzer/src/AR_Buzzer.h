/*
*********************************************************************************************************
*
* ģ������ : ���������
* �ļ����� : AR_Buzzer.h
* ��    �� : V1.0
* ˵    �� : 
*
* Copyright (C), 2015-2020, �����޿Ƽ� www.apollorobot.cn
*
*********************************************************************************************************
*/
#ifndef  __AR_BUZZER_H
#define  __AR_BUZZER_H

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

class AR_Buzzer{
public:
		AR_Buzzer(uint8_t p);
		void tone(int note,int beats);
private:
		uint8_t pin;
};


#endif
/***************************** �����޿Ƽ� www.apollorobot.cn (END OF FILE) *********************************/
