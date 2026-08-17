

#ifndef GPIO_H_
#define GPIO_H_

#include "base_address.h"
#include <stdint.h>


#define MODER_OFFSET	   (0X00)
#define IDR_OFFSET		   (0X10)
#define ODR_OFFSET			(0X14)
#define AFRL_OFFSET			(0X20)
#define AFRH_OFFSET			(0x24)


#define  GPIOA_MODER_ADDRESS			(GPIOA_BASE+ MODER_OFFSET)
#define	 GPIOA_IDR_ADDRESS				(GPIOA_BASE + IDR_OFFSET)
#define  GPIOA_ODR_ADDRESS 				(GPIOA_BASE + ODR_OFFSET)
#define  GPIOA_AFRL_ADDRESS				(GPIOA_BASE + AFRL_OFFSET)
#define  GPIOA_AFRH_ADDRESS 			(GPIOA_BASE + AFRH_OFFSET)


#define  GPIOB_MODER_ADDRESS			(GPIOB_BASE+ MODER_OFFSET)
#define	 GPIOB_IDR_ADDRESS				(GPIOB_BASE + IDR_OFFSET)
#define  GPIOB_ODR_ADDRESS 				(GPIOB_BASE + ODR_OFFSET)
#define  GPIOB_AFRL_ADDRESS				(GPIOB_BASE + AFRL_OFFSET)
#define  GPIOB_AFRH_ADDRESS 			(GPIOB_BASE + AFRH_OFFSET)


#define  GPIOC_MODER_ADDRESS			(GPIOC_BASE+ MODER_OFFSET)
#define	 GPIOC_IDR_ADDRESS				(GPIOC_BASE + IDR_OFFSET)
#define  GPIOC_ODR_ADDRESS 				(GPIOC_BASE + ODR_OFFSET)
#define  GPIOC_AFRL_ADDRESS				(GPIOC_BASE + AFRL_OFFSET)
#define  GPIOC_AFRH_ADDRESS 			(GPIOC_BASE + AFRH_OFFSET)



#define GPIOA_MODER   (*(volatile unsigned int*)(GPIOA_MODER_ADDRESS))    // Treat this 'GPIOA_MODER_ADDRESS' as pointer to an volatile unsigned 32 bit value(hardware register)
#define GPIOA_IDR     (*(volatile unsigned int *)(GPIOA_IDR_ADDRESS))
#define GPIOA_ODR 	  (*(volatile unsigned int *)(GPIOA_ODR_ADDRESS))
#define GPIOA_AFRL   (*(volatile unsigned int *)(GPIOA_AFRL_ADDRESS))
#define GPIOA_AFRH   (*(volatile unsigned int *)(GPIOA_AFRH_ADDRESS))


#define GPIOB_MODER     (*(volatile unsigned int*)(GPIOB_MODER_ADDRESS))
#define GPIOB_IDR       (*(volatile unsigned int *)(GPIOB_IDR_ADDRESS))
#define GPIOB_ODR 	    (*(volatile unsigned int *)(GPIOB_ODR_ADDRESS))
#define GPIOB_AFRL     (*(volatile unsigned int *)(GPIOB_AFRL_ADDRESS))
#define GPIOB_AFRH     (*(volatile unsigned int *)(GPIOB_AFRH_ADDRESS))



#define GPIOC_MODER     (*(volatile unsigned int*)(GPIOC_MODER_ADDRESS))
#define GPIOC_IDR       (*(volatile unsigned int *)(GPIOC_IDR_ADDRESS))
#define GPIOC_ODR   	(*(volatile unsigned int *)(GPIOC_ODR_ADDRESS))
#define GPIOC_AFRL     (*(volatile unsigned int *)(GPIOC_AFRL_ADDRESS))
#define GPIOC_AFRH     (*(volatile unsigned int *)(GPIOC_AFRH_ADDRESS))




#define GPIOAEN  (1U<<0)
#define GPIOBEN  (1U<<1)
#define GPIOCEN  (1U<<2)

#define PA5    (1u<<5)
#define PB13   (1U<<13)
#define PC13   (1U<<13)
#define PA8    (1u<<8)

#define RED_LED  (PA8)
#define BLUE_LED (PB13)
#define PUSH_BUTTON (PC13)
#define USER_LED    (PA5)




void gpio_init(void);
void red_led_on(void);
void red_led_off(void);
void blue_led_on(void);
void blue_led_off(void);
void led_toggle(void);
void program_state_set(enum State *program_state);
void program_state_display(enum State *program_state);






#endif /* GPIO_H_ */
