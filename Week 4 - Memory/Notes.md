# Week 4 – Memory

## Memory
The amount of data we can use is limited to the amount of memory we have available. A photo can be zoomed in only to the limit of which the file contains, after a certain point, we’ve simply run out of data to continue zooming in
Cs50.ly/art a website for a google spreadsheet that represents how computers display images with pixels 
# RGB
Red, Green, Blue. A way to describe specific colors aka a notation for programs that read color information. Each letter represents a range from 0 (black) to 255 (white). Adjusting RGB values is a simple way of defining specific colors

# Hexadecimal
0 1 2 3 4 5 6 7 8 9 A B C D E F = hexadecimal is called “base-16” (#16) decimal: “base-9” (#9) binary: “base-1” (#1)

A way to describe specific colors aka a notation for programs that read color information using “#” and then 3 to 6 digits representing color information. Think of your web development course, you used hexadecimals to select colors or explain what specific color, a color was 

72 73 33 in ASCII represents Hi!
But #727333 in hexadecimal it represents a yellowish color

## Memory Addresses
Funny enough hexadecimal is how memory bytes are counted but a problem can arise as many digits looks like simple binary information. The way programmers have worked around this, is by writing hexadecimal for memory addresses as such 0x___. 0x10 = 16; 24 = 0x18
```
**because it is to the 16th power Hexadecimal uses less memory to store data**

The number 3 in hexadecimal is represented by the number 0x3 
The number 10 is hexadecimal is represented by the letter 0xA
The number 15 is hexadecimal is represented by the letter 0xF
The number 16 in hexadecimal is represented by the numbers 0x10
The number 17 in hexadecimal is represented by the numbers 0x11
The number 255 in hexadecimal is represented by the letters 0xFF

0x0 | 0x1 | 0x2 | 0x3 | 0x4 | 0x5 | 0x6 | 0x7
0x8 | 0x9 | 0xA | 0xB | 0xC | 0xD | 0xE | 0xF
0x10 | 0x11 | 0x12 | 0x13 | 0x14 | 0x15 | 0x16 | 0x17
0x18 | 0x19 | 0x1A | 0x1B | 0x1C | 0x1D | 0x1E | 0x1F
```

### address.c
Data Type int = 4 bytes aka 32 bits
```
#include <stdio.h>

int main(void)
{
    int n = 50;
    printf("%i\n", n);
}
REPL 50
```
The point of this simple program is to demonstrate that the REPL has a location that can be found and takes up 4 bytes of memory. Using hexadecimal, it is located at 0x123 possibly

## Pointers in C
Pointers are a variable that stores the address/location of some value. The specific byte(s) in which that variable, value is stored  
```
int n = 50;
(Operators are: & + - * / etc)
int *p = &n;
```
A single & operator = “Find the Address of ______ variable” aka find n address
 
A single * operator followed by & = Store that address to this new ______ variable” aka declare a pointer of & address with p
### Address Of
```
#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%p\n", p); %p = placeholder for pointers
}
REPL 0x7ffda3b3e7dc     the address of the REPL in my PC's memory in hexadecimal!

syntactic sugar version
A faster way to get the same result
int main(void)

{
    int n = 50;
    printf("%p\n", &n); find the address of n and print it plz
}
REPL 0x7ffc78eb560c every time i REPL the location moved. The reason is security
```
## Dereference Operator = Go to that address/location
There is 1 other use of the * operator when its by itself. 
A single * operator = go to that address
```
#include <stdio.h>

int main(void)

{
    int n = 50;
    int *p = &n;
    printf("%p\n", p); //  %p = placeholder for pointers
    printf("%i\n", *p); // *p = find that location then print what it contains
}
REPL 0x7ffcc0f251dc
50
```
### Visualizing Pointers
A worthwhile fact is pointers take up 8 bytes of memory because they are usable with ALL data types. Pointers used to be 1 byte, then 4, and now 8. 8 is enough for a long while as 64 bits can count to over 100 quadrillion, that’s A LOT of numbers to be able to store into 

### Assignment Operator
If you reference a variable that has a pointer on it. It does not make an additional pointer

### Strings in Memory
```
// Strings in Memory

Strings = an array of chars
string s = "HI!"; 
// per last week strings are an array of chars, that are of course, indexed
// H = s[0], I = s[1], ! = s[2], \0 = s[3]

// well turns out each char has a memory address/location that’s already est.
// H = 0x123, I = 0x124, ! = 0x125, \0 = 0x126 per say 

// AND that the string s is just a pointer to the memory 
// meaning that whatever location the 1st char H starts at. Is also the location of string s
// so, it turns out that 
string s = "HI!"; 
// is acutally the same as
char *s = "HI!";     bc to the memory variables are just pointers
```
### char *
Strictly speaking C doesn’t have a string data type, we’ve been using helper header files like #include <cs50.h>. It does have %s because string is programming terminology 
```
// char * 
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = "HI!";
    printf("%s\n", s);
}
--------------------------------------------------
#include <stdio.h> // cs50.h is gone so data type string won’t work

int main(void)
{
    char *s = "HI!";
    printf("%s\n", s);
}
--------------------------------------------------
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = "HI!";
    char *p = &s[0];
    printf("%p\n", p); // I’m asking for the location of the char H  
    printf("%p\n", s); // I’m asking for the location of the variable s
}
REPL 0x564469ba2004 // they are identical as they should be bc variables
     0x564469ba2004 // are just pointers of the 1st char with strings in memory 
```
```
#include <stdio.h>

int main(void)
{
    char *s = "HI!";
    printf("%p\n", s); // I’m asking for the location of the variable s
    printf("%p\n", &s[0]); // I’m asking for the location of the char H
    printf("%p\n", &s[1]); // I’m asking for the location of the char I
    printf("%p\n", &s[2]); // I’m asking for the location of the char !
    printf("%p\n", &s[3]); // I’m asking for the location of the char null aka \0
}
REPL 0x561f25207004 // the location of the variable s
     0x561f25207004 // the location of the char H
     0x561f25207005 // the location of the char I
     0x561f25207006 // the location of the char !
     0x561f25207007 // the location of the char null aka \0
// All neatly in a row in memory incremented 1 slot at a time 
```
A single & operator = Find the Address

A single * operator = go to/point that address aka dereference 

A single * operator followed by & = Store that address 
```
typedef struct // data structures. Creating my own data type
{
    string name;
    string number;
}
person;
// this is one line of what the header library for #include <cs50.h> has inside 
typedef char *string; // this is creating string as a data type for usage
```
## Pointer Arithmetic & using the dereference operator
Strings in C are only allowed to be used with double quotes. C handles things in specific manners when double quotes are used and interrupts differently
```
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = "HI!";
    printf("%c\n", s[0]);
    printf("%c\n", s[1]);
    printf("%c\n", s[2]);
}
REPL
H
I
!
--------------------------------------------------
#include <stdio.h>

int main(void) // using dereference op and arithmetic together 
{
    char *s = "HI!";
    printf("%s\n", *s); // *s is the address of the 1st char in a string
    printf("%s\n", *(s + 1)); // using arithmetic instead of array indexing
    printf("%s\n", *(s + 2)); // bc we know the memory address 
}
REPL
H
I
!
```
Notice int numbers doesn’t have a * dereference operator yet, I can use * when printing
```
#include <stdio.h>

int main(void) // using dereference op and arithmetic together
{
    int numbers[] = {4, 6, 8, 2, 7, 5, 0}; // arrays are pointers  
    printf("%i\n", *numbers);
    printf("%i\n", *(numbers + 1));
    printf("%i\n", *(numbers + 2));
}
REPL
4
6 
8
A single & operator = Find the Address
A single * operator = go to/point that address aka dereference
A single * operator followed by & = Store that address
```
### compare.c
In this example we’re only comparing 2 memory addresses and not the actual array of strings
```
#include <cs50.h>
#include <stdio.h>
int main(void)
{
    string s = get_string("s: ");
    string t = get_string("t: ");

    if (s == t)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}
REPL
s: hi
t: bye
Different
s: hi
t: hi
Different // we are comparing only the pointers and not what’s inside
```

Now we’re comparing the two strings as strings with strcmp()
```
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");
    char *t = get_string("t: ");

    if (strcmp(s, t) == 0)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}
REPL
s: hi
t: hi
Same
```

Now we’re comparing the BASED OFF the memory addresses and pointing to them with %p
```
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char *s = get_string("s: ");
    char *t = get_string("t: ");

    printf("%p\n", s);
    printf("%p\n", t);
}
REPL
0x55612a8596b0
0x55612a8596f0
```
### copy.c
This doesn’t code doesn’t operate correctly because it is copying the memory location
```
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("s: ");

    string t = s;

    if (strlen(t) > 0);
    {
        t[0] = toupper(t[0]);
    }
    printf("s: %s\n", s);
    printf("t: %s\n", t);
}
REPL
s: hi
s: Hi // The memory address was copied that why this isn't working
t: Hi
```
## malloc and free
	
Malloc = memory allocation; its fn to ask the operating system for some number of bytes. It returns the first byte of memory it found for you to use. The issue is you have to keep in mind how much memory you asked for. If you go over you get segmentation blocks, whomp whomp.

Free = Does the opposite. Whenever you done you “free” the memory and give it back. 
```
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    string s = get_string("s: ");
    if (s == NULL) {
        return 1;
    }
    string t = malloc(strlen(s) + 1); // pointing to free space

    strcpy(t, s);

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }
    printf("s: %s\n", s);
    printf("t: %s\n", t);

    free(t); // release memory

    return 0;
}
```

### Valgrind
Is a program that will look at your code and help find memory errors
```
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *x = malloc(3 * sizeof(int));
    x[1] = 72; // The error is starting the index at 1
    x[2] = 73; // you only allocated memory for 3 int bytes
    x[3] = 33; // not 4
}
$ valgrind ./memory

==15910== Invalid write of size 4
==15910==    at 0x109170: main (testing.c:9)
==15910==  Address 0x4bb504c is 0 bytes after a block of size 12 alloc’d 
==15910==    at 0x4848899: malloc (in /usr/vgpreload_memcheck-amd64-linux.so)
==15910==    by 0x109151: main (testing.c:6)
```

### Garbage Values
If you don’t initialize the variable that you’ve defined aka set the calculator to 0 to set a basis point. You will get garbage values in your memory locations when calling the values of those variables/arrays.


## Binky Pointer Fun
These are the 4 things we’ve learned today:
	& operator = Find that address
	* operator = go to/point that address
	malloc() = ask for memory
	free() = free memory

### swap.c
This code swaps by value which is incorrect. We want to swap by reference 
```
#include <stdio.h>

void swap(int a, int b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(x, y);
    printf("x is %i, y is %i\n", x, y);
}

void swap(int a, int b) // swap two values
{
    int tmp = a;
    a = b;
    b = tmp;
}
REPL:
testing/ $ ./testing
x is 1, y is 2 // it’s not working
x is 1, y is 2 // because they're being passed in by value and not reference
```

## Stack and Heap
This is a conversion about scope and the scope of your PC from top to bottom:
•	Machine code 
•	Globals
•	Heap
•	.
•	.
•	.
•	.
•	Stack
Heap overflow: overflow the heap and touch memory you shouldn’t “up there”
Stack overflow: overflow the stack and touch memory you shouldn’t “down there”
Buffer overflow: a chunk of memory being used.

## Pointer Helpers
To fix the scoping and passing by value issue we use &, * to swap by reference
```
#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(&x, &y);
    printf("x is %i, y is %i\n", x, y);
}

void swap(int *a, int *b) // swap two values
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
REPL:
testing/ $ ./testing
x is 1, y is 2
x is 2, y is 1
```

### scanf()
A fn to scan the users keyboard for inputs
```  
#include <stdio.h>

int main(void)
{
    int x; // must always initialize the variable
    printf("x: ");
    scanf("%i", &x); // scanf is reading the users input
    printf("x: %i\n", x);

}
REPL: 
x: 50
x: 50
```

File Input/Output
```
// Saves names and numbers to a CSV file

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{// datatype called FILE that reads actual files on the hard drive or server in C
    FILE *file = fopen("phonebook.csv", "a"); // a fn to open a file in C
                 
    string name = get_string("Name: ");
    string number = get_string("Number: ");

    fprintf(file, "%s,%s\n", name, number); // fprintf print to a file

    fclose(file); // a fn to close a file in C
}
```
This was CS50

There is always a solution to coding problems
