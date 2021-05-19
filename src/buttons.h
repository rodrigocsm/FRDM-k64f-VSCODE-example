#ifndef BUTTONS_H
#define BUTTONS_H

#define BUTTONS_DEBOUNCE_COUNTER 5000UL
#define BUTTONS_HOLD_COUNTER 100000UL

typedef enum BUTTONS
{
    SW2,
    SW3,
    NUM_OF_BUTTONS
} BUTTON;

typedef enum BUTTON_STATES
{
    IDLE,
    RELEASED,
    PRESSING,
    PRESSED,
    HOLD,
    RELEASING,
}BUTTON_STATE;

void buttons_init(void);
void buttons_process(void);
BUTTON_STATE buttons_get(BUTTON button);

#endif // BUTTONS_H
