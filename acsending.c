#include <stdio.h>
#include <PIC18F4550.h>
void main()
{
    int nums[] = {10, 2, 5, 1, 6};
    for (int i = 0; i <= 4; i++)
    {
        for (int j = i + 1; j <= 4; j++)
        {
            if (nums[i] > nums[j])
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = t
            }
        }
    }
}