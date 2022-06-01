#include <stdio.h>

char choice(void);
void calculate(char choice);

int main(void)
{
    float x, y, result;
    char operator = choice();
    calculate(operator);

	return 0;
}

char choice(void)
{
    printf("Enter + for addition\n");
    printf("Enter - for subtraction\n");
    printf("Enter * for multiplication\n");
    printf("Enter / for division\n");

    char input;
    scanf("%c", &input);
    
    return input;
}

void calculate(char choice)
{
    float result;
    
    float x, y;
    printf("Enter x: ");
    scanf("%f", &x); 
	
    printf("Enter y: ");
    scanf("%f", &y);

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
}