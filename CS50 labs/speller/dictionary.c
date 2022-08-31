// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Using tries instead
typedef struct trienode
{
    struct trienode *children[LENGTH+1];
    bool is_word;
} 
trienode;

trienode *create_node() {
    trienode *new_node = malloc(sizeof(new_node))

    for (int i = 0; i < LENGTH; i++)
    {
        new_node->children[i] = NULL;
    }
    new_node->terminal = false;
}

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Open dictionary file
    FILE *f = fopen(dictionary, "r"); 
    if (f == NULL) 
    { 
        return false; 
    }

    char next_word[LENGTH];
    
    // Read strings from file one at a time
    while (fscanf(f, "%s", next_word) != EOF)
    {
        // Create a new node for each word
        // typedef struct node
        // {
        //     char word[LENGTH + 1];
        //     struct node *next;
        // }
        // node;

        // Maybe tries?
        

        node new_node = malloc(sizeof(node));
        new_node->word = next_word;

        // Hash word to obtain a hash value
        int index = hash(new_node);

        // Insert node into hash table at that location

    }

    fclose(f);
    return true;

    // If unsuccessful, return false
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
