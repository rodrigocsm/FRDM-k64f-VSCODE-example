#include <stdint.h>
#include "buttons.h"
#include "gpio_hal.h"

uint32_t buttons_counter[NUM_OF_BUTTONS];
BUTTON_STATE buttons_states[NUM_OF_BUTTONS];
uint32_t buttons_read[NUM_OF_BUTTONS];
uint32_t hold_counter[NUM_OF_BUTTONS];

void buttons_init(void)
{
    int i;
    pin_init();
    for (i = 0; i < NUM_OF_BUTTONS; i++)
    {
        buttons_counter[i] = 0;
        buttons_read[i] = 1;
        buttons_states[i] = RELEASED;
        hold_counter[i] = 0;
    }
}

void buttons_process(void)
{
    int i = 0;
    PIN pin = PIN_SW2;
    uint32_t read = 0;
    for (i = 0; i < NUM_OF_BUTTONS; i++)
    {
        switch (i)
        {
        case SW2:            
            pin = PIN_SW2;
            break;
        case SW3:            
            pin = PIN_SW3;
            break;
        default:
            return;
        }
        read = pin_read(pin);
        switch (buttons_states[i])
        {  
        case RELEASED:
            if (!read)
                buttons_states[i] = PRESSING;
            break;
        case PRESSING:
            if (!read && !buttons_read[i])
                buttons_counter[i]++;
            else
            {
                buttons_counter[i] = 0;
                buttons_states[i] = RELEASED;
            }
            if (buttons_counter[i] > BUTTONS_DEBOUNCE_COUNTER)
            {
                buttons_counter[i] = 0;
                buttons_states[i] = PRESSED;
            }
            break;
        case PRESSED:
            if (!read && !buttons_read[i])
                hold_counter[i]++;
            else
            {
                hold_counter[i] = 0;
                buttons_states[i] = RELEASING;
            }
            if (hold_counter[i] > BUTTONS_HOLD_COUNTER)
            {
                hold_counter[i] = 0;
                buttons_states[i] = HOLD;
            }
            break;
        case HOLD:        
            if (read)
                buttons_states[i] = RELEASING;
            break;        
        case RELEASING:
            if (read && buttons_read[i])
            {
                buttons_counter[i]++;
            }
            else
            {
                buttons_counter[i] = 0;
                buttons_states[i] = PRESSING;
            }
            if (buttons_counter[i] > BUTTONS_DEBOUNCE_COUNTER)
            {
                buttons_counter[i] = 0;
                buttons_states[i] = RELEASED;
            }
            break;

        default:
            break;
        }
        buttons_read[i] = read;
    }
}

BUTTON_STATE buttons_get(BUTTON button)
{
    if (button >= NUM_OF_BUTTONS)
        return IDLE;
    return buttons_states[button];
}