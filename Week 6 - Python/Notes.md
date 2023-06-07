# Week 6 – Python 
Algorithm: A step-by-step set of instructions for solving a problem

## Python
Hello world in C
```
#include <stdio.h>

int main(void)
{
    printf("hello, world\n");
}
```
Hello world in Python 
```
print("hello, world")
```
### Python is less cryptic/archaic than C

## Compilation, Interpretation
In C you must compile, this is not the case in Python. Python uses an “interpreter”

### Hello
This is the only library header file we’ll be using for now. The keywords are from import
```
from cs50 import get_string
```
In the terminal, this will create a python file called hello.py
```
$ code hello.py
``` 
This is what I want run
```
print("hello, world")
```
Again, back in the terminal, this will run the code calling the file to run
```
$ python hello.py
```
In C
```
#include <cs50.h>
#include <stdio.h>
int main(void)
{
    string answer = get_string("What's your name? ");
    printf("hello, %s\n", answer);
}
```
In Python now
```
answer = get_string("What's your name? ")
print("hello, " + answer)
better
print("hello", answer)
best
print(f"hello, {answer}")  {interpolated aka substituted}  f means format string
```
## Data Types in Python
```
There less than in C but some in common:
•	bool
•	float
•	int aka integer  
•	str aka string
•	range aka a set of numbers starting at 0 
•	tuple aka ordered immutable array (, , ,)
•	list aka ordered mutable array [, , ,]
•	set aka unordered array that takes no duplicates {, , ,}
•	dict aka key value pair/object {: , : , :}
```
### Speller
Speller was homework for week 5 in C. It was difficult to write and took tens of hours. Yet in Python it took 60 seconds for David Malan. That’s the difference of higher level languages
```
words = set()

def check(word):
    if word.lower() in words:
        return True
    else:
        return False
def load(dictionary):
    file = open(dictionary, "r")
    for line in file:
        word = line.rstrip()
        words.add(word)
        close(file)
        return True

def size():
    return len(words)

def unload():
    return True
```
### Image Recognition
Using a python library called from PIL, you can import face_recognition as a library someone else wrote. Doing tons of work for you because the library already exists for you to utilize. You don’t have to understand it, just how it works and how to utilize it.

## CS50 Library
```
Includes less than the C library because only a few are needed. 
•	get_float()
•	get_int()
•	get_string()
from cs50 import get_float, get_int, get_string
```

## Conditionals
### Conditionals in C
```
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    if (x < y)
    {
        printf("x is less than y\n")
    }
}
```
### Conditionals in Python
```
if x < y:
    print("x is less than y")
--------------------------------
if x < y:
    print("x is less than y")
elif:  
    print("x is not greater than y")
else:
    print("x is equal to y")
```
## Variables
Variables in C
```
#include <cs50.h>
#include <stdio.h>
int main(void)
{
 int counter = 0;
}
```
### Variables in Python
```
counter = 0

                              python has no ++ syntax
counter +=1
```

## Loops
Loops in C
```
#include <cs50.h>
#include <stdio.h>
int main(void)
{
    int i = 0;
    while (i < 3)
    {
        printf("meow\n");
        i++;
    }
}
```
### Loops in Python
```
i = 0                 while loop
while i < 3:
    print("meow")
    i += 1

for i in range(3):    for loop
    print("hello, world")  

while True:        forever loop
    print("meow")
```
### Calculator
Notice the body is gone, there’s no “main” fn
```
from cs50 import get_int

x = get_int("x: ")
y = get_int("y: ")

print(x + y)

Taking the training wheels off and not using the cs50 library

x = int(input("x: ")) int() is a fn 
y = int(input("y: "))

print(x + y)

asking for 50 decimals places down

x = int(input("x: "))
y = int(input("y: "))
z = x / y

print(f"{z: .50f}") 
```




### Compare
Python can compare strings out of the box
```
s = input("Do you agree? ")
if s == "Y" or s == "y":            or                   if s in ["Y","y"]:
    print("Agreed.")                                         print("Agreed.")
elif s == "N" or s == "n":          or                   elif s in ["N","n"]:
    print("Not agreed.")                                     print("Not agreed.")
```
## Object-Oriented Programming
Python and I’m guessing most all higher-level languages support OOP. C is considered “procedural programming” you write procedures/functions top to bottom, left to right. Well, when you want to change some value. You use a procedure, “you pass something, like a variable into a fn and it hands you back a value.”

It would be nicer, programming-wise, if some data types just had built-in functionality aka methods. OOP have some built-in functionality, so that you can change variables using their own, default built-in function methods.

OOP = is a technique whereby certain types of values, like a string AKA str, have properties/attributes and as mentioned called fn methods built into them.

A Python class is a structure, aka a boilerplate? No matter what a class in an overarching mega object. After all everything in Python is an object.

The official website for ALL the methods str can use to modify the str values. Built-in Types — Python 3.11.2 documentation
s = input("Do you agree? ")
```
if s.lower() in ["y","yes"]: here I’m using a method built into str data types
    print("Agreed.")
elif s.lower() in ["n","no"]: I'm saying retrieve the method lower() & use on s
    print("Not agreed.") 
```
```
s = input("Do you agree? ")
t = s.lower()

if t in ["y","yes"]: 
    print("Agreed.")
elif t in ["n","no"]: 
    print("Not agreed.")
```
### Meow
	Much like C, Python has an order of cascade it needs to follow or things won’t make sense to the interpreter. If we place def below the loop Python can’t read it.
