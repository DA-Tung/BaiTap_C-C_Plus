#ifndef _I2C_SOFT_H_
#define _I2C_SOFT_H_

#include "stm32f4xx.h"
#include "stm32f407xx.h"

void I2C_Init(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Ack(void);
void I2C_NAck(void);
void I2C_Send_Byte(uint8_t M_data);
uint8_t I2C_Receive_Byte(void);

#endif 





