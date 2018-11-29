#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    long credit_card = get_long_long("Enter valid Credit Card no: ");
    long number = credit_card;
    int digit = 0;
    int count = 0;
    int sumOdd = 0;
    int sumEven = 0;
    int checSum = 0;
    int product = 0;
    while (number != 0)
    {
        digit = number % 10;
        number = number / 10;
        if (count % 2 != 0)
        {
            product = digit * 2;
            if (product >= 10)
            {
                sumOdd += product % 10;
                sumOdd += product / 10;
            }
            else
            {
                sumOdd += product;
            }
        }
        else
        {
            sumEven += digit;
        }
        count++;
    }
    checSum = sumEven + sumOdd;
    int valid = 0;
    if (checSum % 10 == 0)
    {
        valid = 1;
    }
    else
    {
        valid = 0;
    }
    long div = 1;
    int trac = count;
    while(trac > 1)
    {
        div *= 10;
        trac--;
    }
    int digits = credit_card * 10 / div;

    if (valid)
    {
        if ((digits / 10 == 4) && (count == 13 || count == 16))
        {
            printf("VISA\n");
        }
        else if ((digits == 34 || digits == 37) && (count == 15))
        {
            printf("AMEX\n");
        }
        else if ((digits == 51 || digits == 52 || digits == 53 || digits == 54 || digits == 55) && (count == 16))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}