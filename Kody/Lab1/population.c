#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int startingSize;
    do
    {
        startingSize = get_int("Starting Size: ");
        
    }
    while (startingSize < 9);

    // TODO: Prompt for end size
    int endingSize;
    do
    {
        endingSize = get_int("Ending Size: ");
        
    }
    while (endingSize < startingSize);


    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    int totalPop = startingSize;
    while ( totalPop < endingSize)
    {
        //calculate total pop
        totalPop += (totalPop / 3) - (totalPop / 4);
        years++;
        
    }
    

    // TODO: Print number of years
    printf("Years: %i\n", years);
}