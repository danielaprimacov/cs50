#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt_message(string text, string key);
void array_values(char c, string key);

int main(int argc, string argv[])
{
    // Check if user input 1 argument
    if (argc != 2)
    {
        printf("Usage: ./subtitution key\n");
        return 1;
    }
    else
    {
        // Check key if it is a 26 character string
        if (strlen(argv[1]) == 26)
        {
            // Check if key is alphabetic character
            for (int i = 0; i < strlen(argv[1]); i++)
            {
                if (isalpha(argv[1][i]) == 0)
                {
                    printf("Key must be a bunch of characters!\n");
                    return 1;
                }
                for (int j = i + 1; j < strlen(argv[1]); j++)
                {
                    // Check if characters are the same or not
                    if (toupper(argv[1][j]) == toupper(argv[1][i]))
                    {
                        printf("Key must contain norepeated characters!\n");
                        return 1;
                    }
                }
            }
        }
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }
    string key = argv[1];
    // Get from user plaintext
    string text = get_string("plaintext: ");
    printf("ciphertext: ");
    // Printing encrypted message
    encrypt_message(text, key);
}

void encrypt_message(string text, string key)
{
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        if (isalpha(text[i])) // is in alphabet
        {
            char c = text[i];
            if (islower(text[i]))
            {
                array_values(tolower(c), key); // printing character in lowercase
            }
            else
            {
                array_values(toupper(c), key); // printing charcater in uppercase
            }
        }
        else
        {
            // printing other characters (non-alphabetic)
            printf("%c", text[i]);
        }
    }
    printf("\n");
}

void array_values(char c, string key)
{
    string alphabet_array = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // passing every element of the array
    for (int i = 0; i < strlen(alphabet_array); i++)
    {
        if (islower(c)) // character is lowercase
        {
            if (c == tolower(alphabet_array[i]))
            {
                printf("%c", tolower(key[i]));
            }
        }
        else
        {
            // character is uppercase
            if (c == toupper(alphabet_array[i]))
            {
                printf("%c", toupper(key[i]));
            }
        }
    }
}