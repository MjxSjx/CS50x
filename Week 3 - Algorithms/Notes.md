# Week 3 – Algorithms

A step-by-step set of instructions for solving a problem

### Introduction
As things continue to get more cryptic ultimately at the end of the day what we’ve been doing is 
input => algorithm(fn) => output

### Algorithms 
String = An array of characters
Array = A 0 indexed contiguous memory/storage containing data types listed in element form

### Searching
To find information is one of the most common things computers do

## Big O (order of) Notation, Ω and, ϴ
O: Capital letter o is used to describe the upper bound “running time” of an algo 
Ω: Capital Omega symbol is used to describe the lower bound “running time” of an algor 
ϴ: Capital Theta symbol is used to describe when upper & lower are the same “running time”
All are a way of expressing in mathematical terms the efficiency/speed/# of steps, some code is 

### Common Running Time Equations
The most familiar Big O, Ω and, ϴ notations
``` 
O(n2) Ω(n2) ϴ(n2) 
O (n log n) Ω(n log n) ϴ(n log n)
O (n) Ω(n) ϴ(n)
O (log n) Ω(log n) ϴ(log n)
O (1) Ω(1) ϴ(1)
``` 

### Asymptotic Notation
Big O describes how many steps some code has at worst aka worst-case scenario
Big Ω describes how few steps some code has at best aka best-case scenario

### Searching Lockers
Returning false lines of code aren’t used with else conditionals when using if statements bc you would stop the program in one iteration, when clearly many are needed

## Linear Search: left to right
Searching from left to right in an array is called a “Linear search”. When elements are in an array randomly; let’s say some integers in an array int example[] = {3,6,1,8,4,0,9,5} a linear search is the best you can do. 
Because any starting point, left to right, right to left, or even the middle makes no difference in your randomly assorted elements when searching, it’s all random
Left to Right/Right to Left aka “Linear Search”
// pseudocode of a linear Search

for i from 0 to n-1
    if number behind doors[i]
        return true;
return false;

O(n) // bc it will take n number of times/iterations to find what it is seeking on the upper bound aspect 

Ω(1) // bc technically it can be successful in 1 step aka the first iteration on the  lower bound aspect

### The running times
The O notation for this code above is O(n): bc it will take n number of times/iterations to find what it is seeking on the upper bound aspect 
The Ω notation for this code above is Ω(1): bc technically it can be successful in 1 step aka the first iteration on the  lower bound aspect

The only thing that matters in terms of efficiency or inefficiency of the algorithm is what are you doing again and again aka looping bc that’s the thing that’s going to add up. Doing one thing or two things a constant number of times, not a big deal, loops however are

** The way we describe a constant # of steps is, just a single number like 1 **

## Binary Search aka log n
Divide and conquer aka “Binary Search”
// pseudocode of a Binary Search

if no doors
    return false;
if number behind doors[middle]
    return true;
else if number < doors[middle]
    search doors[0] through doors[middle - 1];
else if number > doors[middle]
    search doors[middle + 1] through doors[n - 1];

O(log n) log n refers to the # of times you can divide n by 2. bc we are dividing in half then half and so on 

Ω(1) // bc technically it can be successful in 1 step aka the first iteration on the lower bound aspect
The focus should be on how long/how many steps CAN my code take aka worst case scenario
Sorting then Searching (binary) vs. Just Searching (linear)

### Sorting then searching (binary search): Can greatly help reduce the time spent searching, even when you consider the time it took/takes to sort. Bc when there will be multiple cases of searching for things, in time, the sorting of the elements will pay off and result in faster searches

Just searching (linear search): However, just searching can be beneficial if you’re only searching as a one off, or a few times, as the time required to sort would/could actually make things slower aka “adding to the process”

### Implementing Linear Search of ints 
// numbers.c

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int numbers[] = {4, 6, 8, 2, 7, 5, 0}; // syntactic sugar array

    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == 0)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not Found\n"); // not found is after the loop allowing it to cycle
    return 1;
}

