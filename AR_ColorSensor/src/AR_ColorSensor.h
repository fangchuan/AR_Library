/*
*********************************************************************************************************
*
* 模块名称 : ColorSensor类库
* 文件名称 : AR_ColorSensor.h
* 版    本 : V1.0
* 说    明 : 颜色传感器类库

* Copyright (C), 2015-2020, 阿波罗科技 www.apollorobot.cn
*
*********************************************************************************************************
*/
#ifndef __AR_COLORSENSOR_H
#define __AR_COLORSENSOR_H

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include "AR_PinAssign.h"

// 红：255，0，0    #FF0000 :
// 橙: 255,125,0     #FF7D00:
// 黄：255，255，0   #FFFF00:
// 绿：0，255，0    #00FF00 :
// 蓝：0，0，255    #0000FF :
// 靛: 0,255,255    #00FFFF :
// 紫: 255,0,255    #FF00FF :
// 黑：0， 0， 0    #000000 ：小于50
 
#define  RED_FILTER   0
#define  GREEN_FILTER 1
#define  BLUE_FILTER  2
#define  NON_FILTER   3
 
#define  RED_INDEX    0
#define  GREEN_INDEX  1
#define  BLUE_INDEX   2

#define  USE_DEBUG    1

#define  USE_1MS_INTERRUPT  0
#define  USE_10MS_INTERRUPT 1


class AR_ColorSensor{
private:

	uint8_t s2_pin;
	uint8_t s3_pin;
	uint8_t out_pin;

public:
	unsigned int   g_counts;    // count the frequecy
	unsigned int   g_buffer[3];     // store the RGB value
	int   g_flag;     // filter of RGB queue
	// save the RGB Scale factor: 0.11, 0.13, 0.11
	float g_fac[3];        
	
	AR_ColorSensor();
	
	void initTime2();
	void initPCINT();
	void initialize(uint8_t s2, uint8_t s3, uint8_t out);
	void selectFilter(uint8_t filter_index);
	void scann();
	void outCount();
	void whiteBalance();
	void getResult();
};
 

#endif
/***************************** 阿波罗科技 www.apollorobot.cn (END OF FILE) *********************************/
