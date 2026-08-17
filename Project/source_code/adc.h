
#ifndef ADC_H_
#define ADC_H_

#include "base_address.h"
#include <stdint.h>


#define ADC1_SR_OFFSET 		(0X00)
#define ADC1_CR1_OFFSET 	(0X04)
#define ADC1_CR2_OFFSET		(0X08)
#define ADC1_SMPR1_OFFSET 	(0X0C)
#define ADC1_SMPR2_OFFSET 	(0X10)
#define ADC1_SQR1_OFFSET    (0X2C)
#define ADC1_SQR3_OFFSET 	(0X34)
#define ADC1_DR_OFFSET   	(0X4C)

#define ADC1_SR_ADDRESS   	  (ADC1_BASE + ADC1_SR_OFFSET)
#define ADC1_CR1_ADDRESS      (ADC1_BASE + ADC1_CR1_OFFSET)
#define ADC1_CR2_ADDRESS      (ADC1_BASE + ADC1_CR2_OFFSET)
#define ADC1_SMPR1_ADDRESS    (ADC1_BASE + ADC1_SMPR1_OFFSET)
#define ADC1_SMPR2_ADDRESS    (ADC1_BASE + ADC1_SMPR2_OFFSET)
#define ADC1_SQR1_ADDRESS     (ADC1_BASE + ADC1_SQR1_OFFSET)
#define ADC1_SQR3_ADDRESS     (ADC1_BASE + ADC1_SQR3_OFFSET)
#define ADC1_DR_ADDRESS        (ADC1_BASE + ADC1_DR_OFFSET)




#define ADC1_SR 			    (*(volatile unsigned int *)(ADC1_SR_ADDRESS))
#define ADC1_CR1 				(*(volatile unsigned int *)(ADC1_CR1_ADDRESS))
#define ADC1_CR2				(*(volatile unsigned int *)(ADC1_CR2_ADDRESS))
#define ADC1_SMPR1				(*(volatile unsigned int *)(ADC1_SMPR1_ADDRESS))
#define ADC1_SMPR2 				(*(volatile unsigned int *)(ADC1_SMPR2_ADDRESS))
#define ADC1_SQR1      			(*(volatile unsigned int *)(ADC1_SQR1_ADDRESS))
#define ADC1_SQR3 				(*(volatile unsigned int *)(ADC1_SQR3_ADDRESS))
#define ADC1_DR   				(*(volatile unsigned int *)(ADC1_DR_ADDRESS))



void adc_init(void);
void adc_start_conversion(void);
uint32_t adc_read(void);

void adc_sample_signal(char *buffer, enum State *program_state);
void adc_transmit_signal(char *buffer);








#endif /* ADC_H_ */
