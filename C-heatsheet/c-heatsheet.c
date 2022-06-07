#include <stdio.h>  // 
#include <stdlib.h> // strcmp
#include <string.h> // 
#include <limits.h> // Provides variables to run types function
#include <float.h>

void pointers(void)
{
    /* Quick notes about pointers:
        Using * means pointer to
        Using & means address of
        Dereferencing means declaring variable *p and then calling *p instead of p, which means "whatever there is at this memory location"

    */

   int n = 50;  // 4 bytes containing decimal 50
   int *p = &n; // pointer to the address of the 4 bytes storing n
   //int* p = &n; would be equivalent to int *p = &n

   // To print out the address of n, we can do the following:
   printf("%p\n", p);   // prints 0x7ff7ba10847c (randomised address)
   printf("%p\n", &n);  // prints 0x7ff7ba10847c (randomised address)

   // Other shenanigans with pointers:
   printf("%i\n", *p);  // <- dereference operator, prints 50 (n) 

   char *s = "HI!";     // Pointer to string containing HI!
   char *c = &s[0];     // Pointer containing the address of H
   printf("%p\n", s);   // Prints 0x1045bed90
   printf("%p\n", c);   // Also prints 0x1045bed90

}

void types(void)
{   
    /* Borrowed from https://www.tutorialspoint.com/cprogramming/c_data_types.htm

    - Ints - 
    Type	        Storage size	            Value range
    char	        1 byte	                    -128 to 127 or 0 to 255
    unsigned char	1 byte	                    0 to 255
    signed char	    1 byte	                    -128 to 127
    int	            2 or 4 bytes	            -32,768 to 32,767 or -2,147,483,648 to 2,147,483,647
    unsigned int	2 or 4 bytes	            0 to 65,535 or 0 to 4,294,967,295
    short	        2 bytes	                    -32,768 to 32,767
    unsigned short	2 bytes	                    0 to 65,535
    long	        8 bytes or 4 bytes (x86)    -9223372036854775808 to 9223372036854775807
    unsigned long	8 bytes	                    0 to 18446744073709551615 
    
    - Floats -
    Type	        Storage size	Value range	            Precision
    float	        4 byte	        1.2E-38 to 3.4E+38	    6 decimal places
    double	        8 byte	        2.3E-308 to 1.7E+308	15 decimal places
    long double	    10 byte	        3.4E-4932 to 1.1E+4932	19 decimal places   */

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
    //types();
}

