Week 1 – C

It’s advised to focus on what’s immediately important when learning coding languages. You can’t learn everything all at once. Focus on what’s immediately needed and leave the rest for later. 
The 3 Pillars of coding

 
Correctness
Design
Style
 
      Your code is correct		   Succinct as possible	  	  Following the proper syntax

The Integrated Development Environment (IDE) aka Text Editor
Programs/tools that allow coding languages to operate and be understood for what they are Things like Notepad++ or VS Code. The top half of the IDE is where the code is written

 
.js = files are understood as JavaScript
.ts = files are understood as TypeScript
.py = files are understood as Python
.c = files are understood as C 
 
#include <stdio.h>                                     printing hello, world in C
int main(void)
{printf("hello, world\n");
}
So, how do I run/execute this code written in C? I need an IDE AND to use

A complier (most languages don’t use them anymore)
With C, I need to convert the source code into another language using a complier in the CLI

Source code  □ complier  machine code
                                          The C syntax       algorithm        the binary 
Algorithm a step-by-step set of instructions for solving a problem

The Command Line Interface (CLI)
In VS Code this is the optional bottom section that contains Problems, Output, Debug Console, Terminal, & Jupyter. If it’s hidden go to file section > View tab, inside are all the CLI
 
Terminal window
Old school tech that lets you interact with the IDE and run/execute code (via keywords) with a keyboard. There are no OS easy user-friendly clickable things like apps and folders. You manually type in the terminal, and in time its much faster and efficient.  

GUI – Graphical User Interface
In VS Code this is the far-left side tab: Explorer where all the folders are, Search, Source Control, Run & Debug, Extensions, Testing, Accounts and lastly, Manage, which is the settings menu

Scratch to C
Scratch
Say (hello, world) = a function with an input
C
#include <stdio.h>                                     
int main(void)
{printf("hello, world\n");
}
f stands for formatted 
C uses strings so the words need quotes but MUST be in double quotes
\n = creates a new line after this syntax, moves the cursor down
; Semi colon at the end to say that line is finished


Scratch
ask (What’s your name?) and wait = a function with a return value in (answer)
C
string answer = get_string("What's your name?\n ");  
string = data type; C needs variables to be defined specifically to what data type they are
answer = variable aka identifier aka label
= means assign to _____. Aka set to _____
get_string() = method with an input
C uses strings so the words need quotes but MUST be in double quotes
\n = create a new line after this syntax, move the cursor down
; Semi colon at the end to say that line is finished


Scratch 
text to voice or camera motion are extensions that need to be loaded. They are called libraries 
C
#include <stdio.h>      extensions are loaded at the top of the script
std = standard
io = input output
stdio = standard input output library

If I want to use ANY functions. I then ALSO need to create extensions for those functions	
#include <cs50.h>     loads the library for func get_string() and others
#include <stdio.h>    loads the library for ANY standard input/output functions printf() is included in this extension so it can be accessed/used
get_string()is a function Harvard CS50 wrote some time ago. Making it way easier to get inputs from a user. Because the old/normal way is difficult. So Harvard wrote the function titled get_string()BUT the only way it can be used is by using the extension aka library #include <cs50.h> at the top of your script



#include <cs50.h>  
#include <stdio.h> 

int main(void)
{
    string answer = get_string("What's your name? ");
    printf("hello, answer\n");
}
What’s your name? REPL      ****User enters = Matt 
hello, answer REPL         the variable answer isn’t understood to C right now

# Placeholders %

Unfortunately, C does not understand you want the input returned. So, you need a placeholder
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string answer = get_string("What's your name? ");
    printf("hello, %s\n", answer);
}
What’s your name? REPL       ****User enters = Matt 
hello, Matt REPL         
%s is a format code/a variable, which represents a string placeholder. It says, hey computer put a string here eventually.

input  □ function  return value

You separate inputs (parameters/arguments) with ,
    printf("hello, %s\n", answer);


