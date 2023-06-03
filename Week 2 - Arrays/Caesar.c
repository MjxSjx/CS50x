// Pset 2 

// Caesar 

// Part 1 Counting Command-Line Arguments: if the user provides no CLAs, or two+, the fn prints "Usage: ./caesar key\n"
// and then returns 1.If the user provides exactly one CLA, the program should print nothing and simply return 0

#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[]) // compute CLAs
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    return 0;
}

----------------------------------------------------------------------------------------------------------------------

// Part 2 Checking the Key: making sure non digits are rejected

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[]) // compute CLAs
{
    if (argc != 2) // if the CLA counter doesn't equal exactly 2 
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    for (int i = 0, n = strlen(argv[1]); i < n; i++) // iterate the 2nd CLA string
    { //// if the 2nd string isn't a exclusively a digit, stop the program aka return 1
    if (!isdigit(argv[1][i])) // run each index of the 2nd string and see if its a number
        {
        printf("Usage: ./caesar key\n");
        return 1;
        }
    }
}

----------------------------------------------------------------------------------------------------------------------

// Part 3 Putting it all together

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[]) // compute CLAs
{
    if (argc != 2) // if the CLA counter doesn't equal exactly 2 
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    for (int i = 0, n = strlen(argv[1]); i < n; i++) // iterate the 2nd CLA string
    { //// if the 2nd string isn't a exclusively a digit, stop the program aka return 1
    if (!isdigit(argv[1][i])) // run each index of the 2nd string and see if its a number
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]); // label int fn atoi string to int

    string plaintext = get_string("plaintext:  "); // prompt user string data
    printf("ciphertext: "); // print result next line

    for (int j = 0, m = strlen(plaintext); j < m; j++) // iterate user string input
    {
        if (islower(plaintext[j])) // if lower fn to user data indexed
        {
            printf("%c", (((plaintext[j] - 'a') + key) % 26) + 'a');
        }
        else if (isupper(plaintext[j])) // else if upper fn to user data indexed
        {
            printf("%c", (((plaintext[j] - 'A') + key) % 26) + 'A');
        }
        else // else just print each element 
        {
            printf("%c", plaintext[j]);
        }
    }
    printf("\n"); // print new line once everything runs
    return 0; // not needed but solidifying everything works properly 
}

----------------------------------------------------------------------------------------------------------------------

----------------------------------------------------------------------------------------------------------------------

----------------------------------------------------------------------------------------------------------------------

----------------------------------------------------------------------------------------------------------------------

----------------------------------------------------------------------------------------------------------------------

----------------------------------------------------------------------------------------------------------------------

----------------------------------------------------------------------------------------------------------------------

----------------------------------------------------------------------------------------------------------------------

----------------------------------------------------------------------------------------------------------------------

----------------------------------------------------------------------------------------------------------------------

----------------------------------------------------------------------------------------------------------------------