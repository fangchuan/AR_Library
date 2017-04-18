/*
*********************************************************************************************************
*
* 模块名称 : 16bit定时器类库
* 文件名称 : AR_Timer16Bit.cpp
* 版    本 : V1.0
* 说    明 : 
* 修订记录 : 2017-3-13: 类内方法不可以被赋值给函数指针,必须将方法声明为static,但一旦将属性也改为static就失去了这个传感器类的意义
*			 2017-3-14: 将数据属性全部public,主函数操作这些属性
*					    每次扫描RGB都需要3次定时器溢出中断的过程
*			 2017-3-16: 采用TC2做定时器，定时周期1ms,1s进行一次扫描，中断服务函数必须放在外部(全局可见)
*						采用PCINT中断读取OUT引脚，中断服务函数也得放外部
*			 2017-3-19: 颜色传感器读出的数值都差不多，这是为啥...
*			 2017-3-20: 颜色传感器四个灯换成白色LED,电阻47R
*						白平衡结果参数0.01/0.01/0.01较合理
*						离传感器靠的越近区分效果越好
*
*			 2017-3-22: blue值始终偏高，不是程序问题，买的成品模块也是如此。可以把每次scann周期缩短到10ms，减小blue偏差
*
* Copyright (C), 2015-2020, 阿波罗科技 www.apollorobot.cn
*
*********************************************************************************************************
*/
#include <AR_ColorSensor.h>

