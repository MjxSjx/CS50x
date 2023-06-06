# Week 2 – Arrays

### Introduction
We use C but in reality, the only thing the computer understands is Binary (0-1)

## make
Up until now we’ve been using “make” as a way to compile (format) our code into action
```
#include <stdio.h>

int main(void)
{
    printf("hello, world\n");
}
$
$ cd hello                              // the folder name is hello
hello/ $ make hello                     // the file name is hello
hello/ $ ./hello
hello, world
```
It turns out that make doesn’t actually compile, it does help MAKE programs run, but make is a utility that makes it easier to actually compile code by using an actual compiler 

+ Complier: a program that coverts source code (what we write) into machine code (aka binary)
Make runs a command, automatically in C called “clang”  

## clang = C language aka THE complier
Using the compiler manually with clang: EDIT only works with barebones syntax no get_ fns
```
$ cd hello                                // the folder name is hello
hello/ $ clang hello.c                    // notice .c is called 
list all available files please (there will be 2)
hello/ $ ls                      
a.out* hello.c                   // 1. a.out = assembler output & 2. hello.c
hello/ $ ./a.out 
hello, world                     // the program hello.c has now run through a.out
```
### a.out
is the default file name for a program you compile yourself, only used with clang
a.out is a dumb name so, to change the it we need to use Command Line Arguments 

### Command Line Arguments (CLA)
CLA: are words or numbers that you type at your prompt after the name of a program that then influences/modifies its behavior in some way they add a lot of syntax and it only gets worse as things progress. -o lets you specify explicitly what you want the outputted program to be called
```
hello/ $ clang -o hello hello.c -lcs50 // -lcs50 is for fn’s like get_string
```
Now the program will be titled hello.c. Thankfully, we have “make” to avoid all this
## Compiling
It is worth the time to understand what is actually happening when “make” is used, how much automation is going on. So that when you run these commands it’s not magic. You understand the process from the bottom up when you’re compiling

It turns out when you’re taking your source code and changing it into binary, then back again aka “compiling your code with make”, there are actually 4 steps happening


1. Pre-processing = finds the special characters like #include then copy and pastes their data 
2. Compiling = takes your source code and converts it into “assembling language” aka chunks of archaic words and characters
3. Assembling = the assembly language is then finally converted into binary (0’s and 1’s)
All told I’m using 3 codes
1.	My code aka what I’ve written
2.	The header file #include<cs50.h> which is actually cs50.c but that’s a long story
3.	The other header file #include<stdio.h> which too is actually stdio.c
4. Linking = links all the codes (all 3) together into one file so it can compile properly

## Debugging
Bugs in code happen at all skill levels. There are however techniques & tools that coders use
	
### buggy.c
Here I want to make a mario brick that is 3 # tall. But my code has a bug, its 4 tall
```
#include <stdio.h>

int main(void)
{
    for(i= 0 i <=3; i++)
    {
        printf("#/n");
    }
}
#
#
#
#
```
\ = back slash, its leaning back                                / = slash, its leaning forward aka forward slash



## printf
printf(“”); is one of the best tools. It looks inside values of variables. Meaning it will show you what a fn is actually doing. You can “see inside of the computers mind” by just printing stuff out.
```
#include <stdio.h>

int main(void)
{
    for(i= 0 i <=3; i++)
    {
        printf("i is %i/n, i");               // written for diagnostic help
        printf("#/n");
    }
}
 
i is 0
#
i is 1
#
i is 2
#
i is 3
# 
```
The bug is; computers start counting at 0. Either drop <= for < or start i at 1

## debug50
Is a command that initiates a program called a debugger. debug50 is just the command to start it
```
#include <stdio.h>

int main(void)
{
    for (int i= 0; i <= 3; i++)
    {
        printf("#\n");
    }
}

$ make buggy                                                    compiling buggy
$ debug50 ./buggy   debug50 followed by ./ then the file your debugging’s title 
```
debug50 is automating the process of starting VS Code’s built-in debugger when using C
The debugger walks through the code step-by-step

