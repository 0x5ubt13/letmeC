//
// Created by g on 6/8/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char *test_string = "Reverse this";
    int len_string = strlen(test_string);
    // printf("len_string: %d\n", len_string);
    char *reversed = malloc(len_string);
    int index = 0;

    for (int i = len_string-1; i >= 0; i--)
    {
        // printf("processing test_string[%d]: %c\n", i, test_string[i]);
        reversed[index] = test_string[i];
        index++;
    }
    // Finish the array
    reversed[len_string] = '\0';
    printf("Test string: %s\nReversed string: %s\n", test_string, reversed);
    free(reversed);
    return 0;
}
