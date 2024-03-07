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
} candidate;

// Array of candidates
candidate candidates[MAX];
int size = sizeof(candidates) / sizeof(candidates[0]);

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
    // TODO
    for (int i = 0; i < size - 1; i++)
    {
        // printf("%i, %i, %s, %s\n", size, i, candidates[i].name, name);
        if (candidates[i].name == NULL)
        {
            return false;
        }
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            // printf("votes: %i\n", candidates[i].votes);
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    // sort the candidate votes lowest to highest using bubble sort
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (candidates[j].votes > candidates[j + 1].votes)
            {
                int swap = candidates[j].votes;
                string swap_string = candidates[j].name;

                candidates[j].votes = candidates[j + 1].votes;
                candidates[j].name = candidates[j + 1].name;

                candidates[j + 1].votes = swap;
                candidates[j + 1].name = swap_string;
            }
        }
    }

    // print the candidate with the maximum votes

    for (int i = 0; i < size; i++)
    {
        // printf("%i, %i\n", candidates[i].votes, candidates[size - 1].votes);
        if (candidates[i].votes == candidates[size - 1].votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }

    return;
}
