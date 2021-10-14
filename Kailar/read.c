#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    //Prompts for user input
    string text = get_string("Text: ");
    
    //Integer List
    int i = 0, letters = 0, words = 1, sent = 0;

    //Counts words, letters, and sentences of the user input
    while (text[i] != '\0')
    {
        if (text[i] == ' ')
        {
            words++;
        }
        else if (isalpha(text[i]))
        {
           int letter = toupper(text[i]);
           letters++;
        }
        else if (text[i] == '?' || text[i] == '!' || text[i] == '.')
        {
           sent++;
        }
        i++;
    }
    
    //Index formula
    float L = (float)letters * 100 / words;
    float S = (float)sent * 100 / words;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    //Prints out final output depending on Index Formula
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 1 && index <= 16)
    {
        printf("Grade Level: %f\n", round(index));
    }
    else
    {
        printf("Above Grade 16\n");
    }
    
}