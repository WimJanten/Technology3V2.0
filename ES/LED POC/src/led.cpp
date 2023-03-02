#include "led.h"

led::led(GPIO_TypeDef *port, uint16_t pin) 
: port(port), pin(pin)
{
    port->MODER = (port->MODER & ~(0b11 << (pin * 2))) | (0b01 << (pin * 2));
    port->OTYPER = (port->OTYPER & ~(0b1 << pin)) | (0b0 << pin);
}

void led::on()
{
    port->ODR |= (0b1 << pin);
}

void led::off()
{
    port->ODR &= ~(0b1 << pin);
}

void led::toggle()
{
    port->ODR ^= (0b1 << pin);
}