#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar k");
        return 1;
    }
    int l = atoi(argv[1]);
    if (l > 26)
    {
        do
        {
            l = l - 26;
        }
        while (l > 26);
    }
    string plainText = get_string("Enter the plain Text:");
    printf("ciphertext:");
    for (int i = 0 ; i < strlen(plainText) ; i++)
    {
        if(isalpha(plainText[i]))
        {
            if ((int) plainText[i] + l > 122 || ((int) plainText[i] + l > 90 && (int) plainText[i] + l < 97))
            {
                printf("%c",(int) plainText[i] + l - 26);
            }
            else
            {
                printf("%c", (int) plainText[i] + l);
            }
        }
        else
        {
            printf("%c", plainText[i]);
        }
    }
    printf("\n");

}