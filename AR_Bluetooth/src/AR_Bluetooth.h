/*
*********************************************************************************************************
*
* ģ������ : �����������
* �ļ����� : AR_Bluetooth.h
* ��    �� : V1.0
* ˵    �� : 
*
* Copyright (C), 2015-2020, �����޿Ƽ� www.apollorobot.cn
*
*********************************************************************************************************
*/
#ifndef  __AR_BLUETOOTH_H
#define  __AR_BLUETOOTH_H

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

//size of rx/tx data buffer
#define  BT_RX_BUFFER_SIZE  50
#define  BT_TX_BUFFER_SIZE  50
//bluetooth baudrate
#define  BT_BAUDRATE_9600   9600
#define  BT_BAUDRATE_115200 115200

class AR_Bluetooth{
public:
		AR_Bluetooth();
		void initialize();
		void analyzeAndExcute();
private:
		
		
		volatile  uint8_t  recBuffer[BT_RX_BUFFER_SIZE];
		volatile  uint8_t  recData[BT_RX_BUFFER_SIZE];

};


#endif
/***************************** �����޿Ƽ� www.apollorobot.cn (END OF FILE) *********************************/
