/*
*********************************************************************************************************
*
* 模块名称 : 硬件SPI类库
* 文件名称 : AR_SPI.cpp
* 版    本 : V1.0
* 说    明 : 
* 修订记录 : 2017-4-19: 
*
* Copyright (C), 2015-2020, 阿波罗科技 www.apollorobot.cn
*
*********************************************************************************************************
*/
#include "AR_SPI.h"

/*
*********************************************************************************************************
*  函 数 名: initSpi
* 功能说明: Initialize the SPIx
* 形    参: 
* 返 回 值: 
*********************************************************************************************************
*/
void initSpi()
{
  #ifdef SPI0
    pinMode(SPI0_MOSI, OUTPUT);
    pinMode(SPI0_MISO, INPUT);
    pinMode(SPI0_SCK,  OUTPUT);
//    pinMode(SPI0_CS,   OUTPUT);
    
//    digitalWrite(SPI0_CS,HIGH); //disable device  
    //data lsb, clock high when idle, samples on falling, 1M rate
    SPCR = SPI_ENABLE | SPI_DATA_ORDER | SPI_MASTER | SPI_CLK_POLAR | SPI_CLK_PHASE | SPI_CLK_RATE0; 
  #endif
  
  #ifdef  SPI1
  #endif
  
  #ifdef  SPI2
  #endif
}

/*
*********************************************************************************************************
*  函 数 名: spiTransfer
* 功能说明: Transfer data and return received data
* 形    参: data: 1 byte data to be transfered
* 返 回 值: uint8_t received data
*********************************************************************************************************
*/
uint8_t  spiTransfer(uint8_t data)
{
  SPDR = data;                    // Start the transmission
  while (!(SPSR & (1<<SPIF)));     // Wait for the end of the transmission

  return SPDR;                    // return the received byte
}

/***************************** 阿波罗科技 www.apollorobot.cn (END OF FILE) *********************************/

