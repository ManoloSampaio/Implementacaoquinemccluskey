#include "arduinoToGreen.h"
#include "stm32f0xx_hal.h"


unsigned int equivalencia [20][2]={
    	{GPIOA,GPIO_PIN_3},
    	{GPIOA,GPIO_PIN_2},
    	{GPIOF,GPIO_PIN_0},
    	{GPIOF,GPIO_PIN_1},
    	{GPIOA,GPIO_PIN_13},
    	{GPIOA,GPIO_PIN_14},
    	{0,0},
    	{0,0},
		{0,0},
		{0,0},
		{0,0},
    	{GPIOA,GPIO_PIN_7},
    	{GPIOA,GPIO_PIN_6},
    	{GPIOA,GPIO_PIN_5},
    	{GPIOA,GPIO_PIN_0},
    	{GPIOA,GPIO_PIN_1},
    	{GPIOA,GPIO_PIN_4},
    	{GPIOB,GPIO_PIN_1},
    	{GPIOA,GPIO_PIN_10},
    	{GPIOA,GPIO_PIN_9}
};

void digitalWrite (int pino, int valor){
	GPIO_TypeDef *p;
	p = (GPIO_TypeDef *)equivalencia[pino][0];
	if (valor != 0){
		p->BSRR = equivalencia[pino][1];
	}else{
		p->BRR = equivalencia[pino][1];
	}
}
int    digitalRead (int pino){
	return HAL_GPIO_ReadPin(equivalencia[pino][0], equivalencia[pino][1]);
}

