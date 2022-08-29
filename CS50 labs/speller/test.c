
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#include "dictionary.h"

// Loads dictionary into memory, returning true if successful, else false
void main(void)
{
    // TODO
    // Open dictionary file
    FILE *f = fopen("./dictionaries/small", "r");
    char next_word[LENGTH];

    // Read strings from file one at a time
    while (fscanf(f, "%s", next_word) == 1)
    {
        // Create a new node for each word
        printf("%s\n", next_word);

        // Hash word to obtain a hash value

        // Insert node into hash table at that location
    }

    fclose(f);

    return;
}