Scratch 
when green flag clicked, when ___ pressed down 
Pieces used to start a program
C
int main(void)  the foundation/body of creating C syntax  
{                                                 think of the  HTML body element
…STUFF
}

Scratch 
automatically runs and loads scripts with no complier needed
C
#include <cs50.h>  header file                           like a HTML header but 
#include <stdio.h> header file                          for the complier to use
These header files are mandatory to run functions aka actions/verbs and bring a library of all available functions that can be understood within that specific header file.
Tells the complier to load the library of code someone else wrote, so that the complier knows what any function used actually does/means!

Linux commands

cd = change directory aka folder
cp = copy
ls = list
mkdir = make new directory aka folder
mv = move OR rename
rm = others
rmdir = remove directory aka folder 
.. = go back to the parent/previous directory aka folder
../.. = go back to the grandparent directory aka folder
cd (then press enter) = will take you all the way back to main default directory aka folder 

There’s nothing you can’t do in the command line that you can do in the GUI (the left most tab) CLI is much faster too

C data types

bool = yes/true no/false questions
char = single character
float = a number with a decimal point aka 1.7
double = a number with MORE numbers after the decimal point aka 1.79586455
int = integers aka numbers
long = integers aka larger numbers (64 bit)
string = words
void = function with no input

cs50 library of functions

The cs50 library exists when you just want to get user inputs

get_~blank~ from the user
get_char
get_float 
get_double 
get_int 
get_long 
get_string

format codes
%c = char
%f = float
%i = int
%li = long
%s = string

Operators

+
-
*
/
% = remainder operator

Variables, syntactic sugar

Scratch
orange block “set counter to ____” is a variable 

C
We need the data type in front of the syntax
int counter = 0;

Scratch
orange block “change counter by ____” is a variable 
C
This works because the variable counter is already established
counter = counter +1; 

//syntactic sugar saying the same thing with fewer characters
counter += 1;                       
counter++;
++ or - - only works with the value understood as 1



Calculator.c
The keyword code makes a new file automatically 
code calculator.c                                a new C file has been created 
8 bits = can count to 256 28
32 bits can count to roughly 4 billion 232
An int is 32 bits
BUT because it counts equal negative numbers, anything beyond 2 billion won’t work 
#include <cs50.h>
#include <stdio.h>
int main(void)   
 
{
    int x = get_int("x: ");
    int y = get_int("y: ");
    printf("%i\n", x + y);
}
{
    long x = get_long("x: ");
    long y = get_long("y: ");
    printf("%li\n", x + y);
}
 
Only the data type long can handle calculations above 2 billion positive or negative
A long is 64 bits and can count to roughly 8 billion 264 

Conditionals

Scratch
A yellow block aka conditional: If x < y then
A blue block aka function: Say x is less than y
C
if (x < y) {
    printf("x is less than y\n");
}
When if is used. The () parenthesis are a boolean expression, a yes/true no/false question

Scratch
a yellow block aka conditional: if x < y then
A blue block aka function: say x is less than y
else if x > y then
A blue block aka function: say x is greater than y
else if x = y
A blue block aka function: say x is equal to y
C
if (x < y) {
    printf{"x is less than y\n"};
} else if (x > y) {
    printf("x is greater than y\n");
} else (x == y) {
    printf("x is equal to y\n");
}
$ code points.c more conditionals

const = variable won’t change no matter what. Program more defensively. 


in C const variables are CAPITALIZED
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    const int MINE = 2;
    int points = get_int("How many points did you lose? ");

    if (points < MINE) {
        printf("You lost fewer points than me.\n");
    } else if (points > MINE) {
        printf("You lost more points than me.\n");
    } else {
        printf("You lost the same number of points as me.\n");
    }
}

