#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int count = 0;
    long card; //declaring a variable long for card
    do
    {
        card = get_long("Card no: "); //Getting card number
    }
    while (card < 0); //card must not be less than 0
    long check = card;

    int card1, card2, card3, card4, card5, card6, card7, card8;
    card1 = (((card % 100)/10)*2);                           //(Multiply from second to the last by 2) then keep going
    card2 = (((card % 10000)/1000)*2);                          //(same)
    card3 = (((card % 1000000)/100000)*2);                      //(same)
    card4 = (((card % 100000000)/10000000)*2);
    card5 = (((card % 10000000000)/1000000000)*2);
    card6 = (((card % 1000000000000)/100000000000)*2);
    card7 = (((card % 100000000000000)/10000000000000)*2);
    card8 = (((card % 10000000000000000)/1000000000000000)*2);


    card1 = (card1 % 100/10) + (card1 % 10);
    card2 = (card2 % 100/10) + (card2 % 10);
    card3 = (card3 % 100/10) + (card3 % 10);
    card4 = (card4 % 100/10) + (card4 % 10);
    card5 = (card5 % 100/10) + (card5 % 10);
    card6 = (card6 % 100/10) + (card6 % 10);
    card7 = (card7 % 100/10) + (card7 % 10);
    card8 = (card8 % 100/10) + (card8 % 10);

    int card_no = card1 + card2 + card3 + card4 + card5 + card6 + card7 + card8;

    int non_mult =  (card % 10) + ((card % 1000)/100) + ((card % 100000)/10000) + ((card % 10000000)/1000000) +
    ((card % 1000000000)/100000000) + ((card % 100000000000)/10000000000) + ((card % 10000000000000)/1000000000000) +
    ((card % 1000000000000000)/100000000000000); //adding non multiplied numbers

    int check_sum = card_no + non_mult;   //CHECK SUM CALCULATION for validating input
    if ((check_sum % 10) != 0)   //if check sum doesn't give remainder of "0", print invalid, then terminate
    {
        printf("INVALID\n");
        return 0;
    }
    while (check > 0)    //check is same as card ///check code line 13, i.e, while card is greater than 0
    {
        check = check / 10;  //count the number of digits in card
        count++;   //count untill end
    }
    if (count != 15 && count != 13 && count != 16) //to confirm card length must be equal to 15, 13 or 16
    {
        printf("INVALID\n");
        return 1;
    }
    long MC = card / 100000000000000;     //to give the first two number of card in order to validate MASTER_CARD
    long AMEX = card / 10000000000000;    //to give the first two number of card in order to validate AMERICAN EXPRESS
    long Visa = card / 1000000000000000;  //to give the first number of card in order to validate VISA_CARD
    if (count == 15)
    {
        if (AMEX != 34 && AMEX != 37)  //to check if American Express first two digit is 34 or 37
        {
            printf("INVALID\n");
            return 1;
        }
        else
        {
            printf("AMEX\n");
            return 0;
        }
    }

    if (count == 16)
    {
        if (MC == 51 || MC == 52 || MC == 53 || MC == 54 || MC == 55)  // check if MC first two digit is 51 - 55.
        {
            printf("MASTERCARD\n");
            return 0;
        }
        else if (Visa == 4)  //first validation for visa card(16).....to check if visa_card first digit is 4
        {
            printf("VISA\n");
            return 0;
        }
        else if (MC != 51 && MC != 52 && MC != 53 && MC != 54 && MC != 55 && Visa == 4)
        {
            printf("INVALID\n");
            return 1;
        }
    }

    if (count == 13 && Visa == 4)  //second validation for visa card(13).....to check for validation
    {
        printf("VISA\n");
        return 0;
    }
    else if (count != 13 && Visa != 4)
    {
        printf("INVALID\n");
        return 1;
    }
}

