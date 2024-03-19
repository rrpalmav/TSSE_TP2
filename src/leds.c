#include "leds.h"

#define BIT_HIGH 1
#define LED_OFFSET 1
#define ALL_LED_OFF 0x00
#define ALL_LED_ON 0xFF

static uint16_t led_to_mask(int led){
    return (BIT_HIGH << led - LED_OFFSET  );
}

static uint16_t *puntero;

void leds_init(uint16_t *puerto){
    puntero = puerto;
    *puntero = ALL_LED_OFF;
}


void leds_turn_on(int led){
    *puntero |=  led_to_mask(led);
}

void leds_turn_off(int led){
    *puntero &= ~led_to_mask(led);
}

void leds_turn_on_all(uint16_t *puerto){
    *puntero = ALL_LED_ON;
}

void leds_turn_off_all(uint16_t *puerto){
    *puntero |= ALL_LED_OFF;
}