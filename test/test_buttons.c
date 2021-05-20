#ifdef TEST

#include "unity.h"

#include "buttons.h"
#include "mock_gpio_hal.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_buttons_init_should_call_pin_init(void)
{
    pin_init_Expect();
    buttons_init();
}

void test_buttons_process_should_call_pin_read(void)
{
    pin_read_ExpectAndReturn(PIN_SW2,0);
    pin_read_ExpectAndReturn(PIN_SW3,0);
    buttons_process();
}

#endif // TEST