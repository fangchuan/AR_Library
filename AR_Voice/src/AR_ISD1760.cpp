/*
*********************************************************************************************************
*
* 模块名称 : 语音录放模块类库(ISD1760)
* 文件名称 : AR_ISD1760.cpp
* 版    本 : V1.0
* 说    明 : 单次录音最长时间75s
* 修订记录 : 2017-4-19: 
*
* Copyright (C), 2015-2020, 阿波罗科技 www.apollorobot.cn
*
*********************************************************************************************************
*/
#include "AR_ISD1760.h"
#include "AR_SPI.h"

uint8_t  csPin = 10;
/*
*********************************************************************************************************
*  函 数 名: initISD1760
* 功能说明: Initialize the ISD1760 module
* 形    参: 无
* 返 回 值: 无
*********************************************************************************************************
*/
void initISD1760()
{
      initSpi();
      pinMode(csPin, OUTPUT);
      digitalWrite(csPin, HIGH);
      delay(10);

      digitalWrite(csPin, LOW);
      spiTransfer(ISD_POWERUP); // power up 
      spiTransfer(0x00); // data byte
      digitalWrite(csPin, HIGH);
      delay(10);  
    
      digitalWrite(csPin,LOW);
      spiTransfer(ISD_CLR_INT); // clear interupt and eom bit
      spiTransfer(0x00); // data byte
      digitalWrite(csPin,HIGH);
      delay(10);
}
/*
*********************************************************************************************************
*  函 数 名: powerUp
* 功能说明: POWER up the ISD1760 module
* 形    参: 无
* 返 回 值: 无
*********************************************************************************************************
*/
void  powerUp (void)
{  
      digitalWrite(csPin, LOW);
      spiTransfer(ISD_POWERUP); 
      spiTransfer(0x00);
      digitalWrite(csPin, HIGH);
}
/*
*********************************************************************************************************
*  函 数 名: stop
* 功能说明: stop the ISD1760 module
* 形    参: 无
* 返 回 值: 无
*********************************************************************************************************
*/
void  stop (void)
{  
      digitalWrite(csPin, LOW);
      spiTransfer(ISD_STOP); 
      spiTransfer(0x00);
      digitalWrite(csPin, HIGH);
}
/*
*********************************************************************************************************
*  函 数 名: reset
* 功能说明: reset the ISD1760 module
* 形    参: 无
* 返 回 值: 无
*********************************************************************************************************
*/
void  reset (void)
{
      digitalWrite(csPin, LOW);
      spiTransfer(ISD_RESET); 
      spiTransfer(0x00);
      digitalWrite(csPin, HIGH);

}
/*
*********************************************************************************************************
*  函 数 名: clearInt
* 功能说明: clear INT and EOM
* 形    参: 无
* 返 回 值: 无
*********************************************************************************************************
*/
void  clearInt(void) 
{   
      digitalWrite(csPin, LOW);
      spiTransfer(ISD_RD_STATUS); 
      spiTransfer(0x00);
      digitalWrite(csPin, HIGH);
}
/*
*********************************************************************************************************
*  函 数 名: readStatus
* 功能说明: Read Statu
* 形    参: 无
* 返 回 值: 无
*********************************************************************************************************
*/
uint8_t  readStatus(void)
{     
      uint8_t  first_byte;
      uint8_t  second_byte;
      uint8_t  third_byte;
      
      digitalWrite(csPin, LOW);
      first_byte = spiTransfer(ISD_RD_STATUS); 
      second_byte = spiTransfer(0x00);
      third_byte = spiTransfer(0x00);
      digitalWrite(csPin, HIGH);
      
      return  third_byte;
 }
