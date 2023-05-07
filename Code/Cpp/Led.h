#ifndef LED_H //Header guard som förhindrar dubbelinkludering
#define LED_H //Definierar LED_H om det inte är definierat tidigare

#include <stdint.h> //Inkludera standard integer-huvudfilen
#include "UART.h" //Inkludera UART-huvudfilen
#include "stm32f4xx.h" //Inkludera enhetshuvudfilen för specifika enheter

//Definera vilken GPIO som skall vara ansvarig för LED-funktionen
#define LED_PORT GPIOB

//Definerar klocksignalen för porten
#define LED_PORT_CLOCK (1U<<1)

//Definera de olika pinsen för de olika LED-färgerna
#define LED_RED_PIN (1U<<14)
#define LED_GREEN_PIN (1U<<12)
#define LED_BLUE_PIN (1U<<15)
#define LED_YELLOW_PIN (1U<<13)

//Definera mode bits för varje LED-färg
#define LED_RED_MODE_BIT (1U<<28)
#define LED_GREEN_MODE_BIT (1U<<24)
#define LED_YELLOW_MODE_BIT (1U<<26)
#define LED_BLUE_MODE_BIT (1U<<30)

//Definerar de olika LED-färgerna som finns
typedef enum {
  RED = 0,
  GREEN,
  YELLOW,
  BLUE
} LedColor_Type; //LedColor_Type används för att definiera färgen på LED-lampan

//Definerar ju / numrerar de olika lägena som LED kan befinna sig i
typedef enum {
  OFF = 0,
  ON = 1
} LedState_Type; //LedState_Type används för att definiera statusen på LED-lampan

// Definerar de attribut som LED består utav
class Led {
  private:
    LedColor_Type color; //Attributet color som bestämmer LED-lampans färg
    LedState_Type state; //Attributet state som bestämmer LED-lampans status

  public:
    Led(LedColor_Type _color, LedState_Type _state); //Konstruktorn för LED som tar två parametrar
    void setState(LedState_Type _state); //En funktion som sätter LED-lampans status
    LedState_Type getState() const; //En funktion som hämtar LED-lampans status
};

#endif //Avslutar headerfilen 
