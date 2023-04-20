# TODO
import re
cash = 0
characters = re.compile('[@_!#$%^&*()<>?/\|}{~:]')


# Defining a function to calculate quarters, dimes, nickels and pennies
def calculate_coins(cash):
    cents = round(cash * 100)
    # Initialize the variable to count coins
    count = 0
    # Calculate quarters
    quarters = int(cents / 25)
    # Calculate dime
    dime = int((cents % 25) / 10)
    # Calculate nickels
    nickels = int(((cents % 25) % 10) / 5)
    # Calculate pennies
    pennies = int(((cents % 25) % 10) % 5)
    count += quarters + dime + nickels + pennies
    print(count)


# Get user cash
while cash >= 0:
    try:
        cash = float(input("Change owed: "))
        if cash > 0:
            calculate_coins(cash)
            break
        else:
            print("Input is a negative number")
            cash = float(input("Change owed: "))
            calculate_coins(cash)
            break
    except ValueError:
        try:
            # Check if input contains any characters
            cash_string = str(cash)
            if (characters.search(cash_string) != None):
                print("Input contains special characters")
                cash = float(input("Change owed: "))
        except ValueError:
            print("Input is not a float number!")
            cash = float(input("Change owed: "))

