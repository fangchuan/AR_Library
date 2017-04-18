/*
*********************************************************************************************************
*
* 模块名称 : 蜂鸣器类库
* 文件名称 : AR_Buzzer.h
* 版    本 : V1.0
* 说    明 : 
*
* Copyright (C), 2015-2020, 阿波罗科技 www.apollorobot.cn
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
/***************************** 阿波罗科技 www.apollorobot.cn (END OF FILE) *********************************/
