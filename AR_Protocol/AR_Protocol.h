/*
*********************************************************************************************************
*
* 模块名称 : LecoderV1.0通信协议头文件
* 文件名称 : AR_Protocol.h
* 版    本 : V1.0
* 说    明 : 
* 修订记录 :2017-4-20: 
*				
* Copyright (C), 2015-2020, 阿波罗科技 www.apollorobot.cn
*
*********************************************************************************************************
*/
#ifndef  __AR_PROTOCOL_H
#define  __AR_PROTOCOL_H

#define  PROTOCOL_VERSION  1.0

#define  PROTOCOL_FRAME_START   0xFF
#define  PROTOCOL_FRAME_END     0xEE
#define  PROTOCOL_FRAME_FORBIT  0xFB

#define  ACTION_FORWARD			0x46
#define  ACTION_STOP			0x55
#define  ACTION_RIGHT			0x52
#define  ACTION_LEFT			0x4c
#define  ACTION_BACKWARD		0x42
#define  ACTION_BACKRIGHT		0x40
#define  ACTION_BACKLEFT		0x41
#define  ACTION_ROUNDRIGHT		0x47
#define  ACTION_ROUNDLEFT		0x48
#define  ACTION_DELAY_1S		0x01
#define  ACTION_DELAY_2S		0x02
#define  ACTION_DELAY_3S		0x03
#define  ACTION_DELAY_4S		0x04
#define  ACTION_DELAY_5S		0x05
#define  ACTION_DELAY_6S		0x06
#define  ACTION_DELAY_7S		0x07
#define  ACTION_DELAY_8S		0x08
#define  ACTION_DELAY_9S		0x09
#define  ACTION_DELAY_10S		0x10





#endif
/***************************** 阿波罗科技 www.apollorobot.cn (END OF FILE) *********************************/
