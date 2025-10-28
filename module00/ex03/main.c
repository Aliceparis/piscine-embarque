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

    bool led_state = false;
    bool botton_state = true;

    while (1)
    {
        bool pressed = (PIND & BOUTTON);
        if (!pressed && botton_state)
        {
            _delay_ms(50);
            led_state = !led_state;
            if (led_state)
                PORTB |= LED;
            else
                PORTB &= ~LED;
           
        }
        botton_state = pressed;
         
    }
    return 0;
}