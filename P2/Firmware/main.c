/****************************************************
 * Nombre: 											*
 * Hora clase:								        *
 * Día: 											*
 * N° de lista:										*
 * N° de Equipo: 									*
 * Dispositivo: Atmega328P							*
 * Rev: 2.0                                         *
 * Propósito de la actividad:                       *
 * Crear el efecto del auto fantástico				*
 *													*
 *			                      Fecha: 05/06/2022 *
 ***************************************************/

/*******************Bibliotecas****************************/
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

/*****************Macros y constantes**********************/
// Tiempo de delay
#define TIME 100
// Definir LEDS
#define LEDSB	PORTB
#define LEDSC	PORTC
#define LEDSD	PORTD
#define HIGH	0xFF
#define LOW		0x00

/*******************Variables globales*********************/
#define NUMLEDS 15
#define LEDsForEachPort NUMLEDS / 3

/***********************Funciones**************************/
// Declaración de funciones
void init_ports(void);
void efecto_auto_fantastico(void);

/*******************Programa principal*********************/
int main(void)
{
	init_ports();
	
    while (1) 
    {
		efecto_auto_fantastico();
    }
}

/*******************Definición de funciones******************/

//init_ports  : Inicializa los puertos de salida
void init_ports(void)
{	

	// Salidas
	DDRB |=  HIGH; // Declarar salidas
	DDRC |=  HIGH; // Declarar salidas
	DDRD |=  HIGH; // Declarar salidas

	
}
//efecto_auto_fantastico : Muestra la secuencia del auto fantástico a una velocidad de 0.1s
void efecto_auto_fantastico(void)
{
	// IDA PUERTO D Y B		
	for (int PORT = 0; PORT < 2; PORT++)
	{
		for (int PIN = 0; PIN < LEDsForEachPort; PIN++)
		{
			if (PORT == 0) LEDSD = (1 << PIN);
				else if (PORT == 1) LEDSB = (1 << PIN);
			
			_delay_ms(TIME);
			
			if (PIN == LEDsForEachPort - 1)
			{
				if (PORT == 0) LEDSD = LOW;
					else if (PORT == 1) LEDSB = LOW;	
			}
		}
	}	
	
	// TOPE CON EL PUERTO C		
	for (uint8_t PIN = 0; PIN < LEDsForEachPort; PIN++)
	{
		LEDSC = (1 << PIN);
		_delay_ms(TIME);
	}
	
	
	// VUELTA PUERTO C Y B
	for (int PORT = 0; PORT < 2; PORT++)
	{
		for (int PIN = LEDsForEachPort; PIN > -1; PIN--)
		{
			if (PORT == 0) LEDSC = (1 << PIN);
				else if (PORT == 1) LEDSB = (1 << PIN);
				
			_delay_ms(TIME);
				
			if (PIN == 0)
			{
				if (PORT == 0) LEDSC = LOW;
					else if (PORT == 1) LEDSB = LOW;
			}
		}
	}
	
	// TOPE CON EL PUERTO D
	for (int i = LEDsForEachPort; i > 0; i--)
	{
		LEDSD = (1<<i);
		_delay_ms(TIME);
		if (i == 1)
		{
			LEDSD = LOW;
		}
	}
}

// By: EVRV 