#include "led.h"

// Variabler för att lagra LED-status
LedState_Type led1_state;
LedState_Type led2_state;
LedState_Type led3_state;

// Skapa en LED med rött ljus och sätt den till ON
Led led1(RED,ON);

int main(void){ // Huvudfunktion för att konstruera och hantera LED-lamporna
  USART2_Init();

  // Skapa en LED med blått ljus och sätt den till ON
  Led led2(BLUE,ON);

  // Skapa en pekare till en LED med gult ljus och sätt den till ON
  Led *led3 = new Led(YELLOW,ON);

  // Hämta och lagra LED1:s status
  led1_state = led1.getState();

  // Ändra LED1:s status till OFF
  led1.setState(OFF);

  // Ta bort LED3
  delete led3;

  // Evig loop som inte gör något
  while(1){}
}