Even or ODD using % aka remainder 
#include <cs50.h>
#include <stdio.h>
int main(void)
{
    int n = get_int("n: ");

    if (n % 2 == 0)                             == means strictly equals
{                                          
        printf("even\n");
}
else 
{
    printf("odd\n");
}
} 


Logical Operators: AND (&&), OR (||), NOT (!)
Char uses single quotes. The question is a string not a char.
#include <cs50.h>
#include <stdio.h>

int main(void) 
{
    char c = get_char("Do you agree? ");

    if (c == 'y' || c == 'Y') {
        printf("Agreed.\n");
    } else (c == 'n' || c == 'N') {
        printf("Not agreed.\n");
    }
}

Loops aka while for 

Copy and pasting syntax are likely a signal you’re doing something wrong
#include <cs50.h>
#include <stdio.h>
int main(void) 
{
    printf("meow\n");
    printf("meow\n");
    printf("meow\n");
}

Scratch
yellow block aka loop: forever
blue block aka function: say meow
C
while (true) {}
When while is used. The () are a boolean expression, a yes/true no/false question
#include <cs50.h>
#include <stdio.h>

int main(void) 
{
while (true)
{
    printf("meow\n");
}}
Scratch
yellow block aka loop: repeat 3 times
blue block aka function: say meow
C
 
int i = 0;    initialize the variable
while (i < 3)
{
    printf("meow\n");
    i++;
}

int i = 1;    initialize the variable
while (i <= 3)
{
    printf("meow\n");
    i++;
}

 
i is the standard variable for counting in C
A for loop
int main(void) 
{           
    for (int i = 0; i < 3; i++) {initialize the variable; conditional; increment 
   printf("meow\n");
}}

Creating new functions in C
meow() is a function I made. 

Right now, it requires the data type void bc it does not return anything
AND it has no input value which also requires the keyword void in the ()

void meow(void) {…}  proper syntax
Meow.c
The cascade aka the order matters, the fn statement must be on top of the fn call
#include <stdio.h>

int main(void)  main is preferred at the top of your file
{
    for (int i = 0; i < 3; i++) 
    {
        meow();                     the fn call inserted inside the loop is 1st
    }
} 
void is required & states: there is no return and/or input in meow()
void meow(void)                                         the fn statement is 2nd 
{                                             
    printf("meow\n"); 
}  
This code won’t run & will flag error bc the fn call is before the fn statement

The solution is a “prototype”
void meow(void);     
the syntax is:
return-value-type title-of-fn (input);

This shows a fn is down the cascade. In C the order matters, unlike JS
#include <stdio.h>

void meow(void);    this is the prototype; declaring the fn before it is called

int main(void) 
{
    for (int i = 0; i < 3; i++) 
    { 
        meow(); 
    }
}

void meow(void)
{
    printf("meow\n"); 
}

If you want the meow fn to be programable a set # of times
#include <cs50.h>
#include <stdio.h>

void meow(int n);   this is the prototype; declaring the fn before it is called

int main(void)                     This is considered better code; bc its shorter
{
     int num = get_int("number of meows please: ");
     meow(num);  the fn call. 
}

void meow(int n)                the fn statement with int n being the input now 
{
    for (int i = 0; i < n; i++) 
    {
        printf("meow\n");
    }
}



Discount.c Making a fn that return values
float = a number with a single decimal point aka 1.7
Discount a product using a percentage. A sale going on.
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    float regular = get_float("Regular Price: ");  string & get user entered data
    float sale = regular * .85;
    printf("Sale Price: %.2f\n", sale);      %.2f shows 2 decimals & is the float 
}                                                                     placeholder
When int main(void) is called:
1.	data type float variable regular prompt user to enter “Regular Price: ” & gets entered data
2.	sale is set to the variable regular user entered value * .85
3.	Then print out “Sale Price: ”, and variable sale results
4.	BUT use the placeholder format code %.2f giving results 2 decimal slots

