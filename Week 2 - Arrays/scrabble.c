#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet A = 0 - Z = 25
int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
//indexed value 0  1  2  3  4  5  6  7  8  9 10  11 12 13 14 15 16  17 18 19 20 21 22 23 24 25
int compute_score(string word); // fn declaration aka prototype

int main(void) // boilerplate
{
    string word1 = get_string("Player 1: "); // 1st prompt user 1 for a string
    string word2 = get_string("Player 2: "); // 1st prompt user 2 for a string

    int score1 = compute_score(word1); // 2nd & 4th fn call/execution 
    int score2 = compute_score(word2); // 2nd & 4th fn call/execution

    if (score1 > score2) // 5th Print the winner
    {
        printf("Player 1 wins!\n");
        return 0;
    }
    else if (score1 == score2) // scores strictly equal  
    {
        printf("Tie!\n");
        return 0;
    }
    printf("Player 2 wins!\n");
    return 0; // this line isn't needed
}


int compute_score(string word) // 3rd^2 fn definition
{
    int score = 0; // have to start at a basis
    // strlen - fn that sums the length of a string; ergo: apple = 5 
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (isupper(word[i])) // checks if current [i] letter is upper
        { 
            score = score + points[word[i] - 'A']; // uses ASCII - 65 to ID the char
        }
        else if (islower(word[i])) // checks if current [i] letter is lower
        {
            score += points[word[i] - 'a']; // uses ASCII - 97 to ID the char
        }
    }
    return score;
}

// Explaining score += points[word[i] - 'A' && 'a'];

// Example: Apple

// strlen sums the sting, Apple is 5 char;

// for (int i = 0, n = strlen(word); i < n; i++) 
// i = 0; n = strlen(word), means when i0 < n5 then add 1 to i aka cycle (loop) each letter in Apple

// this is where ASCII comes into play, each char has an ASCII value
// https://asciichart.com/ find the letter and its associated value

// also remember indexed arrays start at 0

// 1st letter is 65A: insert the char into if (isuuper(word[i])) conditional: run the statement 
// 0 = 0 + points[65A] - '65A', which equals points[0] and points[0] holds a value of 1. A = 1

// 2nd letter is p: insert the char into else if (islower(word[i])) conditional: run the statement
// 1 += points[112p] - '97a', which equals points[15] and points[15] holds a value of 3. p = 3

// 3rd letter is p: insert the char into else if (islower(word[i])) conditional: run the statement
// 4 += points[112p] - '97a', which equals points[15] and points[15] holds a value of 3. p = 3

// 4th letter is l: insert the char into else if (islower(word[i])) conditional: run the statement
// 7 += points[108l] - '97a', which equals points[11] and points[11] holds a value of 1. l = 1

// 5th letter is e: insert the char into else if (islower(word[i])) conditional: run the statement
// 8 += points[101e] - '97a', which equals points[4] and points[4] holds a value of 1. e = 1

//return score = 9

// remember points is listed at the top and since its an array its elements start at 0

----------------------------------------------------------------------------------------------------------------------

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int main(void)
{
    char c = get_char("Input: ");
    if (isupper(c))
    {
    printf("1. Your input is a uppercase letter.\n");

    }
    else
    {
    printf("2. Your input is a lowercase letter.\n");
    }
}

----------------------------------------------------------------------------------------------------------------------

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int main(void)
{
    char c = get_char("Input: ");
    if (islower(c))
    {
    printf("1. Your input is a lowercase letter.\n");
    }
    else
    {
    printf("2. Your input is a uppercase letter.\n");
    }
}

----------------------------------------------------------------------------------------------------------------------

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Input: ");

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c\n", s[i]);
    }
}

----------------------------------------------------------------------------------------------------------------------


----------------------------------------------------------------------------------------------------------------------

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet A = 0 - Z = 25
const POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word); // fn declaration

int main(void) // boilerplate
{
    // Get input words from both players
    string word1 = get_string("Player 1: "); // prompt user 1
    string word2 = get_string("Player 2: "); // prompt user 2

    // Score both words
    int score1 = compute_score(word1); // fn call
    int score2 = compute_score(word2); // fn call

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
        return 0;
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
        return 0;
    }
    printf("Tie!\n");
    return 0; // don't think this line is needed
}


int compute_score(string word) // fn definition
{
    int sum = 0; // have to start a basis somewhere aka initialize the variable 

    // TODO: Compute and return score for string
    for (int i = 0, n = strlen(word); i < n; i++) // fn statement
    {
        if (isupper(word[i]))
        {
            sum = sum + POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            sum += POINTS[word[i] - 'a'];
        }
    }
    return sum;
}
