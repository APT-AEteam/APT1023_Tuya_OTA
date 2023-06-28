/*  
 * Display function redirect
 *
 * Copyrights 2015 @ APTCHIP
 *
 * Date             Author          Description
 * ----------       ----------      ------------
 * 2014/06/22       LuXiang         Initial release
 *
 */

/******************************************************************************
* Include Files
******************************************************************************/
#include "apt32f102.h"
#include "apt32f102_uart.h"
#include "stdarg.h"
#include "stddef.h"
#include "stdio.h"

/******************************************************************************
* Main code
******************************************************************************/
U8_T UART_CH_SEL=1;
volatile U8_T Uart0RxDataFlag;
volatile U8_T Uart1RxDataFlag;

/*************************************************************/
//UART TX Byte 
//EntryParameter:UART0,UART1,txdata_u8
//ReturnValue:NONE
/*************************************************************/

/*void UARTTxByte(CSP_UART_T *uart,U8_T txdata_u8)
{

	// Write the transmit buffer
	CSP_UART_SET_DATA(uart,txdata_u8);

	// Wait for the transmit done
	//while ( (CSP_UART_GET_ISR(uart) & UART_TX_INT_S) != UART_TX_INT_S ) {}
	while (((uart->SR) & UART_TX) == UART_TX ) {}
	
	// Clear status bit for the next transmit
	CSP_UART_SET_ISR(uart, UART_TX_INT_S);

}*/

/*************************************************************/
//UART RX Return Byte 
//EntryParameter:UART0,UART1
//ReturnValue:(uart)->DATA
/*************************************************************/
/*U8_T UART_ReturnRxByte(CSP_UART_T *uart)
{	
	volatile U8_T *pflag=&Uart0RxDataFlag;
	switch(UART_CH_SEL){
		case 0:
			pflag = &Uart0RxDataFlag;
			break;
		case 1:
			pflag = &Uart1RxDataFlag;
		break;
	}
	*pflag = FALSE;
	while((*pflag) != TRUE);
	return CSP_UART_GET_DATA(uart);
}*/

void __putchar__ (char s) {
	switch(UART_CH_SEL){
	case 0:
		UARTTxByte(UART0,s);
		break;
	case 1:
		UARTTxByte(UART1,s);
		break;
	default:
		break;
	}
}

char __getchar__(void){
	switch(UART_CH_SEL){
	case 0:
		return UART_ReturnRxByte(UART0);
	case 1:
		return UART_ReturnRxByte(UART1);
	default:
		break;
	}
	return 0;
}

char *myitoa(int value, char* string, int radix)
{

		char tmp[33];
		char* tp = tmp;
		int i;
		unsigned v;
		int sign;
		char* sp;
		
		if (radix > 36 || radix <= 1)
		{
			return 0;
		}
		
		sign = (radix == 10 && value < 0);
		if (sign)
		v = -value;
		else
		v = (unsigned)value;
		while (v || tp == tmp)
		{
			i = v % radix;
			v = v / radix;
			if (i < 10)
			*tp++ = i+'0';
			else
			*tp++ = i + 'a' - 10;
		}
		
		sp = string;
		
		if (sign)
		*sp++ = '-';
		while (tp > tmp)
		*sp++ = *--tp;
		*sp = 0;
		return string;
}





void my_printf(const char *fmt, ...)
{

    const char *s;
   int d;
    char ch, *pbuf, buf[16];
    va_list ap;
    va_start(ap, fmt);
    while (*fmt) {
        if (*fmt != '%') {
              __putchar__(*fmt++);
            continue;
        }
        switch (*++fmt) {
            case 's':
                s = va_arg(ap, const char *);
                for ( ; *s; s++) {
                 __putchar__(*s);
                }
                break;
            case 'd':
                d = va_arg(ap, int);
                myitoa(d, buf, 10);
                for (s = buf; *s; s++) {
                 __putchar__(*s);
                }
                break;             
            case 'x':
            case 'X':
                d = va_arg(ap, int);
                myitoa(d, buf, 16);
                for (s = buf; *s; s++) {
                 __putchar__(*s);
                }
                break;                
            // Add other specifiers here...
            case 'c':
            case 'C':
            	ch = (unsigned char)va_arg(ap, int);
        	    pbuf = &ch;
            	__putchar__(*pbuf);
                break;
            default:  
                __putchar__(*fmt);
                break;
        }
        fmt++;
    }
    va_end(ap);

}

