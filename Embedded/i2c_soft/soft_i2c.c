#include "stm32f4xx.h"
#include "stm32f407xx.h"
#include "gpio.h"
#include "soft_i2c.h"
#include "systick.h"

#define SDA_PIN		7
#define SCL_PIN		6

#define SDA_INPUT	gpio_config(GPIOB,PORTB,SDA_PIN, PIN_INPUT)		// SDA is input pin
#define SDA_OUTPUT	gpio_config(GPIOB,PORTB,SDA_PIN, PIN_OUTPUT)	// SDA is output pin

#define SDA_Check	gpio_input(GPIOB,PORTB,SDA_PIN)					// Check status PIN SDA

#define SDA_HIGH	gpio_output(GPIOB,PORTB,SDA_PIN,PIN_SET)		// Set SDA = 1
#define SDA_LOW		gpio_output(GPIOB,PORTB,SDA_PIN,PIN_RESET)		// Reset SDA
#define SCL_HIGH	gpio_output(GPIOB,PORTB,SCL_PIN,PIN_SET)		// Ser SCL = 1
#define SCL_LOW		gpio_output(GPIOB,PORTB,SCL_PIN,PIN_RESET)		// Reset SCL

/*	I2C Init	*/
void I2C_Init(void)
{
	SDA_OUTPUT;											// Config PIN B7 ~ SDA
	gpio_config(GPIOB,PORTB,SCL_PIN, PIN_OUTPUT);		// Config PIN B6 ~ SCL
}

/*	I2C Start	*/
void I2C_Start(void)
{
	// SDA = 1, SCL = 1
	SDA_HIGH;
	SCL_HIGH;
	delay_systick_us(5);
	// SDA = 0, SCL = 1
	SDA_LOW;
	SCL_HIGH;
	delay_systick_us(5);
	// SDA = 0, SCL = 0
	SDA_LOW;
	SCL_LOW;		
}

/*	I2C Stop	*/
void I2C_Stop(void)
{
	// SDA = 0, SCL = 0
	SDA_LOW;
	SCL_LOW;
	delay_systick_us(5);
	// SDA = 0, SCL = 1
	SDA_LOW;
	SCL_HIGH;
	delay_systick_us(5);
	// SDA = 1, SCL = 1
	SDA_HIGH;
	SCL_HIGH;		
}

/*	ACK bit I2C	*/
void I2C_Ack(void)
{
	// SCL = 0, SDA = 0
	SCL_LOW;
	SDA_LOW;
	delay_systick_us(2);	
	// SCL = 1, SDA = 0
	SCL_HIGH;
	SDA_LOW;
	delay_systick_us(2);
	// SCL = 0, SDA = 0
	SCL_LOW;
	SDA_LOW;	
}

void I2C_NAck(void)
{
	// SCL = 0, SDA = 1
	SCL_LOW;
	SDA_HIGH;
	delay_systick_us(2);	
	// SCL = 1, SDA = 1jj
	SCL_HIGH;
	SDA_HIGH;
	delay_systick_us(2);
	// SCL = 0, SDA = 1
	SCL_LOW;
	SDA_HIGH;		
}

/*	I2C Send Byte	*/
void I2C_Send_Byte(uint8_t M_data)
{
	// config SDA is output
	SDA_OUTPUT;	
	// SCL = 0, waiting next data
	SCL_LOW;
	/*	Send 1 byte data	*/
	for(uint8_t i = 0; i < 8; i++)
	{
		// Send each bit of data
		if((M_data&0x80) == 0)	SDA_LOW;
		else					SDA_HIGH;
		// shift bit to the left to continue transmit next bit			
		M_data = M_data << 1;			
		delay_systick_us(2);
		// Emit high level of a pulse clock to transmit data
		SCL_HIGH;	
		delay_systick_us(2);
		// Set SCL = 0 to waiting next bit 
		SCL_LOW;	
	}
	/*	Check bit ACK/NACK after complete 1 byte	*/ 
	// SDA,SCL = 1 to 
	SDA_HIGH;
	SCL_HIGH;
	delay_systick_us(5);
	while(SDA_Check == PIN_SET);
	SCL_LOW;
	delay_systick_us(5);
}

/*	I2C Receive byte	*/
uint8_t I2C_Receive_Byte()
{
	// Config SDA is input
	SDA_INPUT;
	// 
	uint8_t data;
	// Get data
	for(uint8_t i = 0; i < 8; i++)
	{
		// Set SCL = 0 to can change data of SDA
		SCL_LOW;
		delay_systick_us(2);
		// Set SCL = 1 to stable value of SDA
		SCL_HIGH;
		// shift bit to the left to continue transmit next bit
		data = data << 1;
		// Read value PIN SDA to save data
		if(SDA_Check == PIN_SET)	data |= 0x01;
		else 						data &= ~0x01;
		delay_systick_us(2);
	}
	return data;
}



