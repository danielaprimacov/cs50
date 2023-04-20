#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(char *input, int length);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input, strlen(input) - 1));
}

int convert(char *input, int length)
{
    // TODO
    // Recursive base case
    // Check if current character is non-numeric or is the end of the string reached
    if (length < 0 || (input[length] < '0' || input[length] > '9'))
    {
        return 0;
    }

    // convert remain digits of the string
    return (10 * convert(input, length - 1) + (input[length] - '0'));
}