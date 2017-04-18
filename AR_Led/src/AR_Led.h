/*
*********************************************************************************************************
*
* 模块名称 : LED类库
* 文件名称 : AR_Led.h
* 版    本 : V1.0
* 说    明 : 
*
* Copyright (C), 2015-2020, 阿波罗科技 www.apollorobot.cn
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
/***************************** 阿波罗科技 www.apollorobot.cn (END OF FILE) *********************************/
