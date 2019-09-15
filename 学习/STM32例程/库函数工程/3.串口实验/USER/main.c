#include "sys.h"
#include "usart.h"
#include "delay.h"
#include "led.h"

extern u8 Usart1_SendBuffer[USART1_SendBufferSize];
extern u8 Usart1_RecvBuffer[USART1_RecvBufferSize];
extern int Usart1_SendPointer;	//���ͻ�����ָ��
extern int Usart1_RecvPointer;	//���ջ�����ָ��
extern void Usart1_DataBufferCopy();
extern void Usart1_DataSelect(void);
extern u8 Usart1_DataRead(void);
extern  u32 Usart1_BufferToTrail_Flag;
extern u32 Usart1_Write_RecvPointer;	//д���ջ�����ָ��
extern u32 Usart1_Read_RecvPointer;  //�����ջ�����ָ��
extern u8 Usart1_NewDataFlag;

extern u8 Usart1_DataBuffer[100];	//���ݻ�����

int main(void)
{
    u8 t,n;
    u8 len;
    u16 times=0;
    delay_init(); //��ʱ������ʼ��
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //�����жϷ���
    uart_init(9600); //���ڳ�ʼ��Ϊ 9600
    LED_Init(); //��ʼ���� LED ���ӵ�Ӳ���ӿ�
    while(1)
    {
//        if(USART_RX_STA&0x8000)
//        {
//            len=USART_RX_STA&0x3fff;//�õ��˴ν��յ������ݳ���
//            printf("\r\n �����͵���ϢΪ:\r\n");
//            for(t=0; t<len; t++)
//            {
//                USART1->DR=USART_RX_BUF[t];
//                while((USART1->SR&0X40)==0);//�ȴ����ͽ���
//            }
//            printf("\r\n\r\n");//���뻻��
//            USART_RX_STA=0;
//        } else
//        {
//            times++;
//            if(times%5000==0)
//            {
//								
//                printf("ALIENTEK MiniSTM32 ������ ����ʵ��");
//                
//            }
//            if(times%200==0){
//							Usart1_DataRead();
//							n+=1;
//Usart1_DataBufferCopy(18,2);
//Usart1_DataSelect();

if(Usart1_DataRead()==1){
USART1_Send_Str(Usart1_DataBuffer);
//Usart1_NewDataFlag=0;
}
//USART_SendData(USART1,'c');
delay_ms(1000);
							//printf("%X\n",n);
							//printf("%X\n",Usart1_RecvBuffer[2]);
//							printf("%d\n",Usart1_BufferToTrail_Flag);
//							printf("%d\n",Usart1_Write_RecvPointer);
//							printf("%d\n",Usart1_Read_RecvPointer);
//							printf("%d\n",Usart1_DataBuffer[0]);
//							USART1_Send_Str(Usart1_RecvBuffer);
							//USART1_Send_Str("\n");
							//printf("OOK");
							
							//printf("����������,�Իس�������\r\n");
						}
//            if(times%30==0)LED0=!LED0;//��˸ LED,��ʾϵͳ��������.
//            delay_ms(10);
        //}
//      }
}
