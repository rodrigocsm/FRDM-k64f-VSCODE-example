#ifdef TEST

#include "unity.h"

#include "leds.h"
#include "mock_gpio_hal.h"

void setUp(void)
{
}

void tearDown(void)
{
}
void test_led_init_should_call_pin_init(void)
{
    pin_init_Expect();
    pin_write_Ignore();
    leds_init();
}
void test_led_init_should_clear_leds(void)
{
    pin_init_Ignore();
    pin_write_Expect(PIN_LED_RED, LED_OFF);
    pin_write_Expect(PIN_LED_BLUE, LED_OFF);
    pin_write_Expect(PIN_LED_GREEN, LED_OFF);
    leds_init();
}

void test_led_set_should_clear_leds_before_setting(void)
{    
    pin_write_Expect(PIN_LED_RED, LED_OFF);
    pin_write_Expect(PIN_LED_BLUE, LED_OFF);
    pin_write_Expect(PIN_LED_GREEN, LED_OFF);
    pin_write_Ignore();
    leds_set(RED);
}

void test_led_set_should_set_pin_red_if_set_red(void)
{    
    pin_write_Expect(PIN_LED_RED, LED_OFF);
    pin_write_Expect(PIN_LED_BLUE, LED_OFF);
    pin_write_Expect(PIN_LED_GREEN, LED_OFF);
    pin_write_Expect(PIN_LED_RED, LED_ON);
    leds_set(RED);
}

void test_led_set_should_set_pin_blue_if_set_blue(void)
{    
    pin_write_Expect(PIN_LED_RED, LED_OFF);
    pin_write_Expect(PIN_LED_BLUE, LED_OFF);
    pin_write_Expect(PIN_LED_GREEN, LED_OFF);
    pin_write_Expect(PIN_LED_BLUE, LED_ON);
    leds_set(BLUE);
}

void test_led_set_should_set_pin_green_if_set_green(void)
{    
    pin_write_Expect(PIN_LED_RED, LED_OFF);
    pin_write_Expect(PIN_LED_BLUE, LED_OFF);
    pin_write_Expect(PIN_LED_GREEN, LED_OFF);
    pin_write_Expect(PIN_LED_GREEN, LED_ON);
    leds_set(GREEN);
}

void test_led_set_should_set_pin_red_and_blue_if_set_pink(void)
{    
    pin_write_Expect(PIN_LED_RED, LED_OFF);
    pin_write_Expect(PIN_LED_BLUE, LED_OFF);
    pin_write_Expect(PIN_LED_GREEN, LED_OFF);
    pin_write_Expect(PIN_LED_RED, LED_ON);
    pin_write_Expect(PIN_LED_BLUE, LED_ON);
    leds_set(PINK);
}
void test_led_set_should_set_pin_red_and_green_if_set_yellow(void)
{    
    pin_write_Expect(PIN_LED_RED, LED_OFF);
    pin_write_Expect(PIN_LED_BLUE, LED_OFF);
    pin_write_Expect(PIN_LED_GREEN, LED_OFF);
    pin_write_Expect(PIN_LED_RED, LED_ON);
    pin_write_Expect(PIN_LED_GREEN, LED_ON);
    leds_set(YELLOW);
}
void test_led_set_should_set_pin_blue_and_green_if_set_cyan(void)
{    
    pin_write_Expect(PIN_LED_RED, LED_OFF);
    pin_write_Expect(PIN_LED_BLUE, LED_OFF);
    pin_write_Expect(PIN_LED_GREEN, LED_OFF);
    pin_write_Expect(PIN_LED_BLUE, LED_ON);
    pin_write_Expect(PIN_LED_GREEN, LED_ON);
    leds_set(CYAN);
}

void test_led_set_should_set_all_led_pins_if_set_white(void)
{    
    pin_write_Expect(PIN_LED_RED, LED_OFF);
    pin_write_Expect(PIN_LED_BLUE, LED_OFF);
    pin_write_Expect(PIN_LED_GREEN, LED_OFF);
    pin_write_Expect(PIN_LED_RED, LED_ON);
    pin_write_Expect(PIN_LED_BLUE, LED_ON);
    pin_write_Expect(PIN_LED_GREEN, LED_ON);
    leds_set(WHITE);
}


#endif // TEST
