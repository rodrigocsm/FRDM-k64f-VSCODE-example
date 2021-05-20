typedef enum PINS
{
    PIN_SW2,
    PIN_SW3,
    PIN_LED_RED,
    PIN_LED_BLUE,
    PIN_LED_GREEN,
}PIN;

void pin_init(void);
void pin_write(PIN pin, uint8_t output);
uint32_t pin_read(PIN pin);