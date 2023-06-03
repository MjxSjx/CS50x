// Pset 2 

// Readability

// part 1 Getting User Input: gather user input then print it back out

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = get_string("Text: "); // 1st prompt user for a string
    printf("%s\n", s); // print the user entered string
}

// part 2 Letters: print the total amount of letters used

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text); // fn declaration aka prototype

int main(void)
{
    string s = get_string("Text: "); // 1st prompt user for a string

    int letters = count_letters(s); // 2nd & 4th fn call/execution

    printf("%i letters\n", letters); // 5th print the # of letters
}

int count_letters(string text) // 3rd fn definition
{
    int counter = 0; // have to start at a basis
                                                
    for (int i = 0, n = strlen(text); i < n; i++) 
    {                        
        if(isalpha(text[i])) // isalpha - checks whether a character is alphabetical
        {                    // even though i'm using strlen i still have to index each char using [i] in isalpha()
        counter++;           // isalpha(text) = ERROR: "cast to smaller integer type 'int' from 'string'(aka 'char')" 
        }                    // the error = "I need the string indexed plz!" 
    }
    return counter; // the sum of counter "returns" to part 4 above
}

----------------------------------------------------------------------------------------------------------------------

// part 3 Words: print the total amount of letters & words used

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text); // fn declaration aka prototype
int count_words(string text);

int main(void)
{
    string s = get_string("Text: "); // 1st prompt user for a string

    int letters = count_letters(s); // 2nd & 4th fn call/execution
    int words = count_words(s);

    printf("%i letters\n", letters); // 5th print the # of letters
    printf("%i words\n", words); // 5th print the # of words
}

int count_letters(string text) // 3rd fn definition
{
    int counter = 0; // have to start at a basis
                                                
    for (int i = 0, n = strlen(text); i < n; i++) 
    {                        
        if(isalpha(text[i])) // isalpha - checks whether a character is alphabetical
        {                    // even though i'm using strlen i still have to index each char using [i] in isalpha()
        counter++;           // isalpha(text) = ERROR: "cast to smaller integer type 'int' from 'string'(aka 'char')" 
        }                    // the error = "I need the string indexed plz!" 
    }
    return counter; // the sum of counter "returns" to part 4 above
}

int count_words(string text) // 3rd fn definition
{
    int counter = 1; // this basis needs to start @1 bc the last word won't have a space

    for (int i = 0, n = strlen(text); i < n; i++)
    {                        
        if(isspace(text[i])) // isspace - checks whether a character is whitespace
        {                    // even though i'm using strlen i still have to index each char using [i] in isspace()
        counter++;            
        }         
    }
    return counter; // the sum of counter "returns" to part 4 above
}

----------------------------------------------------------------------------------------------------------------------

// Part 4 Sentences: print the total amount of letters, words, & sentences used

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text); // fn declaration aka prototype
int count_words(string text);
int count_sentences(string text);


int main(void)
{
    string s = get_string("Text: "); // 1st prompt user for a string

    int letters = count_letters(s); // 2nd & 4th fn call/execution
    int words = count_words(s);
    int sentences = count_sentences(s); 

    printf("%i letters\n", letters); // 5th print the # of letters
    printf("%i words\n", words); // 5th print the # of words
    printf("%i sentences\n", sentences); // 5th print the # of sentences
}

int count_letters(string text) // 3rd fn definition
{
    int counter = 0; // have to start at a basis
                                                
    for (int i = 0, n = strlen(text); i < n; i++) 
    {                        
        if(isalpha(text[i])) // isalpha - checks whether a character is alphabetical
        {                    // even though i'm using strlen i still have to index each char using [i] in isalpha()
        counter++;           // isalpha(text) = ERROR: "cast to smaller integer type 'int' from 'string'(aka 'char')" 
        }                    // the error = "I need the string indexed plz!" 
    }
    return counter; // the sum of counter "returns" to part 4 above
}

int count_words(string text) // 3rd fn definition
{
    int counter = 1; // this basis needs to start @1 bc the last word won't have a space

    for (int i = 0, n = strlen(text); i < n; i++)
    {                        
        if(isspace(text[i])) // isspace - checks whether a character is whitespace
        {                    // even though i'm using strlen i still have to index each char using [i] in isspace()
        counter++;            
        }         
    }
    return counter; // the sum of counter "returns" to part 4 above
}

