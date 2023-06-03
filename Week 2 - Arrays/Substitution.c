// Pset 2 

// Substitution

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[]) // compute CLAs
{
    if (argc != 2) // if the CLA counter doesn't equal exactly 2
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    int argv_length = strlen(argv[1]); // grabbing argv as an int
    if (argv_length != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++) // iterate the 2nd CLA string
    {
        if (!isalpha(argv[1][i])) // run each index of the 2nd string and see if its a a-z
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        for (int j = i + 1; j < argv_length; j++) // iterate over CLA and check for repeats
        {
            if (argv[1][i] == argv[1][j])
            {
                printf("Key must not contain repeated alphabetic chars\n");
                return 1;
            }
        }
    }

    string plaintext = get_string("plaintext:  "); // prompt user string data
    printf("ciphertext: "); // print result next line

    for (int k = 0, m = strlen(plaintext); k < m; k++) // iterate user string input
    {
        if (islower(plaintext[k])) // if lower fn to user data indexed
        {
            printf("%c", tolower(argv[1][plaintext[k] - 97]));
        }
        else if (isupper(plaintext[k])) // else if upper fn to user data indexed
        {
            printf("%c", toupper(argv[1][plaintext[k] - 65]));;
        }
        else // else just print each element
        {
            printf("%c", plaintext[k]);
        }
    }
    printf("\n"); // print new line once everything runs
    return 0; // not needed but solidifying everything works properly
}

----------------------------------------------------------------------------------------------------------------------
