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
#include "spi_soft_master.h"

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
	// Inint Master SPI
	SPI_Master_Init();
	// Config Button
	BUTTON_CONFIG;
	gpio_config(GPIOD,PORTD,PIN12,PIN_OUTPUT);
	gpio_config(GPIOD,PORTD,PIN13,PIN_OUTPUT);
	gpio_config(GPIOD,PORTD,PIN14,PIN_OUTPUT);
	gpio_config(GPIOD,PORTD,PIN15,PIN_OUTPUT);
	
	uint8_t transmit_data[4] = {0x0C,0x0D,0x0E,0x0F};
	uint8_t receive_data[4];
	while(1)
	{
		for(int i = 0; i < 8; i++)
		{
			SS_ENABLE;												// Reset Pin SS to start transmit data	
			receive_data[i] = SPI_Master_ReadWrite(transmit_data[i]);
			SS_DISENABLE;											// Set Pin SS to stop transmit data	
			gpio_output(GPIOD,PORTD,receive_data[i],PIN_TOGGLE);
			delay_systick_ms(1000);	
		}
	}
}







