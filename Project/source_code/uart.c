#include "uart.h"
#include "gpio.h"






void uart_init(void)
{
							/* Gpio init for USART2*/

	// Set PA2 & PA3  as Alternate function mode  for USART2

		GPIOA_MODER &= ~(1<<4);
		GPIOA_MODER |= (1<<5);

		GPIOA_MODER &= ~(1<<6);
		GPIOA_MODER |= (1<<7);

	// Set PA2  to Alternate function type AF07 For USART2 TX  */
		GPIOA_AFRL |= (1U<<8);
		GPIOA_AFRL |= (1U<<9);
		GPIOA_AFRL |= (1U<<10);
		GPIOA_AFRL &= ~(1U<<11);

	// Set PA3  to Alternate function type AF07 For USART2 RX  */
		GPIOA_AFRL |= (1U<<12);
		GPIOA_AFRL |= (1U<<13);
		GPIOA_AFRL |= (1U<<14);
		GPIOA_AFRL &= ~(1U<<15);




				/* Configure USART2 Registers */

		// /Clock access to USART2
			RCC_APB1ENR |= USART2EN;

		// Baud rate configuration
			configure_baud_rate(BAUD_RATE,APB1_CLOCK);

		// Enable TE & RE (TRansmitter/Reciever enable ) in CR1
			USART2_CR1 |= TE_CR1 | RE_CR1;

		// Enble UART module using CR1
			USART2_CR1 |= UE_CR1;


}


void usart2_write(int c)
{
	while(!(USART2_SR & TXE_SR)) {}  // wait till Data register is empty

	USART2_DR = (c) & (0xFF);   // now that DR is empty write the next character to it
}

char usart2_read(void)
{
	while(!(USART2_SR & RXNE_SR)){}  // wait till DR is filled with the new byte

	return USART2_DR;   // Read the byte

}


void configure_baud_rate(uint32_t BAUDRATE,uint32_t PERIPHERAL_CLOCK)
{
	USART2_BRR = ((PERIPHERAL_CLOCK + (BAUDRATE/2U))/BAUDRATE);
}
