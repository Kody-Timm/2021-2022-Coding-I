#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int startingSize;
    do
    {
        startingSize = get_int("What is the starting size? ");
    }
    while (startingSize < 9);
    
    // TODO: Prompt for end size
    int endingSize;
    do
    {
        endingSize = get_int("What is the ending size? ");
    }
    while (endingSize < startingSize);
    
    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    int totalPop = startingSize;
    do
    {
        totalPop += (totalPop / 3) - (totalPop / 4);
        years++;
    }
    while (totalPop < endingSize );
    
    // TODO: Print number of years
    printf("Years: %i\n", years);
}