/* System */
/*-----------------------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "stm32f407xx.h"
#include "stdio.h"
#include "string.h"
#include "math.h"
#include "main.h"

/* Library*/
/*-----------------------------------------------------------------------------------*/
#include "gpio.h"
#include "systick.h"
#include "soft_i2c.h"

/* Declare */
/*-----------------------------------------------------------------------------------*/
uint8_t buffer[8] = {0x10,0x20,0x30,0x40,0x50,0x60,0x70,0x80};

/* Funcion */
/*-----------------------------------------------------------------------------------*/

/* Main Program */
/*-----------------------------------------------------------------------------------*/
int main()
{
	SysClock_configure();
	I2C_Init();
	
	while(1)
	{
		for(int i = 0; i < 8; i++)
		{
			I2C_Start();
			I2C_Send_Byte(0x4E);
			I2C_Send_Byte(0x00);
			I2C_Send_Byte(buffer[i]);
			I2C_Stop();
			delay_systick_ms(500);
		}
	}
}



