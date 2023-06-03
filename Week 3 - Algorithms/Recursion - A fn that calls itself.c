// Recursion - a fn that calls itself

// the old way to build mario-less.c

#include <cs50.h>
#include <stdio.h>

void draw(int n); // fn declaration aka prototype

int main(void)
{
    int height = get_int("Height: "); // 1st prompt user for a number

    draw(height); // 2nd fn call
} 

void draw(int n) // 3rd fn definition
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}

----------------------------------------------------------------------------------------------------------------------

// the new way to build mario-less.c using recursion

#include <cs50.h>
#include <stdio.h>

void draw(int n); // fn declaration aka prototype

int main(void)
{
    int height = get_int("Height: "); // 1st prompt user for a number

    draw(height); // 2nd fn call
} 

void draw(int n) // 3rd fn definition
{
// the top section of this fn runs its course, applying the user data until it stops 
    if (n <= 0) // this is the base case of the recursive fn
    {
        return;
    }
    draw(n - 1); // 4th fn recursion - a fn calling itself this is what makes the 4,3,2,1
     // and the results get released from the call stack in reverse order 1,2,3,4,5

// the bottom section uses that data in reverse, each num running its own iteration
    for (int i = 0; i < n; i++) // then after it hits base case the for loop runs
    {
        printf("#");
    }
    printf("\n");
}  

// the n-1 base case stops the loop from becoming an "infinite loop"
// Once the value of n reaches 0, the recursive calls stop.

----------------------------------------------------------------------------------------------------------------------

// the breakdown of whats going on inside void draw(int n)

void draw(int n)
{
    if (n <= 0) 
    {
        return;
    }
    draw(n - 1); 
}

----------------------------------------------------------------------------------------------------------------------

// the user inputs the num 2
// it starts by taking the user’s input; the num 2 and running it 
// comparing 2 <= 0, then moving down to the recursion titled draw(2 - 1); which = 1

void draw(2)
{
    if (2 <= 0) 
    {
        return;
    }
    draw(2 - 1);
}

// that same singular user input gets ran until it stops 
// the results from each iteration are used later but in reverse order

----------------------------------------------------------------------------------------------------------------------

// comparing 1 <= 0, then moving down to the recursion titled draw(1 - 1); which = 0

void draw(1)
{
    if (1 <= 0) 
    {
        return;
    }
    draw(1 - 1);
}

----------------------------------------------------------------------------------------------------------------------

// finally comparing 0 <= 0, which stops the code

void draw(0)
{
    if (0 <= 0) // the code stops here 
    {
        return;
    }
    draw(n - 1);
}
// the code ran 2 times, using the num2 then the num1 

----------------------------------------------------------------------------------------------------------------------

// the the bottom section uses that data in reverse, each num running its own iteration 
// 1st the number 1 gets an iteration as n

void draw(1) 
{
    for (int i = 0; 0 < 1; i++)
    {
        printf("#");
    }
    printf("\n");
}
REPL 
# 

----------------------------------------------------------------------------------------------------------------------

// then the number 2 gets an iteration as n

void draw(2) 
{
    for (int i = 0; 0 < 2; i++)
    {
        printf("#");
    }
    printf("\n");
}
REPL 
#
##

----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------

----------------------------------------------------------------------------------------------------------------------

----------------------------------------------------------------------------------------------------------------------

----------------------------------------------------------------------------------------------------------------------

----------------------------------------------------------------------------------------------------------------------