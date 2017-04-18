/*
*********************************************************************************************************
*
* 模块名称 : 超声波传感器类库
* 文件名称 : AR_Ultrasonic.cpp
* 版    本 : V1.0
* 说    明 : 
* 修订记录 :
* Copyright (C), 2015-2020, 阿波罗科技 www.apollorobot.cn
*
*********************************************************************************************************
*/
#include "AR_Ultrasonic.h"

/*
*********************************************************************************************************
*	函 数 名: AR_Ultrasonic()构造函数
*	功能说明:  
*	形    参: trig: trig port to ultrasonic sensor
*			  echo: echo port to ultrasonic sensor
*	返 回 值: 无
*********************************************************************************************************
*/
AR_Ultrasonic::AR_Ultrasonic(uint8_t trig, uint8_t echo)
{
	trig_pin = trig;
	echo_pin = echo;
	
	pinMode(trig_pin, OUTPUT);
	pinMode(echo_pin, INPUT);
	
	digitalWrite(trig_pin, LOW);
	digitalWrite(echo_pin, LOW);
}

/*
*********************************************************************************************************
*	函 数 名: getDistance()构造函数
*	功能说明:  
*	形    参: 无
*	返 回 值: distance in cm
*********************************************************************************************************
*/
double AR_Ultrasonic::getDistance()
{
	pinMode(trig_pin, OUTPUT);
	digitalWrite(trig_pin, HIGH);
	delayMicroseconds(15);//delay 14us
	digitalWrite(trig_pin, LOW);
	
	pinMode(echo_pin, INPUT);
	unsigned long distance = pulseIn(echo_pin, HIGH, TIMEOUT_DEFAULT);
	
	return (double)distance*0.017241;
}

/***************************** 阿波罗科技 www.apollorobot.cn (END OF FILE) *********************************/
