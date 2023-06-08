// When using for loops that decrement the variables max i value (aka height = ) is used each iteration

// Alternative Template for Right Aligned bricks

int height =

    for (int row = 0; row < height; row++) 
    {
        for (int space = height - row; space > 1; space--) // h(always starts with the largest height value) 
        {
            printf(".");
        }
        for (int brick = 0; brick <= row; brick++) 
        {
            printf("#");
        }
        printf("\n"); 
    }
------------------------------------------------------------------------------------------------

// Template for Right Aligned bricks in mario-less for loop

int height = 

    for (int row = 0; row < height; row++) 
    {
        for (int space = height - 1; space > row; space--) // h(always starts with the largest height value)
        {
            printf("."); 
        }    
        for (int brick = 0; brick <= row; brick++) 
        {
            printf("#");
        }
        printf("\n"); 
    }
------------------------------------------------------------------------------------------------

int height = 0; // The only way 0 produces anything is if the 1st loop conditional is <= 

    for (int row = 0; r < h0; r++)  // loop stops here
    {
        for (int space = h0 - 1; s > r; s--) // h(always starts with the largest height value)
        {
            printf("."); 
        }
        for (int brick = 0; b <= r; b++)
        {
            printf("#");
        }
        printf("\n");
    }
REPL:
N/A
-------------------------------------------------------------------------------------------------

int height = 1; // run/iterate each number individually 

    for (int row = 0; r < h1; r++) // only iterates r0 < h1, which adds 1 to r later & r1 < h1 = N/A
    {
        for (int space = h1 - 1; s > r; s--) // doesn't run bc s0 > r0 stops it
        {
            printf("."); 
        }
        for (int brick = 0; b <= r; b++) // only iterates b0 <= r0. Bc parent stops the loop
        {
            printf("#"); // prints 1 pound sign because b0 <= r0
        }
        printf("\n"); // only iterates once and on r0
    }
REPL:
#
-------------------------------------------------------------------------------------------------

int height = 2; // run/iterate each number individually 

    for (int row = 0; r < h; r++)
    {
        for (int space = h2 - 1; s > r; s--) // h(always starts with the largest height value)
        {   
            printf("."); // print the totaled value of space each i. egro: 1 then 0
        }
        for (int brick = 0; b <= r; b++)
        {
            printf("#"); // b0 prints 1 # then next i b0 & b1 prints 1 #, making 2 total on the same line 
        }
        printf("\n"); // print a new line after each completed iteration of the 1st loop
    }
REPL:
.#
##
-------------------------------------------------------------------------------------------------

int height = 3; // run/iterate each number individually 

    for (int row = 0; r < h; r++)
    {
        for (int space = h3 - 1; s > r; s--) // h(always starts with the largest height value)
        {    
            printf("."); // print the totaled value of space each i. egro: 2 1 0
        }
        for (int brick = 0; b <= r; b++)
        {
            printf("#");
        }
        printf("\n"); // print a new line after each completed iteration of the 1st loop
    }
REPL:
..#
.##
###
-------------------------------------------------------------------------------------------------

int height = 4; // run/iterate each number individually 

    for (int row = 0; r < h; r++)
    {
        for (int space = h4 - 1; s > r; s--) // h(always starts with the largest height value)
        {
            printf("."); // print the totaled value of space each i. egro: 3 2 1 0
        }
        for (int brick = 0; b <= r; b++)
        {
            printf("#");
        }
        printf("\n"); // print a new line after each completed iteration of the 1st loop
    }
REPL:
...#
..##
.###
####
-------------------------------------------------------------------------------------------------

int height = 5; // run/iterate each number individually 

    for (int row = 0; r < h; r++)n
    {
        for (int space = h5 - 1; s > r; s--) // h(always starts with the largest height value)
        {
            printf("."); // print the totaled value of space each i. egro: 4 3 2 1 0
        }
        for (int brick = 0; b <= r; b++)
        {
            printf("#");
        }
        printf("\n"); // print a new line after each completed iteration of the 1st loop
    }
REPL:
....#
...##
..###
.####
#####
-------------------------------------------------------------------------------------------------

int height = 6; // run/iterate each number individually 

    for (int row = 0; r < h; r++)
    {
        for (int space = h6 - 1; s > r; s--) // h(always starts with the largest height value)
        {
            printf("."); // print the totaled value of space each i. egro: 5 4 3 2 1 0
        }
        for (int brick = 0; b <= r; b++)
        {
            printf("#");
        }
        printf("\n"); // print a new line after each completed iteration of the 1st loop
    }
REPL:
.....#
....##
...###
..####
.#####
######
-------------------------------------------------------------------------------------------------

int height = 7; // run/iterate each number individually 

    for (int row = 0; r < h; r++)
    {
        for (int space = h7 - 1; s > r; s--) // h(always starts with the largest height value)
        {
            printf("."); // print the totaled value of space each i. egro: 6 5 4 3 2 1 0
        }
        for (int brick = 0; b <= r; b++)
        {
            printf("#");
        }
        printf("\n"); // print a new line after each completed iteration of the 1st loop
    }
REPL:
......#
.....##
....###
...####
..#####
.######
#######
-------------------------------------------------------------------------------------------------

int height = 8; // run/iterate each number individually 

    for (int row = 0; r < h; r++)
    {
        for (int space = h8 - 1; s > r; s--) // h(always starts with the largest height value)
        {
            printf("."); // print the totaled value of space each i. egro: 7 6 5 4 3 2 1 0
        }
        for (int brick = 0; b <= r; b++) 
        {
            printf("#"); 
        }
        printf("\n"); // print a new line/row after each completed iteration of the 1st loop
    }
REPL:
.......#
......##
.....###
....####
...#####
..######
.#######
########





