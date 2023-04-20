// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool check_low = false;
    bool check_up = false;
    bool check_num = false;
    bool check_sym = false;
    bool check = false;
    int length = strlen(password);
    for (int i = 0; i < length; i++)
    {
        if (islower(password[i])) // check if it's lowercase letter
        {
            check_low = true;
        }
        if (isupper(password[i])) // check if it's uppercase letter
        {
            check_up = true;
        }
        if (isdigit(password[i])) // check if it's number
        {
            check_num = true;
        }
        if (ispunct(password[i])) // check if it's symbol
        {
            check_sym = true;
        }
        // check if all requirements are true
        if (check_low == true && check_up == true && check_num == true && check_sym == true)
        {
            check = true;
        }
        else
        {
            check = false;
        }
    }
    return check;
}
