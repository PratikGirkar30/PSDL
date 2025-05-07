#include <pic18f4550.h>

void main(void)
{
    unsigned char data[5] = {5, 15, 25, 35, 45};
    unsigned char i;

    TRISD = 0x00; // Set PORTD as output (to simulate external memory)
    PORTD = 0x00; // Clear PORTD

    for (i = 0; i < 5; i++)
    {
        PORTD = data[i]; // Transfer internal data to "external memory"
        __delay_ms(500); // Delay to simulate write time or view LED change
    }

    while (1)
        ; // End of program
}