/*
*********************************************************************************************************
*	函 数 名: AR_ColorSensor()构造函数
*	功能说明:  
*	形    参: 
*	返 回 值: 无
*********************************************************************************************************
*/
AR_ColorSensor::AR_ColorSensor()
{
	
}
/*
*********************************************************************************************************
*	函 数 名: initialize
*	功能说明: Initialize the pins color sensor used, and TC2 initialize
*	形    参: s2: S2 pin
*			  s3：S3 pin
*			  out: OUT pin
*	返 回 值: 无
*********************************************************************************************************
*/
void AR_ColorSensor::initialize(uint8_t s2, uint8_t s3, uint8_t out)
{
	  s2_pin = s2;
	  s3_pin = s3;
	  out_pin = out;
	  
	  pinMode(s2_pin, OUTPUT);
	  pinMode(s3_pin, OUTPUT);
	  pinMode(out_pin, INPUT);
	  
	  initTime2();
	  initPCINT();
	  
	  g_counts = 0; 
	  g_flag = 0;
	  g_buffer[0] = 0;
	  g_buffer[1] = 0;
	  g_buffer[2] = 0;
	  g_fac[0] = 0.01;
	  g_fac[1] = 0.01;
	  g_fac[2] = 0.01;
}
/*
*********************************************************************************************************
*	函 数 名: initTime2
*	功能说明: 配置TC2寄存器，普通模式，64分频，定时器初值为6  1ms定时周期
*                                      1024分频，初值定为100  约10Ms定时周期
*	形    参: 
*	返 回 值: 无
*********************************************************************************************************
*/
void AR_ColorSensor::initTime2() //
{
       TCCR2A = 0;
	   TIMSK2 = _BV(TOIE2);
	 #if USE_1MS_INTERRUPT
       TCCR2B = _BV(CS22);
       TCNT2 = 6;
	 #elif  USE_10MS_INTERRUPT
	   TCCR2B = _BV(CS22) | _BV(CS21) | _BV(CS20); //1024分频
	   TCNT2 = 100;  //初值100
	 #endif
       sei();
}
/*
*********************************************************************************************************
*	函 数 名: initPCINT
*	功能说明: 配置PCINT寄存器，ennable PCINT0/2 and PCINT pin 0/1/2/23
*			  PCINT0--8(Arduino)
*			  PCINT1--9(Arduino)
*			  PCINT2--10(Arduino)
*			  PCINT23--7(Arduino)
*	形    参: 
*	返 回 值: 无
*********************************************************************************************************
*/
void AR_ColorSensor::initPCINT()
{
   if (out_pin > 7){
	  PCICR = 1 << PCIE0;
	  if(8 == out_pin)	  PCMSK0 = 1 << PCINT0;
	  if(9 == out_pin)	  PCMSK0 = 1 << PCINT1;
	  if(10 == out_pin)	  PCMSK0 = 1 << PCINT2;
   }else{
	  PCICR = 1 << PCIE2;
	  PCMSK2 = 1 << PCINT23;
   }
}
/*
*********************************************************************************************************
*	函 数 名: selectFilter
*	功能说明: Select the filter color  
*	形    参: filter_index: 颜色滤波器 index
*	返 回 值: 无
*********************************************************************************************************
*/
void AR_ColorSensor::selectFilter(uint8_t filter_index)
{
  switch(filter_index){
	  case RED_FILTER:
	    digitalWrite(s2_pin, LOW); 
		digitalWrite(s3_pin, LOW); 
	  break;
	  case GREEN_FILTER:
	  	digitalWrite(s2_pin, HIGH); 
		digitalWrite(s3_pin, HIGH); 
	  break;
	  case BLUE_FILTER:
	  	digitalWrite(s2_pin, LOW); 
		digitalWrite(s3_pin, HIGH); 
	  break;
	  case NON_FILTER:
	  	digitalWrite(s2_pin, HIGH); 
		digitalWrite(s3_pin, LOW); 
	  break;
	  default:break;
	  
  }
  //update the scann queue
  g_flag ++;
  if(g_flag > 2)
	  g_flag = 0;
  
}
/*
*********************************************************************************************************
*	函 数 名: scann
*	功能说明: 扫描RGB值，每执行一次scann只能扫R/G/B，所以扫完一个物体要至少执行3次
*	形    参: filter_index: 颜色滤波器 index
*	返 回 值: 无
*********************************************************************************************************
*/
void AR_ColorSensor::scann()
{
  switch(g_flag)
  {
    case RED_FILTER:
#if USE_DEBUG	
         Serial.print("->frequency B=");
         Serial.println(g_counts);
#endif
         g_buffer[BLUE_INDEX] = g_counts;   //store the previous filter out
         selectFilter(RED_FILTER);              //filter red
         break;
    case GREEN_FILTER:
#if USE_DEBUG	
         Serial.print("->frequency R=");
         Serial.println(g_counts);
#endif
         g_buffer[RED_INDEX] = g_counts;    //store the previous filter out
         selectFilter(GREEN_FILTER);            //filter green
         break;
    case BLUE_FILTER:
#if USE_DEBUG	
         Serial.print("->frequency G=");
         Serial.println(g_counts);
#endif
         g_buffer[GREEN_INDEX] = g_counts;    //store the previous filter out
         selectFilter(BLUE_FILTER);             //filter blue
         break;
   default: break;
  }
     
	 g_counts = 0;
}
/*
*********************************************************************************************************
*	函 数 名: whiteBalance
*	功能说明: white balance  process
*	形    参: 无
*	返 回 值: 无
*********************************************************************************************************
*/
void AR_ColorSensor::whiteBalance()
{
	if(g_buffer[0] != 0 && g_buffer[1] != 0 && g_buffer[2] != 0){
		g_fac[0] = 255.0 / g_buffer[0];
		g_fac[1] = 255.0 / g_buffer[1];
		g_fac[2] = 255.0 / g_buffer[2];
#if USE_DEBUG
		Serial.print("R_Factor:");
		Serial.println(g_fac[0]);
		Serial.print("G_Factor");
		Serial.println(g_fac[1]);
		Serial.print("B_Factor");
		Serial.println(g_fac[2]);
#endif
	}else{
		g_fac[0] = 0;
		g_fac[1] = 0;
		g_fac[2] = 0;
	}
}
/*
*********************************************************************************************************
*	函 数 名: getResult
*	功能说明: print the red/green/blue value
*			  range: 0~255
*	形    参: 无
*	返 回 值: 无
*********************************************************************************************************
*/
void AR_ColorSensor::getResult()
{
	float red = g_buffer[RED_INDEX] * g_fac[RED_INDEX];
	float green = g_buffer[GREEN_INDEX] * g_fac[GREEN_INDEX];
	float blue = g_buffer[BLUE_INDEX] * g_fac[BLUE_INDEX];
#if USE_DEBUG
	Serial.print("red_result");
	Serial.println(red);
	Serial.print("green_result");
	Serial.println(green);
	Serial.print("blue_result");
	Serial.println(blue);
#endif
}
/***************************** 阿波罗科技 www.apollorobot.cn (END OF FILE) *********************************/
