#include "adc.h"

#include "gpio.h"
#include "base_address.h"
#include "uart.h"


#define ADC1_EN      (1<<8)  // bit 8 in the APB2ENR
#define ADC1_CH1     (1<<0)  // we want out PA1 as the first to be converted
#define CR2_ADON     (1<<0) // ADC1 ON bit in the cr2
#define CR2_CONT     (1<<1)  // Continous conversion enabled
#define CR2_SWSTART  (1<<30)  // software start enable to start conversion
#define SR_EOC       (1<<1) // End of conversion










void adc_init(void)
{
				/* GPIO INIT FOR ADC*/

	// Set the mode of PA1 to  analog mode */

	 GPIOA_MODER |= (1U<<2);
	 GPIOA_MODER |= (1U<<3);

	 	 	 	 /* Configure the ADC Module*/

	 // Clock for ADC module
	 	RCC_APB2ENR |= ADC1_EN;

	 // Conversion sequence start
	 	ADC1_SQR3 = ADC1_CH1;    // 0b 00001   - 5 bit value which is 1  for channel 1 in sequence order 1

	 // Conversion sequence length

	    ADC1_SQR1 = 0; // 0 value implying the length of sequence is 1 ie only 1 channel is used which is PA1

	   // Enable ADC module
	    ADC1_CR2 |= CR2_ADON;  // Turn on the ADC module

}

void adc_start_conversion(void)
{
	/*Enable continous conversion */

			ADC1_CR2 |= CR2_CONT;


		/* start conversion */

		ADC1_CR2 |= CR2_SWSTART;  // START CONVERSION OF REGULAR CHANNELS

}


uint32_t adc_read(void)
{
	while(!(ADC1_SR & SR_EOC)){}   // Wait for the conversion to get complete

	return ADC1_DR;  // once complete return the value from DR
}


void adc_sample_signal(char *buffer, enum State *program_state)  //whenever the led turns blue , start sampling the data
{

	uint32_t uart_byte;  // the value sampled by the adc
	char byte_one;

	if(*program_state == ON){
		char *ptr = buffer;

		for(int i=0; i<64; i++)
		{
			uart_byte = adc_read();  	// adc reads the 12 bit value and put that in the uart_byte
			byte_one = (uart_byte & 0xFF);   // just take the first byte

			*buffer++ = byte_one;  // transfer that byte to the buffer since the uart trasnfers 8 bits of data
		}  // Sampling complete


		adc_transmit_signal(ptr);  // pass the pointer to the first byte and start transmitting via uart from there

	}

}


void adc_transmit_signal(char *buffer)
{
	for(int i =0;i<64; i++){
		usart2_write(*buffer++); // Pass on all the 64 bytes to the uart_write function
	}
}