You need to click the utmost left of VS Code. Further than the #’s shown for each line. There is a little dot that highlights when hovered over. Select 1 dot to “set a breakpoint”; breakpoints are the line you want the debugger to stop running at

### Step Over
Step Over is a button in the center at the top of the VS Code screen when using debug50
Step Over lets you run 1 line at a time. When you press the button or use the hotkey ALT+F10
Your logic literally moves 1 fn or 1 line down the script at a time, super neat

### Rubber Duck Debugging
A genuine technique is talking about the code with someone else. If no one else exists the point is talking to yourself calmly about your code step-by-step or talking to a rubber ducky

### get_negative_int
get_negative_int is not a fn in any header library, so we have to make it ourselves. It works but isn’t giving the correct response. In reality the while conditional needs to be n > 0
```
#include <cs50.h>
#include <stdio.h>

int get_negative_int(void);                                           prototype

int main(void)
{
    int i = get_negative_int();    the line we are running debug50 Step Over on
    printf("%i\n", i);    
}

int get_negative_int(void)
{
    int n;
    do
    {
        n = get_int("Negative Integer: ");
        printf("n is %i\n" , n); // written for diagnostic help but doesn't help
    } 
    while (n < 0);
    return n;
}
```

### Step Into
Stepping Over didn’t help the problem, so let’s Step Into it. Step Into means to jump into the specific fn in question based off the focal breakpoint. Step Into “lets you go into fn you wrote
```
int get_negative_int(void)                    the fn Step Into is connecting to
{
    int n;
    do
    {
        n = get_int("Negative Integer: ");   this is the line Step Into runs on
        printf("n is %i\n" , n); // written for diagnostic help but doesn't help
    } 
    while (n < 0);
    return n;
}
```

### Types
Refers to data types that C uses: int, long, float, double, bool, char, string etc. What is actually happening when we manipulate bits as in int vs a char or a string for example. 

* 1 byte = 8 bits

 
* bool & char = 1 byte
* float & int = 4 bytes
* double & long = 8 bytes
* String = ? its variable how many bytes 


## Memory
Random Access Memory (RAM). Data takes up bytes storing memory even if it’s just temporary to execute things.

Picture a grid; char would use 1 byte of data in RAM. For examples sake it would take up 1 unit in the upmost top left of RAM’s storage. 

### scores.c
Adding the medium score using C. The real answer is 59.3333333333333333333333333333
```
#include <stdio.h>

int main(void)
{
    int score1 = 72; = 4 bytes aka 32 bits
    int score2 = 73; = 4 bytes aka 32 bits
    int score3 = 33; = 4 bytes aka 32 bits 

    printf("Average: %i\n", (score1 + score2 + score3) / 3);
}
REPL is 59
    // To make a float work and not chop off the remainder 3 needs to be 3.0
    printf("Average: %f\n", (score1 + score2 + score3) / 3.0);
REPL is 59.333333
```
And what happens if I want to add more scores, I keep adding variables which is ugly and slow 



## Arrays
An array is type of data that allows you to store multiple values of the same type back-to-back
`int scores[3];`
this is declaring there is an int-based array of size 3. AKA an array with 3 integers stored inside

 **Arrays are ALWAYS zero indexed; meaning they start counting @ 0**

Just like JS but Python starts at 1 oddly enough. 
Here I’m making the code prompt each score total to the user, making code have more usability
```
#include <cs50.h>                   notice a new library is added bc of get_int
#include <stdio.h>

int main(void)
{
    int scores[3]; // an array of 3 integers titled scores

    scores[0] = get_int("Score: "); // each value is stored in the same variable
    scores[1] = get_int("Score: "); // only the array indexes are different
    scores[2] = get_int("Score: "); 

    printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / 3.0);
}
```
Now I’m using a for loop to get rid of excess
```
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int scores[n]; // an array of 3 integers titled scores

    for (int i = 0; i < n; i++)   for loops are for specific amount of iterations
    {
        scores[i] = get_int("Score: "); // variable[i] that way i iterates scores
    }
    printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / 3.0);
}
```
Now i prompt the user to input how many scores they want to check the median of dynamically
```
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = get_int("How many scores? "); // this prompts 1st bc of the cascade
    int scores[n]; // an array of user inputted amount of scores

    for (int i = 0; i < n; i++)
    { 
        scores[i] = get_int("Score: "); // variable[i] that way i iterates scores
    }
    printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / 3.0);
}
```
Array of char; aka characters/letters/symbols

