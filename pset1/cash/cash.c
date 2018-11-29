#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float cash=0.0;
    do
    {
        cash=get_float("Change owed: ");
    }
    while(cash<0);
    // Rounding of dollars to cents
    int change= cash*100+0.5;


    //initialise number of coins
    int NoOfCoin=0;
    //how many coins for quarters(25cents)
    NoOfCoin+=change/25;
    change=change%25;
    //how many coins for dime(10cents)
    NoOfCoin+=change/10;
    change=change%10;
    //how many coins for Nicles(5cents)
    NoOfCoin+=change/5;
    change=change%5;
    //how many coins for Pennies(1 cents)
    NoOfCoin+=change;
    printf("%d\n",NoOfCoin);
}

