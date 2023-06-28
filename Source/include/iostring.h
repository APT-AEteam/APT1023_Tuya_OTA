/*
 * Filename : iostring.h
 *
 * UART standio header file
 *
 * Copyrights 2015 @ APTCHIP
 *
 * Date             Author          Description
 * ----------       ----------      ------------
 * 2015/09/23       XJ              Initial release
 *
 */
#ifndef IOSTRING__H
#define IOSTRING__H
extern unsigned char UART_CH_SEL;
//extern void my_printf(const char *fmt, ...);
extern void UARTTxByte(CSP_UART_T *uart,U8_T txdata_u8);
extern int get_string(char *dst,unsigned char len);
//extern int my_scanf(const char *fmt,...);
void my_printf(const char *fmt, ...);
#endif /**< IOSTRING__H */
