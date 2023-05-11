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

/* Declare */
/*-----------------------------------------------------------------------------------*/
// Declare Master
#define Master_SS			4
#define Master_SCK			5
#define Master_MISO			6
#define Master_MOSI			7

// Declare Slave
#define Slave_SS			12
#define Slave_SCK			13
#define Slave_MISO			14
#define Slave_MOSI			15

// Declare Funcion Master
//void SPI_Master_Init();							// Funcion init master SPI
//void SPI_Mater_Clock();							// Funcion create a pulse clock
//void SPI_Master_Transmit(uint8_t data);			// Funicon transmit 1 byte of master
//uint8_t SPI_Master_Receive();					// Funcion recieve 1 byte

// Declare Funcion Slave

	uint8_t master_transmit_data = 5;
//	uint8_t master_receive_data[4];
//	uint8_t slave_transmit_data[4] = {0x22,0x44,0x88,0xBB};
	uint8_t slave_receive_data = 0;

/* Funcion */
/*-----------------------------------------------------------------------------------*/
// SPI funcion clock
void SPI_Clock()
{
	gpio_output(GPIOA,PORTA,Master_SCK,PIN_SET);
	delay_systick_us(10);
	gpio_output(GPIOA,PORTA,Master_SCK,PIN_RESET);
	delay_systick_us(10);
}

// SPI Master Init
void SPI_Master_Init()
{
	// Setup PIN mode
	gpio_output(GPIOA,PORTA,Master_SS,PIN_SET);
	gpio_output(GPIOA,PORTA,Master_SCK,PIN_RESET);
	gpio_output(GPIOA,PORTA,Master_MOSI,PIN_RESET);	
	gpio_config(GPIOA,PORTA,Master_MISO,PIN_INPUT);
}

uint8_t SPI_TransmitReceive_Byte(uint8_t data)
{
	uint8_t receive_data;
	for(uint8_t i = 0; i < 8; i++)
	{
		if((data&0x80) == 0) gpio_output(GPIOA,PORTA,Master_MOSI,PIN_RESET);
		else gpio_output(GPIOA,PORTA,Master_MOSI,PIN_SET);
		
		delay_systick_us(10);
		gpio_output(GPIOA,PORTA,Master_SCK,PIN_SET);
		
		if(gpio_input(GPIOB,PORTB,Slave_SCK) == BIT_SET)
		{
			receive_data = receive_data << 1;
			receive_data = receive_data | gpio_input(GPIOB,PORTB,Slave_MOSI);	
		}		
		delay_systick_us(10);	
		gpio_output(GPIOA,PORTA,Master_SCK,PIN_RESET);	
		data = data << 1;
	}
	return receive_data;
}

// SPI Master transmit
/*
	Funcion : SPI Master transmit
	Purpure : transmit 1 byte form MOSI Pin
*/
void SPI_Master_Transmit(uint8_t data)
{
	/* program implementation transmit each bit at MOSI Pin	*/
	for(uint8_t i = 0; i < 8; i++)
	{
		if((data&0x80) == 0)	gpio_output(GPIOA,PORTA,Master_MOSI,PIN_RESET);		// Check status each bit to transmit data
		else					gpio_output(GPIOA,PORTA,Master_MOSI,PIN_SET); 
		SPI_Clock();																// Emit 1 pulse clock to transmit 1 bit
		data = data << 1;															// shift bit to the left to continue transmit next bit 
	}
}	

uint8_t SPI_Master_Receive()
{
	uint8_t data;
	/* program implementation receive 1 byte at MISO Pin	*/	
	for(uint8_t i = 0; i < 8; i++)
	{
		SPI_Clock();																// Emit 1 pulse clock to receive next bit
		data = data << 1;
		data = data | gpio_input(GPIOA,PORTA,Master_MISO);							// Read status of MISO Pin 
	}
	return data;																	// Reteurn value of data after end receive
}

// SPI Slave Init
void SPI_Slave_Init()
{
	gpio_output(GPIOB,PORTB,Slave_MOSI,PIN_RESET);	
	gpio_config(GPIOB,PORTB,Slave_SCK,PIN_INPUT);
	gpio_config(GPIOB,PORTB,Slave_MOSI,PIN_INPUT);
	gpio_config(GPIOB,PORTB,Slave_SS,PIN_INPUT);
}

// SPI Slave transmit
void SPI_Slave_Transmit(uint8_t data)
{
	//
	for(uint8_t i = 0; i < 8; i++)
	{
		if((data&0x80) == 0)	gpio_output(GPIOB,PORTB,Slave_MISO, PIN_RESET);		//
		else					gpio_output(GPIOB,PORTB,Slave_MISO, PIN_SET);		//
		data = data << 1;
	}
}

// SPI Slave reveice
uint8_t SPI_Slave_Reveice()
{
	uint8_t data;
	for(uint8_t i = 0; i < 8; i++)
	{
		if(gpio_input(GPIOB,PORTB,Slave_SCK) == BIT_SET)
		{
			data = data << 1;
			data = data | gpio_input(GPIOB,PORTB,Slave_MOSI);	
		}
	}
	return data;
}

/* Main Program */
/*-----------------------------------------------------------------------------------*/
int main()
{
	SysClock_configure();
	SPI_Master_Init();
	SPI_Slave_Init();
	while(1)
	{
		gpio_output(GPIOA,PORTA,Master_SS,PIN_RESET);									// Reset Pin SS to start transmit data			
//		SPI_Master_Transmit(master_transmit_data);
//		slave_receive_data = SPI_Slave_Reveice();		
		slave_receive_data = SPI_TransmitReceive_Byte(master_transmit_data);
		gpio_output(GPIOA,PORTA,Master_SS,PIN_SET);										// Set Pin SS to end transmit data	
		delay_systick_ms(1000);			
		master_transmit_data += 2;	
	}
}







