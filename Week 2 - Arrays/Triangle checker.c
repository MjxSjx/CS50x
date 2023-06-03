// valid triangle

// prompt for 3 real numbers 
// the fn should output true or false if the #'s provided can produce a triangle


#include <cs50.h> // These are headers also called libraries they contain fn's ppl
#include <stdio.h> // have already created and are common enough to get stored as a linked reference

bool valid_triangle(float x, float y, float z);  // fn declaration, the input names don't matter
// also called a prototype, this is saying "HEY complier, at some point this will come into play"

bool valid_triangle(float x, float y, float z);  // fn declaration
int main(void) // main fn; think boilerplate
{
    float x = 0; // initialize the variables bc w/out this section the variables
    float y = 0; // can't be used bc we have no basis
    float z = 0; // **Think how calculators start with 0, it’s a foundation

    do // do this until conditions are met
    {
        x = get_float("positive only plz side 1: ");
    }
    while (x <= 0); 
    do
    {
        y = get_float("positive only plz side 2: ");
    }
    while (y <= 0);
    do
    {
        z = get_float("positive only plz side 3: ");
    }
    while (z <= 0);

    float zz = valid_triangle(x, y, z); // the fn call aka execution

    if(zz == 0) // set to the variable zz so i can print the results
    {  
        printf("Results: SORRY!\n"); 
        return 0; // I’m saying i approve these results, aka there is no error
    } 
    printf("Results: Makes A Triangle!\n");
    return 0;
}

bool valid_triangle(float x, float y, float z) // fn definition
{
    if ((x + y <= z) || (x + z <= y) || (y + z <= x))
    {
        return false; 
    }
    return true; 
}               // Inside a bool 0 represents false & any other # represents true



----------------------------------------------------------------------------------------------------------------------

// this is what i had b4 i realized i had to set the fn call zz to the print out NOT the fn itself

#include <cs50.h>
#include <stdio.h>

bool valid_triangle(float x, float y, float z);  // fn declaration, the input names don't matter

int main(void) // main fn; think boilerplate
{
float x = 0; // initialize variable
float y = 0;
float z = 0;

do
{
    x = get_int("positive only plz side 1: ");
}
while (x <= 0);
do
{
    y = get_int("positive only plz side 2: ");
}
while (y <= 0);
do
{
    z = get_int("positive only plz side 3: ");
}
while (z <= 0);

int zz = valid_triangle(x, y, z);

if (valid_triangle = 0)
{
    printf("Results: Is A Triangle! %i\n", zz);
}
printf("Results: SORRY!\n")
}

bool valid_triangle(float x, float y, float z)
{
    if ((x + y <= z) || (x + z <= y) || (y + z <= x))
    {
        return false;
    }
    return true;
}