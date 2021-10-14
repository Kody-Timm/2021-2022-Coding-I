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
    
    // Create spaces for first double pyrimid
    for(int i = 1; i <= pHeight; i++){
        for(int j = pHeight - i ; j > 0; j--){
            printf(".");
        }
        printf("\n");
    }
}