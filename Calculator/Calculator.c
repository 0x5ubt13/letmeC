#include <stdio.h>
#include <string.h>

char choice(void);
float calculate(char choice, float x, float y);
void usage(void);

int main(int argc, char *argv[])
{
    if (argc < 4) 
    {
        printf("Not enough command-line arguments.");
        usage();
        return 1;
    }

    float operators[argc / 2], result;
    int counter;
    char operation;

    for (int i = 1; i < argc; i++)
    {
        if (i % 2 == 1)
        {  
            operators[counter] = atoi(argv[i]);
            counter++;
        } 
        else 
        {
            if (argv[i] == "plus" || argv[i] == '+')
            {
                operation = '+';
            }
            else if (strncmp(argv[i], "minus", 6) == 0 || argv[i] == '-')
            {
                operation = '-';
            }
            else if (argv[i] == "times" || argv[i] == '*')
            {
                operation = '*';
            }
            else if (argv[i] == "over" || argv[i] == '/')
            {
                operation = '/';
            }
        }
    }

    result = calculate(operation, operators[0], operators[1]);

	return 0;
}

float calculate(char choice, float x, float y)
{
    float result;
    switch(choice)
    {
        case '+':
            result = x + y;
            printf("Result: %.f\n", result);
            break;
        case '-':
            result = x - y;
            printf("Result: %.f\n", result);
            break;
        case '*':
            result = x * y;
            printf("Result: %.f\n", result);
            break;
        case '/':
            result = x / y;
            printf("Result: %.2f\n", result);
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