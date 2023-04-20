#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    // TODO

    int count = 0;
    // Check if number is not prime
    for (int i = 2; i <= number / 2; i++)
    {
        // number modulo i
        if (number % i == 0)
        {
            count++;
            break;
        }
    }
    // If count = 0 number is prime
    // 1 is not prime
    if (count == 0 && number != 1)
    {
        return true;
    }
    return false;
}