David asked how can we use variables c1, c2, c3 to say ‘HI!’
```
#include <stdio.h>       this is the monster I came up with

int main(void)
{
    char c1 = 'H';
    char c2 = 'I';
    char c3 = '!';

    for (int i =0; i < 1; i++)    for loops are for specific amount of iterations
    {
    printf("%c", c1);
    printf("%c", c2);
    printf("%c", c3);
    }
    printf("\n");
}
REPL HI!
```
This is David's example, i didn't know you could use placeholders back-to-back
```
#include <stdio.h>

int main(void)
{
    char c1 = 'H';
    char c2 = 'I';
    char c3 = '!';

    printf("%c%c%c\n", c1, c2, c3);                              new info to me
}
```
now we see ASCII values of each char implicitly aka on accident
```
#include <stdio.h>

int main(void)
{
    char c1 = 'H'; // #72 in ASCII
    char c2 = 'I'; // #73 in ASCII
    char c3 = '!'; // #33 in ASCII

    printf("%i %i %i\n", c1, c2, c3);  the placeholder has changed to be an int
}
REPL 72 73 33                                        surprisingly enough it works
```
now we are explicitly wanting the ASCII integers printed of c1 c2 c3
```
#include <stdio.h>

int main(void)
{
    char c1 = 'H'; // #72 in ASCII
    char c2 = 'I'; // #73 in ASCII
    char c3 = '!'; // #33 in ASCII
below I'm “typecasting” (int) aka converting one data type to another 
    printf("%i %i %i\n", (int) c1, (int) c2, (int) c3); placeholder % has to stay
}                                                            i or it doesn’t work
REPL 72 73 33
```

Using a string to print HI!
```
#include <cs50.h>   //data type string requires
#include <stdio.h>

int main(void)
{
    string s = "HI!"; //strings are an array of chars!
    printf("%s\n", s);
}
REPL HI!
```

Using a string to show they're arrays and have indexes
```
#include <cs50.h>   //data type string requires
#include <stdio.h>

int main(void)
{
    string s = "HI!"; //strings are an array of chars!
    printf("%i %i %i\n", s[0], s[1], s[2]); // the power of indexing arrays
}
REPL 72 73 33 // #72 in ASCII = H, #73 = I, #33 = !
```
A string is an array of chars!





## NUL Character /0 aka 00000000 in binary
A “sentinel” character designated for blank spaces, called NUL

There is an invisible divider at the end of strings called NUL that in ASCII is represented as /0
```
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = “HI!”;                            there’s only 3 char indexes here
    printf(“%i %i %i %i\n”, s[0], s[1], s[2] s[3]);   yet I added a 4th %i & char
}
REPL 72 73 33 0                      #72 in ASCII = H, #73 = I, #33 = !, #0 = NUL
```
There is always a NUL at the end of every string which takes up 1 byte. HI! is acutally HI!/0

adding more strings & those too all have invisible NUL char at the end adding 1 byte each string
```
#include <cs50.h>
#include <stdio.h>

int main(void)

{
    string s = “HI!”;
    string t = “BYE!”;
    printf(“%s\n”, s);
    printf(“%s\n”, t);
}
REPL
HI!/0        
BYE!/0        There is an invisible NUL character /0 at the end of every string
```
### length.c
Figuring out what the length of a string is AFTER it has been stored to a variable
```
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("Name: ");                   // prompt user for name

    int i = 0;                // Required starting point for the CPU to work with
    while (name[i] != '\0')       until the user inputted string = char NUL add 1 
    {                                                    to the variable titled i
        i++;
    }
    printf("%i\n", i);                               print the amount i ends with
}
REPL Name: Savhana 7, Name: Lukey 5                     It works and its awesome!
```
Doing the same thing, finding the length of a random string, but making it into a fn just because
```
#include <cs50.h>
#include <stdio.h>

int string_length(string s);                                         // prototype

int main(void)
{
    string name = get_string("Name: ");                   // prompt user for name
    int length = string_length(name);
    printf("%i\n", length);                     print the amount length ends with 
}

int string_length(string s)
{
    int i = 0;                // Required starting point for the CPU to work with
    while (s[i] != '\0')          until the user inputted string = char NUL add 1
    {                                                    to the variable titled i
        i++;
    }
    return i; rather than printing here we return the final total of i to the
} 
fn call that then gets sent as what length equals to & THAT links to printf
```
I understand this one, but I don’t like it. Ironically in the next section there’s a better way than all

