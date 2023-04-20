#include <cs50.h>
#include <stdio.h>

int get_size(void);
void print_grid(int height);

int main(void)
{
    int height;
    // Get user input
    height = get_size();
    // Printing piramids
    print_grid(height);
}

int get_size(void)
{
    int height;
    // waiting for user prompt between 1 and 8
    do
    {
        height = get_int("Height: "); // get user input
    }
    while (height < 1 || height > 8);
    return height;
}

void print_grid(int h)
{
    for (int i = 0; i < h; i++)
    {
        for (int j = h - i - 2; j >= 0; j--)
        {
            printf(" "); // spaces are printed
        }
        for (int k = 0; k <= i; k++)
        {
            printf("#"); // hashes for bricks
        }
        printf("  "); // space between piramids
        for (int l = 0; l <= i; l++)
        {
            printf("#"); // regulat piramid
        }
        printf("\n"); //new line
    }
}