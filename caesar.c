#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return (1);
    }
    int str_len = strlen(argv[1]);

    for (int i = 0; i < str_len; i++)
    {
        if (isdigit(argv[1][i]) == false)
        {
            printf("Usage: ./caesar key\n");
            return (1);
        }
    }

    int atoi(const char argv[]);
    int n = atoi(argv[1]);

    // printf("Input is %i\n", atoi(argv[1]));

    string plaintext = get_string("Plaintext:  ");
    int length = strlen(plaintext);
    string ciphertext = plaintext;

    for (int i = 0; i <= length; i++)
    {
        if islower (plaintext[i])
        {
            ciphertext[i] = ((plaintext[i] - 97) + atoi(argv[1])) % 26 + 97;
        }
        if isupper (plaintext[i])
        {
            ciphertext[i] = ((plaintext[i] - 65) + atoi(argv[1])) % 26 + 65;
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }

    printf("Ciphertext: %s\n", ciphertext);

    return (0);
}
