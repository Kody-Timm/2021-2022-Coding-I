#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for(int currCand = 0; currCand < candidate_count; currCand++)
    {
        if(strcmp(name, candidates[currCand].name) == 0)
        {
            candidates[currCand].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    //Top candidates number of votes
    int topVotes = 0;
    
    //Resets the currCand variable
    int currCand = 0;
    
    //Changes top candidate if the current candidate has more votes
    while(currCand < candidate_count)
    {
        if(topVotes < candidates[currCand].votes)
        {
            topVotes = candidates[currCand].votes;
        }
        currCand++;
    }
    
    for(currCand = 0; currCand < candidate_count; currCand++)
    {
        if(candidates[currCand].votes == topVotes)
        {
            printf("%s\n", candidates[currCand].name);
        }
    }
    return;
}