/*int my_scanf(const char *fmt,...)
{ 
	int i = 0;
	unsigned char c;
	va_list args;
	char buffer[32]; 

	while(1)
	{
		c = __getchar__();
		__putchar__(c);
		if((c == 0x0d) || (c == 0x0a))
		{
			buffer[i] = '\0';
			break;
		}
		else{			
			buffer[i++] = c;
		}
		if(i>=32) break;
	}
	va_start(args,fmt);
	i = vsscanf(buffer,fmt,args);
	va_end(args);
	__putchar__('\n');
	return i;
}*/

/*int my_scanf(const char *fmt,...)
{ 
	int i = 0,j = 0;
	unsigned char c;
	unsigned char delimiter = '\40'; //delimiter is space.
	char *pstr,*pbuf;
    int *pd;
	unsigned char *pc;  
	va_list args;
	char buffer[128]; 	
	for(i=0;i<128;i++) buffer[i]='\0';
	i=0;
	while(1)
	{
		c = __getchar__();
		if(c != 0x0d) __putchar__(c);	//deal with carriage return
		if((c == 0x0d) || (c == 0x0a))
		{
			buffer[i] = '\0';
			break;
		}
		else{	
			if(c == '\b'){ 				//deal with backspace
				buffer[i] = '\0';
				__putchar__('\40');
				__putchar__('\b');
				i--;
				if(i<0) i=0;
			}
			else{
				buffer[i++] = c;
			}
		}
		if (i>=128) i=127;
	}
	pbuf = buffer;
	va_start(args,fmt);
	 while (*fmt) {
        if (*fmt != '%') {
       		fmt++;
            continue;
        }
        switch (*++fmt) {
            case 's':
                pstr = va_arg(args, char *);
				for ( j=0; ;pbuf++,pstr++,j++) {
					if(*pbuf== '\0' || *pbuf== delimiter) 
						break;
					*pstr= *pbuf;
					if(j>=32) break; //max char number 32
                }
				*pstr = '\0';
                break;
            case 'd':
                pd = va_arg(args, int *);
				c = *pbuf;
				while(c == '\40') {
					pbuf++;
					c = *pbuf;
				}
				j=0;
				while(c == delimiter){
					j++;
					pbuf++;
					c = *pbuf;
				}
				if(j>1) break;
				while(c == '\40') {
					pbuf++;
					c = *pbuf;
				}
				j=0;
                while (c >47 && c < 58) {
					if(j) *pd = (*pd)*10+(c-48);
					else *pd = (c-48);

					c = *++pbuf;
					j++;				
                }
                break;                
            case 'x':
            case 'X':
                pd = va_arg(args, int *);
				c = *pbuf;
				while(c == '\40') {
					pbuf++;
					c = *pbuf;
				}
				j=0;
				while(c == delimiter){
					j++;
					pbuf++;
					c = *pbuf;
				}
				if(j>1) break;
				while(c == '\40') {
					pbuf++;
					c = *pbuf;
				}
				j=0;
				if(c=='x'|| c=='X') c = *++pbuf;
                while (c >47 && c < 103) {
					if(c >57 && c < 65) break;
					if(c >70 && c < 97) break;

					if (c < 58) c=c-48;
					else if (c < 71) c=c-55;
					else c=c-87;
					
					if(j) {
						*pd = (*pd)*16+c;
					}					
					else *pd = c;

					c = *++pbuf;
					if(c=='x'|| c=='X') {
						c = *++pbuf;
						j++;
					}
					j++;				
                }
                break;                
            // Add other specifiers here...
            case 'c':
            case 'C':
				pc = va_arg(args, unsigned char *);
				j=0;
				while(c == delimiter){
					j++;
					pbuf++;
					c = *pbuf;
				}
				if(j>1) break;
				*pc = *pbuf++;
                break;
            default:  
                break;
        }
        fmt++;
    }
	va_end(args);
	__putchar__('\n');
	return i;
}*/

int get_string(char *dst,unsigned char len)
{ 
	int i = 0;
	unsigned char c;
	if(len >128) len = 128;
	while(1)
	{
		c = __getchar__();
		if(c != 0x0d) __putchar__(c);	//deal with carriage return
		if((c == 0x0d) || (c == 0x0a))
		{
			dst[i] = '\0';
			break;
		}
		else{	
			if(c == '\b'){ 				//deal with backspace
				dst[i] = '\0';
				__putchar__('\40');
				__putchar__('\b');
				i--;
				if(i<0) i=0;
			}
			else{
				dst[i++] = c;
			}
		}
		if (i>=len) i=len-1;
	}
	return i;
}