import sys, random, pyfiglet

figlet = pyfiglet.Figlet()

# Check for valid usage
if len(sys.argv) == 1:
    isRandomFont = True
elif len(sys.argv) == 3 and (sys.argv[1] == "-f" or sys.argv[1] == "--font"):
    isRandomFond = False
else:
    sys.exit(1)

# Get the list of the avaible fonts
figlet.getFonts()

# Get user input
text = input("Input:")

if isRandomFond == False:
    try:
        figlet.setFont(font = sys.argv[2])
        print("Output: ")
        print(figlet.renderText(text))
    except:
        print("Invalid usage")
        sys.exit(1)
else:
    font = random.choice(figlet.getFonts())
    print("Output: ")
    print(figlet.renderText(text))