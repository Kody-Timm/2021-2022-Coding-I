#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    //Write code that gets words from players, capital letters do not matter
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    //Prints the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}


// TODO: Compute and return score for string, use ASCII values
//Find each individual characters ASCII distance from A by subtraction
//This will give you their location in the array
int compute_score(string word)
{
    int sumPoints = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        if (isalpha(word[i]))
        {
            int character = toupper(word[i]) - 'A';
            sumPoints += POINTS[character];
        }
    }
    return sumPoints;
}