#include <pic18f4550.h>

// Configuration bits (these are usually required for proper operation)
// #pragma config settings here if you're compiling with MPLAB or XC8

void main(void)
{
    unsigned char choice, num1, num2, result;

    TRISC = 0xFF; // Set PORTC as input (for choice via switches/buttons)
    TRISD = 0x00; // Set PORTD as output (to show result on LEDs)
    PORTD = 0x00; // Clear PORTD initially

    while (1)
    {
        choice = PORTC & 0x03; // Read lower 2 bits of PORTC as choice (00, 01, 10)

        if (choice == 1)
        { // Multiply
            num1 = 5;
            num2 = 6;
            result = num1 * num2;
            PORTD = result; // Output result to PORTD
        }
        else if (choice == 2)
        { // Divide
            num1 = 20;
            num2 = 4;
            if (num2 != 0)
            {
                result = num1 / num2;
                PORTD = result; // Output result to PORTD
            }
            else
            {
                PORTD = 0xFF; // Show error (e.g. 0xFF) if divide by zero
            }
        }
        else
        {
            PORTD = 0x00; // Default: clear output if choice is 0 or other
        }
    }
}