----------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int digit = 0; // setting a base of 0
    long card; // using long because the digits will exceed 5
    do
    {
        card = get_long("Card no: "); //prompt for digits
    }
    while (card < 0); // keep prompting until a # larger than 0 is entered
    
    long verify = card; // verification that card is > 0 increasing digit++

    int card1, card2, card3, card4, card5, card6, card7, 
    card8; // get every other digit, starting with the 2nd to last digit nth-of-type right to left. Multiply them by 2
    
    card1 = (((card % 100) / 10) * 2);
    card2 = (((card % 10000) / 1000) * 2);
    card3 = (((card % 1000000) / 100000) * 2);
    card4 = (((card % 100000000) / 10000000) * 2);
    card5 = (((card % 10000000000) / 1000000000) * 2);
    card6 = (((card % 1000000000000) / 100000000000) * 2);
    card7 = (((card % 100000000000000) / 10000000000000) * 2);
    card8 = (((card % 10000000000000000) / 1000000000000000) * 2);

    card1 = (card1 % 100 / 10) + (card1 % 10); // take double digit #’s apart
    card2 = (card2 % 100 / 10) + (card2 % 10);
    card3 = (card3 % 100 / 10) + (card3 % 10);
    card4 = (card4 % 100 / 10) + (card4 % 10);
    card5 = (card5 % 100 / 10) + (card5 % 10);
    card6 = (card6 % 100 / 10) + (card6 % 10);
    card7 = (card7 % 100 / 10) + (card7 % 10);
    card8 = (card8 % 100 / 10) + (card8 % 10);


    int cards = card1 + card2 + card3 + card4 + card5 + card6 + card7 + card8; // sum those products’ digits together

    int not_mult = (card % 10) + ((card % 1000) / 100) + ((card % 100000) / 10000) + ((card % 10000000) / 1000000) +
                   ((card % 1000000000) / 100000000) + ((card % 100000000000) / 10000000000) + ((card % 10000000000000) / 1000000000000) +
                   ((card % 1000000000000000) / 100000000000000); // sum the digits that weren’t multiplied by 2

    int check = cards + not_mult; // adding both sums
   
    if ((check % 10) != 0) 
    {
        printf("INVALID\n");
        return 0; // return 0 means everthing is working
    }
    
    while (verify > 0) // run while card > 0
    {
        verify = verify / 10; // count # of digits
        digit++; //increment 1 digit
    }
   
    if (digit != 13 && digit != 15 && digit != 16) // dump if user entered digits aren't 13, 15 or 16
    {
        printf("INVALID\n");
        return 0; // return 0 means everthing is working
    }

    long AMEX = card / 10000000000000; //template for all cards to be seperated into types based on starting #'s
    long MC = card / 100000000000000;
    long Visa = card / 1000000000000000;

    if (digit == 15) // signifying the possiblity of an AMEX card
    {
        if (AMEX == 34 || AMEX == 37)
        {
            printf("AMEX\n"); // starting with 34 and 37 while already meeting checksum
            return 0; // return 0 means everthing is working
        }
        else
        {
            printf("INVALID\n"); // 15 digit dumpster
            return 0; // return 0 means everthing is working
        }
    }

    if (digit == 16) // signifying the possiblity of a MC & Visa card
    {
        if (MC == 51 || MC == 52 || MC == 53 || MC == 54 || MC == 55)
        {
            printf("MASTERCARD\n"); // starting with 51 - 55 while already meeting checksum
            return 0; // return 0 means everthing is working
        }
        else if (Visa == 4)
        {
            printf("VISA\n"); // starting with 4 while already meeting checksum
            return 0; // return 0 means everthing is working
        }
        else if (MC != 51 && MC != 52 && MC != 53 && MC != 54 && MC != 55 && Visa == 4)
        {
            printf("INVALID\n");  // 16 digit dumpster
            return 0; // return 0 means everthing is working
        }
    }

    if (digit == 13) // signifying the possiblity of a Visa card
    {
        printf("VISA\n"); // starting with 4 while already meeting checksum
        return 0; // return 0 means everthing is working
    }
    else if (digit != 13)
    {
        printf("INVALID\n");  // 13 digit dumpster
        return 0; // return 0 means everthing is working
    }
}

