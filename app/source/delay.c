/*
 * Filename : delay.c
 *
 * apt32f101 delay function Code
 *
 * Copyrights 2017 @ APTCHIP
 *
 * Date             Author          Description
 * ----------       ----------      ------------
 * 2017/09/28       ZHP              Initial release
 *
 */

#include "delay.h"

volatile unsigned int dlytimer[2] ={0,0};

//代码延时函数
//about 1us step @ PCLK 20MHz,Optimization -Og
// t=0 ,1.01us
// t=1 ,1.01us
// t=2 ,2.02us
// t=3 ,3.01us
void delayus_Bycode(unsigned int t)
{
	volatile unsigned int i = t>0? t-1:t;
	while(i--){
		i = i+1;
		i = i-1;
		i = i+1;
		i = i-1;
		i = i+0;
		asm("nop");
	}
}

//代码延时函数
//about 300ns step @ PCLK 20MHz,Optimization -Og
// t=0 ,910ns
// t=1 ,1.22us
// t=2 ,1.53us
// t=3 ,1.83us
void delay300ns_Bycode(unsigned int t)
{
	volatile unsigned int i = t;
	while(i-->0){
		asm("nop");
	}
}

//代码延时函数
//1ms step @ PCLK 20MHz,Optimization -Og
// t=0 ,1.22us
// t=1 ,1.00ms
// t=2 ,2.00ms
// t=3 ,3.00ms
void delayms_Bycode(unsigned int t)
{
	volatile unsigned int i = t;
	while(i--){
		//delayus_Bycode(980);
		delayus_Bycode(408);
	}
}


//定时器延时函数 定时器周期1ms
void delay_ms(unsigned int t){
	volatile unsigned int i = t;
	dlytimer[dlyms] = 0;
	while(dlytimer[dlyms] < i){};
}

//定时器延时函数 定时器周期1us
void delay_us(unsigned int t){
	dlytimer[dlyus] = 0;
	while(dlytimer[dlyus] < t){};
}