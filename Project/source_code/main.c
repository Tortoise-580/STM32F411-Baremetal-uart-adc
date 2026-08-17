#include "gpio.h"
#include "adc.h"
#include "uart.h"
#include <stdio.h>
#include "base_address.h"


enum State program_state = OFF;
char buffer[64];
char adc_value;


int main()
{
	gpio_init();
	uart_init();
	adc_init();
	adc_start_conversion();

	while(1){

	led_toggle();
	program_state_set(&program_state);  // Check for push button pressed or not
	program_state_display(&program_state);  //Change led red/blue , based on program_state

	adc_sample_signal(buffer,&program_state);  // if push button is pressed (blue led) then Start  Sample 64 bytes and then send it over UART

	adc_value = *buffer;  // check the live value of this variable , while the blue led is on and adc is sampling the 64 values .






	}


	return 0;
}
