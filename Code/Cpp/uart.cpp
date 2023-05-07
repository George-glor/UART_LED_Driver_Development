#include "UART.h" // Inkluderar headerfilen för UART-funktionerna

void USART2_Init(void) { // Funktion för att initiera USART2-protokollet och dess komponenter

  // 1. Aktivera klocktillgång för UART2
  RCC->APB1ENR |= 0x20000; // Sätter bit 17 i RCC->APB1ENR till 1 för att aktivera UART2.

  // 2. Aktivera klocktillgång för Port A
  RCC->AHB1ENR |= 0x01; // Sätter bit 0 i RCC->AHB1ENR till 1 för att aktivera Port A.

  // 3. Konfigurera alternativ funktion för valda pinnar på Port A
  GPIOA->MODER &= ~0x00F0; // Rensar bitarna 4-7 för att förbereda pinnarna PA2 och PA3
  GPIOA->MODER |= 0x00A0; // Sätter bitarna 5 och 7 till 1 för att aktivera alternativ funktion på pins PA2 och PA3

  // 4. Välj typ av alternativ funktion för de valda pinnarna
  GPIOA->AFR[0] &= ~0xFF00; // Rensar bitarna 8-15 för att förbereda pinnarna PA2 och PA3
  GPIOA->AFR[0] |= 0x7700; // Sätter bitarna 8-11 samt 12-15 till formatet 0111 för att aktivera UART-funktionen

  /* Konstruktion av enhetens kommunikation avslutas */

  // Konfigurera UART
  USART2->BRR = 0x0683; // Sätter standard baud-rate till 9600 bps med hexadecimala värdet 0x0683.
  USART2->CR1 = 0x000C; // Sätter tx och rx till att arbeta med 8-bitars data (8 bitar data, 1 stoppbit, ingen paritet).
  USART2->CR2 = 0x000; // Nollställer kontrollregistret 2.
  USART2->CR3 = 0x000; // Nollställer kontrollregistret 3.
  USART2->CR1 |= 0x2000; // Sätter bit 13 (UART-aktiveringen) till 1 för att aktivera UART.

}

// Funktion för att skriva data till UART.
int USART2_write(int ch){

  while(!(USART2->SR & 0x0080)){} // Väntar på att överföringsbufferten ska bli tom och klar för nästa tecken (byte).
  USART2->DR = (ch & 0xFF); // Överför det aktuella tecknet (byte) till dataregistret för UART.

  return ch; // Returnerar det översända tecknet (byte).

}

// Funktion för att läsa data från UART.
int USART2_read(void){

  while(!(USART2->SR & 0x0020)){} // Väntar på att det finns mer data att läsa.
  return USART2->DR; // Returnerar data från
