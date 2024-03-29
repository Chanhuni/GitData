#include "sys.h"
#include "usart.h"	
#include "string.h"
////////////////////////////////////////////////////////////////////////////////// 	 
//如果使用ucos,则包括下面的头文件即可.
#if SYSTEM_SUPPORT_OS
#include "includes.h"					//ucos 使用	  
#endif
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32开发板
//串口1初始化		   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2012/8/18
//版本：V1.5
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved
//********************************************************************************
//V1.3修改说明 
//支持适应不同频率下的串口波特率设置.
//加入了对printf的支持
//增加了串口接收命令功能.
//修正了printf第一个字符丢失的bug
//V1.4修改说明
//1,修改串口初始化IO的bug
//2,修改了USART_RX_STA,使得串口最大接收字节数为2的14次方
//3,增加了USART_REC_LEN,用于定义串口最大允许接收的字节数(不大于2的14次方)
//4,修改了EN_USART1_RX的使能方式
//V1.5修改说明
//1,增加了对UCOSII的支持
////////////////////////////////////////////////////////////////////////////////// 	  
 

//////////////////////////////////////////////////////////////////
//加入以下代码,支持printf函数,而不需要选择use MicroLIB	  
#if 1
#pragma import(__use_no_semihosting)             
//标准库需要的支持函数                 
struct __FILE 
{ 
	int handle; 

}; 

FILE __stdout;       
//定义_sys_exit()以避免使用半主机模式    
_sys_exit(int x) 
{ 
	x = x; 
} 
//重定义fputc函数 
int fputc(int ch, FILE *f)
{      
	while((USART1->SR&0X40)==0);//循环发送,直到发送完毕   
    USART1->DR = (u8) ch;      
	return ch;
}
#endif 

 
 
//#if EN_USART1_RX   //如果使能了接收
//串口1中断服务程序
//注意,读取USARTx->SR能避免莫名其妙的错误   	
//u8 USART_RX_BUF[USART_REC_LEN];     //接收缓冲,最大USART_REC_LEN个字节.

//发送缓冲区
u8 Usart1_SendBuffer[USART1_SendBufferSize];
//接收缓冲区
u8 Usart1_RecvBuffer[USART1_RecvBufferSize];

 u8 Usart1_DataBuffer[100] = {0};	//数据缓冲区

u32 Usart1_SendPointer = 0;	//发送缓冲区指针
u32 Usart1_Write_RecvPointer = 0;	//写接收缓冲区指针
u32 Usart1_Read_RecvPointer = 0;  //读接收缓冲区指针
u32 Usart1_BufferToTrail_Flag = 0; //读写接收缓冲区数据到数组最后一个元素标志 当写缓冲区指针返回时置1，读缓冲区指针返回时清0 
u8 Usart1_NewDataFlag = 0;

//int Usart1_SendDataSize = 0;
//int Usart1_RecvDataSize = 0;

//接收状态
//bit15，	接收完成标志
//bit14，	接收到0x0d
//bit13~0，	接收到的有效字节数目
//u16 USART_RX_STA=0;       //接收状态标记	
  
void uart_init(u32 bound){
  //GPIO端口设置
  GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1|RCC_APB2Periph_GPIOA, ENABLE);	//使能USART1，GPIOA时钟
	
	USART_DeInit(USART1);		//复位串口1
  
	//USART1_TX   GPIOA.9
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; //PA.9
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//复用推挽输出
  GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA.9
   
  //USART1_RX	  GPIOA.10初始化
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;//PA10
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//浮空输入
  GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA.10  

  //Usart1 NVIC 配置
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3 ;//抢占优先级3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;		//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器
  
   //USART 初始化设置

	USART_InitStructure.USART_BaudRate = bound;//串口波特率
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//字长为8位数据格式
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//一个停止位
	USART_InitStructure.USART_Parity = USART_Parity_No;//无奇偶校验位
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//收发模式

  USART_Init(USART1, &USART_InitStructure); //初始化串口1
	USART_ClearITPendingBit(USART1,USART_IT_RXNE);//清空串口1接收标记
  USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);//开启串口1接受中断
  USART_Cmd(USART1, ENABLE);                    //使能串口1 

}

