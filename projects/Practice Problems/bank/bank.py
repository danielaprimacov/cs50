# Get user input
text = input("Greeting: ")
if "hello" in text.lower():
    print("$0")
elif "hey" in text.lower():
    print("$100")
elif text[0].lower() == "h":
    print("$20")
else:
    print("$100")