discount1.c: Returning a value from a fn
#include <cs50.h>                  Return value
#include <stdio.h>
 
float discount(float price);                                          prototype 

int main(void)
{
    float regular = get_float("Regular Price: ");
    float sale = discount(regular);
    printf("Sale Price: %.2f\n", sale);
}
Discount price
float discount(float price)   float is the data type price is the parameter title
{
    return price * .85;
}
When called:
1.	data type float variable regular prompt user to enter “Regular Price: ” & gets entered data
2.	sale is set to call the fn discount(). That parameter retrieves user entered data from the variable regular. That data then goes inside the statement of fn discount() and is used inside ITS para titled float price, that then runs & gets returned after being * by .85
3.	Then printf runs “Sale Price: ”, and variable sale results
4.	BUT use the placeholder format code %.2f. Giving it 2 decimal slots
discount2.c: Now there are 2 parameters and I can manually set the sale % each call
#include <cs50.h>
#include <stdio.h>
Return value, multiple arguments
float discount(float price, int percentage);                          prototype

int main(void)
{
    float regular = get_float("Regular Price: ");
    int percent_off = get_int("Percent Off: ");              int = a whole number
    float sale = discount(regular, percent_off);
    printf("Sale Price: %.2f\n", sale); 
}
Discount price
float discount(float price, int percentage)
{
    return price * (100 - percentage) / 100;
}
When called:
1.	data type float variable regular prompt user to enter “Regular Price: ” & gets entered data
2.	Then percent_off prompts user to enter “Percent Off: ” & gets user entered data
3.	sale is set to call the fn discount() those parameters retrieve user entered data from the variable regular & percent_off. That data then goes inside statement side of fn discount()  and is used inside ITS own paras titled float price & int percentage, that then runs & gets returned after regular * (100 - percent_off) / 100
4.	Then printf runs “Sale Price: ”, and variable sale results
5.	BUT use the placeholder format code %.2f. Giving it 2 decimal slots

Mario.c

Print 4 ?’s
This is the lazy way to print 4 question marks “?”
#include <stdio.h>
int main(void)
{
    printf("????\n");
}
REPL ????
This for loop way works but leaves an unwanted $
#include <stdio.h>
int main(void)
{
    for (int i = 0; i < 4; i++) 
    {
        printf("?");
    }
}
REPL ????$

Here we have exactly what I want, BUT there’s no variable to set the amount to anything
int main(void)
{
    for (int i = 0; i < 4; i++) 
    {                     
        printf("?");
    }                         
    printf("\n");
}
REPL ????

Validating User Input do while loop
Now we want to ask the user how many ? to print
A do while loop runs the code/loop first. THEN checks the condition (boolean expression)
#include <cs50.h>
#include <stdio.h>   
int main(void)
{            run statement/question 1st THEN check condition aka do; while 
    int n;         this is the opposite of normal conditional loops
    do                                                         
    { 
        n = get_int("Width: ");    do this FIRST. Ask the width & get user data 
    }  
    while (n < 1);                   THEN check the condition last; while n < 1 
   
    for (int i = 0; i < n; i++)     Move to the 2nd loop ONLY AFTER n > 1 happens
    {
        printf("?");
    }
    printf("\n");
} 
REPL Width: whatever the user enters for n as long as its greater than 1
The do runs 1st (that’s what makes it special).
Run the code: user gets prompt string "Width: " and retrieve user entered data
That code will continue to loop until the condition of n = > 1 is met

So, if the user enters 0, the do while loop continues to run
If the user enters -100, the do while loop still continues to run

Only when the user enters a number > 1 does it stop

The question/statement gets run 1st
THEN the conditional is run

Validating User Input: Nesting

I want to make a block shape out of #’s 
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Size: ");
    } 
    while (n < 1);

    for (int i = 0; i < n; i++) 
    {
        printf("#\n");
    }
}

REPL Size: 3                I’ve made a column of # instead of a brick type shape
#
#
#         


