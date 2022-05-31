#include <stdio.h>

int print_menu(void);

int main(void)
{
    print_menu();
    int choice;
    long result;
    scanf("%d", &choice);

	long x;
	long y;
	
	printf("Enter x: ");
	scanf("%ld", &x);

	printf("Enter y: ");
	scanf("%ld", &y);

    switch (choice)
    {
        case 1:
            result = x + y;
            break;
        case 2:
            result = x - y;
            break;
        case 3:
            result = x * y;
            break;
        case 4:
            result = x / y;
            break;
    }

	printf("The result is: %li\n", result);
	return 0;
}

int print_menu(void)
{
    printf("Select 1 for +\n");
    printf("Select 2 for -\n");
    printf("Select 3 for *\n");
    printf("Select 4 for /\n");
    return 0;
}
