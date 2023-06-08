// part 1 todo

// Update candidates names and totals given a new vote(s)
bool vote(string name)
{
    // iterate through the candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // check for name match in string using strcmp helper fn
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++; // add +1 to counter if a name matches
            return true; // and return true bc it’s a bool fn
        }
    }
    return false; // else return false to stop
}

----------------------------------------------------------------------------------------------------------------------

// part 2 todo

// Print the winner (or winners) of the election
void print_winner(void)
{
    // set a basis starting with 0
    int vote_total = 0;

    // iterate over list of candidates and check the vote totals
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > vote_total)
        {
            vote_total = candidates[i].votes; // set total to candidate votes
        }
    }

    // iterate over list of candidates total votes and print winner(s)
    for (int i = 0; i < candidate_count; i++)
    {
        //check each candidates vote totals
        if (candidates[i].votes == vote_total)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}

----------------------------------------------------------------------------------------------------------------------

// correct

#include <cs50.h>
#include <stdio.h>
#include <string.h>

// MAX is a constant = to 9
#define MAX 9

// this is here bc C isn't an object oriented language
typedef struct // creating a new datatype titled "candidate"
{
    string name;
    int votes;
}
candidate; // has 2 variables a string titled "name" and an int titled "votes"


// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes aka declarations
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[]) // main uses CLA's
{
    // Check for invalid CLA usage
    if (argc < 2) // needs at least 2 words entered or REPL this
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1; // - 1 bc ./plurality starts things

    if (candidate_count > MAX) // if more than 9 CLA's after ./plurality REPL
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    for (int i = 0; i < candidate_count; i++) // loop the CLA info
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: "); // then prompt # of voters

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: "); // prompt for votes

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}



// Update candidates names and totals given a new vote(s)
bool vote(string name)
{
    // iterate through the candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // check for name match in string using strcmp helper fn
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++; // add +1 to counter if a name matches
            return true; // and return true bc it’s a bool fn
        }
    }
    return false; // else return false to stop
}


// Print the winner (or winners) of the election
void print_winner(void)
{
    // set a basis starting with 0
    int vote_total = 0;

    // iterate over list of candidates and check the vote totals
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > vote_total)
        {
            vote_total = candidates[i].votes; // set total to candidate votes
        }
    }

    // iterate over list of candidates total votes and print winner(s)
    for (int i = 0; i < candidate_count; i++)
    {
        //check each candidates vote totals
        if (candidates[i].votes == vote_total)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}
