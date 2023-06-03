# The goal of this course is that you fundamentally have learned how to program regardless of the language used

All languages use: 
 
* Functions: actions of inputs & outputs
* Conditionals: forks in the road
* Variables: store values
* Boolean expressions: yes/true no/false ?’s
* Loops: do things again and again
* Logical Operators: And, Or, Not  
 
Week 0 – Scratch

	Input  □  output

Binary: 0 and 1

Bits: binary digits 

Transistors: tiny switches, that turn on or off.  

Decimal system: digits 0-9 and to power of 10

Binary system: digits 0-1 and to the power of 2

           2^3 = 8                   2^2 = 4               2^1 = 2              2^0 = 1
        23 = 2⋅2⋅2⋅1 = 8            22 = 2⋅2⋅1 = 4         21 = 2⋅1 = 2          20 = 1⋅1 = 1
 
        001 = 1 
        010 = 2
        011 = 3
        100 = 4
        101 = 5
        110 = 6
        111= 7
        1000 = 8
        1001 = 9
        1010 = 10
        1011 = 11
        1100 = 12 

Binary system covers everything a computer does including letters

Capital A = 65 or in binary 01000001
Capital B = 66 or in binary 01000010

Prefixes are the reason capital A and 65 aka 01000001 can exist as the same binary code is all in the interpretation its being used in aka context dependent of which program is running
ASCII American Standard Code for information interchange

        72 73 33                                                                 1111 1111 = 255 in binary 
        H   I    ! 
Each letter is 8 bits 

8 bits equals 1 byte

1 kilobyte is thousands of bytes
1 megabyte is millions of bytes
1 gigabyte is billions of bytes
1 terabyte is trillions of bytes

Unicode the ultimate representation of format
Representing information using binary with different formats

 A superset of ASCII the mapping of many more bits which go as high as 32 bits to characters in all languages emojis etc 16 bits totals over 65000 combinations of characters.
At 32 bits the possibilities are over 4 billion combinations 

1111 0000  1001 1111  1001 1000  1011 0111 = the yellow emoji face with a medical mask

Color
Programs interrupt numbers as colors for example: R = 72 G = 73 B = 33. 

Images
Pixels are assigned numbers in specific pixel locations to create what we see as images. On average 24 bits are being used per pixel to represent the necessary color

Videos
How is a video represented only using binary (zeros and ones)? Formats; specific applications that utilize binary numbers to convey images at 24-30-60-120 per second creating what we see as motion 

Music
Computer programs interrupt sounds with binary as well using specific formats for the binary information the note, the tempo, the duration of note and the intensity the note is being played. All with bits



Algorithm 
Algorithm: A step-by-step set of instructions for solving a problem

It’s all input, “some process”, to then produce an output
Input  □  output
That “some process” is called an algorithm

When you write software aka code/programs, you are implementing 1 or more algorithms
When you boil all this down, everything is done with just zeros and ones (binary)

Using an algorithm 

finding “John Harvard” phone # via contacts app
An example of an algorithm is your phones contacts app. Your contacts are listed from A to Z, based on first name and or last name, and listed from top to bottom. 
To find John: 
Step 1. Open the app
Step 2. Scroll down to the J’s or H’s
Step 3. Find John Harvard
This is a step-by-step process an ‘algorithm’


finding “John Harvard” phone # via a phonebook
Another example of an algorithm is a tactile phonebook. Phone numbers are listed from A to Z, based on first name or last name, and listed from left to right per page.
To find John:
Step 1. Open the book
Step 2. Work towards at the H section, if not found jump to the J section
Step 3. Find John Harvard 
This too is a step-by-step approach an ‘algorithm’

Without the algorithm you would flip/scroll through every page to find John

Both algorithms divide the problem into simple step-by-step instructions making the problem smaller, efficient

All of this was harnessing human intuition, expressing them into an algorithm, this is what writing code is.




Pseudocode

A way of expressing yourself in any language succinctly, correctly and getting your algorithm (step-by-step for solving a problem) across 

Core pieces to algorithms 

Functions = actions/verbs that solve some smaller problem, they tend to do specific tasks

Conditionals = things that are done conditionally based on the answer of some boolean question (true/false yes/no). If ______ blank happens then execute, else if _______ run this, else quit. Apt to forks in the road, ‘Do you go left or right?’

Boolean Expressions = Questions that have yes/true or no/false answers 

Loops = Some kind of cycle, some kind of directive that tells us to do something again and again


Scratch
A graphical programing language from MIT

Drag and drop things that look like puzzle pieces that interlock together without the distraction of brackets, parenthesis, semicolons, quotes etc.

Allow you to explore programing fundamentals that are in things like C, Python, JS, but without the distraction of syntax

Algorithm 
A step-by-step set of instructions for solving a problem
 Input  □  output
say is a function
Hello, world  say  scratch says Hello, world

Say, ask = function 

The white ovals = parameters/arguments

when clicked, when key down = event listener

repeat, forever = loops

if = conditionals 
stored values = variables(orange custom boxes with ovals inside aka inputs/outputs returns)


Problem set 0 ideas:

Starby’s big crazy adventure:

Hide button until after dialog 
Press start 
But you can’t 
there’s a button that says click me, when you do it switches to a new location. After the 3rd click Starby starts talking to you 
and the button starts gliding away? 


I have to make a function and a conditional 
IF you select the button; infinity repeat
ELSE you select Starby and you leave the 1st page.


Change of plans, once you click Starby you get sent to a simple side scrolling page. Walk to the right touch the Mario-like flag and then load to one last screen saying Thank You, that was a great adventure!!

I’m only happy when it rains for music?

Broadcast is how you link sprites 

The evil Dr. Kerr has stopped the rain from coming down on your land. Set out on a journey to find where his evil hasn't tarnished and save your peoples immediate future. 

Use arrow directional keys to move. If you get stuck hold the down directional



8 bits equals 1 byte

There is always a solution to coding problems
