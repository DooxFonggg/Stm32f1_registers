#include "stm32f10x.h"              // Device header

void delay(int time){
	unsigned int count;
	while(time--){
		for (count = 0; count < 1000; count++);
	}
}
void gpio_configc13() {
	// cap clock
	RCC->APB2ENR |= (1<<4);
	// reset chan gpioc
	GPIOC->CRH = 0x00000000;

	// config chan c13
	GPIOC->CRH |= 0x00300000;
	
}

int main() {

	gpio_configc13();
	while(1) {
		GPIOC->ODR |= (1<<13);
		delay(3000);
		GPIOC->ODR &= ~(1<<13);
		delay(3000);
	}
}
