/*
 * Filename : delay.h
 *
 * apt32f101 delay funcitons header file
 *
 * Copyrights 2015 @ APTCHIP
 *
 * Date             Author          Description
 * ----------       ----------      ------------
 * 2015/09/23       XJ              Initial release
 *
 */
#ifndef __DELAY__H
#define __DELAY__H

typedef enum{
	dlyms =0,
	dlyus =1,
}DLYTIMER_DEF;

extern volatile unsigned int dlytimer[2];

extern void delay300ns_Bycode(unsigned int t);
extern void delayus_Bycode(unsigned int t);
extern void delayms_Bycode(unsigned int t);
extern void delay_ms(unsigned int t);
extern void delay_us(unsigned int t);
#endif /**<  DELAY__H */
