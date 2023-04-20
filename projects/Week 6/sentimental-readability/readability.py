# TODO


# Algorithm Coleman-Liau
def check_grade(string_check):
    # Count letter, words and sentences of the string
    letters = count_letters(string_check)
    words = count_words(string_check)
    sentences = count_sentences(string_check)
    avg_letter = letters / words * 100
    avg_sent = sentences / words * 100
    # Calculate the grade
    grade = round(0.0588 * avg_letter - 0.296 * avg_sent - 15.8)
    if grade < 1:
        print("Before Grade 1")
    elif grade >= 16:
        print("Grade 16+")
    else:
        print("Grade: ", grade)


# Count letters
def count_letters(text):
    count = 0
    for i in range(len(text)):
        if text[i].isalpha():
            count += 1
    return count


# Count words
def count_words(text):
    count = 0
    for i in range(len(text)):
        if text[i].isspace():
            count += 1
    return count + 1


# Count sentences
def count_sentences(text):
    count = 0
    for i in range(len(text)):
        if text[i] == '.' or text[i] == '!' or text[i] == '?':
            count += 1
    return count


# Get user input
text = input("Text: ")
check_grade(text)
