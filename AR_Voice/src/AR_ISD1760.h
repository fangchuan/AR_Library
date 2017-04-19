/*
*********************************************************************************************************
*
* 模块名称 : 语音录放模块类库(ISD1760)
* 文件名称 : AR_ISD1760.h
* 版    本 : V1.0
* 说    明 : 
*
* Copyright (C), 2015-2020, 阿波罗科技 www.apollorobot.cn
*
*********************************************************************************************************
*/
#ifndef  __AR_ISD1760_H
#define  __AR_ISD1760_H

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

//operation codes
#define ISD_POWERUP     0x01
#define ISD_STOP        0x02
#define ISD_RESET       0x03
#define ISD_CLR_INT     0x04
#define ISD_RD_STATUS   0x05
#define ISD_RD_PLAY_PTR 0x06
#define ISD_POWERDOWN   0x07
#define ISD_RD_REC_PTR  0x08
#define ISD_DEVICE_ID   0x09

#define ISD_PLAY        0x40
#define ISD_RECORD      0x41
#define ISD_ERASE       0x42
#define ISD_ALL_ERASE   0x43
#define ISD_RD_APC      0x44
#define ISD_WR_APC1     0x45
#define ISD_WR_APC2     0x65
#define ISD_WR_NVCFG    0x46
#define ISD_LD_NVCFG    0x47
#define ISD_FWD         0x48
#define ISD_CHK_MEM     0x49
#define ISD_EXTCLK      0x4A
#define ISD_SET_PLAY    0x80
#define ISD_SET_REC     0x81
#define ISD_SET_ERASE   0x82

void initISD1760();
void  powerUp (void);
void  stop (void);
void  reset (void);
void  clearInt(void);
uint8_t  readStatus(void);
uint16_t  readCurrentRowAddress(void);
uint8_t  readDeviceId(void);
void play();
void forward();
void setPlay(uint16_t st_addr, uint16_t end_addr);
uint16_t readCurrentPlayPtr();
uint16_t readCurrentRecordPtr();

#endif
/***************************** 阿波罗科技 www.apollorobot.cn (END OF FILE) *********************************/
