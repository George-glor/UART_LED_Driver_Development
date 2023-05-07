#ifndef __UART_H
// Headerfil som inkluderar de nödvändiga biblioteken och funktionerna för att använda UART på en STM32F4-mikrocontroller

#ifndef __UART_H //Inkluderar Standard Peripheral Library som tillhandahåller funktioner för att arbeta med STM32F4-hårdvaran
#define __UART_H //Inkluderar standard I/O-biblioteket för C

#include "stm32f4xx.h" //Hämtar källkoden och hänvisningar för arbete på STM-Hårdvara
#include <stdio.h> //Inkluderar standard I/O för C

void USART2_Init(void); // KFunktionsdeklaration för att initiera UART-protokollet
void test_setup(void); //Funktionsdeklaration för att sätta upp testmiljön för UART
#endif //Avslutar headerfilen och undviker dubbla inkluderingar av filen.
