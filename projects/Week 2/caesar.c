#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void algorithm_Caesar(string text, string key);

int main(int argc, string argv[])
{
    // check if user input is 1 argument and it's a number
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Define the key
    string k = argv[1];
    // check that input is a digit
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    // get plaintext from user
    string text = get_string("plaintext: ");
    printf("ciphertext: ");
    algorithm_Caesar(text, k);
}

void algorithm_Caesar(string text, string key)
{
    int length = strlen(text);
    //conver key to integer
    int k = atoi(key);
    // iterate through every character and obtain ciphertext
    for (int i = 0; i < length; i++)
    {
        if (isupper(text[i]))
        {
            printf("%c", (((text[i] - 65) + k) % 26) + 65);
        }
        else if (islower(text[i]))
        {
            printf("%c", (((text[i] - 97) + k) % 26) + 97);
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}