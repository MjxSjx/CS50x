
// Practice Problems 1

// Debug.c
// Become familiar wih C syntax
// Learn to debug buggy code

#include <cs50.h> // missing header library <stdio.h> for printf to work

int main(void)
{
    // Ask for your name and where live
    name = get_string("What is your name? ") // no datatype listed, no ;
    location = get_string("Where do you live? ") // no datatype listed, no ;

    // Say hello
    print("Hello, %i, from %i!", name, location) // wrong placeholder, no new line and no ;
}

// Solution

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Ask for your name and where live
    string name = get_string("What is your name? ");
    string location = get_string("Where do you live? ");

    // Say hello
    printf("Hello, %s, from %s!\n", name, location);
}


----------------------------------------------------------------------------------------------------------------------

// half.c
// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

float half(float bill, float tax, int tip); // fn declaration aka prototype

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: "); // 1st prompt user for a number
    float tax_percent = get_float("Sale Tax Percent: ");        // 1st prompt user for a number
    int tip_percent = get_int("Tip percent: ");                 // 1st prompt user for a number

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));  // 2nd fn call
}

// TODO: Complete the function
float half(float bill, float tax, int tip)  // 3rd fn definition
{
    return;
}

// Solution A

// the trick is a calculator doesn't know when things are a percent
// How to Multiply a Number by a Percent
// https://sciencing.com/answer-20-number-8-8214129.html
// number * percent / 100 = result

float half(float bill, float tax, int tip) 
{
    float total = bill * tax / 100 + bill;
    total = total * tip / 100 + total;   
    return total / 2; 
}

// Solution B

// Remember PEMDAS. and unfortunately C doesn' seem to do PEMDAS correctly, or i'm not doing it correctly
// regardless the answer from the complier isn't correct, yet when i do it myself the answer is correct

float half(float bill, float tax, int tip)
{
    float total = bill * (1 + tax / 100); 
    total = total * (1 + tip / 100);
    return total / 2;
}

// Chat GPT // it doesnt add the tax to the tip total. It totals everything separately then adds the total 
// This isn't wrong, but isn't what the test is looking for. It's likely there's some wordage that i'm not using 

float half(float bill, float tax, int tip)
{
    float total = bill + (bill * tax / 100) + (bill * tip / 100);
    return total / 2;
}

----------------------------------------------------------------------------------------------------------------------

// Prime

#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    // TODO
    return false;
}

---------------

bool prime(int number)
{
    if (number <= 1)
    {
        return false;
    }

    for (int i = 2; i <= number / 2; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }

    return true;
}

----------------------------------------------------------------------------------------------------------------------



----------------------------------------------------------------------------------------------------------------------



----------------------------------------------------------------------------------------------------------------------