### strlen
A fn from a new library header “#include <string.h>” that specifically gets get_string total index
```
#include <cs50.h>
#include <stdio.h>
#include <string.h>  new header that uses strlen();

int main(void)
{
    string name = get_string("Name: "); // prompt user for name
    int length = strlen(name); special fn that auto gets get_string total index
    printf("%i\n", length); // print the amount variable length ends with
}
```
## Manual Pages
Manual.cs50.io

is a website that lists all the C library header files called “manual pages”. They list all fn’s associated with C and the header file needed. 

It also has a search bar at the top. There’s a lot, like ALOT
### ASCII
https://asciichart.com

is a website that lists the 1st 128 ASCII chart items in decimal. 32 for example SP is space

### string.c
Only strings are accompanied by char nul /0 at the end

a simple user prompt input, REPL same user prompt input out
```
#include <cs50.h>
#include <stdio.h>
#include <string.h>  new header that uses strlen();

int main(void)
{
    string s = get_string("Input: "); // prompt user for a string
    printf("Output:"); // literally print the word Output
    printf("%s\n", s); // paste input data in same print but after the 1st one
}
```
Ok, how would you do the above without the placeholder printf???

You’d likely use some type of while or for loop to iterate overall the characters in variable s
```
#include <cs50.h>
#include <stdio.h>
#include <string.h>>  new header that uses strlen();

int main(void)
{
    string s = get_string("Input:  "); // prompt user for a string
    printf("Output: "); // literally print the word Output
    for (int i =0; i < strlen(s); i++) when i is < s total char indexed; +1 to i
    {
        printf("%c", s[i]); // print each char of s, aka print s[i]
    }
    printf("\n"); // no new line until everything is finished and we reach here
}
```
the code above is good but "suboptimal" bc it has to ask the string index total every iteration
```
#include <cs50.h>
#include <stdio.h>
#include <string.h>  new header that uses strlen();

int main(void)
{
    string s = get_string("Input:  "); // prompt user for a string
    printf("Output: "); // literally print the word Output
    int length = strlen(s); // a defined variable of s’s char indexed

    for (int i =0; i < length; i++) // now s[i] is already defined & not checked 
    {
        printf("%c", s[i]); // print each char of s, aka print s[i]
    }
    printf("\n"); // no new line until everything is finished and we reach here
}
```
defining length outside of the loop means it doesn’t get checked every iteration, 
then plugging it in to the loop as a defined variable is optimal



### for loops let you declare multiple variables at once

This is the IDEAL version
```
#include <cs50.h>
#include <stdio.h>
#include <string.h>  new header that uses strlen();

int main(void)
{
    string s = get_string("Input:  "); // prompt user for a string
    printf("Output: "); // literally print the word Output 

    for (int i = 0, n = strlen(s); i < n; i++) // s[i] is defined inside the loop
    {
        printf("%c", s[i]); // print each char of s, aka print s[i]
    }
    printf("\n"); // no new line until everything is finished and we reach here
}
```





