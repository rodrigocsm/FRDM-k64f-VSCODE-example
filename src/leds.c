#include "leds.h"
#include "pin_mux.h"
#include "fsl_gpio.h"
#include "fsl_debug_console.h"

COLOR led_state = OFF;

void leds_init(void)
{
    BOARD_InitLEDsPins();
    leds_clear();
}
void leds_clear(void)
{
    GPIO_PinWrite(BOARD_LED_RED_GPIO, BOARD_LED_RED_PIN, LED_OFF);
    GPIO_PinWrite(BOARD_LED_BLUE_GPIO, BOARD_LED_BLUE_PIN, LED_OFF);
    GPIO_PinWrite(BOARD_LED_GREEN_GPIO, BOARD_LED_GREEN_PIN, LED_OFF);
    led_state = OFF;
}
void leds_set(COLOR color)
{
    leds_clear();
    switch (color)
    {
    case RED:
        GPIO_PinWrite(BOARD_LED_RED_GPIO, BOARD_LED_RED_PIN, LED_ON);
        led_state = color;
        break;
    case BLUE:
        GPIO_PinWrite(BOARD_LED_BLUE_GPIO, BOARD_LED_BLUE_PIN, LED_ON);
        led_state = color;        
        break;
    case GREEN:
        GPIO_PinWrite(BOARD_LED_GREEN_GPIO, BOARD_LED_GREEN_PIN, LED_ON);
        led_state = color;
        break;
    case PINK:
        GPIO_PinWrite(BOARD_LED_RED_GPIO, BOARD_LED_RED_PIN, LED_ON);
        GPIO_PinWrite(BOARD_LED_BLUE_GPIO, BOARD_LED_BLUE_PIN, LED_ON);
        led_state = color;
        break;
    case YELLOW:
        GPIO_PinWrite(BOARD_LED_RED_GPIO, BOARD_LED_RED_PIN, LED_ON);
        GPIO_PinWrite(BOARD_LED_GREEN_GPIO, BOARD_LED_GREEN_PIN, LED_ON);
        led_state = color;
        break;
    case CYAN:
        GPIO_PinWrite(BOARD_LED_BLUE_GPIO, BOARD_LED_BLUE_PIN, LED_ON);
        GPIO_PinWrite(BOARD_LED_GREEN_GPIO, BOARD_LED_GREEN_PIN, LED_ON);
        led_state = color;
        break;
    case WHITE:
        GPIO_PinWrite(BOARD_LED_RED_GPIO, BOARD_LED_RED_PIN, LED_ON);
        GPIO_PinWrite(BOARD_LED_BLUE_GPIO, BOARD_LED_BLUE_PIN, LED_ON);
        GPIO_PinWrite(BOARD_LED_GREEN_GPIO, BOARD_LED_GREEN_PIN, LED_ON);
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