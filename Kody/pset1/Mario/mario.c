#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    int pHeight;
    do
    {
        pHeight = get_int("Starting Size: ");
        
    }
    while (pHeight < 0 || pHeight > 9);
    
    
    for(int i = 1; i <= pHeight; i++){
        string output = "";
        for(int j = pHeight - i ; j > 0; j--){
            printf(" ");
        }
        for(int k = 0; k < i; k++){
            printf("#");
        }
        printf("  ");
        for(int l = 0; l < i; l++){
            printf("#");
        }
        printf("\n");
    }
}