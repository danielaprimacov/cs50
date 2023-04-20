#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int algorithm_Coleman_Liau(string text);
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Get user input - string
    string text = get_string("Text: ");
    int grade = algorithm_Coleman_Liau(text);
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int algorithm_Coleman_Liau(string text)
{
    int grade = 0;
    // determine the number of letter
    int c_letters = count_letters(text);
    // determine the numner of words
    int c_words = count_words(text);
    // determine the number of sentences
    int c_sentences = count_sentences(text);
    // calculating the average number of letters per 100 words in the text
    float avg_letters = ((float)c_letters / c_words) * 100;
    // calculating the average number of sentences per 100 words in the text
    float avg_sentences = ((float)c_sentences / c_words) * 100;
    // calculating the grade of the text
    grade = round(0.0588 * avg_letters - 0.296 * avg_sentences - 15.8);
    return grade;
}

int count_letters(string text)
{
    int count_letters = 0;
    // calculating the length of the text
    int length = strlen(text);
    // determine the number of letters
    for (int i = 0; i < length; i++)
    {
        if (isalpha(text[i]) != 0)
        {
            count_letters++;
        }
    }
    return count_letters;
}

int count_words(string text)
{
    int count_words = 0;
    // determine the number of words
    for (int i = 0; text[i] != '\0'; i++)
    {
        if ((text[i] == ' ' || text[i] == ',') && text[i + 1] != ' ')
        {
            count_words++;
        }
    }
    return count_words + 1;
}

int count_sentences(string text)
{
    int count_sentences = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count_sentences++;
        }
    }
    return count_sentences;
}