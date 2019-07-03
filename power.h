#ifndef __POWER_H
#define __POWER_H	 
#include "sys.h"
#include "main.h"

#define SV1_OFF		GPIOA->BRR = GPIO_Pin_4
#define SV1_ON		GPIOA->BSRR = GPIO_Pin_4

#define SV2_OFF		GPIOA->BRR = GPIO_Pin_5
#define SV2_ON		GPIOA->BSRR = GPIO_Pin_5

#define SV3_OFF		GPIOA->BRR = GPIO_Pin_6
#define SV3_ON		GPIOA->BSRR = GPIO_Pin_6

#define SV4_OFF		GPIOA->BRR = GPIO_Pin_7
#define SV4_ON		GPIOA->BSRR = GPIO_Pin_7
void POWER_Init(void);

#endif

