/*
*********************************************************************************************************
*
* 模块名称 : 硬件SPI类库
* 文件名称 : AR_SPI.h
* 版    本 : V1.0
* 说    明 : 
*
* Copyright (C), 2015-2020, 阿波罗科技 www.apollorobot.cn
*
*********************************************************************************************************
*/
#ifndef  __AR_SPI_H
#define  __AR_SPI_H

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

// serials of SPI Peripherals
#define  SPI0
#define  SPI1
#define  SPI2

//Every bit in SPI register SPCR
#define  SPI_INT_ENABLE   0x80    //这一位置1表示使能SPI中断，置0表示关闭SPI中断
#define  SPI_ENABLE       0x40    //这一位置1表示使能SPI，置0表示关闭SPI
#define  SPI_DATA_ORDER   0x20    //这一位置1表示LSB先发送，置0表示MSB先发送
#define  SPI_MASTER       0x10    //这一位置1表示当前设备处于SPI Master模式， 置0表示处于Slave模式
#define  SPI_CLK_POLAR    0x08    //这一位置1表示SCK为高时处于idle， 置0表示SCK为低时处于idle
#define  SPI_CLK_PHASE    0x04    //这一位置1表示在第一个SCK有效边沿开始采样， 置0表示在第二个SCK有效边沿采样
#define  SPI_CLK_RATE1    0x02    //速率设置位
#define  SPI_CLK_RATE0    0x01

//SPI  clock select 
#define  SPI_CLK_RATE_2_DIV  
#define  SPI_CLK_RATE_4_DIV
#define  SPI_CLK_RATE_8_DIV
#define  SPI_CLK_RATE_16_DIV
#define  SPI_CLK_RATE_64_DIV
#define  SPI_CLK_RATE_128_DIV

//define spi pins on arduino
#ifdef   SPI0
  #define SPI0_MOSI      11   //mosi
  #define SPI0_MISO      12   //miso
  #define SPI0_SCK       13   //sck
//  #define SPI0_CS        10   //ss
#endif

void  initSpi(void);
uint8_t  spiTransfer(uint8_t data);


#endif

/***************************** 阿波罗科技 www.apollorobot.cn (END OF FILE) *********************************/

