#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 0;
    //Get Positive Height less than 23 from the user
    do
    {
        height = get_int("Enter a positive number less than 23: ");

    }
    while (height > 23 || height < 0);
    // Loop for the Rows to be printed, j will be number of whitespaces
    for (int i = 0, j = (height - 1); i < height; i++, j--)
    {
        // Loop for whitespaces
        for (int k = 0; k < j; k++)
        {
            printf(" ");
        }
        // Loop for Brics
        for (int k = 0; k < (height + 1) - j; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}