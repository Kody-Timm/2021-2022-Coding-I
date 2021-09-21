#include <cs50.h>
#include <stdio.h>


int main(void)
{
    //Prompt user for height between 1-8
    int pyramidHeight;
    do
    {
        pyramidHeight = get_int("Pyramid height: ");
    }
    while (pyramidHeight < 1 || pyramidHeight > 8);

    //This loop prints each line
    for (int i = 0; i < pyramidHeight; i++)
    {
        //This loop prints spaces
        for (int j = pyramidHeight - i; j > 0; j--)
        {
            printf(" ");
        }
            //This loop prints one half-pyramid
            for (int k = -1; k < i; k++)
            {
                printf("#");
            }
            printf("  ");
                //This loop prints the other half-pyramid
                for (int m = -1; m < i; m++)
                {
                    printf("#");
                }
        printf("\n");
    }
}