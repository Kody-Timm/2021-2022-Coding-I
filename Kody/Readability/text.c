#include<cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    // Get Text for indexing
    string text = get_string("text: ");

    // inialize count variables
    int i = 0;
    int letters = 0;
    int words = 1;
    int sent = 0;

    //Pre-Process
    while (text[i] != '\0'){
    
        if(text[i] == ' ')
        {
            words++;
        }
        else if(isalpha(text[i]) != 0)
        {
            letters++;
        }
        else if(text[i] == '.'|| text[i] == '!' || text[i] == '?')
        {
            sent++;
        }
        i++;
    }
    

    //TEST TIME

    // Coleman-Liau Calculation
    float l = (float)letters*100 / words;
    float s = (float)sent*100 / words;
    float index = 0.0588 * l - 0.296 * s - 15.8;
    index = round(index);
    
    //Output
    if(index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if(index < 16)
    {
        printf("Grade %i\n", (int)index);
    }
    else
    {
        printf("Grade 16+\n");
    }
}




