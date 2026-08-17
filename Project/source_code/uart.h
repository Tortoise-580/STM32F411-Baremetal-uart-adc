#ifndef UART_H
#define UART_H

#include "base_address.h"
#include <stdint.h>

#define SR_OFFSET    (0X00)
#define DR_OFFSET    (0X04)
#define BRR_OFFSET   (0X08)
#define CR1_OFFSET   (0X0C)
#define CR2_OFFSET   (0X10)
#define CR3_OFFSET   (0X14)

#define USART2_SR_ADDRESS   	(USART2_BASE + SR_OFFSET)
#define USART2_DR_ADDRESS		(USART2_BASE + DR_OFFSET)
#define USART2_BRR_ADDRESS		(USART2_BASE + BRR_OFFSET)
#define USART2_CR1_ADDRESS		(USART2_BASE + CR1_OFFSET)
#define USART2_CR2_ADDRESS		(USART2_BASE + CR2_OFFSET)
#define USART2_CR3_ADDRESS		(USART2_BASE + CR3_OFFSET)


#define USART2_SR           (*(volatile unsigned int *)(USART2_SR_ADDRESS))
#define USART2_DR 			(*(volatile unsigned int *)(USART2_DR_ADDRESS))
#define USART2_BRR 			(*(volatile unsigned int *)(USART2_BRR_ADDRESS))
#define USART2_CR1 			(*(volatile unsigned int *)(USART2_CR1_ADDRESS))
#define USART2_CR2			(*(volatile unsigned int *)(USART2_CR2_ADDRESS))
#define USART2_CR3 			(*(volatile unsigned int *)(USART2_CR3_ADDRESS))



#define USART2EN    (1<<17)  // Bit 17 of APB1ENR
#define UE_CR1          (1<<13)  // Bit 13 in CR1 for UART Enable

#define SYS_FREQ   16000000
#define APB1_CLOCK    SYS_FREQ
#define BAUD_RATE   (115200UL)



#define TE_CR1    (1u<<3)  //  bit 3 of CR1 for TE
#define RE_CR1    (1<<2) //  bit 2 of CR1 for RE
#define TXE_SR    (1<<7)  // bit 7 of TXE SR
#define RXNE_SR   (1<<5)



void usart2_write(int c);
char usart2_read(void);
void uart_init(void);
void configure_baud_rate(uint32_t BAUDRATE,uint32_t PERIPHERAL_CLOCK);





#endif
