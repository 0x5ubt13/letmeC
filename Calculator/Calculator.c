#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float calculate(char choice, float x, float y);
void usage(void);

int main(int argc, char *argv[])
{
    if (argc < 4) 
    {
        printf("Error: Not enough command-line arguments.");
        usage();
        return 1;
    }

    double operators[10], result;
    int counter = 0;
    char operation;

    for (int i = 1; i < argc; i++) // Parse arguments.
    {   
        if (i % 2 == 1) // If it's a number, add it to the numbers array
        {  
            operators[counter] = atof(argv[i]); // Convert str to float
            counter++;
        } 

        if (strncmp(argv[i], "plus", 5) == 0 || strncmp(argv[i], "+", 1) == 0)
        {
            operation = '+';
        }
        
        if (strncmp(argv[i], "minus", 6) == 0 || strncmp(argv[i], "-", 1) == 0)
        {
            operation = '-';
        }
        
        if (strncmp(argv[i], "times", 6) == 0 || strncmp(argv[i], "*", 1) == 0)
        {
            operation = '*';
        }
        
        if (strncmp(argv[i], "over", 4) == 0 || strncmp(argv[i], "/", 1) == 0)
        {
            operation = '/';
        }
    }

    result = calculate(operation, operators[0], operators[1]);

    printf("Result: %.2f\n", result);

	return 0;
}

float calculate(char choice, float x, float y)
{
    double result;
    switch(choice)
    {
        case '+':
            result = x + y;
            break;
        case '-':
            result = x - y;
            break;
        case '*':
            result = x * y;
            break;
        case '/':
            result = x / y;
            break;
    }

    return result;
}

void usage(void)
{
    printf("Usage: <Operator1> <keyword> <operator2>\n");
    printf("Examples:\n");
    printf("Sum:\t\t 2 plus 3\tor\t 2 + 3\n");
    printf("Subtraction:\t 5 minus 2\tor\t 5 - 2\n");
    printf("Multiplication:\t 4 times 5\tor\t 4 * 5\n");
    printf("Division:\t 10 over 5\tor\t 10 / 5\n");
}