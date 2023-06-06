# Week 5 – Data Structures 
Algorithm: A step-by-step set of instructions for solving a problem

### Introduction
C is considered a “lower-level language.” That isn’t an insult, all that means is; it takes a lot more effort to do things than “higher level languages” that have libraries and amenities to make coding easier and less archaic.

### Data Structures
How do you arrange(structure) data in memory? The answer is  building things digitally using pointers. Pointers allow you to storage addresses in memory like in variables, stitching pieces of data together. You’ll see what I mean in a few paragraphs.

## Stack and Queues – are Abstract Data Type Structures
A data type queue has properties one of which is FIFO (first in first out) Think JS and how it is Async? Only 1 thing loads at a time when multiple things are selected, once they final stop buffering and start loading, they still load in order, they load FIFO.
```
enqueue(): Adding something to the END of the queue
dequeue(): Removing the first something from the queue
```
A data type stack has properties as well, one of which is LIFO (last in first out) Think of serving trays that are clean, they get placed from the bottom, up, then when used, they get used from the top down. So, the newest tray (which is at the top) is then the first taken and so on. Email is another example of a stack. The emails that come in most recent sit first in view.
```
	push(): Adding something to the top of a stack
	pop(): Removing something from the top of the stack
```

## Resizing Arrays
Arrays are a Data Structure as well. They are chunks of memory, where elements are stored by design in a “row” back-to-back to back aka contiguous memory.
When an array is created, memory is allocated for it. BUT what happens if you want to add to the array? Keeping in mind elements in an array or in contiguous memory aka the elements are in memory slots back-to-back etc ergo: 0x123, 0x124, 0x125. But now, I want to add to 0x126, yet that slot is already full… SO, I then move the array to a location that has 4 slots available! YET later I end up adding a 5th 6th and 7th slot.
This is where pointers come in. Instead of moving the array, I just use slot 4 and so on anywhere memory is available, then use POINTERS to reference their locations. Allowing for quick data entry and efficient use of my time.

Week 2 stuff
### list0.c - Implements a list of numbers with an array of fixed size
```
#include <stdio.h>

int main(void)
{
    // List of size 3
    int list[3];

    // Initialize list with numbers
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // Print list
    for (int i = 0; i < 3; i++)
    {
        printf("%i\n", list[i]);
    }
}
```

A single & operator = Find that Address

A single * operator = go/point to that address aka dereference 

A single * operator followed by & = Store that address  


Same basic program but allocating memory dynamically by adding the new method realloc()
```
realloc(what variable do you want changed, what size do you want it to);
realloc(list, 4);
```

### list1.c - Implements a list of numbers with an array of dynamic size
```
#include <stdio.h>
#include <stdlib.h> // required to use malloc() realloc() & free()

int main(void)
{
    // List of size 3
    int *list = malloc(3 * sizeof(int)); // point to list
    if (list == NULL)
    {
        return 1;
    }

    // Initialize list of size 3 with numbers
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // List of size 4
    int *tmp = realloc(list, 4 * sizeof(int)); // point to tmp
    if (tmp == NULL)
    {
        free(list);
        return 1;
    }
    list = tmp;

    // Add number to list
    list[3] = 4; // [3] bc C is 0 indexed

    // Print list
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    // Free list
    free(list);
    return 0;
}
```

## Linked Lists – Data Structure

One of the most useful and powerful things in C that you can take for granted in JS and Python.

