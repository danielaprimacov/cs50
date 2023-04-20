// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string text);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./no-vowels word\n");
        return 1;
    }
    else
    {
        string text = argv[1];
        string converted_text = replace(text);
        printf("%s\n", converted_text);
    }
}


string replace(string text)
{
    int length = strlen(text);
    for (int i = 0; i < length; i++) // iterating through every character of the string
    {
        if (text[i] == 'a') // check 'a' vowel
        {
            text[i] = '6'; // changing to 6
        }
        else if (text[i] == 'e') // check 'e' vowel
        {
            text[i] = '3'; // changing to 3
        }
        else if (text[i] == 'i') // check 'i' vowel
        {
            text[i] = '1'; // changing to 1
        }
        else if (text[i] == 'o') // check 'o' vowel
        {
            text[i] = '0'; //changing to 0
        }
        else if (text[i] == 'u') // check 'u' vowel
        {
            text[i] = 'u'; // dont change
        }
        else
        {
            text[i] = text[i]; // other characters remain the same
        }
    }
    return text;
}