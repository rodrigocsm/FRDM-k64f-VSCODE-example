#include "pin_mux.h"
#include "fsl_gpio.h"
#include "gpio_hal.h"

void pin_init(void){
    BOARD_InitButtonsPins();
    BOARD_InitLEDsPins();
}

void pin_write(PIN pin, uint8_t output)
{
    switch (pin)
    {
    case PIN_LED_RED:
        GPIO_PinWrite(BOARD_LED_RED_GPIO, BOARD_LED_RED_PIN, output);
        break;
    case PIN_LED_BLUE:
        GPIO_PinWrite(BOARD_LED_BLUE_GPIO, BOARD_LED_BLUE_PIN, output);
        break;
    case PIN_LED_GREEN:
        GPIO_PinWrite(BOARD_LED_GREEN_GPIO, BOARD_LED_GREEN_PIN, output);
        break;
    }
}
uint32_t pin_read(PIN pin)
{
    switch (pin)
    {
    case PIN_SW2:
        return GPIO_PinRead(BOARD_SW2_GPIO, BOARD_SW2_PIN);
        break;
    case PIN_SW3:
        return GPIO_PinRead(BOARD_SW3_GPIO, BOARD_SW3_PIN);
        break;
    default:
        return 0;
    }
}