#include "stm32f10x.h"                  // Device header


void delay(int time) {
	unsigned int count;
	while(time--) {
		for(count = 0; count<1000; count++);
	}
}

void rcc_config(void){
	// cap clock port b
	RCC->APB2ENR |=(1<<3);
	//cap clock port c
	RCC->APB2ENR |=(1<<4);
}

void config_c13(void){
	//reset CRH
	GPIOC->CRH = 0x00000000;
	//config mode 11 cnf 00
	GPIOC->CRH |= 0x00300000;
}
void cofig_b9(void) {
    //reset CRH
	GPIOB->CRH = 0x00000000;
	//cofig chan
	GPIOB->CRH |= 0x00000080;
	//bat outbut chan b90 de nhan tin hieu button
	GPIOB->ODR |= (1<<9);
}
void gpio_setled(void) {
	GPIOC->BSRR = (1<<13); 
}
void gpio_setlowlet(void){
	GPIOC->BRR = (1<<13);
}
unsigned char gpio_getButton(void) {
	if(GPIOB->IDR &(1<<9)) {
		return 1;
	}
	else {
		return 0;
	}
}

unsigned char oldButton;
unsigned char newButton;
unsigned char ledStatus;

int main() {
	 rcc_config();
	 config_c13();
	 cofig_b9();
	while(1) {
		/* newButton = gpio_getButton();
		
		if((newButton==0) && (oldButton==1)) {
			ledStatus = !ledStatus;
			if(ledStatus !=0) {
				gpio_setled();
			}
			else{
				gpio_setlowlet();
			}
		}
		oldButton = newButton;
		delay(200); */
		
		if(GPIOB->IDR &(1<<9)) gpio_setled();
		else gpio_setlowlet();
		delay(200);
		
	} 
	/*gpio_setled();
	delay(3000);
	gpio_setlowlet();
	delay(3000); */
}
