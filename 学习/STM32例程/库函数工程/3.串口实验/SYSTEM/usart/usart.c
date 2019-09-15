#include "sys.h"
#include "usart.h"	
#include "string.h"
////////////////////////////////////////////////////////////////////////////////// 	 
//���ʹ��ucos,����������ͷ�ļ�����.
#if SYSTEM_SUPPORT_OS
#include "includes.h"					//ucos ʹ��	  
#endif
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32������
//����1��ʼ��		   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/8/18
//�汾��V1.5
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved
//********************************************************************************
//V1.3�޸�˵�� 
//֧����Ӧ��ͬƵ���µĴ��ڲ���������.
//�����˶�printf��֧��
//�����˴��ڽ��������.
//������printf��һ���ַ���ʧ��bug
//V1.4�޸�˵��
//1,�޸Ĵ��ڳ�ʼ��IO��bug
//2,�޸���USART_RX_STA,ʹ�ô����������ֽ���Ϊ2��14�η�
//3,������USART_REC_LEN,���ڶ��崮�����������յ��ֽ���(������2��14�η�)
//4,�޸���EN_USART1_RX��ʹ�ܷ�ʽ
//V1.5�޸�˵��
//1,�����˶�UCOSII��֧��
////////////////////////////////////////////////////////////////////////////////// 	  
 

//////////////////////////////////////////////////////////////////
//�������´���,֧��printf����,������Ҫѡ��use MicroLIB	  
#if 1
#pragma import(__use_no_semihosting)             
//��׼����Ҫ��֧�ֺ���                 
struct __FILE 
{ 
	int handle; 

}; 

FILE __stdout;       
//����_sys_exit()�Ա���ʹ�ð�����ģʽ    
_sys_exit(int x) 
{ 
	x = x; 
} 
//�ض���fputc���� 
int fputc(int ch, FILE *f)
{      
	while((USART1->SR&0X40)==0);//ѭ������,ֱ���������   
    USART1->DR = (u8) ch;      
	return ch;
}
#endif 

 
 
//#if EN_USART1_RX   //���ʹ���˽���
//����1�жϷ������
//ע��,��ȡUSARTx->SR�ܱ���Ī������Ĵ���   	
//u8 USART_RX_BUF[USART_REC_LEN];     //���ջ���,���USART_REC_LEN���ֽ�.

//���ͻ�����
u8 Usart1_SendBuffer[USART1_SendBufferSize];
//���ջ�����
u8 Usart1_RecvBuffer[USART1_RecvBufferSize];

 u8 Usart1_DataBuffer[100] = {0};	//���ݻ�����

u32 Usart1_SendPointer = 0;	//���ͻ�����ָ��
u32 Usart1_Write_RecvPointer = 0;	//д���ջ�����ָ��
u32 Usart1_Read_RecvPointer = 0;  //�����ջ�����ָ��
u32 Usart1_BufferToTrail_Flag = 0; //��д���ջ��������ݵ��������һ��Ԫ�ر�־ ��д������ָ�뷵��ʱ��1����������ָ�뷵��ʱ��0 
u8 Usart1_NewDataFlag = 0;

//int Usart1_SendDataSize = 0;
//int Usart1_RecvDataSize = 0;

//����״̬
//bit15��	������ɱ�־
//bit14��	���յ�0x0d
//bit13~0��	���յ�����Ч�ֽ���Ŀ
//u16 USART_RX_STA=0;       //����״̬���	
  
void uart_init(u32 bound){
  //GPIO�˿�����
  GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1|RCC_APB2Periph_GPIOA, ENABLE);	//ʹ��USART1��GPIOAʱ��
	
	USART_DeInit(USART1);		//��λ����1
  
	//USART1_TX   GPIOA.9
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; //PA.9
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//�����������
  GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIOA.9
   
  //USART1_RX	  GPIOA.10��ʼ��
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;//PA10
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//��������
  GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIOA.10  

  //Usart1 NVIC ����
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3 ;//��ռ���ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;		//�����ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ���
  
   //USART ��ʼ������

	USART_InitStructure.USART_BaudRate = bound;//���ڲ�����
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//�ֳ�Ϊ8λ���ݸ�ʽ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
	USART_InitStructure.USART_Parity = USART_Parity_No;//����żУ��λ
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//�շ�ģʽ

  USART_Init(USART1, &USART_InitStructure); //��ʼ������1
	USART_ClearITPendingBit(USART1,USART_IT_RXNE);//��մ���1���ձ��
  USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);//��������1�����ж�
  USART_Cmd(USART1, ENABLE);                    //ʹ�ܴ���1 

}

