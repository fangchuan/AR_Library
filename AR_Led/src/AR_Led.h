/*
*********************************************************************************************************
*
* ģ������ : LED���
* �ļ����� : AR_Led.h
* ��    �� : V1.0
* ˵    �� : 
*
* Copyright (C), 2015-2020, �����޿Ƽ� www.apollorobot.cn
*
*********************************************************************************************************
*/
#ifndef  __AR_LED_H
#define  __AR_LED_H


#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

class AR_Led{
public:
		AR_Led(uint8_t p);
		
		void setStatu(uint8_t statu);
		void toggleStatu();
private:
		uint8_t pin;
};

#endif
/***************************** �����޿Ƽ� www.apollorobot.cn (END OF FILE) *********************************/
