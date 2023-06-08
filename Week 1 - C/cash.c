int get_cents(void) 
{
    do
    {
       n = get_int("Change owed: ");
    }
    while (n < 0);
}
REPL: error: non-void function does not return a value [-Werror,-Wreturn-type]
}

This means a return is required in the statement 

-------------------------------------------------------------------------------------------------

//Only while loop will meet the criteria because because you don’t know how many loops each coin will run. 
//An if statement doesn’t work, they are true false oriented nor a for loop they run a specific iteration. 

//https://stackoverflow.com/questions/14606466/difference-between-an-if-statement-and-while-loop#14606495

-------------------------------------------------------------------------------------------------
#include <cs50.h>
#include <stdio.h>

int get_cents(void); // Prototypes
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // total
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int n; //declare user variable
int coins_quarters = 0; // setting a base
int coins_dimes = 0;
int coins_nickels = 0;
int coins_pennies = 0;

int get_cents(void)
{
    do
    {
       n = get_int("Change owed: ");
    }
    while (n < 0);
    return n;
}

int calculate_quarters(int cents)
{
    while (cents >= 25)
    {
        cents = cents - 25;
        coins_quarters++;
    }
    return coins_quarters;
}

int calculate_dimes(int cents)
{
    while (cents >= 10)
    {
        cents = cents - 10;
        coins_dimes++;
    }
    return coins_dimes;
}

int calculate_nickels(int cents)
{
    while (cents >= 5)
    {
        cents = cents - 5;
        coins_nickels++;
    }
    return coins_nickels;
}

int calculate_pennies(int cents)
{
    while (cents >= 1)
    {
        cents = cents - 1;
        coins_pennies++;
    }
    return coins_pennies;
}

--------------------------------------------------------------------------------------------------------------------

// Alt version; it works but the complier says it can't compile when asking for a check50. Yet it gives proper answer

#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_coins(int cents, int coin_value);

int main(void)
{
    int cents = get_cents();

    int quarters = calculate_coins(cents, 25);
    cents -= quarters * 25;

    int dimes = calculate_coins(cents, 10);
    cents -= dimes * 10;

    int nickels = calculate_coins(cents, 5);
    cents -= nickels * 5;

    int pennies = calculate_coins(cents, 1);

    int coins = quarters + dimes + nickels + pennies;

    printf("%i\n", coins);
}

int get_cents(void)
{
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);
    return cents;
}

int calculate_coins(int cents, int coin_value)
{
    int coins = 0;
    while (cents >= coin_value)
    {
        cents -= coin_value;
        coins++;
    }
    return coins;
}