Putting the new line of code out after the loop gives me a row
#include <cs50.h>
#include <stdio.h>
int main(void)
{
    int n;
    do
    {
        n = get_int("Size: ");
    } 
    while (n < 1);

    for (int i = 0; i < n; i++) 
    {
        printf("#");
    }
    printf("\n");
}
REPL Size: 3               I’ve made a row now of # instead of a brick type shape
###

Putting it all together
int main(void)
{
    int n;
    do
    {
        n = get_int("Size: ");
    } 
    while (n < 1);

    // For each row
    for (int i = 0; i < n; i++) 
    {
        // For each column
        for (int j = 0; j < n; j++)            j is used if i is already in use
        {
            // Print a brick
            printf("#");
        }
        // Move down to next row
        printf("\n");
    }  
} 
REPL Size: 3   ###           the code runs down 3 times then repeats 2 more times
               ###                                   creating the desired pattern
               ###

Floating Point Imprecision
The fact that although billions of numbers can be used; there is still a limit. The computer is unable to represent all possible real numbers; and that’s called Floating Point Imprecision

float 32bits = a number with up to 6 decimal points at the end aka 1.654321
double 64bits = a number with MORE numbers after the decimal point aka 1.795864555435431
#include <cs50.h>
#include <stdio.h>

int main(void)   
{
    // Prompt user for x
    float x = get_float("x: ");

    // Prompt user for y
    float y = get_float("y: ");

    // Divide x by y
    float z = x / y;

    // perform division
    printf("%.50f\n", z);              %.50f = I want 50 points after the decimal 
}                                      %f = normally you get 6 digits after the .
REPL 2/3 = .6666667513515456135153615513213                   this is incorrect

Integer Overflow
In C when dividing an integer by an integer, you can only get back an integer, floating point values don’t work; everything after the decimal gets thrown away aka Truncation
int main(void)   
{
    // Prompt user for x
    int x = get_int("x: ");

    // Prompt user for y
    int y = get_int("y: ");

    // Divide x by y
    float z = x / y;          you can't divide an int by an int and get a decimal 

    // perform division
    printf("%.20f\n", z);
} REPL 2/3 = 0.000000000000000000000 
REPL 4/3 = 1.00000000000000000                the answer should be 1.33333333 etc

Casting
Converting to a float using casting, only 1 (float) is needed
#include <cs50.h>
#include <stdio.h>

int main(void)   
{
    // Prompt user for x
    int x = get_int("x: ");

    // Prompt user for y
    int y = get_int("y: ");

    // Divide x by y
    float z = (float) x / (float) y;                 casting on the variables x y 

    // perform division
    printf("%.20f\n", z);
}
REPL 2/3 = 0.6666666666666666667
REPL 4/3 = 1.3333333333333333334

Jan 1st 1970 was the epoch for computers time counting (they use seconds), on Jan 19th 2038 32-bit computers will run out of bits to count and think its dec 13th 1901


Type conversion
Telling the computer to treat an integer as though it’s a floating-point value
#include <cs50.h>
#include <stdio.h>

int main(void) 
{
    float amount = get_float("Dollar amount: ");
    int pennies = amount * 100;
    printf("Pennies: %i\n", pennies);
}
REPL Dollar amount: 99 = 99 pennies
Dollar amount: 1.23 = 123 pennies
Dollar amount: 4.20 = 419 pennies ???? ERROR




The solution
#include <cs50.h>
#include <math.h>                           adding the library header of math.h
#include <stdio.h>
int main(void) 
{
    float amount = get_float("Dollar amount: ");
    int pennies = round(amount * 100);                       the method round()
    printf("Pennies: %i\n", pennies);
}
REPL Dollar amount: 99 = 99 pennies
Dollar amount: 1.23 = 123 pennies 
Dollar amount: 4.20 = 420 pennies

There is always a solution to coding problems
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

