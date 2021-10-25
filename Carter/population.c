#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int startingSize;
    do
    {
        startingSize = get_int("Starting Population: ");

    }
    while (startingSize < 9);


    int endingSize;
    do
    {
    endingSize = get_int("Number of years: ");

    }
    while (startingSize < endingSize);


    int years = 0;
    int totalPop = startingSize;

    if(years < endingSize)
    {
        totalPop += (totalPop / 3) - (totalPop / 4);
        years++;
    }
    else
    {
        totalPop = startingSize;
        printf("ending size: %i\n", totalPop);
    }

    printf("ending size: %i\n", totalPop);

}
