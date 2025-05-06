#include <p18f4550.h>
unsigned char count = 0;
bit TIMER, SPEED_UP;
void timer2Init(void)
{
    T2CON = 0b00000010; // Prescalar = 16; Timer2 OFF
    PR2 = 0x95;         /* Period Register*/
}
void delay(unsigned int time)
{
    unsigned int i, j;
    for (i = 0; i < time; i++)
        for (j = 0; j < 1000; j++)
            ;
}
void main(void)
{
    unsigned int i;
    TRISCbits.TRISC1 = 0; // RC1 pin as output
    TRISCbits.TRISC2 = 0; // CCP1 pin as output
    LATCbits.LATC1 = 0;
    CCP1CON = 0b00111100; // Select PWM mode; Duty cycle LSB CCP1CON<4:5> = <1:1>
    CCPR1L = 0x0F;        // Duty cycle 10%
    timer2Init();         // Initialise Timer2
    TMR2ON = 1;           // Timer2 ON
    while (1)             /*Loop forever*/
    {
        for (i = 15; i < 150; i++)
        {
            CCPR1L = i;
            delay(100);
        }
        for (i = 150; i > 15; i--)
        {
            CCPR1L = i;
            delay(100);
        }
    }
}