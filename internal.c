#include <pic18f4550.h>

void main(void)
{
    unsigned char source[5] = {10, 20, 30, 40, 50};
    unsigned char destination[5];
    unsigned char i;

    for (i = 0; i < 5; i++)
    {
        destination[i] = source[i]; // Internal to internal memory transfer
    }

    while (1)
        ; // End of program
}