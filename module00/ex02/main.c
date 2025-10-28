#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

#define LED (1 << PB0)
#define BOUTTON (1 << PD2)

int main()
{
    /*setup for PB0*/
    DDRB |= LED;
    PORTB &= ~LED;

    /*setup pd2*/
    DDRD &= ~BOUTTON;
    PORTD |= BOUTTON;

    bool botton_state = false;

    while (1)
    {
        bool    pressed = PIND & BOUTTON;

        if (!pressed)
        {
            PORTB |= LED;
        }
        else
            PORTB &= ~LED;
    }
    return 0;
}