
// When using for loops that decrement the variables max i value (aka height = ) is used each iteration

// Template for mario-more

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height; //declare user variable

    do
    {
        h = get_int("Height (ranges from 1 to 8): ");
    }
    while (h < 1 || h > 8);


    for (int row = 0; r < h; r++) // rows
    {
        for (int space = h - 1; s > r; s--) // h(always starts with the largest height value)
        {
            printf(" ");
        }
        for (int brick = 0; b <= r; b++) // left bricks but, right aligned
        {
            printf("#");
        }
        printf("  "); // divider

        for (int rightBrick = 0; rb <= r; rb++) // right bricks but, left aligned
        {
            printf("#");
        }
        printf("\n"); // new line/row creater
    }
}
    //printf("Stored: %i\h", h);
------------------------------------------------------------------------------------------------

int height = 0; // The only way 0 produces anything is if the 1st loop conditional is <= 

    for (int row = 0; r < h; r++)  // loop stops here
    {
        for (int space = h - 1; s > r; s--) // h(always starts with the largest height value)
        {
            printf(" ");
        }
        for (int brick = 0; b <= r; b++) // left bricks but, right aligned
        {
            printf("#");
        }
        printf(".."); // divider

        for (int rightBrick = 0; rb <= r; rb++) // right bricks but, left aligned
        {
            printf("#");
        }
        printf("\n"); // new line/row creater
    }
REPL:
N/A
-------------------------------------------------------------------------------------------------

int height = 1; // run/iterate each number individually 

    for (int row = 0; r < h; r++)
    {
        for (int space = h1 - 1; s > r; s--) // h(always starts with the largest height value)
        {
            printf(" ");
        }
        for (int brick = 0; b <= r; b++) // left bricks but, right aligned
        {
            printf("#");
        }
        printf(".."); // divider

        for (int rightBrick = 0; rb <= r; rb++) // right bricks but, left aligned
        {
            printf("#");
        }
        printf("\n"); // print a new line/row after each completed iteration of the 1st loop
    }
REPL:
#..#
-------------------------------------------------------------------------------------------------

int height = 3; // run/iterate each number individually 

    for (int row = 0; r < h; r++)
    {
        for (int space = h3 - 1; s > r; s--) // h(always starts with the largest height value)
        {
            printf(" "); // print the totaled value of space each i. egro: 2 1 0
        }
        for (int brick = 0; b <= r; b++) // left bricks but, right aligned
        {
            printf("#");
        }
        printf(".."); // divider

        for (int rightBrick = 0; rb <= r; rb++) // right bricks but, left aligned
        {
            printf("#");
        }
        printf("\n"); // print a new line/row after each completed iteration of the 1st loop
    }
REPL:
  #..#
 ##..##
###..###
-------------------------------------------------------------------------------------------------

int height = 8; // run/iterate each number individually 

    for (int row = 0; r < h; r++)
    {
        for (int space = h8 - 1; s > r; s--) // h(always starts with the largest height value)
        {
            printf(" "); // print the totaled value of space each i. egro: 7 6 5 4 3 2 1 0
        }
        for (int brick = 0; b <= r; b++) // left bricks but, right aligned
        {
            printf("#");
        }
        printf(".."); // divider

        for (int rightBrick = 0; rb <= r; rb++) // right bricks but, left aligned
        {
            printf("#");
        }
        printf("\n"); // print a new line/row after each completed iteration of the 1st loop
    }
REPL:
       #..#
      ##..##
     ###..###
    ####..####
   #####..#####
  ######..######
 #######..#######
########..########
-------------------------------------------------------------------------------------------------
