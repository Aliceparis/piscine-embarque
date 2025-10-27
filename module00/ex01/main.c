#include <avr/io.h>

/*
Pour chaque port, on retrouve 3 registres : DDR, PORT et PIN :
- DDR permet de définir la direction (INPUT ou OUTPUT)
- PORT permet de définir l'état de sortie (HIGH ou LOW)
- PIN permet de réccupérer l'état d'entrée (HIGH ou LOW).
*/

int main()
{
    DDRB |= (1 << PB0);
    PORTB |= (1 << PB0);
}

/*
led allume 采用推电流（current sourcing）方式，micro controleur 给他提供电流，然后通过led以后经过电阻R1 然后引流回地面；
所以led 的direction设置是output，然后采用高电流，往低电流方向；

方法二：
采用灌电流方式（current sinking），电源提供电流，通过电阻R1以及led，然后micro controleur设置为低电流然后引会地面
所以他的设置DDR 也是output，然后采用的port是低电流；

*/