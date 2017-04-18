/*
*********************************************************************************************************
*
* 模块名称 : LED类库
* 文件名称 : AR_Led.cpp
* 版    本 : V1.0
* 说    明 : 
* 修订记录 :

* Copyright (C), 2015-2020, 阿波罗科技 www.apollorobot.cn
*
*********************************************************************************************************
*/
#include "AR_Led.h"
#include "AR_PinAssign.h"
/*
*********************************************************************************************************
*	函 数 名: AR_Led()构造函数
*	功能说明:  
*	形    参: p: port to IR sensor
*	返 回 值: 无
*********************************************************************************************************
*/
AR_Led::AR_Led(uint8_t p)
{
	pin = p;
	pinMode(pin, OUTPUT);
}
/*
*********************************************************************************************************
*	函 数 名: setStatu
*	功能说明: set led on/off
*	形    参: statu: 0--off  1--on
*	返 回 值: 无
*********************************************************************************************************
*/
void AR_Led::setStatu(uint8_t statu)
{
	pinMode(pin, OUTPUT);
	digitalWrite(pin, statu);
}

/*
*********************************************************************************************************
*	函 数 名: toggleStatu
*	功能说明: toggle led on/off
*	形    参: 
*	返 回 值: 无
*********************************************************************************************************
*/
void AR_Led::toggleStatu()
{
	switch(pin){
		case DS1_PIN:	PORTB ^= 0x01;
		break;
		case DS2_PIN:	PORTD ^= 0x80;
		break;
		case DS3_PIN:	PORTB ^= 0x04;
		break;
		case DS4_PIN:	PORTB ^= 0x02;
		break;
	}
}
/***************************** 阿波罗科技 www.apollorobot.cn (END OF FILE) *********************************/