```
Checksum of: 343456789012346

Get every other digit, starting with the 2nd to last digit ergo; 4
4 2 0 8 6 4 4 
Multiply them by 2

 
4 * 2 = 8
2 * 2 = 4
0 * 2 = 0
8 * 2 = 16
6 * 2 = 12
4 * 2 = 8
4 * 2 = 8
 

Add those products’ digits together and take double digit #’s apart ergo; 16 = 1 + 6
8 + 4 + 0 + 1 + 6 + 1 + 2 + 8 + 8 = 38

Then, sum the digits that weren’t multiplied by 2
3 + 3 + 5 + 7 + 9 + 1 + 3 + 6 = 37

Add both sums 38 + 37 = 75 DOESN’T PASS
Finally, if the total has a last digit of 0, then the CC number is valid


Checksum of: 4234567890123456

Get every other digit, starting with the 2nd to last digit ergo; 5
5 3 1 9 7 5 3 4
Multiply them by 2
5 * 2 = 10
3 * 2 = 6
1 * 2 = 2
9 * 2 = 18
7 * 2 = 14
5 * 2 = 10
3 * 2 = 6
4 * 2 = 8

Add those products’ digits together and take double digit #’s apart ergo; 10 = 1 + 0
1 + 0 + 6 + 2 + 1 + 8 + 1 + 4 + 1 + 0 + 6 + 8 = 38

Then, sum the digits that weren’t multiplied by 2
2 + 4 + 6 + 8 + 0 + 2 + 4 + 6 = 32

Add both sums 38 + 32 = 70 PASSES
Finally, if the total has a last digit of 0, then the CC number is valid

Checksum of: 4111111111111111

Get every other digit, starting with the 2nd to last digit ergo; 1
1 1 1 1 1 1 1 4
Multiply them by 2
1 * 2 = 2
1 * 2 = 2
1 * 2 = 2
1 * 2 = 2
1 * 2 = 2
1 * 2 = 2
1 * 2 = 2
4 * 2 = 8

Add those products’ digits together
2 + 2 + 2 + 2 + 2 + 2 + 2 + 8 = 22

Then, sum the digits that weren’t multiplied by 2
1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 = 8

Add both sums 22 + 8 = 30 PASSES
Finally, if the total has a last digit of 0, then the CC number is valid


Checksum of: 4111111111111113

Get every other digit, starting with the 2nd to last digit ergo; 1
1 1 1 1 1 1 1 4
Multiply them by 2
1 * 2 = 2
1 * 2 = 2
1 * 2 = 2
1 * 2 = 2
1 * 2 = 2
1 * 2 = 2
1 * 2 = 2
4 * 2 = 8

Add those products’ digits together
2 + 2 + 2 + 2 + 2 + 2 + 2 + 8 = 22

Then, sum the digits that weren’t multiplied by 2
1 + 1 + 1 + 1 + 1 + 1 + 1 + 3 = 10

Add both sums 22 + 10 = 32 DOESN’T PASS
Finally, if the total has a last digit of 0, then the CC number is valid
Checksum of: 4222222222223

Get every other digit, starting with the 2nd to last digit ergo; 2
2 2 2 2 2 2 
Multiply them by 2
2 * 2 = 4
2 * 2 = 4
2 * 2 = 4
2 * 2 = 4
2 * 2 = 4
2 * 2 = 4

Add those products’ digits together
4 + 4 + 4 + 4 + 4 + 4 = 24

Then, sum the digits that weren’t multiplied by 2
4 + 2 + 2 + 2 + 2 + 2 + 3 = 17

Add both sums 24 + 17 = 41 DOESN’T PASS
Finally, if the total has a last digit of 0, then the CC number is valid



Checksum of: 4222222222222

Get every other digit, starting with the 2nd to last digit ergo; 2
2 2 2 2 2 2 
Multiply them by 2
2 * 2 = 4
2 * 2 = 4
2 * 2 = 4
2 * 2 = 4
2 * 2 = 4
2 * 2 = 4

Add those products’ digits together
4 + 4 + 4 + 4 + 4 + 4 = 24

Then, sum the digits that weren’t multiplied by 2
4 + 2 + 2 + 2 + 2 + 2 + 2 = 16

Add both sums 24 + 16 = 40 PASSES
Finally, if the total has a last digit of 0, then the CC number is valid
```
