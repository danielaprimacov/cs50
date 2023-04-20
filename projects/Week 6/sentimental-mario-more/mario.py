# TODO
height = 0
# do while loop
while height > 8 or height < 1:
    try:
        height = int(input("Height: "))
    except ValueError:
        print("Input is a string")
        height = int(input("Height: "))
for i in range(1, height + 1):
    for j in range(1, height + 1):
        # Printing hashes
        if j > (height - i):
            print("#", end="")
        else:
            # Printing spaces
            print(" ", end="")
        # Printing middle space and hashes
        if j == height:
            print(" ", "#" * i, end="")
    print()