/*
*********************************************************************************************************
*  函 数 名: readCurrentRowAddress
* 功能说明: Read Statu and current row address
* 形    参: 无
* 返 回 值: 无
*********************************************************************************************************
*/
uint16_t  readCurrentRowAddress(void)
{    
      uint8_t  first_byte;
      uint8_t  second_byte;
      uint8_t  third_byte;
      
      digitalWrite(csPin, LOW);
      first_byte = spiTransfer(ISD_RD_STATUS); 
      second_byte = spiTransfer(0x00);
      third_byte = spiTransfer(0x00);
      digitalWrite(csPin, HIGH);

      return ((first_byte>>5) | (second_byte << 3));
}
/*
*********************************************************************************************************
*  函 数 名: readDeviceId
* 功能说明: 器件ID 1byte的高5位 ISD1760：10100
* 形    参: 无
* 返 回 值: 无
*********************************************************************************************************
*/
uint8_t  readDeviceId(void)
{
      uint8_t id = 0;
      digitalWrite(csPin, LOW);
      spiTransfer(ISD_PLAY); // clear interupt and eom bit
      spiTransfer(0x00); // data  
      id = spiTransfer(0x00); // data  
      digitalWrite(csPin, HIGH);

      return (id & 0xf8);
}
/*
*********************************************************************************************************
*  函 数 名: play
* 功能说明: 播放当前语音段(默认延迟5S来完成当前段播放)
* 形    参: 无
* 返 回 值: 无
*********************************************************************************************************
*/
void play()
{
      digitalWrite(csPin, LOW);
      spiTransfer(ISD_PLAY); // clear interupt and eom bit
      spiTransfer(0x00); // data byte
      digitalWrite(csPin, HIGH);
      delay(5000);

}
/*
*********************************************************************************************************
*  函 数 名: forward
* 功能说明: 播放指针向前移一段
* 形    参: 无
* 返 回 值: 无
*********************************************************************************************************
*/
void forward()
{
      digitalWrite(csPin, LOW);
      spiTransfer(ISD_FWD); // 
      spiTransfer(0x00); // data
      digitalWrite(csPin,HIGH);
      delay(10);
}
/*
*********************************************************************************************************
*  函 数 名: setPlay
* 功能说明: 播放指定地址的语音
* 形    参: st_addr:
*           end_addr:
* 返 回 值: 无
*********************************************************************************************************
*/
void setPlay(uint16_t st_addr, uint16_t end_addr)
{
    digitalWrite(csPin, LOW);
    spiTransfer(ISD_SET_PLAY); //commad
    spiTransfer(0x00);        // data 
    spiTransfer(st_addr & 0xFF);//start address
    spiTransfer(st_addr >> 8);
    spiTransfer(end_addr & 0xFF);//end address
    spiTransfer(end_addr >> 8);
    spiTransfer(0x00);       // data 
    digitalWrite(csPin,HIGH);
    delay(10);
}
/*
*********************************************************************************************************
*  函 数 名: readCurrentPlayPtr
* 功能说明:  读取当前播放指针所指向的语音地址
* 形    参:
* 返 回 值: 语音地址
*********************************************************************************************************
*/
uint16_t readCurrentPlayPtr()
{
    uint8_t play_ptr_high;
    uint8_t play_ptr_low;
      
    digitalWrite(csPin,LOW);
    spiTransfer(ISD_RD_PLAY_PTR); 
    spiTransfer(0x00);
    play_ptr_low = spiTransfer(0x00); 
    play_ptr_high = spiTransfer(0x00);   
    digitalWrite(csPin, HIGH);     
    delay(10);

    return (play_ptr_high << 8 | play_ptr_low);
}
/*
*********************************************************************************************************
*  函 数 名: readCurrentRecordPtr
* 功能说明:  读取当前录音指针所指向的语音地址
* 形    参:
* 返 回 值: 录音地址
*********************************************************************************************************
*/
uint16_t readCurrentRecordPtr()
{
    uint8_t record_ptr_high;
    uint8_t record_ptr_low;
      
    digitalWrite(csPin,LOW);
    spiTransfer(ISD_RD_REC_PTR); 
    spiTransfer(0x00);
    record_ptr_low = spiTransfer(0x00); 
    record_ptr_high = spiTransfer(0x00);   
    digitalWrite(csPin, HIGH);     
    delay(10);

    return (record_ptr_high << 8 | record_ptr_low);
}

/***************************** 阿波罗科技 www.apollorobot.cn (END OF FILE) *********************************/
