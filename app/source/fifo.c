/*
 * Filename : fifo.c
 *
 * apt32f101 fifo function Code
 *
 * Copyrights 2017 @ APTCHIP
 *
 * Date             Author          Description
 * ----------       ----------      ------------
 * 2023/04/26       LHY             Initial release
 *
 */

#include "fifo.h"

MYFIFO_t  UartFifo_t;

//入队
U8_T MyWriteOneByteToFifoBuff(MYFIFO_t *myfifo, U8_T data)                
{
	    //判断指针是否为空指针
		if(myfifo == NULL)
		{
				//my_printf("The pointer is NULL！！！\r\n");
				return 1;
		}
		
		//MAX_FIFO_SIZE是申请的内存长度 可以修改 如果超过则为溢出
		 if(myfifo->Lenght >= MAX_FIFO_SIZE) 
		 {
			    //确认数据溢出返回值1
				return 1;                                   
		 }
		 //将数据通过尾指针指向的地址存入Ring_Buff缓冲数组中
		 myfifo->Fifo_Buff[myfifo->Tail] = data;  
		 //构建尾部指针的循环 指针累加 指针地址超过MAX_FIFO_SIZE 则重新置于0
		 myfifo->Tail = (myfifo->Tail+1)%MAX_FIFO_SIZE;     
		 //记录存入数据的长度 判断数据的存有数量和溢出情况
		 myfifo->Lenght++;  
		 //无溢出情况存入数据 返回值0
		 return 0; 
}

//出队,从指定的缓冲数组中读出头指针指向地址的数据
U8_T MyReadOneByteToFifoBuff(MYFIFO_t *myfifo, U8_T *data) 
{
		//判断指针是否为空指针
		if(myfifo == NULL)
		{
				//my_printf("The pointer is NULL！！！\r\n");
				return 1;
		}
		
		//如果数据长度为0 则此时缓冲数组中未存有数据
		if(myfifo->Lenght==0)  
		{
				//取出数据失败 返回值1
				return 1; 
		}
		//在Fifo_Buff中从头指针指向的地址中取出数据
		*data = myfifo->Fifo_Buff[myfifo->Head];
		//构建头部指针的循环 指针累加 指针地址超过MAX_FIFO_SIZE 则重新置于0
		myfifo->Head = (myfifo->Head+1)%MAX_FIFO_SIZE;  
		//取出数据时减去相应的数据长度
		myfifo->Lenght--; 
		//取出数据正常 返回值0
		return 0; 
}

//往队列里面写多字节
void MyWriteMoreBytesToFifoBuff(MYFIFO_t *myfifo, U8_T *writebuff, U16_T len)
{
		U16_T i = 0;
		volatile U8_T  ret = 0;
	
		//判断指针是否为空指针
		if(myfifo == NULL)
		{
				//my_printf("The pointer is NULL！！！\r\n");
				return;
		}
		
		for(i = 0; i < len; i++)
		{
				MyWriteOneByteToFifoBuff(myfifo, writebuff[i]); 
				
				if(ret == 1)
				{
						return;
				}
		}
}


//从队列里面读多字节
void MyReadMoreBytesToFifoBuff(MYFIFO_t *myfifo, U8_T *readbuff, U16_T len)
{
		U16_T i = 0;
		U8_T  ret = 0;
	
		//判断指针是否为空指针
		if(myfifo == NULL)
		{
				//my_printf("The pointer is NULL！！！\r\n");
				return;
		}
		
		for(i = 0; i < len; i++)
		{
				ret = MyReadOneByteToFifoBuff(myfifo, &readbuff[i]);
				
				if(ret == 1)
				{
						return;
				}
		}
}


void MyFifoBuff_Init(MYFIFO_t *myfifo)
{
		U16_T i = 0;
		//判断指针是否为空指针
		if(myfifo == NULL)
		{
				//my_printf("The pointer is NULL！！！\r\n");
				return;
		}
		
		myfifo->Head  = 0;
		myfifo->Tail     = 0;
		myfifo->Lenght = 0;
		
		for(i = 0; i < MAX_FIFO_SIZE; i ++)
		{
				myfifo->Fifo_Buff[i] = 0;
		}
		
}
