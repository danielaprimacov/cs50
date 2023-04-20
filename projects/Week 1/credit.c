#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

long long get_card(void);
void validate_card(long long card);
void algorithm_Luhn(long long length, long long array_card[]);

long long number;

int main(void)
{
    // Get user input
    number = get_card();
    // Validate the number of the card
    validate_card(number);
}

long long get_card(void)
{
    // prompting for card number
    do
    {
        number = get_long_long("Number: ");
        return number;
    }
    while (number <= 0);
}

void validate_card(long long card)
{
    // Calculating the length of the number of the card
    long long length = 0;
    if (card != 0)
    {
        length = floor((log(llabs(card)) / log(10))) + 1;
    }
    // convert long long integer in array and reverse it
    long long array_card[length]; // array that contains the digits of the card
    for (int i = (length - 1); i >= 0; i--)
    {
        array_card[i] = card % 10;
        card = floor(card / 10);
    }
    // Luhn's algorithm
    algorithm_Luhn(length, array_card);
}

void algorithm_Luhn(long long length, long long array_card[])
{
    // multiply every other digits of the card with 2 and store in other array
    long long multiplyArray[length];
    for (int i = (length - 2), j = 0; i >= 0; i -= 2, j++)
    {
        multiplyArray[j] = array_card[i] * 2;
    }
    // add the digits into array
    int sum_multiply = 0;
    for (int i = 0; i <= ((length - 2) / 2); i++)
    {
        if (multiplyArray[i] > 9)
        {
            sum_multiply = sum_multiply + ((floor(multiplyArray[i] / 10)) + (multiplyArray[i] % 10));
        }
        else
        {
            sum_multiply = sum_multiply + multiplyArray[i];
        }
    }
    // add the remaining digits into array
    int sum_nomultiply = 0;
    for (int i = length - 1; i >= 0; i -= 2)
    {
        int nomultiplyArray = array_card[i];
        sum_nomultiply = sum_nomultiply + nomultiplyArray;
    }
    // add nomultiply and multiply and check if the last digit is zero
    if ((sum_multiply + sum_nomultiply) % 10 == 0) // is valid
    {
        // check for type
        if (array_card[0] == 3 && (array_card[1] == 4 || array_card[1] == 7))
        {
            printf("AMEX\n");
        }
        else if (array_card[0] == 4 && (length == 13 || length == 16))
        {
            printf("VISA\n");
        }
        else if (array_card[0] == 5 && (array_card[1] == 1 || array_card[1] == 2))
        {
            printf("MASTERCARD\n");
        }
        else if (array_card[0] == 5 && (array_card[1] == 3 || array_card[1] == 4 || array_card[1] == 5))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    //check card number length if it is valid
    else if (length != 13 && length != 15 && length != 16)
    {
        printf("INVALID\n");
    }
    else
    {
        printf("INVALID\n");
    }
}