int count_sentences(string text) // 3rd fn definition
{
    int counter = 0; // have to start at a basis

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
        counter++;
        }
    }
    return counter; // the sum of counter "returns" to part 4 above
}

----------------------------------------------------------------------------------------------------------------------

// Part 5 Putting It All Together: take all the data & use Colman-Liau Index then round the # and print based on results

#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text); // fn declaration aka prototype
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string s = get_string("Text: "); // 1st prompt user for a string

    int letters = count_letters(s); // 2nd & 4th fn call/execution
    int words = count_words(s); 
    int sentences = count_sentences(s); 

    // Coleman-Liau index = 0.0588 * L - 0.296 * S - 15.8
    // L = avg # of letters per 100 words; aka count_letters(s) / count_words(s) * 100
    // S = avg # of sentences per 100 words; count_sentences(s) / count_words(s) * 100
    float Co_Li = (0.0588 * count_letters(s) / count_words(s) * 100) - 
                  (0.296 * count_sentences(s) / count_words(s) * 100) - 15.8;

    int CLI = round(Co_Li);

    if (CLI >= 2 && CLI <= 15)
    {
        printf("Grade %i\n", CLI);
    }
    else if (CLI < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }
}

int count_letters(string text) // 3rd fn definition
{
    int counter = 0; // have to start at a basis
                                                
    for (int i = 0, n = strlen(text); i < n; i++) 
    {                        
        if(isalpha(text[i])) // isalpha - checks whether a character is alphabetical
        {                    // even though i'm using strlen i still have to index each char using [i] in isalpha()
        counter++;           // isalpha(text) = ERROR: "cast to smaller integer type 'int' from 'string'(aka 'char')" 
        }                    // the error = "I need the string indexed plz!" 
    }
    return counter; // the sum of counter "returns" to part 4 above
}

int count_words(string text) // 3rd fn definition
{
    int counter = 1; // this basis needs to start @1 bc the last word won't have a space

    for (int i = 0, n = strlen(text); i < n; i++)
    {                        
        if(isspace(text[i])) // isspace - checks whether a character is whitespace
        {                    // even though i'm using strlen i still have to index each char using [i] in isspace()
        counter++;            
        }         
    }
    return counter; // the sum of counter "returns" to part 4 above
}

int count_sentences(string text) // 3rd fn definition
{
    int counter = 0; // have to start at a basis

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
        counter++;
        }
    }
    return counter; // the sum of counter "returns" to part 4 above
}

----------------------------------------------------------------------------------------------------------------------

// helping Dan

#include <cs50.h>
#include <stdio.h>

int main(void) // aka class for Java
{
int price = get_int("How much?: ");

if (price < 20) //
{
    printf("Buying new shirt\n");
    return 0;
}
printf("too expensive\n");
}

 // return value of 0 means everything is working
 // return value of 1 means ERROR

 // however a boolean value of 0 means false
 // and a boolean value of any other non-negative integer means true

----------------------------------------------------------------------------------------------------------------------

// ChatGPT

#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text); // fn declaration aka prototype
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string s = get_string("Text: "); // 1st prompt user for a string

    int letters = count_letters(s); // 2nd & 4th fn call/execution
    int words = count_words(s);
    int sentences = count_sentences(s);

    float L = (float) letters / words * 100; // typecasting
    float S = (float) sentences / words * 100;

    // Coleman-Liau index = 0.0588 * L - 0.296 * S - 15.8
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text) // 3rd fn definition
{
    int counter = 0; // have to start at a basis

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if(isalpha(text[i])) // isalpha - checks whether a character is alphabetical
        {                    // even though i'm using strlen i still have to index each char using [i] in isalpha()
        counter++;           // isalpha(text) = ERROR: "cast to smaller integer type 'int' from 'string'(aka 'char')"
        }                    // the error = "I need the string indexed plz!"
    }
    return counter; // the sum of counter "returns" to part 4 above
}

int count_words(string text) // 3rd fn definition
{
    int counter = 1; // this basis needs to start @1 bc there's always 1 word entered

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if(isspace(text[i])) // isspace - checks whether a character is whitespace
        {                    // even though i'm using strlen i still have to index each char using [i] in isspace()
        counter++;
        }
    }
    return counter; // the sum of counter "returns" to part 4 above
}

int count_sentences(string text) // 3rd fn definition
{
    int counter = 0; // have to start at a basis

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
        counter++;
        }
    }
    return counter; // the sum of counter "returns" to part 4 above
}