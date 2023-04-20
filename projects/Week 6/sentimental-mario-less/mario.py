# TODO
height = 0
while True:
    try:
        height = int(input("Height: "))
        if (height >= 1 and height <= 8):
            break
    except:
        print("", end="")
s = 1
for i in range(height):
    # Printing speces
    for s in range(height - i - 1):
        print(" ", end="")
    # Printing hashes
    for j in range(i + 1):
        print("#", end="")
    print()