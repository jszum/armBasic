#include "stm32f4xx.h"

#define RED 		(1<<14)
#define GREEN 	(1<<12)
#define BLUE 		(1<<15)
#define ORANGE	(1<<13)

void system_setup(void){
	//RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPCEN;
	RCC->AHB1ENR |= 0x00000008;
	GPIOD->MODER |= (1 << 24) | (1 << 26) | (1 << 28) | (1 << 30); //set leds lines
	GPIOA->MODER |= (1<<0);
	GPIOD->OTYPER &= 0x00000000;
	GPIOD->AFR[1];
	
	__enable_irq();
	NVIC_EnableIRQ(EXTI0_IRQn);
	NVIC_SetPriority(EXTI0_IRQn, 0);
}
void wait() {
	int i = 0;
	for(i = 0; i <1000000; ++i);
}

void blink_led() {

	GPIOD->ODR &= (1<<14);
	wait();
	GPIOD->ODR = ~(1<<14);	
	wait();
}


int main() {

	system_setup();
	while(1) {
		blink_led();
	}
	return 0;
}
