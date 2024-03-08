#include "stm32f10x.h"                  // Device header

GPIO_InitTypeDef  GPIO_InitStructure; 


void Delay_SysTick_Ms (int time) 
{
	unsigned int count;
	while(time--){
		for (count = 0; count < 1000; count++);
	}
}

//mang led tu 1->9

uint8_t LedCode7seg[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};


// no la so d(D1, D2D3,D4)  u32Number la so cua mang 0->9
void ShowLed7Seg(uint8_t no, uint32_t u32Number) {
	uint32_t u32TempNumber = 0U;
	
	u32TempNumber = LedCode7seg[u32Number]; // giá tri khoi tao mang  
	
	//a trong led 7
	if((u32TempNumber&0x01) == 0x01) 
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_0);
	}
	else 
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_0);
	}
	//b
	u32TempNumber = u32TempNumber>>1;
	if((u32TempNumber&0x01) == 0x01) 
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_1);
	}
	else 
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_1);
	}
	//c
	u32TempNumber = u32TempNumber>>1;
	if((u32TempNumber&0x01) == 0x01) 
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_2);
	}
	else 
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_2);
	}
	//d
	u32TempNumber = u32TempNumber>>1;
	if((u32TempNumber&0x01) == 0x01) 
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_3);
	}
	else 
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_3);
	}
	//e
	u32TempNumber = u32TempNumber>>1;
	if((u32TempNumber&0x01) == 0x01) 
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_4);
	}
	else 
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_4);
	}
	//f
	u32TempNumber = u32TempNumber>>1;
	if((u32TempNumber&0x01) == 0x01) 
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_5);
	}
	else 
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_5);
	}
	//g
	u32TempNumber = u32TempNumber>>1;
	if((u32TempNumber&0x01) == 0x01) 
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_6);
	}
	else 
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_6);
	}
	//set up cac chan D nho no
	if(no == 1)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_7);
	}
	else if(no == 2)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_8);
	}
	else if(no == 3)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_9);
	}
	else if(no == 4)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_10);
	}
	else 
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_7);
		GPIO_ResetBits(GPIOA, GPIO_Pin_8);
		GPIO_ResetBits(GPIOA, GPIO_Pin_9);
		GPIO_ResetBits(GPIOA, GPIO_Pin_10);
	}
	
	Delay_SysTick_Ms(7);
}

// ham hien thi 4 so vd: 1234

void Display_7Seg(uint32_t u32Number) 
{
	uint32_t u32Digit;
	
    GPIO_ResetBits(GPIOA, GPIO_Pin_7);
	GPIO_ResetBits(GPIOA, GPIO_Pin_8);
	GPIO_ResetBits(GPIOA, GPIO_Pin_9);
	GPIO_ResetBits(GPIOA, GPIO_Pin_10);
	
	u32Digit = u32Number/1000; //vd: 1234/1000 = 1 lay duoc dau
	ShowLed7Seg(4, u32Digit);
	GPIO_ResetBits(GPIOA, GPIO_Pin_7);
	GPIO_ResetBits(GPIOA, GPIO_Pin_8);
	GPIO_ResetBits(GPIOA, GPIO_Pin_9);
	GPIO_ResetBits(GPIOA, GPIO_Pin_10);
	
	u32Number = u32Number - u32Digit*1000; //1234-1000 = 234
	u32Digit = u32Number/100; //234/100 = 2
	ShowLed7Seg(3, u32Digit);
	GPIO_ResetBits(GPIOA, GPIO_Pin_7);
	GPIO_ResetBits(GPIOA, GPIO_Pin_8);
	GPIO_ResetBits(GPIOA, GPIO_Pin_9);
	GPIO_ResetBits(GPIOA, GPIO_Pin_10);
	
	u32Number = u32Number - u32Digit*100; //234-200 = 34
	u32Digit = u32Number/10; //34/10 = 3
	ShowLed7Seg(2, u32Digit);
	GPIO_ResetBits(GPIOA, GPIO_Pin_7);
	GPIO_ResetBits(GPIOA, GPIO_Pin_8);
	GPIO_ResetBits(GPIOA, GPIO_Pin_9);
	GPIO_ResetBits(GPIOA, GPIO_Pin_10);
	
	u32Number = u32Number - u32Digit*10; //34-30 = 4
	u32Digit = u32Number;
	ShowLed7Seg(1, u32Digit);
	// boc tung so xong ghi vao den d1 la luu het cac so 
}

void Display_Led7(uint32_t u32Number) {
	// uint32_t u32TempNumber = 0U;
	 unsigned int temp;
	 temp = LedCode7seg[u32Number]; // giá tri khoi tao mang  
	
	  
	   // so 1 thi b c muc 0 con lai muc 1 . oxF9  (0x11111001)
	
		if((temp&0x01)==0x01)		   		 //   a
		   GPIO_SetBits(GPIOA ,GPIO_Pin_0);   
		   else
		   GPIO_ResetBits(GPIOA ,GPIO_Pin_0); 		  
		   temp=temp>>1;
		   
		if((temp&0x01)==0x01)		   		 //   b
		   GPIO_SetBits(GPIOA ,GPIO_Pin_1);   
		   else
		   GPIO_ResetBits(GPIOA ,GPIO_Pin_1); 		  
		   temp=temp>>1;
		
		if((temp&0x01)==0x01)		   		 //   c
		   GPIO_SetBits(GPIOA ,GPIO_Pin_2);   
		   else
		   GPIO_ResetBits(GPIOA ,GPIO_Pin_2); 		  
		   temp=temp>>1;
		
		if((temp&0x01)==0x01)		   		 //   d
		   GPIO_SetBits(GPIOA ,GPIO_Pin_3);   
		   else
		   GPIO_ResetBits(GPIOA ,GPIO_Pin_3); 		  
		   temp=temp>>1;
		   
		if((temp&0x01)==0x01)		   		 //   e
		   GPIO_SetBits(GPIOA ,GPIO_Pin_4);   
		   else
		   GPIO_ResetBits(GPIOA ,GPIO_Pin_4); 		  
		   temp=temp>>1;
		
		if((temp&0x01)==0x01)		   		 //   f
		   GPIO_SetBits(GPIOA ,GPIO_Pin_5);   
		   else
		   GPIO_ResetBits(GPIOA ,GPIO_Pin_5); 		  
		   temp=temp>>1;
			 
		if((temp&0x01)==0x01)		   		 //   g
		   GPIO_SetBits(GPIOA ,GPIO_Pin_6);   
		   else
		   GPIO_ResetBits(GPIOA ,GPIO_Pin_6); 		  
		   temp=temp>>1;
	
}
void GPIO_Config(void) {
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1| GPIO_Pin_2| GPIO_Pin_3| GPIO_Pin_4| GPIO_Pin_5| GPIO_Pin_6| GPIO_Pin_7| GPIO_Pin_8| GPIO_Pin_9| GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	//tao config de su dung
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}
void GPIO_Config2(void) 
{
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1| GPIO_Pin_2| GPIO_Pin_3| GPIO_Pin_4| GPIO_Pin_5| GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	//tao config de su dung
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}
uint32_t cnt= 0U; //so 0

int main() 
{   
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	//GPIO_Config();
	GPIO_Config2();
	while(1)
	{
		//Display_7Seg(cnt);
		//cnt++;
		uint32_t i = 0;
		for(i = 0; i<10; i++) 
		{
			Display_Led7(i);
			Delay_SysTick_Ms(2000);
		}
	}  
	
	
}
