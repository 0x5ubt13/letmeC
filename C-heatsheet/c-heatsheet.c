#include <stdio.h>  // printf
#include <stdlib.h> // malloc
#include <string.h> // strcmp
#include <limits.h> // Provides variables to run types function
#include <float.h>

void pointers(void)
{
    /* 
        Quick notes about pointers:
        Using * means pointer to
        Using & means address of
        Dereferencing means declaring variable *p and then calling *p instead of p, which means "whatever there is at this memory location"
        There can be pointers to pointers (oof)
    */

    int n = 50;  // 4 bytes containing decimal 50
    int *p = &n; // pointer to the address of the 4 bytes storing n
    //int* p = &n; would be equivalent to int *p = &n

    // To print out the address of n, we can do the following:
    printf("%p\n", p);   // prints 0x7ff7ba10847c (randomised address)
    printf("%p\n", &n);  // prints 0x7ff7ba10847c (randomised address)

    // Other shenanigans with pointers, like dereferencing and pointer arithmetic
    printf("%i\n", *p);      // <- dereference operator, prints 50 (n) 

    char *s = "HI!";         // Pointer to string containing HI!
    char *c = &s[0];         // Pointer containing the address of H
    printf("%p\n", s);       // Prints 0x10931fd90 (random memory)
    printf("%p\n", c);       // Also prints 0x10931fd90
    printf("%p\n", &s[0]);   // Also prints 0x10931fd90 (memory location of char 'H')
    printf("%p\n", &s[1]);   // Prints 0x10931fd91 (memory location of char 'I')
    printf("%p\n", &s[2]);   // Prints 0x10931fd92 (memory location of char '!')
    printf("%p\n", &s[3]);   // Prints 0x10931fd93 (memory location of null byte \0)

    printf("%c\n", *s);      // Prints H (dereference)
    printf("%c\n", *(s+1));  // Prints I (dereference location + 1) <- "Pointer arithmetic"
    printf("%c\n", *(s+2));  // Prints ! (dereference location + 2) <- "Pointer arithmetic"

    // Pointer arithmetic also works with integers and even though we only add 1, it prints 4 bytes forward
    int numbers[] = {4, 6, 8, 2, 7, 5, 0};
    int len_numbers = sizeof(numbers) / sizeof(*numbers); // Getting the array's length

    printf("%i\n", *numbers);       // Prints first number
    for (int next = 1; next < len_numbers; next++)
    {
        printf("%i\n", *(numbers + next));  // Prints second, third, fourth number, and so on
    }

    /*
        To compare strings, we need to use strcmp
        If we try to compare s2 == t2 it will always
        be different, because it's comparing the addresses
        of both arrays of chars that the pointers are
        pointing to. If we want to compare the actual 
        characters of each string, an additional function 
        in C is needed as shown below:
    */

    char *s2 = "HI!";
    char *t2 = "HI!";

    if (strcmp(s2, t2) == 0)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }

    /*
        To copy a string (array of chars), we can't simply do s = t,
        because we would be copying the pointer to the same array. One
        solution would be using malloc() and strcpy(), and then use free()
    */

    char *s3 = "Hiya!"; // String we want to copy
    int len_s3 = strlen(s3) + 1; // Memory allocated to the whole array
    
    char *t3 = malloc(len_s3); // We declare the empty array allocating the same memory than s3 (plus the null byte)
    for (int i = 0; i < len_s3; i++)
    {
        t3[i] = s3[i];
    }

    printf("Original: %s | Copy: %s\n", s3, t3);
    
    free(t3); // We need to remember to use free() after using malloc()
}


void types_and_sizes(void)
{   
    /* Borrowed from https://www.tutorialspoint.com/cprogramming/c_data_types.htm

    - Ints - 
    Type                Storage size                Value range
    char                1 byte                      -128 to 127 or 0 to 255
    unsigned char       1 byte                      0 to 255
    signed char         1 byte                      -128 to 127
    int                 2 or 4 bytes                -32,768 to 32,767 or -2,147,483,648 to 2,147,483,647
    unsigned int        2 or 4 bytes                0 to 65,535 or 0 to 4,294,967,295
    short               2 bytes                     -32,768 to 32,767
    unsigned short      2 bytes                     0 to 65,535
    long                8 bytes or 4 bytes (x86)    -9223372036854775808 to 9223372036854775807
    unsigned long       8 bytes                     0 to 18446744073709551615 
    
    - Floats -
    Type                Storage size        Value range             Precision
    float               4 byte              1.2E-38 to 3.4E+38      6 decimal places
    double              8 byte              2.3E-308 to 1.7E+308    15 decimal places
    long double         10 byte             3.4E-4932 to 1.1E+4932  19 decimal places   */

    printf("Printing mins and max for different data types based on integers:\n");
    printf("CHAR_BIT  : %d\n", CHAR_BIT);                       // prints 8
    printf("CHAR_MAX  : %d\n", CHAR_MAX);                       // prints 127
    printf("CHAR_MIN  : %d\n", CHAR_MIN);                       // prints -128
    printf("INT_MAX   : %d\n", INT_MAX);                        // prints 2147483647
    printf("INT_MIN   : %d\n", INT_MIN);                        // prints -2147483648
    printf("LONG_MAX  : %ld\n", (long) LONG_MAX);               // prints 9223372036854775807
    printf("LONG_MIN  : %ld\n", (long) LONG_MIN);               // prints -9223372036854775808
    printf("SCHAR_MAX : %d\n", SCHAR_MAX);                      // prints 127
    printf("SCHAR_MIN : %d\n", SCHAR_MIN);                      // prints -128
    printf("SHRT_MAX  : %d\n", SHRT_MAX);                       // prints 32767
    printf("SHRT_MIN  : %d\n", SHRT_MIN);                       // prints -32768
    printf("UCHAR_MAX : %d\n", UCHAR_MAX);                      // prints 255
    printf("UINT_MAX  : %u\n", (unsigned int) UINT_MAX);        // prints 4294967295
    printf("ULONG_MAX : %lu\n", (unsigned long) ULONG_MAX);     // prints 18446744073709551615
    printf("USHRT_MAX : %d\n\n", (unsigned short) USHRT_MAX);   // prints 65535

    printf("Printing mins and max for different data types based on floats:\n");
    printf("Storage size for float : %lu \n", sizeof(float));   // prints 4
    printf("Precision value: %d\n", FLT_DIG );                  // prints 6
    printf("FLT_MAX   : %g\n", (float) FLT_MAX);                // prints 3.40282e+38
    printf("FLT_MIN   : %g\n", (float) FLT_MIN);                // prints 1.17549e-38
    printf("-FLT_MAX  : %g\n", (float) -FLT_MAX);               // prints -3.40282e+38
    printf("-FLT_MIN  : %g\n", (float) -FLT_MIN);               // prints -1.17549e-38
    printf("DBL_MAX   : %g\n", (double) DBL_MAX);               // prints 1.79769e+308
    printf("DBL_MIN   : %g\n", (double) DBL_MIN);               // prints 2.22507e-308
    printf("-DBL_MAX  : %g\n", (double) -DBL_MAX);              // prints -1.79769e+308
}

int main(void) 
{
    pointers();
    //types_and_sizes();
}