//���ڷ���һ���ֽ�
void USART1_Send_Byte(u8 PortNum, u8 byte)
{
	if(PortNum == 1){
		USART_ClearFlag(USART1,USART_FLAG_TC);
		USART_SendData(USART1,byte);
		while(USART_GetFlagStatus(USART1,USART_FLAG_TC) != SET);  //�ȴ�������ɣ����USART_FLAG_TC�Ƿ���1��
	}/*else if(PortNum == 2){
		USART_SendData(USART2,byte);
		while(USART_GetFlagStatus(USART2,USART_FLAG_TC) != SET);  //�ȴ�������ɣ����USART_FLAG_TC�Ƿ���1��
	}else if(PortNum == 3){
		USART_SendData(USART3,byte);
		while(USART_GetFlagStatus(USART3,USART_FLAG_TC) != SET);  //�ȴ�������ɣ����USART_FLAG_TC�Ƿ���1��
	}else if(PortNum == 4){
		USART_SendData(UART4,byte);
		while(USART_GetFlagStatus(UART4,USART_FLAG_TC) != SET);  //�ȴ�������ɣ����USART_FLAG_TC�Ƿ���1��
	}else if(PortNum == 5){
		USART_SendData(UART5,byte);
		while(USART_GetFlagStatus(UART5,USART_FLAG_TC) != SET);  //�ȴ�������ɣ����USART_FLAG_TC�Ƿ���1��
	}*/
}

//���ڷ����ַ���
void USART1_Send_Str(u8 *str)
{
	while(*str != '\0'){
		USART1_Send_Byte(1,*str);
		str++;
	}
}

//���ڷ���һ�������ַ���
void USART1_Send_Str2(u8 *str, u32 len)
{
	while(len != 0){
		USART1_Send_Byte(1,*str);
		str++;
		len--;
	}
}

void USART1_IRQHandler(void)                	//����1�жϷ������
{
	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)  //�����ж� 
		{
			USART_ClearITPendingBit(USART1,USART_IT_RXNE);//��մ���1���ձ��
		  Usart1_RecvBuffer[Usart1_Write_RecvPointer++] = USART_ReceiveData(USART1);	//��ȡ���յ�������
		
//			//���û�����������������+1.���߶���������
//			if(Usart1_RecvDataSize < USART1_RecvBufferSize){
//				Usart1_RecvDataSize ++;
//			}
			
			//ָ���ƶ���������β��ַ��ѭ�����������׵�ַ
			if(Usart1_Write_RecvPointer == USART1_RecvBufferSize){
				Usart1_Write_RecvPointer = 0;
				Usart1_BufferToTrail_Flag = 1;
			}	 
     }

//		if(USART_GetITStatus(USART1,USART_IT_TXE) != RESET){	//�����ж�
//			USART_SendData(USART1,TxBuffer[TxCounter++]);
//		}
		 
		 
}

void Usart1_DataBufferCopy(u32 indexL, u32 indexR){	//�Ӵ��ڽ��ջ���������һ�����ݵ����ݻ�����
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


u8 Usart1_DataSelect(void){			//ѡȡһ֡���� 7E��ͷ7E��β
	u8 Flag = 0;	//��⵽7E
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

u8 Usart1_DataRead(void){	//�ӽ��ջ�������һ֡����
	
	u8 check = 0;
//	u8 Flag = 0;	//��⵽7E
//	u32 indexL = 0, indexR = 0; 
	if(Usart1_BufferToTrail_Flag == 0){
		if(Usart1_Read_RecvPointer == Usart1_Write_RecvPointer)
			return 0;	//���ݻ�����Ϊ�ջ��Ѿ�����
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
//void USART1_IRQHandler(void)                	//����1�жϷ������
//	{

//	u8 Res;
//#if SYSTEM_SUPPORT_OS 		//���SYSTEM_SUPPORT_OSΪ�棬����Ҫ֧��OS.
//	OSIntEnter();    
//#endif
//	
//	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)  //�����ж�(���յ������ݱ�����0x0d 0x0a��β)
//		{
//		Res =USART_ReceiveData(USART1);	//��ȡ���յ�������

//		
//		if((USART_RX_STA&0x8000)==0)//����δ���
//			{
//			if(USART_RX_STA&0x4000)//���յ���0x0d
//				{
//				if(Res!=0x0a)USART_RX_STA=0;//���մ���,���¿�ʼ
//				else USART_RX_STA|=0x8000;	//��������� 
//				}
//			else //��û�յ�0X0D
//				{	
//				if(Res==0x0d)USART_RX_STA|=0x4000;
//				else
//					{
//					USART_RX_BUF[USART_RX_STA&0X3FFF]=Res ;
//					USART_RX_STA++;
//					if(USART_RX_STA>(USART_REC_LEN-1))USART_RX_STA=0;//�������ݴ���,���¿�ʼ����	  
//					}		 
//				}
//			}   		 
//     } 
//#if SYSTEM_SUPPORT_OS 	//���SYSTEM_SUPPORT_OSΪ�棬����Ҫ֧��OS.
//	OSIntExit();  											 
//#endif
//} 
//#endif	

