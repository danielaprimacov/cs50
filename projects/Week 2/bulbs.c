#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);
void stringToBinary(string s);

int main(void)
{
    // TODO
    // Get string from the user
    string message = get_string("Message: ");
    // converting into binary
    stringToBinary(message);
}

void stringToBinary(string s)
{
    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        int binary[] = {0, 0, 0, 0, 0, 0, 0, 0};
        // convert each char to ASCII value
        char c = s[i];
        //convert ASCII value to binary
        int j = 0;
        while (c > 0)
        {
            binary[j] = c % 2;
            c /= 2;
            j++;
        }
        for (int k = BITS_IN_BYTE - 1; k >= 0; k--)
        {
            print_bulb(binary[k]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