Linked lists are a way to stitch together/link fancier data structures without having to move things around. You are just “connecting the dots.”
```
1 = 0x123
2 = 0x456
3 = 0x789 
// by definition this is NOT an array bc the memory is not contiguous
```
The only solution to get 1, 2, 3 to become ‘an array’ is to spend more memory and point to the next elements memory address.
```
1 = 0x123 AND 0x456  // 1 is pointing to 2
2 = 0x456 AND 0x789  // 2 is pointing to 3
3 = 0x789 AND 0x0 // 3 is not pointing aka NULL
```
Now even though they’re not actually contiguous, they are “stitched/linked” in to be an array (specifically a singly linked list/array (meaning linked in a singular direction). Also, the pointer data is called “metadata,” additional data that’s related data but not the data you care about, it’s there but isn’t the priority.
NODE: a container in code for storing some values. The problem with Arrays now being linked lists is:
•	Takes up much more memory
•	No longer use square bracket notation aka subset indexed elements: example[3];
•	Can no longer us Binary Search
```
* + . = ->

* = go/point to
. = retrieve data 
-> = go to and retrieve data 

n -> number = 1;
```

### Implements a sorted list of numbers using a linked list
```
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(int argc, char *argv[])
{
    // Memory for numbers
    node *list = NULL;

    // For each command-line argument
    for (int i = 1; i < argc; i++)
    {
        // Convert argument to int
        int number = atoi(argv[i]);

        // Allocate node for number
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n->number = number; //-> = go to and retrieve data 
        n->next = NULL;

        // If list is empty
        if (list == NULL)
        {
            list = n;
        }

        // If number belongs at beginning of list
        else if (n->number < list->number)
        {
            n->next = list;
            list = n; 
        }
        // If number belongs later in list
        else
        {
            // Iterate over nodes in list
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                // If at end of list
                if (ptr->next == NULL)
                {
                    // Append node
                    ptr->next = n;
                    break;
                }

                // If in middle of list
                if (n->number < ptr->next->number)
                {
                    n->next = ptr->next;
                    ptr->next = n;
                }
            }
        }
    }

    // Print numbers
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }

    // Free memory
    node *ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
}
testing/ $ ./testing 1 2 3
1
2
3
```
## Trees - 2-dimensional Data Structure
Trees like a family tree, not like a physical tree that grows bottom up. Tree arrays are a quick binary search way to have arrays be flexible in their memory orientation. Different than linked lists.

## Dictionaries – Data Structure
The holy grail of algorithms is Big O of 1; O(1)  “constant time”. Storing huge amounts of data but finding what you need instantly in one step, or two steps, even 20 steps just independent of the size of the data structure. 
A dictionary in C is basically an Object. A dictionary is defined as having a key and a value aka key value pairs.
•	Key: is what you use to look for something
•	Value: is what you find via that key

## Hashing and Hash Tables
Hashing: Taking in some input value and outputting a simpler version “thereof”. An example would be a shuffled deck of cards. Then sorting them by their suit. You have just hashed that deck of cards, as they now are a simpler version than before to understand and put in order.

Hash Tables: A wonderful application of arrays and linked lists to try and leverage the best of both worlds. The goal being to achieve that Holy Grail of constant time O(1). 
	Your phones contacts are a representation of hash tables. The data is from top to bottom A to Z, the sorting is already hashed to 26 alphabets that are arrays. The 26 letters will never change and will stay in order. Linked lists are then applied to each letter for multiple entries in the same letter. The linked lists are so granular that they are also created for the first 2 letters the first 3 letters 4 and onwards in each letter in the alphabet, ergo: M, MA, MAB, and so on. Linked lists are used because arrays are too stagnant. Constantly having info added and removed, dynamic alterations are what linked lists do naturally. Once again, the catch is this uses a fuck ton of memory, comparative to just an array of contacts. 
	What I surmise from this; Having as much data sorted as possible is the key to understanding how modern algorithms work.
Tries – Data Structure (short for retrieval)
	Tries are “even cooler” in that it does not devolve into Big O(n). It is truly constant time. A tri is a sort of fancier data tree (think family tree orientation) each node of the tree is an array. AKA A LOT of arrays but all with pointers that create a cool approach to sorting data. You have your foundation array, once again the alphabet example. Your foundation A- Z, then another array aka node aka branch that connects via a pointer than another array and onwards until you find all the values you were after.
	The name Harry would take 5 arrays Starting with H, H points to A, A points to R, R points to a different set of the alphabet and onwards till D. 
	We used 5 full arrays that each contained all 26 letters. We worked down the tree quickly using only arrays.
The catch: Once again is A LOT of memory
Any time you want to speed up your algorithm you’re gonna spend more in space. And of course, if you want to decrease the amount of space used, you’re going to increase the amount of time the algorithm takes.

There is always a solution to coding problems
