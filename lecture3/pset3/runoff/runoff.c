#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

//     printf("preferences[0][0]: %i\n", preferences[0][0]);
//     printf("preferences[0][1]: %i\n", preferences[0][1]);
//     printf("preferences[0][2]: %i\n", preferences[0][2]);
// 
//     printf("preferences[1][0]: %i\n", preferences[1][0]);
//     printf("preferences[1][1]: %i\n", preferences[1][1]);
//     printf("preferences[1][2]: %i\n", preferences[1][2]);
// 
//     printf("preferences[2][0]: %i\n", preferences[2][0]);
//     printf("preferences[2][1]: %i\n", preferences[2][1]);
//     printf("preferences[2][2]: %i\n", preferences[2][2]);

    // Keep holding runoffs until winner exists
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
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    int counter = 0;
    for (int i = 0; i < voter_count; i++)
    {
        if (candidates[preferences[i][counter]].eliminated == false)
        {
            candidates[preferences[i][counter]].votes++;
//             printf("votes are updates[%i][%i]: %i", i, counter, candidates[preferences[i][counter]].votes);
        }
        else if (candidates[preferences[i][counter]].eliminated == true)
        {
            int j = 0;
            while (candidates[preferences[i][j]].eliminated == true)
            {
                j++;
            }
            candidates[preferences[i][j]].votes++;
//                 printf("votes are updates[%i][%i]: %i", i, j, candidates[preferences[i][j]].votes);

        }
    }

    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    int total_votes = voter_count;
    int higher_vote = 0;
    int winner;
    for (int i = 0; i < candidate_count; i++)
    {
        if (higher_vote < candidates[i].votes)
        {
            higher_vote = candidates[i].votes;
            winner = i;
        }
    }
    if (50 < (higher_vote * 100 / total_votes))
    {
        printf("%s\n", candidates[winner].name);
        return true;
    }
    else 
    {
        return false;
    }
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int min = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false)
        {
            if (min < candidates[i].votes)
            {
                min = candidates[i].votes;
            }
        }
    }
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    float sum = 0;
    float candidates_remaining = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false)
        {
            sum += candidates[i].votes;
            candidates_remaining++;
        }
    }
    if ((sum / candidates_remaining / (float) min) == 1.0)
    {
        return true;
    }
    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false) 
        {
            if (candidates[i].votes == min)
            {
                candidates[i].eliminated = true;
            }
        }
    }
    return;
}