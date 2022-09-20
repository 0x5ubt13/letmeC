// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = (LENGTH + 1) * 'z';

// Hash table
node *table[N];
int total_words = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Get hash index
    int index = hash(word);

    node *cursor = table[index];
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int len = strlen(word);
    int hashed_result = 0 + len;

    for (int i = 0; word[i] == '\0'; i++)
    {
        hashed_result += tolower(word[i]) + i;
    }
    
    return (hashed_result % N);
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Open dictionary file, create root node and declare space for words
    FILE *f = fopen(dictionary, "r"); 
    if (f == NULL) 
    { 
        return false; 
    }

    // Read strings from file one at a time
    char next_word[50];
    while (fscanf(f, "%s", next_word) != EOF)
    {
        // printf("Starting fscanf()\n");

        // Create new node
        node *new_node = calloc(1, sizeof(node));
        if (new_node == NULL)
        {
            return false;
        }

        strcpy(new_node->word, next_word);

        // Obtain hashing index
        int index = hash(next_word);
        if(table[index] == NULL)
        {
            table[index] = new_node;
        }
        else
        {
            new_node->next = table[index];
            table[index] = new_node;
        }

        total_words++;

    }

    fclose(f);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return total_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *head = table[i];
        node *cursor = head;
        node *tmp = head;

        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
    }
    return true;
}