### String Comparison – helper fn strcmp
// names.c

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string names[] = {"Bill", "Charlie", "Fred", "George", "Ginny", "Percy", "Ron"}; // syntactic sugar array
    for(int i = 0; i < 7; i++)
    {
        if(names[i] == "Ron") // if(names[i] == "Ron") = error
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}
// error: “result of comparison against a string literal is unspecified (use an explicit string comparison fn instead)” literally asking for strcmp()

***strcmp - compare two strings is needed***
int strcmp(string s1, string s2);  the syntax
strcmp has a return type of int bc there are 3 possibilities bool cannot work

  #1 if string s1 comes before string s2 return -1. Aka < 0
 #2 if string s1 is the same string s2 return 0. Aka == 0
#3 if string s1 comes after string s2 return 1. Aka > 0

// names.c

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string names[] = {"Bill", "Charlie", "Fred", "George", "Ginny", "Percy", "Ron"}; // syntactic sugar array

    for(int i = 0; i < 7; i++)
    {
        if(strcmp(names[i],"Ron") == 0) // if s1 is the same s2 run the statement
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}
Strings are arrays and can’t be compared by normal means bc they aren’t simple 1v1 of info
## Storing Data in Arrays

This is relying on a 1:1 ratio of the variables and can fail easily, not well designed
// phonebook.c

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string names[] = {"Carter", "David"}; // names[0] is tied to numbers[0]  
    string numbers[] = {"+1-617-495-1000", "+1-949-468-2750"}; // bad design 

    for (int i = 0; i < 2; i++)
    {
        if (strcmp(names[i], "David") == 0) if s1 & s2 are the same execute
        {
            printf("Found %s\n", numbers[i]);
            return 0;
        }
    }
    printf("Not found\n"); 
    return 1;
}

## Creating Data Structures aka struct

In C you can build your own types of data!
typedef: A key word in C that creates a brand-new data type
struct: A key word expressing the new data type will be a structure not just a singular data type like int or bool, but has dimensions aka holding multiple data types
typedef struct 
{
    string name;
    string number;
};
person;  this is where you give your new data type its title aka name
// data type person is now known to contain the variables names & numbers



Now there’s no potential error things are “encapsulated inside the same data type”
#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct // like a prototype aka fn declaration typedef goes at the top
{
    string name;
    string number;
}
person;

