#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//Custom function that checks if the key entered is an integer
bool check_valid_key(string s);

int main(int argc, string argv[])
{
    //Checks if command line input is valid, counts the number of arguments and runs the custom function on the second argument
    if (argc!= 2 || !check_valid_key(argv[1]))
    {
       printf("Usage: ./caesar key\n");
       return 1;
    }
    //Changes the integer inputted in the command line to a string
    int key = atoi(argv[1]);
   
   
    //Gets word from user
    string ptext = get_string("Plaintext: ");
     
     
    //Prints encrypted text
    printf("Ciphertext: ");
    

    //Runs the cipher
    for (int i = 0; i < strlen(ptext); i++)
    {
        char c= ptext[i];
        //Checks capitalization
        if (isalpha(c))
        {
            char m = 'A';
            if (islower(c))
            {
                m = 'a';
            }
            //Rotates characters while preserving capitalization
            printf("%c", (c - m + key) % 26 + m);
        }
        //Prints non-alphabetic characters normally
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");
}

//Custom function
bool check_valid_key(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}