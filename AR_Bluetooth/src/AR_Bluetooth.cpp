/*
*********************************************************************************************************
*
* 模块名称 : 蓝牙类库
* 文件名称 : AR_Blluetooth.cpp
* 版    本 : V1.0
* 说    明 : 
*
* Copyright (C), 2015-2020, 阿波罗科技 www.apollorobot.cn
*
*********************************************************************************************************
*/

#include "AR_Bluetooth.h"
#include "AR_Protocol.h"
/*
*********************************************************************************************************
*	函 数 名: AR_Bluetooth构造函数
*	功能说明: 
*	形    参: 
*	返 回 值: 无
*********************************************************************************************************
*/
AR_Bluetooth::AR_Bluetooth()
{
	
}
/*
*********************************************************************************************************
*	函 数 名: initialize
*	功能说明: 蓝牙初始化
*	形    参: 
*	返 回 值: 无
*********************************************************************************************************
*/
void initialize()
{
    bitSet(UCSR0B,RXCIE0);                    //enable RX interrupt
    bitSet(UCSR0B,RXEN0);                     //enable RX  
    bitSet(UCSR0B,TXEN0);                     //enbale TX 
    bitSet(UCSR0C,UCSZ01);					  //asynchronous mode ,no parity, 1bit stop, 8bit character
    bitSet(UCSR0C,UCSZ00);  
    UBRR0L=(F_CPU/16/(BAUDRATE+1)) & 0xFF;  
    UBRR0H=(F_CPU/16/(BAUDRATE+1)) >> 8;    

	sei();//enable global interrupt
}
/*
*********************************************************************************************************
*	函 数 名: analyzeAndExcute
*	功能说明: 蓝牙初始化
*	形    参: 
*	返 回 值: 无
*********************************************************************************************************
*/
void analyzeAndExcute()
{
	//disable the global interrupt
//	cli();
	
    static uint8_t i=2;
    uint8_t length = recData[1];
  
    if(recData[0] == PROTOCOL_FRAME_START && recData[length+2] == PROTOCOL_FRAME_END)
    {
        
        switch(recData[i++])
        {
          case ACTION_FORWARD:     break;
          case ACTION_STOP:        break;
          case ACTION_RIGHT:       break;
          case ACTION_LEFT:        break;
          case ACTION_BACKWARD:    break;
          case ACTION_BACKRIGHT:   break;
          case ACTION_BACKLEFT:    break;
          case ACTION_ROUNDRIGHT:  break;
          case ACTION_ROUNDLEFT:   break;
          case ACTION_DELAY_1S:    break;
          case ACTION_DELAY_2S:    break;
          case DELAY_3S:     break;
          case DELAY_4S:     break;
          case DELAY_5S:     break;
          case DELAY_6S:     break;
          case DELAY_7S:     break;
          case DELAY_8S:     break;
          case DELAY_9S:     break;
          case DELAY_10S:    break;
        }
        
        if(i > length+1) 
        { 
          i = 2;
          recData[0] = PROTOCOL_FRAME_FORBIT;  //整条指令只执行一次,避免重复执行
        }
    }
	//enable the global interrupt
//	sei();    
}
/*
*********************************************************************************************************
*	函 数 名: ISR(USART_RX_vect)
*	功能说明: 串口接收中断服务函数
*	形    参: 
*	返 回 值: 无
*********************************************************************************************************
*/
ISR(USART_RX_vect)
{
  static uint8_t index = 0;
  uint8_t temp = UDR0;

  recBuffer[index++] = temp;

  if(recBuffer[0] == PROTOCOL_FRAME_START && recBuffer[index - 1] == PROTOCOL_FRAME_END){
          index = 0;
          memcpy(recData, recBuffer, BT_RX_BUFFER_SIZE);
          memset(recBuffer,0, BT_RX_BUFFER_SIZE);
    }

}
/***************************** 阿波罗科技 www.apollorobot.cn (END OF FILE) *********************************/
