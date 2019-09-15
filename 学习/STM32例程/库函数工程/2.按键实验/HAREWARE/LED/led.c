#include "led.h"
#include "stm32f10x.h"

void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStrcture;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);//GPIOD
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//GPIOA
	
	GPIO_InitStrcture.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStrcture.GPIO_Pin=GPIO_Pin_2;
	GPIO_InitStrcture.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOD,&GPIO_InitStrcture);
	GPIO_SetBits(GPIOD,GPIO_Pin_2);

	GPIO_InitStrcture.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStrcture.GPIO_Pin=GPIO_Pin_8;
	GPIO_InitStrcture.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStrcture);
	GPIO_SetBits(GPIOA,GPIO_Pin_8);

}
