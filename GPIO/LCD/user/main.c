#include "stm32f10x.h"


#define LCD_Data_Dir    DDRD
#define LCD_Command_Dir  DDRC
#define LCD_Data_Port    PORTD
#define LCD_command_Port  PORTC


#define RS 0
#define RW 1
#define EN 2

//ham gui lenh
void LCD_Command(unsigned char cmd);

//ham ghi du lieu len lcd
void LCD_Char(unsigned char char_data);
void delay(int time);
void LCD_String(char *str);
void main()
{
	LCD_Data_Dir = 0xFF; //output
	LCD_Command_Dir |= (1<<RS) | (1<<RW) | (1<<EN);
	
	// khoi tao LCD
	LCD_Command(0x38); // 8bit 2 dong
	LCD_Command(0x0C); // hien thi, bat tat con tro
	LCD_Command(0x01); 
	
	LCD_String("good morning");
	LCD_Command(0xC0);// dong2
	LCD_String)("good bye");
	while(1) 
	{
		
	}
}

void LCD_Command(unsigned char cmd)
{
	LCD_command_Port &= ~(1<<RW); // keo rw xg thap = 0
	LCD_command_Port &= ~(1<<RS); //RS = 0
	LCD_Data_Port = cmd;
	LCD_command_Port |= (1<<EN);
	delay(1);
	LCD_command_Port &= (1<<RS);
	delay(3);
}
void LCD_Char(unsigned char char_data) 
{
	LCD_command_Port &= ~(1<<RW); // keo rw xg thap = 0
	LCD_command_Port |= (1<<RS); //RS = 1
	LCD_Data_Port = cmd;
	LCD_command_Port |= (1<<EN);
	delay(1);
	LCD_command_Port &= (1<<RS);
	delay(1);
}
void delay(int time) 
{
	unsigned int cnt;
	while(time--)
	{
		for(cnt=0; cnt<1000; cnt++);
	}
}
void LCD_String(char *str)
{
	int i;
	for(i = 0; str[i] != 0; i++ ) 
	{
		LCD_Char(str[i]); 
	}
}
