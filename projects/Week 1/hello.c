#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get input from user
    string name = get_string("What's your name? ");
    //Print hello with user's name
    printf("hello, %s\n", name);
}