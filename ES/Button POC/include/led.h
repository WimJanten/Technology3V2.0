#ifndef LED_H
#define LED_H

#include <stm32f303xe.h>

class led
{
private:
    GPIO_TypeDef *port;
    uint16_t pin;
public:
    led(GPIO_TypeDef *port, uint16_t pin);
    void on();
    void off();
    void toggle();
};

#endif /* LED_H */
