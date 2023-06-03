#include <cs50.h>
#include <stdio.h>

void set_array(int array[4]); // declaration of fn
void set_int(int x); // declaration of fn

int main(void)
{
    int a = 10; 
    int b[4] = { 0, 1, 2, 3};
    set_array(b); // fn call
    set_int(a); // fn call
    printf("%d %d\n", a, b[0]);
}

void set_array(int array[4]) // fn definition does not output
{
    array[0] = 22; // passed in by reference bc its an array so b[0] becomes 22
}                   

void set_int(int x) // fn definition does not output and does not work
{
    x = 22; // passed in by value but since its void nothing gets copied
}