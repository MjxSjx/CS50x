
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size

    // TODO: Prompt for end size

    // Keep track of number of years
    
    // TODO: Calculate number of years until we reach threshold
    
    // TODO: Print number of years

}

----------------------------------------------------------------------------------------------------------------------


#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);

    // TODO: Prompt for end size
    int end;
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);

    // Keep track of number of years
    int years = 0;

    // TODO: Calculate number of years until we reach threshold
    while (start < end)
    {
        start = start + (start / 3) - (start / 4);
        years++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", years);
}