#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int size;
    do
    {
        size = get_int("Height: ");
    }
        while( size < 0 || size > 9);

    //something is wrong here
    for(int i = 1; i <= size; i++){
        string output = " ";
        for (int j = size - i; j >= 0; j-- ) {
            printf(" ");
        }
        for(int k = 0; k < i; k++){
            printf("#");
        }
        printf("  ");
        for (int l = 0; l < i; l++){
            printf("#");
        }
        printf("\n");

    }

}