### uppercase.c
```
#include <cs50.h>
#include <stdio.h>
#include <string.h>>   new header that uses strlen();
int main(void) 
{
    string s = get_string("Before: "); // prompt user for a string
    printf("After:  ");// literally print the word After 
    for (int i = 0, n = strlen(s); i < n; i++) // s[i] is defined inside the loop
    {// 'a' = 97 && 'z' = 122 in ASCII
        if (s[i] >= 'a' && s[i] <= 'z') //are the words current letter lowercase?
        { // if is correct bc this is a boolean conditional
            printf("%c", s[i] - 32); // if it is remove 32 digits from its ASCII     
        }                              # making it the same letter but uppercase
        else
        {
            printf("%c", s[i]);  // else print it bc its already uppercase
        }
    }
    printf("\n"); // no new line until everything is finished and we reach here
}
```
This is a program that makes all letters uppercase, by checking if they’re lower case first


### islower
There is a library header that already does what we just did making things easier Manual.cs50.io
```
#include <cs50.h>
#include <ctype.h>  new header that uses islower();
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: "); // prompt user for a string
    printf("After:  "); // literally print the word After  
    for (int i = 0, n = strlen(s); i < n; i++) // s[i] is defined inside the loop
    {
        if (islower(s[i])) // is the words current letter lowercase?
        { 
            printf("%c", s[i] - 32); // if it is remove 32 digits from its ASCII
        }                              # making it the same letter but uppercase
        else
        {
            printf("%c", s[i]); // else print it bc its already uppercase
        }
    }
    printf("\n"); // no new line until everything is finished and we reach here
} 
```
Inside a boolean expression 0 represents false and any other # represents true

### toupper
Adding a prebuilt fn to shorten syntax 
```
#include <cs50.h>
#include <ctype.h>  new header that uses toupper();
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: "); // prompt user for a string
    printf("After:  "); // literally print the word After  
    for (int i = 0, n = strlen(s); i < n; i++) // s[i] is defined inside the loop
    {
        printf("%c", toupper(s[i]));  // print uppercased using this fn
    }
    printf("\n"); // no new line until everything is finished and we reach here
}
```
 ## Command-line Arguments
The void in main
```
int main(void)         the void here in main specifically = none of the programs that 
{                                     we’ve written inside here {} will take CLAs

}
````
Aka the main fn we use in C as the boilerplate. The void in THIS SPECIFIC input for main has been saying; none of the programs that we’ve written will take command line arguments

normally (void) in a fn means that fn does not take inputs aka parameters/arguments
` int get_cents(void)             void is saying I take no inputs!! In this fn`

### int argc and string argv
It turns out that the () in main is the slot that allows CLA’s
```
int main(int argc, string argv[])
{
    if (argc == 2) // if user CLA word count is 2 do this… else do that…
}
```
how you specify that your program DOES take CLAs aka words after the command in terminal

int argc = argument count. An integer that stores how many words the human types at da prompt

string argv = argument vector. An array that stores all of the words the human types at da prompt 

Only strings are accompanied by char nul /0 at the end. This is how argv&c can tell strings apart in sentences, ALL strings end in a char NUL /0
Take user entered data that’s entered AT the command line aka user typing in the terminal 
```
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    printf("hello, %s\n", argv[1]); // 2nd string is plugged in the rest ignored 
}
REPL:
testing/ $ ./testing        // 1st string aka argv[0] REPL (null)  
hello, (null)               
testing/ $ ./testing Lukey  // the REPL comes from the user CLA input 2nd string
hello, Lukey                
```

## Exit Status
main can signal to the user whether something was successful or not via mains return value
```
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if(argc != 2) // if user CLA word count not 2 run this statement
    {
        printf("Missing command-line argument\n");
        return 1;                    // return 1 means something went wrong ERROR
    }                                      // YET in bool values 1 represent true
    printf("hello, %s\n", argv[1]);
    return 0;                                 // return 0 means everything worked 
}                                         // YET IN Bool values 0 represent false
```
### Readability
The more descriptive and detailed text is, the more mature as audience it is intended for
Next problem set is counting how many words are used to rate what grade level they are for??

### Cryptography
Scrambling information in such a way that you can hide the contents of a message from someone who might otherwise intercept it. Aka make it difficult to interpret “encrypt it” for someone to decrypt it. A = B, B = C, C = D etc that is an algorithm and the key is how you solve it.

There is always a solution to coding problems