//串口发送一个字节
void USART1_Send_Byte(u8 PortNum, u8 byte)
{
	if(PortNum == 1){
		USART_ClearFlag(USART1,USART_FLAG_TC);
		USART_SendData(USART1,byte);
		while(USART_GetFlagStatus(USART1,USART_FLAG_TC) != SET);  //等待发送完成，检测USART_FLAG_TC是否置1；
	}/*else if(PortNum == 2){
		USART_SendData(USART2,byte);
		while(USART_GetFlagStatus(USART2,USART_FLAG_TC) != SET);  //等待发送完成，检测USART_FLAG_TC是否置1；
	}else if(PortNum == 3){
		USART_SendData(USART3,byte);
		while(USART_GetFlagStatus(USART3,USART_FLAG_TC) != SET);  //等待发送完成，检测USART_FLAG_TC是否置1；
	}else if(PortNum == 4){
		USART_SendData(UART4,byte);
		while(USART_GetFlagStatus(UART4,USART_FLAG_TC) != SET);  //等待发送完成，检测USART_FLAG_TC是否置1；
	}else if(PortNum == 5){
		USART_SendData(UART5,byte);
		while(USART_GetFlagStatus(UART5,USART_FLAG_TC) != SET);  //等待发送完成，检测USART_FLAG_TC是否置1；
	}*/
}

//串口发送字符串
void USART1_Send_Str(u8 *str)
{
	while(*str != '\0'){
		USART1_Send_Byte(1,*str);
		str++;
	}
}

//串口发送一定长度字符串
void USART1_Send_Str2(u8 *str, u32 len)
{
	while(len != 0){
		USART1_Send_Byte(1,*str);
		str++;
		len--;
	}
}

void USART1_IRQHandler(void)                	//串口1中断服务程序
{
	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)  //接收中断 
		{
			USART_ClearITPendingBit(USART1,USART_IT_RXNE);//清空串口1接收标记
		  Usart1_RecvBuffer[Usart1_Write_RecvPointer++] = USART_ReceiveData(USART1);	//获取接收到的数据
		
//			//如果没有溢出，待处理数据+1.或者丢弃该数据
//			if(Usart1_RecvDataSize < USART1_RecvBufferSize){
//				Usart1_RecvDataSize ++;
//			}
			
			//指针移动到缓冲区尾地址后，循环到缓冲区首地址
			if(Usart1_Write_RecvPointer == USART1_RecvBufferSize){
				Usart1_Write_RecvPointer = 0;
				Usart1_BufferToTrail_Flag = 1;
			}	 
     }

//		if(USART_GetITStatus(USART1,USART_IT_TXE) != RESET){	//发送中断
//			USART_SendData(USART1,TxBuffer[TxCounter++]);
//		}
		 
		 
}

void Usart1_DataBufferCopy(u32 indexL, u32 indexR){	//从串口接收缓冲区拷贝一段数据到数据缓冲区
	u8 j=0;
	u32 i;
	memset(Usart1_DataBuffer,0,100);
	if(indexL <= indexR){
		for(i=indexL;i<=indexR;i++)
			Usart1_DataBuffer[j++]=Usart1_RecvBuffer[i];
	}else{
		for(i=indexL;i<USART1_RecvBufferSize;i++)
			Usart1_DataBuffer[j++]=Usart1_RecvBuffer[i];
		for(i=0;i<=indexR;i++)
			Usart1_DataBuffer[j++]=Usart1_RecvBuffer[i];
	}
	return;
}


