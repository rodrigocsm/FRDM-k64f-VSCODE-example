#include <stdint.h>
#include "leds.h"
#include "gpio_hal.h"

COLOR led_state = OFF;

void leds_init(void)
{
    pin_init();
    leds_clear();
}
void leds_clear(void)
{
    pin_write(PIN_LED_RED, LED_OFF);
    pin_write(PIN_LED_BLUE, LED_OFF);
    pin_write(PIN_LED_GREEN, LED_OFF);
    led_state = OFF;
}
void leds_set(COLOR color)
{
    leds_clear();
    switch (color)
    {
    case RED:
        pin_write(PIN_LED_RED, LED_ON);
        led_state = color;
        break;
    case BLUE:
        pin_write(PIN_LED_BLUE, LED_ON);
        led_state = color;        
        break;
    case GREEN:
        pin_write(PIN_LED_GREEN, LED_ON);
        led_state = color;
        break;
    case PINK:
        pin_write(PIN_LED_RED, LED_ON);
        pin_write(PIN_LED_BLUE, LED_ON);
        led_state = color;
        break;
    case YELLOW:
        pin_write(PIN_LED_RED, LED_ON);
        pin_write(PIN_LED_GREEN, LED_ON);
        led_state = color;
        break;
    case CYAN:
        pin_write(PIN_LED_BLUE, LED_ON);
        pin_write(PIN_LED_GREEN, LED_ON);
        led_state = color;
        break;
    case WHITE:
        pin_write(PIN_LED_RED, LED_ON);
        pin_write(PIN_LED_BLUE, LED_ON);        
        pin_write(PIN_LED_GREEN, LED_ON);
        led_state = color;
        break;
    default:
        leds_clear();
    }    
}
COLOR leds_get(void)
{
    return led_state;
}