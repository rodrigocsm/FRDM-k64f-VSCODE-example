#include <stdint.h>
#include "board.h"
#include "pin_mux.h"
#include "peripherals.h"

#include "leds.h"
#include "buttons.h"

uint32_t global = 0;
int main(void)
{
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();
    BOARD_InitBootPeripherals();
    leds_init();
    buttons_init();
    uint32_t local = 0;

    for (;;)
    {
        global++;
        local += global;
        buttons_process();
        if (buttons_get(SW2) == RELEASED && buttons_get(SW3) == RELEASED)
            leds_set(RED);
        else if (buttons_get(SW2) == PRESSED && buttons_get(SW3) == RELEASED)
            leds_set(GREEN);
        else if (buttons_get(SW3) == PRESSED && buttons_get(SW2) == RELEASED)
            leds_set(BLUE);
        else if (buttons_get(SW2) == HOLD && buttons_get(SW3) == RELEASED)
            leds_set(YELLOW);
        else if (buttons_get(SW3) == HOLD && buttons_get(SW2) == RELEASED)
            leds_set(PINK);
        else if (buttons_get(SW2) == PRESSED && buttons_get(SW3) == PRESSED)
            leds_set(CYAN);
        else if (buttons_get(SW2) == HOLD && buttons_get(SW3) == HOLD)
            leds_set(WHITE);
    }
}