#include <stdint.h>

void leds_init(uint16_t *puerto);

void leds_turn_on(int led);

void leds_turn_off(int led);

void leds_turn_on_all(uint16_t *puerto);

void leds_turn_off_all(uint16_t *puerto);