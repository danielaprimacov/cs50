# TODO
import sys
card = 0


# Defining a function to check the card
def check_card(card):
    # Check length if it valid
    if len(card) < 13 or len(card) > 16:
        print("INVALID")
        sys.exit(0)
    count1_sum, count2_sum = 0, 0
    # Calculate length of the card number
    length = len(card)

    # Digits of the card number
    def digits_of(n):
        return [int(d) for d in str(n)]
    digits = digits_of(card)
    # Odd digits and even digits
    count1 = digits[-1::-2]  # odd
    count2 = digits[-2::-2]  # even
    # Calculating the sum of the digits
    check_sum = 0
    check_sum += sum(count1)
    for i in count2:
        check_sum += sum(digits_of(i * 2))
    check_sum = check_sum % 10
    if check_sum == 0:
        check_1 = int(card[0])  # first digit of the card
        check_2 = int(card[1])  # second digit of the card
        if check_1 == 3 and check_2 == 4 or check_2 == 7:
            print("AMEX")
        elif check_1 == 5 and check_2 >= 1 and check_2 <= 5:
            print("MASTERCARD")
        elif check_1 == 4 and (len(card) == 13 or len(card) == 16):
            print("VISA")
        elif len(card) != 13 and len(card) != 15 and len(card) != 16:
            print("INVALID")
        else:
            print("INVALID")


# Get user input - credit card number
while True:
    card = input("Number: ")
    try:
        if len(card) > 0 and int(card):
            check_card(card)
            if check_card(card) == None:
                print("INVALID")
                break
    except ValueError:
        print("INVALID")