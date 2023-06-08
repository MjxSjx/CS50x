// Runoff

// part 1 todo

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // iterate through the candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // check for name match in string using strcmp helper fn
        if (strcmp(name, candidates[i].name) == 0)
        {
            preferences[voter][rank] = i; // record voter prefer & find match
            return true; // and return true bc it’s a bool fn
        }
    }
    return false; // else return false to stop
}

----------------------------------------------------------------------------------------------------------------------

// part 2 todo

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // counts the votes for each iteration of the election
    // candidates eliminated are skipped for next preference of that voter
    for (int j = 0; j < voter_count; j++)
    {
        for (int k = 0; k < candidate_count; k++)
        {
            int p = preferences[j][k];

            if (candidates[p].eliminated == false)
            {
                candidates[p].votes++;
                break;
            }
        }
    }
}

----------------------------------------------------------------------------------------------------------------------

// part 3 todo

// Print the winner of the election, if there is one
bool print_winner(void)
{
    int majority = round(voter_count / 2);

    // Check each candidate for 50%+ of votes
    for (int l = 0; l < candidate_count; l++)
    {
        if (candidates[l].votes > majority)
        {
            printf("%s\n", candidates[l].name);
            return true;
        }
    }
    return false;
}

----------------------------------------------------------------------------------------------------------------------

// part 4 todo

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    for (int m = 0; m < candidate_count; m++)
    {
        if (candidates[m].votes < voter_count && candidates[m].eliminated == false)
        {
            voter_count = candidates[m].votes;
        }
    }
    return voter_count;
}

----------------------------------------------------------------------------------------------------------------------

// part 5 todo

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // setting a basis to tally for ties
    int tie = 0;
    int tally = 0;

    for (int n = 0; n < candidate_count; n++)
    {
        // add to both counters when candids still around & candids have min per voter
        if (candidates[n].eliminated == false && candidates[n].votes == min)
        {
            tie++;
            tally++;
        }
        //  add only to tally
        else if (candidates[n].eliminated == false)
        {
            tally++;
        }
    }
    // Checks for tie
    if (tie == tally)
    {
        return true;
    }
    return false;
}

----------------------------------------------------------------------------------------------------------------------

// part 6 todo

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // eliminate all with min totals
    for (int o = 0; o < candidate_count; o++)
    {
        if (candidates[o].eliminated == false && candidates[o].votes == min)
        {
            candidates[o].eliminated = true;
        }
    }
}

----------------------------------------------------------------------------------------------------------------------

// correct

#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct // creating a new datatype titled "candidate"
{
    string name;
    int votes;
    bool eliminated;
}
candidate; // has 3 variables "name", "votes" and "eliminated"

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes aka declarations
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[]) // main uses CLA's
{
    // Check for invalid usage
    if (argc < 2) // needs at least 2 words entered or REPL this
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1; // - 1 bc ./plurality starts things

    if (candidate_count > MAX_CANDIDATES) // if more than 9 CLA's after ./plurality REPL
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++) // loop the CLA info
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: "); // then prompt # of voters
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {

        // Loop over all totals
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1); // prompt for votes

            // Check for invalid vote
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding aka loop runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // iterate through the candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // check for name match in string using strcmp helper fn
        if (strcmp(name, candidates[i].name) == 0)
        {
            preferences[voter][rank] = i; // record voter prefer & find match
            return true; // and return true bc it’s a bool fn
        }
    }
    return false; // else return false to stop
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // counts the votes for each iteration of the election
    // candidates eliminated are skipped for next preference of that voter
    for (int j = 0; j < voter_count; j++)
    {
        for (int k = 0; k < candidate_count; k++)
        {
            int p = preferences[j][k];

            if (candidates[p].eliminated == false)
            {
                candidates[p].votes++;
                break;
            }
        }
    }
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    int majority = round(voter_count / 2);

    // Check each candidate for 50%+ of votes
    for (int l = 0; l < candidate_count; l++)
    {
        if (candidates[l].votes > majority)
        {
            printf("%s\n", candidates[l].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    for (int m = 0; m < candidate_count; m++)
    {
        if (candidates[m].votes < voter_count && candidates[m].eliminated == false)
        {
            voter_count = candidates[m].votes;
        }
    }
    return voter_count;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // setting a basis to tally for ties
    int tie = 0;
    int tally = 0;

    for (int n = 0; n < candidate_count; n++)
    {
        // add to both counters when candids still around & candids have min per voter
        if (candidates[n].eliminated == false && candidates[n].votes == min)
        {
            tie++;
            tally++;
        }
        //  add only to tally
        else if (candidates[n].eliminated == false)
        {
            tally++;
        }
    }
    // Checks for tie
    if (tie == tally)
    {
        return true;
    }
    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // eliminate all with min totals
    for (int o = 0; o < candidate_count; o++)
    {
        if (candidates[o].eliminated == false && candidates[o].votes == min)
        {
            candidates[o].eliminated = true;
        }
    }
}

----------------------------------------------------------------------------------------------------------------------

----------------------------------------------------------------------------------------------------------------------

----------------------------------------------------------------------------------------------------------------------
