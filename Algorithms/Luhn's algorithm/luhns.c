#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int luhns(long card);

int main(void)
{
    // Get user's credit card input
    long *card = malloc(sizeof(long));
    printf("Number: ");
    scanf("%ld", card);
    
    printf("Checkpoint 1: card: %s\n", card);
    // Parse credit card
    int result = luhns(card);
    free(card);
    // free();

    printf("Checkpoint 2\n");

    switch (result)
    {
        case 0:
            // Amex
            printf("AMEX\n");
            break;
        case 1:
            // Visa
            printf("VISA\n");
            break;
        case 2:
            // Mastercard
            printf("MASTERCARD\n");
            break;
        case 3:
            // Invalid
            printf("INVALID\n");
            break;
    }
    // valid visa: 4003600000000014
}

// Length helper kindly borrowed from https://stackoverflow.com/questions/3068397/finding-the-length-of-an-integer-in-c
int lenHelper(unsigned x) { 
    // this is either a fun exercise in optimization 
    // or it's extremely premature optimization.
    if(x >= 100000) {
        if(x >= 10000000) {
            if(x >= 1000000000) return 10;
            if(x >= 100000000) return 9;
            return 8;
        }
        if(x >= 1000000) return 7;
        return 6;
    } else {
        if(x >= 1000) {
            if(x >= 10000) return 5;
            return 4;
        } else {
            if(x >= 100) return 3;
            if(x >= 10) return 2;
            return 1;
        }
    }
}


// Analyse the card's numbers using Luhn's Algorithm:
// 1. Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
// 2. Add the sum to the sum of the digits that weren’t multiplied by 2.
// 3. If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
int luhns(long card)
{
    // 1. Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
    // 1.1 Split number in digits
    int *card_digits = malloc(16 * sizeof(int));

    // We need to know the length of the card
    int len_card = lenHelper(card);
    

    for (int i = 0; i > len_card; i++)
    {

    }

    // 1.2 do the calculations

    // free allocations
    free(card_digits);
}

long *array_of_digits_helper(void)
{
    long num;
    long temp, factor = 1;
    long *array_of_digits = malloc(16 * sizeof(long));
    printf("Enter a number: ");
    scanf("%ld", &num);

    temp=num;

    while(temp){
        temp=temp/10;
        factor = factor*10;
    }

    // printf("Each digits of given number are: ");

    int counter = 0;
    while(factor>1){
        // Digits 1 by 1
        factor = factor/10;
        // printf("%ld ", num/factor);
        array_of_digits[counter] = num/factor;
        counter++;
        num = num % factor;
    }
    
    return array_of_digits;
}

/*
    // old code 
    // Take length
    char *card_to_string = malloc(sizeof(long));
    sprintf(card_to_string, "%ld", card);
    int len = 0; 
    len = strlen(card_to_string);
    printf("len: %i\n", len);

    // Exit if it's not any suitable length (amex is 15, visa is either 13 or 16, mastercard is 16)
    if (len != 16 && len != 15 && len != 13)
    {
        return 3;
    }

    // Create numbers array and parse num to digits
    long num = card;
    long temp, factor = 1;
    long *digits = malloc(16 * sizeof(long));
    
    temp=num;

    while(temp){
        temp=temp/10;
        factor = factor*10;
    }

    printf("Each digits of the card are: ");

    int counter = 0;
    while(factor > 1)
    {
        // Digits 1 by 1
        factor = factor / 10;
        printf("%ld ", num / factor);
        digits[counter] = num / factor;
        counter++;
        num = num % factor;
    }
    
    // NOW DIGITS HAS THE INDIVIDUAL NUMBERS
    // return array_of_digits;
    //////////////////////////
    printf("Checkpoint: print all digits: ");
    for (int i = 0; i < len; i++)
    {
        printf("%ld ", digits[i]);
    }

    // // Process the array of numbers with Luhn's algorithm to determine its validity

    // // If it's an even number, checks every 2 numbers from the first one
    // int even = 0;
    // // Else, if it's an odd number checks every 2 numbs from the second one
    // if (len % 2 == 1)
    // {
    //     even = 1;
    // }

    // int counter1 = 0;
    // int counter2 = 0;
    // // Start in 0 if it's even, in 1 if it's odd
    // for (int i = even; i < len; i++)
    // {
    //     if (counter1 == 0 || counter1 % 2 == 0)
    //     {  
    //         printf("debug card_nums[i] line 120: %i\n", card_nums[i]);
    //         int new_num = card_nums[i] * 2;
    //         printf("new_num: %i\n", new_num);
    //         multiplied[counter2] += card_nums[i] * 2;
    //         counter2++;
    //     }
    //     else {
    //         sum_not_multiplied += card_nums[i];
    //     }

    //     counter1++;
    // }

    // // Sum every digit of the multiplied ones
    // int len_multiplied = sizeof(multiplied) / sizeof(multiplied[0]);
    // char processed[len_multiplied];

    // for (int i = 0; i < len_multiplied; i++)
    // {
    //     int num = *multiplied[i];
    //     printf("Debug Line 137 - Num: %i\n", num);
    //     if (num == 0)
    //     {
    //         continue;
    //     }
        
    //     // Transform to chars to split the numbers 1 by 1
    //     int digits_length = lenHelper(num);
    //     // int nums_array[digits_length];
    //     sprintf(&processed[i], "%i", num);

    //     // Sum every digit
    //     for (int j; j < digits_length; j++)
    //     {
    //         int converting = atoi(&processed[j]);
    //         sum_multiplied += converting; // PROBLEMS HERE
    //     }
    // }

    // if ((sum_multiplied + sum_not_multiplied) % 10 == 0)
    // {
    //     if (card_nums[0] == 3)
    //     {
    //         if (card_nums[1] == 4 || card_nums[1] == 7)
    //         {
    //             return 0;
    //         }
    //     }

    //     if (card_nums[0] == 4)
    //     {
    //         return 1;
    //     }

    //     if (card_nums[0] == 5)
    //     {
    //         if (card_nums[1] == 1 || card_nums[1] == 2 || card_nums[1] == 3 || card_nums[1] == 4 || card_nums[1] == 5)
    //         {
    //             return 2;
    //         }
    //     }
    // }

    free(card_to_string);
    free(digits);


    return 3;
}