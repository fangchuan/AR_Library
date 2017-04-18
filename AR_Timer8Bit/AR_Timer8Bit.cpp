/*
*********************************************************************************************************
*
* 模块名称 : 8bit定时器类库
* 文件名称 : AR_Timer8Bit.h
* 版    本 : V1.0
* 说    明 : 
*
* Copyright (C), 2015-2020, 阿波罗科技 www.apollorobot.cn
*
*********************************************************************************************************
*/

#include <AR_Timer8Bit.h>

AR_Timer8Bit Timer8Bit;              // preinstatiate
unsigned char AR_Timer8Bit::instances = 0;

/*
*********************************************************************************************************
*	函 数 名: ISR()
*	功能说明: interrupt service routine that wraps a user defined function supplied by attachInterrupt
*	形    参: TIMER1_OVF_vect:定时器溢出中断.由定时周期决定
*			  TIMER1_CAPT_vect:捕获中断，PB0(AVR)--DigitalPin 8(Arduino)
*	返 回 值: 无
*********************************************************************************************************
*/
ISR(TIMER1_OVF_vect)          
{
  Timer16Bit.isrOVFCallBack();
}

ISR(TIMER1_CAPT_vect)          
{
  Timer16Bit.isrCAPTCallBack();
}
/*
*********************************************************************************************************
*	函 数 名: AR_Timer16Bit构造函数
*	功能说明: 
*	形    参: 无
*	返 回 值: 无
*********************************************************************************************************
*/
AR_Timer16Bit::AR_Timer16Bit():pwmPeriod(0),clockSelectBits(0)
{
	instances ++;
	
	if(instances == 1){

	}else{
		if(instances == 2){

		}else{
			
		}
	}
	
}
AR_Timer16Bit::~AR_Timer16Bit()
{
	if(instances == 1){//clear 16bit timer 1
		TCCR1A = 0;
		TCCR1B = 0;
	}else{
		if(instances == 2){//clear 16bit timer 2
			
		}
	}
	
	instances --;
}
/*
*********************************************************************************************************
*	函 数 名: initialize
*	功能说明: 默认采用PFC mode,
*			  OC1A/OC1B做普通引脚使用，不复用为Timer1
*	形    参: microseconds:周期
*	返 回 值: 无
*********************************************************************************************************
*/
void AR_Timer16Bit::initialize(long microseconds)
{
		TCCR1A = 0;                 // clear control register A 
		TCCR1B = _BV(WGM13);        // set mode as phase and frequency correct pwm, stop the timer	
		setPeriod(microseconds);
		start();
}
/*
*********************************************************************************************************
*	函 数 名: setPeriod
*	功能说明: because of PFC PWM mode, the count cycle is 1/2 * (F_CPU*period)/1000000
*						 
*	形    参:  microseconds: us周期
*	返 回 值: 无
*********************************************************************************************************
*/
void AR_Timer16Bit::setPeriod(long microseconds)
{
  long cycles = (F_CPU * microseconds) / 2000000;// the counter runs backwards after TOP, interrupt is at BOTTOM so divide microseconds by 2
  if(cycles < RESOLUTION)              
	  clockSelectBits = _BV(CS10);              // no prescale, full xtal
  else
	  if((cycles >>= 3) < RESOLUTION) clockSelectBits = _BV(CS11);              // prescale by /8
  else 
	  if((cycles >>= 3) < RESOLUTION) clockSelectBits = _BV(CS11) | _BV(CS10);  // prescale by /64
  else
	  if((cycles >>= 2) < RESOLUTION) clockSelectBits = _BV(CS12);              // prescale by /256
  else 
	  if((cycles >>= 2) < RESOLUTION) clockSelectBits = _BV(CS12) | _BV(CS10);  // prescale by /1024
  else{
	  cycles = RESOLUTION - 1;
	  clockSelectBits = _BV(CS12) | _BV(CS10);  // request was out of bounds, set as maximum
  }
  
  ICR1 = pwmPeriod = cycles;                                                     // ICR1 is TOP in PFC pwm mode
  
  TCCR1B &= ~(_BV(CS10) | _BV(CS11) | _BV(CS12));								 // reset clock select register
  TCCR1B |= clockSelectBits;                                                     
}
/*
*********************************************************************************************************
*	函 数 名: setPwmDuty
*	功能说明: 设置PWM的占空比
*			  OC1A----PB1(avr)--Digital 9(arduino)
*			  OC1B----PB2(avr)--Digital 10(arduino)			 
*	形    参:  pin: TIMER1复用的引脚
*			   duty: 0~1024
*	返 回 值: 无
*********************************************************************************************************
*/
void AR_Timer16Bit::setPwmDuty(char pin, int duty)
{
  unsigned long dutyCycle = pwmPeriod;
  dutyCycle *= duty;
  dutyCycle >>= 10;
  if(pin == 1 || pin == 9)       OCR1A = dutyCycle;
  else if(pin == 2 || pin == 10) OCR1B = dutyCycle;
}
/*
*********************************************************************************************************
*	函 数 名: setPwm
*	功能说明: 设置PWM周期和占空比
*			  OC1A----PB1(avr)--Digital 9(arduino)
*			  OC1B----PB2(avr)--Digital 10(arduino)			 
*	形    参:  pin: TIMER1复用的引脚
*			   duty: 0~1024
*			   microseconds: period
*	返 回 值: 无
*********************************************************************************************************
*/
void AR_Timer16Bit::setPwm(char pin, int duty, long microseconds)  // expects duty cycle to be 10 bit (1024)
{
  if(microseconds > 0) 
	  setPeriod(microseconds);
  if(pin == 1 || pin == 9){
    DDRB |= _BV(PORTB1);                                   // sets data direction register for pwm output pin
    TCCR1A |= _BV(COM1A1);                                 // activates the output pin
  }else{
	if(pin == 2 || pin == 10){
		DDRB |= _BV(PORTB2);
		TCCR1A |= _BV(COM1B1);
	}
  }
  setPwmDuty(pin, duty);
  start();
}
/*
*********************************************************************************************************
*	函 数 名: disablePwm
*	功能说明: 关闭PWM输出引脚
*			  OC1A----PB1(avr)--Digital 9(arduino)
*			  OC1B----PB2(avr)--Digital 10(arduino)			 
*	形    参:  pin: TIMER1复用的引脚
*	返 回 值: 无
*********************************************************************************************************
*/
void AR_Timer16Bit::disablePwm(char pin)
{
  if(pin == 1 || pin == 9)       TCCR1A &= ~_BV(COM1A1);   // clear the bit that enables pwm on PB1
  else if(pin == 2 || pin == 10) TCCR1A &= ~_BV(COM1B1);   // clear the bit that enables pwm on PB2
}
/*
*********************************************************************************************************
*	函 数 名: attachInterrupt
*	功能说明: 打开定时器溢出中断		 
*	形    参: isr: Interrupt Service Routine
*			  microseconds： period of PWM
*	返 回 值: 无
*********************************************************************************************************
*/
void AR_Timer16Bit::attachInterrupt(void (*isrOvf)(), void (*isrCapt)(), long microseconds)
{
  if(microseconds > 0)
	  setPeriod(microseconds);
  
  isrOVFCallBack = isrOvf;                            // register the user's callback with the real ISR
  isrCAPTCallBack = isrCapt;
  if(NULL != isrOVFCallBack)  TIMSK1 |= 0x01;         // sets the timer overflow interrupt enable bit
  if(NULL != isrCAPTCallBack) TIMSK1 |= 0x10;		  // sets the timer captrue  interrupt enable bit
  sei();                                              // ensures that interrupts are globally enabled
}
/*
*********************************************************************************************************
*	函 数 名: detachInterrupt
*	功能说明: 关闭定时器溢出中断		 
*	形    参: 无
*	返 回 值: 无
*********************************************************************************************************
*/
void AR_Timer16Bit::detachInterrupt()
{
  TIMSK1 &= ~_BV(TOIE1);                                   // clears the timer overflow interrupt enable bit 
}
/*
*********************************************************************************************************
*	函 数 名: start
*	功能说明: 开启定时器		 
*	形    参: 无
*	返 回 值: 无
*********************************************************************************************************
*/
void AR_Timer16Bit::start()
{

	TCCR1B |= clockSelectBits;
}
/*
*********************************************************************************************************
*	函 数 名: stop
*	功能说明: 关闭定时器		 
*	形    参: 无
*	返 回 值: 无
*********************************************************************************************************
*/
void AR_Timer16Bit::stop()
{
	// clears all clock selects bits,
	//non clock source
	//timer stop
	TCCR1B &= ~(_BV(CS10) | _BV(CS11) | _BV(CS12));          
}
/*
*********************************************************************************************************
*	函 数 名: restart
*	功能说明: 重启定时器，重新计数
*	形    参: 无
*	返 回 值: 无
*********************************************************************************************************
*/
void AR_Timer16Bit::restart()
{
  TCNT1 = 0;
}
