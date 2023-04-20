# Set up prices - create menu dictionary
prices = {
    "Baja Taco": 4.00,
    "Burrito": 7.50,
    "Bowl": 8.50,
    "Nachos": 11.00,
    "Quesadilla": 8.50,
    "Super Burrito": 8.50,
    "Super Quesadilla": 9.50,
    "Taco": 3.00,
    "Tortilla Salad": 8.00
}

# Set sum to 0
sum_amount = 0

# Looping through dictionary
while True:
    try:
        # Get user input
        item = input("Item: ").title()
        if item in prices:
            sum_amount += prices[item]
        # Print current sum amount
        print("Total: $", end="")
        print("{:.2f}".format(sum_amount))
    except EOFError:
        # Print a new line and stop loop
        print()
        break