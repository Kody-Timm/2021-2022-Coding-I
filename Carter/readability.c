#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main(void)
{

    string text = get_string("Text: ");

    int i = 0;
    int letters = 0;
    int words = 1;
    int sen = 0;

// preprocces for formula

    //space for words
    while(text[i] != '\0')
    {
        if(text[i] == ' ')
        {
            words++;
        }
        else if(isalpha(text[i]) != 0)
        {
            letters++;

        }
        else if(text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sen++;
        }
        i++;
    }

    float l = letters*100 / words;
    float s = sen*100 / words;
    float index = 0.0588 * l - 0.296 * s - 15.8;

    printf("Level: %f\n", index);

    if(index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if ( index < 16)
    {
        printf("Grade %i\n", (int)index);
    }
    else
    {
        printf("Grade 16+\n");
    }
}