int main(void)
{
    person people[2]; // Arrays are indexed @ 0

    people[0].name = "Carter"; // . means to retrieve/access info
    people[0].number = "+1-617-495-1000"; // . means to retrieve/access info

    people[1].name = "David"; // . means to retrieve/access info
    people[1].number = "+1-949-468-2750"; // . means to retrieve/access info

    for (int i = 0; i < 2; i++)
    {
        if (strcmp(people[i].name, "David") == 0)if s1 & s2 are the same return 0
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
The big spoiler here is C isn’t an object-oriented language so this is our work around

## Sorting
When sorting what you’re really doing is
unsorted => algorithm => sorted

6 3 2 8 1 4 5 7 => algorithm => 1 2 3 4 5 6 7 8

### Visualizing Sorts
Computers need you to be methodical to solve problems, something easy for a human to understand and visually see, is not the case for a computer. It has to do things 1 methodical tedious step at a time. The nice part is, it does it at speeds we can’t imagine 
### 2 methods for sorting numbers from lowest to highest

## Selection Sort - selecting the smallest element in a linear search
Selecting the smallest # one at a time and placing it to the utmost possible left in ascending order
// pseudocode of Selection Sort

for i from 0 to n-1
    find smallest number between numbers[i] and numbers[n-1]
    swap smallest number with numbers[i] 
// O upper bound = O(n2) 
// Ω lower bound = Ω(n2) 
// And since they are equal that means 
// ϴ(n2) 

## Bubble Sort - comparing adjacent elements and swapping accordingly
Comparing 2 adjacent #’s, selecting the larger #, then swapping it to the right “bubbling it up”
// pseudocode of bubble Sort

Repeat n-1 times
    for i from 0 to n-2 // n-2 to not go beyond the boundary of the array 
        if numbers[i] and numbers [i+1] out of order
            swap them
    if no swaps quit    
// O upper bound = O(n2) 
// Ω lower bound = Ω(n) 
 
Comparison Sorts
They’re both slow, and in fact Bubble Sort is slower. The issue is, the n2 part. They have to cycle through all of the elements that haven’t been positioned correctly each and every iteration. Squared is the heaviest burden and ideally avoid it when possible.
 
Recursion - A fn that calls itself.c

The old way to build mario-less.c
// the old way to build mario-less.c
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

the NEW way to build mario-less.c
// recursion.c - the new way to build mario-less.c
#include <cs50.h>
#include <stdio.h>

void draw(int n); // fn declaration aka prototype

int main(void)
{
    int height = get_int("Height: "); // 1st prompt user 1 for a number

    draw(height); // 2nd fn call
} 

void draw(int n) // 3rd fn definition
{
the top section of this fn runs its course, applying the user data until it stops 
    if (n <= 0) // this is the base case of the recursive fn
    {
        return;
    }            // this is what makes the 4,3,2,1               
    draw(n - 1); // 4th fn recursion - a fn calling itself

the bottom section uses that data in reverse, each num running its own iteration
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
} 


The breakdown of the new fn technique recursion 
// the user inputs the num 2
// it starts by taking the user’s input; the num 2 and running it
// comparing 2 <= 0, then moving down to the recursion titled draw(2 - 1);

void draw(2)
{
    if (2 <= 0) 
    {
        return;
    } 
    draw(2 - 1); = 1
}
// that same singular user input gets ran until it stops 
// the results from each iteration are used later but in reverse order

// comparing 1 <= 0, then moving down to the recursion titled draw(1 - 1);

void draw(1)
{
    if (1 <= 0) 
    {
        return;
    }
    draw(1 - 1); = 0
}
// finally comparing 0 <= 0, which stops the code
// the code ran 2 times, using the num2 then the num1

 The bottom section uses that data in reverse, each num running its own iteration 

void draw(n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
} 
REPL 
# // 1st the number 1 gets an iteration as n
## // then the number 2 gets an iteration as n
I have a .c file titled "Recursion - A fn that calls itself.c" that breaks down recursions step by step
also debug50 ./testing can show the breakdown too
Recursion – a fn that calls itself

So far, all we’ve done is comparison sorts. How can we do better than something on the order of n2? By using a mathematical process known as “recursion”
When searching for example, instead of doing a linear search or a binary search of ALL the data. Why don’t we divide the problem as many times as possible into little searches that all run at the same time, then compare the results with other results cutting the problem in half then half then half again, comparing results until the answer is found
when this flags it means the program will loop forever and needs an out written

"error: all paths through this function will call itself [-Werror,-Winfinite-recursion]
// {"

Merge Sort – a sorting algorithm
// pseudocode of Merge Sort
// If only one number
//    Quit
// Else
//    Sort left half of lockers
//    Sort right half of lockers
//    Merge sorted halves
// upper & lower bound = ϴ(n log n)  
The strength here is each of these lines of pseudocode is sorting a smaller piece of the problem. The thing with computers is they can do simple tasks VERY fast and unlike us can actually do more than one thing at a time. 
By breaking the sorting problem into many little problems then comparing the results you get a drastically faster bound than the other methods discussed thus far and are properly utilizing the strength of a computer

Methodically “Merge Two Sorted Halves”: Take the 1st element of each array (left half & right half) and compare which of the two is placed first. Then move down the elements merging the proper ones into a new array

Merge Sort uses more memory than others, but the total run time is drastically reduced 

Sort Race
A visual demonstration of all 3 sorts running at the same time. 1st is Merge Sort 2nd is Selection Sort. 3rd is Bubble sort

There is always a solution to coding problems
