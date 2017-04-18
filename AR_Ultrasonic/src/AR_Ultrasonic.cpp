/*
*********************************************************************************************************
*
* ģ������ : ���������������
* �ļ����� : AR_Ultrasonic.cpp
* ��    �� : V1.0
* ˵    �� : 
* �޶���¼ :
* Copyright (C), 2015-2020, �����޿Ƽ� www.apollorobot.cn
*
*********************************************************************************************************
*/
#include "AR_Ultrasonic.h"

/*
*********************************************************************************************************
*	�� �� ��: AR_Ultrasonic()���캯��
*	����˵��:  
*	��    ��: trig: trig port to ultrasonic sensor
*			  echo: echo port to ultrasonic sensor
*	�� �� ֵ: ��
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
*	�� �� ��: getDistance()���캯��
*	����˵��:  
*	��    ��: ��
*	�� �� ֵ: distance in cm
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

/***************************** �����޿Ƽ� www.apollorobot.cn (END OF FILE) *********************************/
