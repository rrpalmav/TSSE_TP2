/**
3.  Apagar un led prendido y ver que efectivamente se apaga y que el resto no cambia.
4.  Con todos los leds apagados prender un led y verificar que al consultar el estado del mismo me informe que esta prendido.
7.  Prender leds que ya estan prendidos de antes.
8.  Apagar leds que ya esten apagados.
9.  Comprobar valores prohibidos.
10. Comprobar los valores de limite
*/
#include "leds.h"
#include "unity.h"

static uint16_t leds_virtuales;

static const int LED_3 = 3;
static const int LED_5 = 5;
static const int LED_7 = 7;
static const int LED_9 = 9;

void setUp(void){
    leds_init(&leds_virtuales);
}


// 1.  Al iniciar el controlador los leds deben quedar todos 
//     los bits en 0 sin importar el estado anterior.
void test_todos_los_led_inician_apagados(void){
    leds_virtuales = 0xFF;
    leds_init(&leds_virtuales);
    TEST_ASSERT_EQUAL_UINT16(0X00, leds_virtuales);
}


// 2.  Con todos los led apagados prender el led 3 y verificar que 
//     efectivamente el bit 2 se ponen en 1 y el resto de bits permanece en 0
void test_prender_un_led( void) {
    //uint16_t leds_virtuales = 0x0000;    
    leds_turn_on(LED_3);
    // El bit 2 esta en alto
    TEST_ASSERT_BIT_HIGH( LED_3 - 1,  leds_virtuales);
    // Todos los otros bits estan en bajo
    TEST_ASSERT_BITS_LOW( ~(1 << (LED_3 - 1)), leds_virtuales);
    //TEST_ASSERT_EQUAL_UINT16(1 << (LED - 1), leds_virtuales);
}

// 3.  Apagar un led prendido y ver que efectivamente 
//     se apaga y que el resto no cambia.
void test_apagar_un_led( void) {
    //ui nt16_t leds_virtuales = 0x0000;
    leds_turn_on(LED_3);
    leds_turn_off(LED_3);
    
    TEST_ASSERT_EQUAL_UINT16(0x00, leds_virtuales);
} 

// 3.  Apagar un led prendido y ver que efectivamente 
//     se apaga y que el resto no cambia.
void test_prender_y_apagar_varios_leds( void) {
    //uint16_t leds_virtuales = 0x0000;
    leds_turn_on(LED_5);
    leds_turn_on(LED_7);
    leds_turn_on(LED_5);
    leds_turn_off(LED_5);
    leds_turn_off(LED_9);

    TEST_ASSERT_EQUAL_UINT16( 1 << (7 - 1) , leds_virtuales);
} 

// 5.  Prender todos los leds que estan apagados antes de la operacion.
void test_prender_todos_los_leds( void) {
    //uint16_t leds_virtuales = 0x0000;
    leds_init(&leds_virtuales);
    leds_turn_on_all(&leds_virtuales);

    TEST_ASSERT_EQUAL_UINT16( 0xFF , leds_virtuales);
}

//6.  Apagar todos los leds que ya estan prendidos.
void test_apagar_todos_los_led_prendidos( void ){
    leds_init(&leds_virtuales);
    leds_turn_off_all(&leds_virtuales);

}