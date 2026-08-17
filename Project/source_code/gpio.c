#include "gpio.h"





void gpio_init(void)
{
	RCC_AHB1ENR |=GPIOAEN;    // Clock to PORTA
	RCC_AHB1ENR |=GPIOBEN;  // CLOCK TO PORTB
	RCC_AHB1ENR |=GPIOCEN;  // CLOCK TO PORTC

	// PA5 for user led output mode (green)
	GPIOA_MODER &=~ (1<<11);
	GPIOA_MODER |= (1<<10);


	// PA8 for led output mode (RED)
	GPIOA_MODER &=~ (1<<17);
	GPIOA_MODER |= (1<<16);

	//PB13 for led output mode  (blue)
	GPIOB_MODER &=~ (1<<27);
	GPIOB_MODER |= (1<<26);

	// PC13 for push button input mode( By default a pull up is connected to this circuitry)
	GPIOC_MODER &=~ (1<<27);
	GPIOC_MODER &=~(1<<26);





}


void red_led_on(void)
{
	GPIOA_ODR|= RED_LED;
}

void blue_led_on(void)
{
	GPIOB_ODR|= BLUE_LED;
}

void red_led_off(void)
{
	GPIOA_ODR &= ~RED_LED;

}

void blue_led_off(void)
{
	GPIOB_ODR &= ~BLUE_LED;
}


void led_toggle(void)
{
	GPIOC_ODR ^= USER_LED;

	for(int i =0; i<100000;i++);  // small delay to make the change atleast visible
}

void program_state_set(enum State *program_state)
{
	// If button is pressed
	if((GPIOC_IDR & PUSH_BUTTON) == 0){
			if(*program_state == OFF){    // going from OFF TO ON (first button press)
				*program_state = ON;
				for(volatile int i =0; i<150000; i++);  // To prevent toggling
			}
			else if(*program_state == ON){   // Going from ON TO OFF
			*program_state = OFF;	  // If button not pressed and the program_state = ON  :-> then change it to OFF
			for(volatile int i =0; i<150000; i++); // To prevent toggling , since the cpu is considerably fast
			}

	}
}

void program_state_display(enum State *program_state)  // Change led color , based on the program_state obtained/change at program_state_set
{
	if(*program_state == OFF){  // if off turn on red led , and turn off blue led
		red_led_on();
		blue_led_off();
	}else { 				// Program state = on -> measuring ADC
		blue_led_on();
		red_led_off();
	}
}

