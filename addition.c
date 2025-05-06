#include <stdio.h>
#include <PIC18F4550.h>
void main()
{
    int a = 8;
    int b = 2;
    int c = a + b;
    TRISA = 0;
    PORTA = c;
}
