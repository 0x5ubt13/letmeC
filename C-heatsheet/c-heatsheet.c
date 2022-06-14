#include <stdio.h>  // printf
#include <stdlib.h> // malloc
#include <string.h> // strcmp
#include <limits.h> // Provides variables to run types function
#include <float.h>
void recursion(void);
void draw(int n);
void pointers(void);
void types_and_sizes(void);
int arrays_lv1(void);
int arrays_lv2(void);
void linked_lists_lv1(void);
void linked_lists_lv2(void);

int main(void) 
{
    //recursion(); 
    //pointers();

    //arrays_lv1();
    //arrays_lv2(); // realloc()
    
    // linked_lists_lv1();
    linked_lists_lv2(); // No training wheels

    //types_and_sizes();
}

void recursion(void)
{
    /*
        We want to print a pyramid of this sort: 
        
        #
        ##
        ###
        #### (height 4)

        To showcase the usefulness of recursion, we will tell the function what's the final height we want
        and it will recursively go upwards to print the upper layers
    */

    int height;
    printf("Enter pyramid height: ");
    scanf("%i", &height);
    
    draw(height);
}

void draw(int n)
{
    if (n <= 0) // Stop if height is 0 and start printing
    {
        return;
    }
    
    draw(n - 1); // Keeps recursively call this same function to print itself upwards until reaches height 0 adding layers and layers

    // Then it releases all printf functions from 1 to n
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}

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

int arrays_lv1(void)
{
    /*
        When declaring arrays in C, we can allocate them either in the stack or in the heap.
        The next two operations are equivalent, with a twist:
        int my_array[3];                            // will allocate memory in the stack
        int *my_array = malloc(3 * sizeof(int));    // will allocate memory in the heap
    */ 

    // Declare array and populate it
    int *list = malloc(3 * sizeof(int)); if (list == NULL) { free(list); return 1; } // error checking
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // Time passes and the program is very large. Problem: we want to increase the array's size

    // Allocate new array of size 4
    int *tmp = malloc(4 * sizeof(int)); if (tmp == NULL) { free(tmp); return 1; }
    for (int i = 0; i < 3; i++) // Copy numbers from old array into new array
    {
        tmp[i] = list[i];
    }
    tmp[3] = 4;

    // Free up the orphan array
    free(list);

    // Point our former list array to the tmp array
    list = tmp;
    
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    // Free up the array before exiting the function
    free(list);
    return 0;
}

int arrays_lv2(void)
{
    /*
        When declaring arrays in C, we can allocate them either in the stack or in the heap.
        The next two operations are equivalent, with a twist:
        int my_array[3];                            // will allocate memory in the stack
        int *my_array = malloc(3 * sizeof(int));    // will allocate memory in the heap
    */ 

    // Declare array and populate it
    int *list = malloc(3 * sizeof(int)); if (list == NULL) { free(list); return 1; } // error checking
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // Time passes and the program is very large. Problem: we want to increase the array's size

    // Resize old array to be of size 4
    int *tmp = realloc(list, 4 * sizeof(int)); if (tmp == NULL) { free(tmp); return 1; }

    // No longer necessary:
    // for (int i = 0; i < 3; i++) // Copy numbers from old array into new array 
    // {
    //     tmp[i] = list[i];
    // }
    tmp[3] = 4;

    // Free up the orphan array
    free(list);

    // Point our former list array to the tmp array
    list = tmp;
    
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    // Free up the array before exiting the function
    free(list);
    return 0;
}

typedef struct node
{
    int number;
    struct node *next;
}
node;

void linked_lists_lv1(void)
{
    /*
        We will declare a new struct (node) that has both an int and a pointer to the next
        node on the list, so that we don't depend of reallocating back to back
        arrays in memory. We can terminate the list by adding a null address (0x0) to the last
        element of the list. 
    */

    node *list = NULL; // We initialise the value to NULL so it's empty instead of a garbage value
    node *n = malloc(sizeof(node)); // Tmp node, the compiler will know the size we need for a node struct

    if (n != NULL) // If malloc() didn't give us an invalid memory
    {
        //(*n).number = 1; // (*n). is a dereference and means "go to what's in the address and then access the data structure"
        n->number = 1; // n-> is syntactic sugar for (*n). so we don't mess with order of operations
        n->next = NULL;
    }

    list = n;
    free(list);
}

void linked_lists_lv2(void)
{
    // List of size node
    node *list = malloc(sizeof(node)); if (n == NULL) { return; }
    
    // Add a number to the list and point to the next node
    list->number = 1;
    list->next = NULL;

    // Append a number to the list
    node *n = malloc(sizeof(node)); if (n == NULL) {free(list); return;}
    n->number = 2;
    n->next = NULL;
    list->next = n; // Update the next value of 1 to the newly created node

    // Append another number to the list
    node *n = malloc(sizeof(node));
    if (n == NULL) // Visualising better the error catching now, a bit trickier
    {
        free(list->next); // First, free the pointer to the second element
        free(list); // Then, free the pointer to the first element
        return;
    }
    n->number = 3;
    n->next = NULL;
    list->next->next = n; // !!!! what??? We have to stitch together all pointers

    // Print numbers
    // Declare new tmp node, assign it to list, while it's not the last one, keep going through them
    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("%i\n", tmp->number);
    }

    // Free list -> you need to follow the stitches
    while (list != NULL)
    {
        node *tmp = list->next; // tmp is now the second element
        free(list); // We get rid of the first element
        list = tmp; // Assign list to second element, rinse and repeat
    }
    return;
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

