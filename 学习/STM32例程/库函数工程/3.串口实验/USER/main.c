#include "sys.h"
#include "usart.h"
#include "delay.h"
#include "led.h"

extern u8 Usart1_SendBuffer[USART1_SendBufferSize];
extern u8 Usart1_RecvBuffer[USART1_RecvBufferSize];
extern int Usart1_SendPointer;	//发送缓冲区指针
extern int Usart1_RecvPointer;	//接收缓冲区指针
extern void Usart1_DataBufferCopy();
extern void Usart1_DataSelect(void);
extern u8 Usart1_DataRead(void);
extern  u32 Usart1_BufferToTrail_Flag;
extern u32 Usart1_Write_RecvPointer;	//写接收缓冲区指针
extern u32 Usart1_Read_RecvPointer;  //读接收缓冲区指针
extern u8 Usart1_NewDataFlag;

extern u8 Usart1_DataBuffer[100];	//数据缓冲区

int main(void)
{
    u8 t,n;
    u8 len;
    u16 times=0;
    delay_init(); //延时函数初始化
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置中断分组
    uart_init(9600); //串口初始化为 9600
    LED_Init(); //初始化与 LED 连接的硬件接口
    while(1)
    {
//        if(USART_RX_STA&0x8000)
//        {
//            len=USART_RX_STA&0x3fff;//得到此次接收到的数据长度
//            printf("\r\n 您发送的消息为:\r\n");
//            for(t=0; t<len; t++)
//            {
//                USART1->DR=USART_RX_BUF[t];
//                while((USART1->SR&0X40)==0);//等待发送结束
//            }
//            printf("\r\n\r\n");//插入换行
//            USART_RX_STA=0;
//        } else
//        {
//            times++;
//            if(times%5000==0)
//            {
//								
//                printf("ALIENTEK MiniSTM32 开发板 串口实验");
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
							
							//printf("请输入数据,以回车键结束\r\n");
						}
//            if(times%30==0)LED0=!LED0;//闪烁 LED,提示系统正在运行.
//            delay_ms(10);
        //}
//      }
}
