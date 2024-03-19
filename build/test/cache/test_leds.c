#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"
#include "inc/leds.h"


static uint16_t leds_virtuales;



static const int LED_3 = 3;

static const int LED_5 = 5;

static const int LED_7 = 7;

static const int LED_9 = 9;



void setUp(void){

    leds_init(&leds_virtuales);

}









void test_todos_los_led_inician_apagados(void){

    leds_virtuales = 0xFF;

    leds_init(&leds_virtuales);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0X00)), (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(29), UNITY_DISPLAY_STYLE_UINT16);

}









void test_prender_un_led( void) {



    leds_turn_on(LED_3);



    UnityAssertBits((UNITY_INT)(((UNITY_UINT)1 << (LED_3 - 1))), (UNITY_INT)((UNITY_UINT)(-1)), (UNITY_INT)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(39));



    UnityAssertBits((UNITY_INT)((~(1 << (LED_3 - 1)))), (UNITY_INT)((UNITY_UINT)(0)), (UNITY_INT)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(41));



}







void test_apagar_un_led( void) {



    leds_turn_on(LED_3);

    leds_turn_off(LED_3);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x00)), (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(52), UNITY_DISPLAY_STYLE_UINT16);

}







void test_prender_y_apagar_varios_leds( void) {



    leds_turn_on(LED_5);

    leds_turn_on(LED_7);

    leds_turn_on(LED_5);

    leds_turn_off(LED_5);

    leds_turn_off(LED_9);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((1 << (7 - 1))), (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(65), UNITY_DISPLAY_STYLE_UINT16);

}





void test_prender_todos_los_leds( void) {



    leds_init(&leds_virtuales);

    leds_turn_on_all(&leds_virtuales);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0xFF)), (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(74), UNITY_DISPLAY_STYLE_UINT16);

}





void test_apagar_todos_los_led_prendidos( void ){

    leds_init(&leds_virtuales);

    leds_turn_off_all(&leds_virtuales);



}
