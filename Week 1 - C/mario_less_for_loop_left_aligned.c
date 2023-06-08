 //Template for Left Aligned bricks in mario-less for loop

int height = 

    for (int row = 0; row < height; row++) 
    {
        for (int brick = 0; brick <= row; brick++) 
        {
            printf("#");
        }
        printf("\n"); 
    }
------------------------------------------------------------------------------------------------

int height = 0;  // The only way 0 produces anything is if the 1st loop conditional is <= 

    for (int row = 0; r < h0; r++)  // loop stops here 
    {
        for (int brick = 0; b <= r; b++)
        {
            printf("#");
        }
        printf("\n");
    }
REPL:
N/A
-------------------------------------------------------------------------------------------------

int height = 1;  // run/iterate each number individually

    for (int row = 0; r < h1; r++) // only iterates r0 < h1, which adds 1 to r later & r1 < h1 = N/A
    {
        for (int brick = 0; b <= r; b++) // only iterates b0 <= r0. Bc parent stops the loop
        {
            printf("#"); // prints 1 # because b0 <= r0
        }
        printf("\n"); // only iterates once and on r0
    }
REPL:
#
------------------------------------------------------------------------------------------------

int height = 2;  // run/iterate each number individually

    for (int row = 0; r < h; r++) 
    {
        for (int brick = 0; b <= r; b++)
        {
            printf("#"); // b0 prints 1 # then next i b0 & b1 prints 1 #, making 2 total on the same line 
        }
        printf("\n"); // print a new line after each completed iteration of the 1st loop
    }
REPL:
#
##
------------------------------------------------------------------------------------------------

int height = 3;  // run/iterate each number individually

    for (int row = 0; r < h; r++)  
    {
        for (int brick = 0; b <= r; b++) 
        {
            printf("#"); 
        }
        printf("\n"); // print a new line after each completed iteration of the 1st loop
    }
REPL:
#
##
###
------------------------------------------------------------------------------------------------

int height = 4;  // run/iterate each number individually

    for (int row = 0; r < h; r++) 
    {
        for (int brick = 0; b <= r; b++) 
        {
            printf("#"); 
        }
        printf("\n"); // print a new line after each completed iteration of the 1st loop
    }
REPL:
#
##
###
####
------------------------------------------------------------------------------------------------

int height = 5;  // run/iterate each number individually

    for (int row = 0; r < h; r++) 
    {
        for (int brick = 0; b <= r; b++)
        {
            printf("#"); 
        }
        printf("\n"); // print a new line after each completed iteration of the 1st loop
    }
REPL:
#
##
###
####
#####
------------------------------------------------------------------------------------------------

int height = 6;  // run/iterate each number individually

    for (int row = 0; r < h; r++) 
    {
        for (int brick = 0; b <= r; b++)
        {
            printf("#"); 
        }
        printf("\n"); // print a new line after each completed iteration of the 1st loop
    }
REPL:
#
##
###
####
#####
######
------------------------------------------------------------------------------------------------

int height = 7;  // run/iterate each number individually

    for (int row = 0; r < h; r++)
    {
        for (int brick = 0; b <= r; b++)
        {
            printf("#"); 
        }
        printf("\n"); // print a new line after each completed iteration of the 1st loop
    }
REPL:
#
##
###
####
#####
######
#######
------------------------------------------------------------------------------------------------

int height = 8;  // run/iterate each number individually

    for (int row = 0; r < h; r++) 
    {
        for (int brick = 0; b <= r; b++)
        {
            printf("#"); 
        }
        printf("\n"); // print a new line after each completed iteration of the 1st loop
    }
REPL:
#
##
###
####
#####
######
#######
########
