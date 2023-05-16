/* System */
/*-----------------------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "stm32f411xe.h"
#include "stdio.h"
#include "string.h"
#include "math.h"
#include "main.h"

/* Library*/
/*-----------------------------------------------------------------------------------*/
#include "gpio.h"
#include "systick.h"
#include "spi_soft.h"

/* Declare */
/*-----------------------------------------------------------------------------------*/

/* Funcion */
/*-----------------------------------------------------------------------------------*/

/* Main Program */
/*-----------------------------------------------------------------------------------*/
int main()
{
	// Init system clock
	SysClock_configure();
	// Inint Slave SPI
	SPI_Slave_Init();
	// Config Button
	//BUTTON_CONFIG;
	
	gpio_config(GPIOD,PORTD,PIN12,PIN_OUTPUT);
	gpio_config(GPIOD,PORTD,PIN13,PIN_OUTPUT);
	gpio_config(GPIOD,PORTD,PIN14,PIN_OUTPUT);
	gpio_config(GPIOD,PORTD,PIN15,PIN_OUTPUT);
	uint8_t receive_data[4];
	uint8_t transmit_data[4] = {0x0C,0x0D,0x0E,0x0F};	
	while(1)
	{
//		receive_data[1] = SPI_Slave_ReadWrite(transmit_data[1]);
//		gpio_output(GPIOD,PORTD,receive_data[1],PIN_TOGGLE);
		gpio_output(GPIOD,PORTD,12,PIN_TOGGLE);
		delay_systick_ms(1000);
	}
}







