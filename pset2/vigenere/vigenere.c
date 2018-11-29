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
    string s = argv[1];
    for(int i = 0 ; i < strlen(s) ; i++)
    {
        if(!isalpha(s[i]))
        {
            printf("Usage: ./caesar k");
            return 1;
        }
    }

    int j=0;
    string plainText = get_string("plaintext:");
    printf("ciphertext:");
    int sub=0;
    int cipher = 0;
    for (int i = 0 ; i < strlen(plainText) ; i++)
    {   if (j>=strlen(s))
        {
            j=0;
        }
        if(isalpha(plainText[i]))
        {
            if (isupper(s[j]))
            {
                sub = s[j] - 65;
                cipher = (int) plainText[i] + (s[j] - 65);
                if (cipher > 90)
                {
                    cipher-=26;
                }
                printf("%c", cipher);
            }
            else
            {
                sub = s[j] - 97;
                cipher = (int) plainText[i] + (s[j] - 97);
                if (cipher > 122)
                {
                    cipher-=26;
                }
                printf("%c", cipher);
            }
            j++;
        }
        else
        {
            printf("%c", plainText[i]);
        }
    }
    printf("\n");
}