```
def meow:                 def is the keyword for functions
    print("meow")

for i in range(3):
    meow()
```

### Python doesn’t need prototypes though, but a main() fn is recommended
```
def main:             C would require a declaration aka prototype
    for i in range(3):
        meow()

def meow: 
    print("meow")
main()       for this to work calling main() at the end is required
```

### Cleaner
```
def main:
    meow(3)

def meow(n):
    for i in range(n):
        print("meow")
main()
```

### Mario
The OG mario example in Python. REPL is 1 # per line 3 times
```
for i in range(3):
    print("#")
```
Prompting the user for a number with the training wheels of get_int
```
from cs50 import get_int

def main:
    height = get_height()
    for i in range(height):
        print("#")


def get_height():
    while True:                           The Python version of a C do while loop
        n = get_int("Height: ")  cs50 training wheels get_int()
        if n > 0:
            return n               
main()                                        calling main at the end is required
```
Prompting the user for a number without the training wheels of get_int
```
def main:
    height = get_height()
    for i in range(height):
        print("#")


def get_height():
    while True:
        try:                                                      the keyword try
            n = int(input("Height: "))
            if n > 0:
                return n 
        except ValueError:                                     the keyword except
            print("Not an integer")
main() 
```
get_int was doing the try and except loop for us. That’s all it contained. It would force the user to enter an int, else it would re-prompt until the condition was met.

Since Python automatically gives a new line after every loop. How do we make a row of # blocks and not a column?
```
for in in range(4):
    print("#", end = "")       the default hidden setting in python is end = "\n"
print()
```
You manually change the hidden default setting end to a blank string
```
print("#" * 4)  same result
```
### The classic Mario blocks
```
for i in range(3):
    for j in range(3):
        print("#", end = "")
    print()

---------- OR

for i in range(3):
    print("#" * 3)
```

## Scores
Using methods in Python to do print the average of 3 scores, in C it was a lot of work
```
scores = [72, 73, 33]

average = sum(scores) / len(scores)               sum() and len() are int methods
print(f"Average: {average}")
```

Adding user entered data to a scores list that starts blank. Then getting the average num
```
from cs50 import get_int

scores = []                          Python can use empty arrays (this is a list)
for i in range(3):
    score = get_int("Score: ")
    scores.append(score)

average = sum(scores) / len(scores)              
print(f"Average: {average}")
```
### Uppercase
Again, demonstrating the power of OOL and the methods inside data types
```
# Uppercases string all at once

before = input("Before: ")
after = before.upper()
print(f"After:  {after}")
```

### Greet
Python has CLA just like C, int argc string argv. This code prints all user CLA input
```
# Printing command-line arguments

from sys import argv

for i in argv:
    print(i)
```

### Exit Status
```
# Exits with explicit value, importing sys

import sys                 importing the entire sys library not just 1 part of it

if len(sys.argv) != 2:
    print("Missing command-line argument")
    sys.exit(1)                                           like in C 1 means ERROR

print(f"hello, {sys.argv[1]}")
sys.exit(0)                                    like in C 0 means expected results
```

### Search
A program that searches for names form a predefined list
```
# Implements linear search for names using `in`
import sys

names = ["Bill", "Charlie", "Fred", "George", "Ginny", "Percy", "Ron"]

name = input("Name: ")

# Search for name
if name in names:
    print("Found")
    sys.exit(0)

print("Not found")
sys.exit(1)
```
### Phonebook
Using a dict aka object {key: value}
```
# Implements a phone book

from cs50 import get_string

people = {
    "Carter": "+1-617-495-1000",
    "David": "+1-949-468-2750"
}

# Search for name
name = get_string("Name: ")
if name in people:
    print(f"Number: {people[name]}")
```
### Compare
Python can compare strings directly
```
# Compares two strings

# Get two strings
s = input("s: ")
t = input("t: ")

# Compare strings
if s == t:
    print("Same")
else:
    print("Different")
```
Here as well Python can create a new word without pointer errors.
```
# Capitalizes a copy of a string

s = input("s: ")

# Capitalize copy of string
t = s.capitalize()                                 only capitalize the 1st letter

print(f"s: {s}")
print(f"t: {t}")
```
### Swap
Swap in C
```
// Swaps two integers using pointers
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

void swap(int *a, int *b) in python this part is x, y = y, x
{
    int tmp = *a;  
    *a = *b;
    *b = tmp;
}
```
### Swap in Python
``` 
x = 1
y = 2

print(f"x is {x}, y is {y}")
x, y = y, x
print(f"x is {x}, y is {y}")
```

## CSV
```
# Saves names and numbers to a separate CSV file
import csv

# Open CSV file the "a" stands for append, we're adding to the file
file = open("phonebook.csv", "a") 


# Get name and number
name = input("Name: ")
number = input("Number: ")

# Print to file
writer = csv.writer(file)
writer.writerow([name, number])

# Close file
file.close()
```

### There is a CSV library with special methods
```
# Saves names and numbers to a CSV file using a DictWriter
import csv

# Get name and number
name = input("Name: ")
number = input("Number: ")

# Open CSV file
with open("phonebook.csv", "a") as file:      # with auto closes the file for you

    # Print to file
    writer = csv.DictWriter(file, fieldnames=["name", "number"])
    writer.writerow({"name": name, "number": number})
```
There is always a solution to coding problems
