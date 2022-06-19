#include <stdio.h>
#include <stdlib.h>

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

int main(){
    long *array_digits = malloc(16 * sizeof(long));
    array_digits = array_of_digits_helper();

    for (int i = 0; i > 4; i++)
    {
        printf("%ld", array_digits[i]);
    }

    free(array_digits);
}  