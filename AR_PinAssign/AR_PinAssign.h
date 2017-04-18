/*
*********************************************************************************************************
*
* 模块名称 : LecoderV1.0引脚分布头文件
* 文件名称 : AR_PinAssign.h
* 版    本 : V1.0
* 说    明 : 
* 修订记录 :2017-3-22: 
*				
* Copyright (C), 2015-2020, 阿波罗科技 www.apollorobot.cn
*
*********************************************************************************************************
*/
#ifndef  __AR_PINASSIGN_H
#define  __AR_PINASSIGN_H


//每个RJ12端口对应数字引脚
#define  DS1_PIN     8
#define  DS2_PIN     7
#define  DS3_PIN     10
#define  DS4_PIN 	 9

//LED对应引脚
#define  LED1_PIN     8
#define  LED2_PIN     7
#define  LED3_PIN     10
#define  LED4_PIN 	  9

//每个RJ12端口对应模拟引脚
#define  AS1_PIN     0
#define  AS2_PIN	 1
#define  AS3_PIN	 2
#define  AS4_PIN     3

//每个RJ12端口对应超声波引脚
#define  ECHO_PIN     12
#define  TRIG_PIN     13

//颜色传感器S2,S3引脚分布
#define  CS2_PIN      12
#define  CS3_PIN	  13

//1号电机引脚分布
#define MOTOR1_DIR_PIN   3
#define MOTOR1_PWM_PIN   5
//2号电机引脚分布
#define MOTOR2_DIR_PIN	 4
#define MOTOR2_PWM_PIN   6

//蜂鸣器引脚
#define BUZZER_PIN      11


#endif
/***************************** 阿波罗科技 www.apollorobot.cn (END OF FILE) *********************************/