u8 Usart1_DataSelect(void){			//选取一帧数据 7E开头7E结尾
	u8 Flag = 0;	//检测到7E
	u8 i = 0;
	u32 indexL = 0, indexR = 0; 
	while(1)
	{
		if((Usart1_Read_RecvPointer==Usart1_Write_RecvPointer)&&(Usart1_BufferToTrail_Flag==0)){
			return 0;
		}else{
			if(Flag){
				if(Usart1_RecvBuffer[Usart1_Read_RecvPointer]==0x7e){
					indexR = Usart1_Read_RecvPointer;
//					Usart1_Read_RecvPointer++;
//					if(Usart1_Read_RecvPointer==USART1_RecvBufferSize){
//						Usart1_Read_RecvPointer = 0;
//						Usart1_BufferToTrail_Flag = 0;
//					}
					if(indexR<indexL)
						i=indexR+USART1_RecvBufferSize-indexL+1;
					else
						i=indexR-indexL+1;
					if((Usart1_RecvBuffer[(indexL+2)%USART1_RecvBufferSize]+5)<=i){
						Usart1_DataBufferCopy(indexL, indexR);
						Usart1_NewDataFlag = 1;
						Usart1_Read_RecvPointer++;
						if(Usart1_Read_RecvPointer==USART1_RecvBufferSize){
							Usart1_Read_RecvPointer = 0;
							Usart1_BufferToTrail_Flag = 0;
						}
						Flag = 0;
						return 1;
					}else{
						indexL = indexR;
					}
				}
					
		}else{
			if(Usart1_RecvBuffer[Usart1_Read_RecvPointer]==0x7e){
				Flag = 1;
				indexL = Usart1_Read_RecvPointer;
			}
		}
		Usart1_Read_RecvPointer++;
		if(Usart1_Read_RecvPointer==USART1_RecvBufferSize){
			Usart1_Read_RecvPointer = 0;
			Usart1_BufferToTrail_Flag = 0;
		}
	}
//		if(Usart1_Read_RecvPointer == Usart1_Write_RecvPointer)
//			break ;
	}

}

u8 Usart1_DataRead(void){	//从接收缓冲区读一帧数据
	
	u8 check = 0;
//	u8 Flag = 0;	//检测到7E
//	u32 indexL = 0, indexR = 0; 
	if(Usart1_BufferToTrail_Flag == 0){
		if(Usart1_Read_RecvPointer == Usart1_Write_RecvPointer)
			return 0;	//数据缓冲区为空或已经读完
		else if(Usart1_Read_RecvPointer > Usart1_Write_RecvPointer)
			Usart1_Read_RecvPointer = Usart1_Write_RecvPointer;
		else{
			check = Usart1_DataSelect();
			
		}
	}else{
		if(Usart1_Read_RecvPointer <= Usart1_Write_RecvPointer){
			Usart1_Read_RecvPointer = Usart1_Write_RecvPointer+1;
			if(Usart1_Read_RecvPointer==USART1_RecvBufferSize){
			Usart1_Read_RecvPointer = 0;
			Usart1_BufferToTrail_Flag = 0;
			}
			check=Usart1_DataSelect();
		}else{
			check=Usart1_DataSelect();
		}
	}
	return check;
}
//void USART1_IRQHandler(void)                	//串口1中断服务程序
//	{

//	u8 Res;
//#if SYSTEM_SUPPORT_OS 		//如果SYSTEM_SUPPORT_OS为真，则需要支持OS.
//	OSIntEnter();    
//#endif
//	
//	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)  //接收中断(接收到的数据必须是0x0d 0x0a结尾)
//		{
//		Res =USART_ReceiveData(USART1);	//读取接收到的数据

//		
//		if((USART_RX_STA&0x8000)==0)//接收未完成
//			{
//			if(USART_RX_STA&0x4000)//接收到了0x0d
//				{
//				if(Res!=0x0a)USART_RX_STA=0;//接收错误,重新开始
//				else USART_RX_STA|=0x8000;	//接收完成了 
//				}
//			else //还没收到0X0D
//				{	
//				if(Res==0x0d)USART_RX_STA|=0x4000;
//				else
//					{
//					USART_RX_BUF[USART_RX_STA&0X3FFF]=Res ;
//					USART_RX_STA++;
//					if(USART_RX_STA>(USART_REC_LEN-1))USART_RX_STA=0;//接收数据错误,重新开始接收	  
//					}		 
//				}
//			}   		 
//     } 
//#if SYSTEM_SUPPORT_OS 	//如果SYSTEM_SUPPORT_OS为真，则需要支持OS.
//	OSIntExit();  											 
//#endif
//} 
//#endif	

