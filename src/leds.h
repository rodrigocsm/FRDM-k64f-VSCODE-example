#ifndef LEDS_H
#define LEDS_H

typedef enum COLORS
{
    OFF,
    RED,
    BLUE,
    GREEN,
    PINK,
    YELLOW,
    CYAN,
    WHITE,
} COLOR;

typedef enum LED_STATES
{
    LED_ON=0,
    LED_OFF=1,
}LED_STATE;

void leds_init(void);
void leds_set(COLOR color);
COLOR leds_get(void);
void leds_clear(void);

#endif // LEDS_H
