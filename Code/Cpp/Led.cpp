#include "LED.h" //Inkluderar header filen för att även denna fil skall känna till de olika LED-beteckningarna och funktioner

//Konstruktorn för LED-lamporna
Led::Led(LedColor_Type _color, LedState_Type _state)
{

  this->color = _color; //Sätta färgen på LED-lampan med hjälp av parameter
  this->state = _state; //Sätta statusen på LED-lampan med hjälp av parameter

  //Enablea klockan för LED-porten (GPIOB)
  RCC->AHB1ENR |= LED_PORT_CLOCK;

  //Konfigurera LED-pinsen baserad på deras färg och status
  switch(_color){

    case RED: //Om LED-lampan är röd
      LED_PORT->MODER |= LED_RED_MODE_BIT; //Sätta portläget för LED-konfigurationen till output
      if(this->state == ON){ //Om LED-lampan skall vara på
        LED_PORT->ODR |= LED_RED_PIN; //Stänga på LED
      }
      else{ //Annars
        LED_PORT->ODR &= ~LED_RED_PIN; //Stänga av LED
      }
      break;

    case YELLOW: //Om LED-lampan är gul
      LED_PORT->MODER |= LED_YELLOW_MODE_BIT; //Sätta portläget för LED-konfigurationen till output
      if(this->state == ON){ //Om LED-lampan skall vara på
        LED_PORT->ODR |= LED_YELLOW_PIN; //Stänga på LED
      }
      else{ //Annars
        LED_PORT->ODR &= ~LED_YELLOW_PIN; //Stänga av LED
      }
      break;

    case BLUE: //Om LED-lampan är blå
      LED_PORT->MODER |= LED_BLUE_MODE_BIT; //Sätta portläget för LED-konfigurationen till output
      if(this->state == ON){ //Om LED-lampan skall vara på
        LED_PORT->ODR |= LED_BLUE_PIN; //Stänga på LED
      }
      else{ //Annars
        LED_PORT->ODR &= ~LED_BLUE_PIN; //Stänga av LED
      }
      break;

    case GREEN: //Om LED-lampan är grön
      LED_PORT->MODER |= LED_GREEN_MODE_BIT; //Sätta portläget för LED-konfigurationen till output
      if(this->state == ON){ //Om LED-lampan skall vara på
        LED_PORT->ODR |= LED_GREEN_PIN; //Stänga på LED
      }
      else{ //Annars
        LED_PORT->ODR &= ~LED_GREEN_PIN; //Stänga av LED
      }
      break;

  }

}

void Led::setState(LedState_Type _state){

  //Sätta statusen av LED:n
  this->state = _state; //Sätt LED-lampans status med hjälp av parameter

  //Kolla färgen på LED för att veta att korrekt LED manipuleras
  switch(this->color){

    //om LED Röd
    case RED:
      //sätta pin till outputläge
      LED_PORT->MODER |= LED_RED_MODE_BIT


  //Kontrollera färgen av den LED som efterfrågas, printa sedan statusen
  switch(this->color){

    case RED:
      break;

    case YELLOW:
      break;

    case BLUE:
      break;

    case GREEN:
      break;
  }
  
  // Returnerar LED-lampans status av vald färg
  return this->state;
}
