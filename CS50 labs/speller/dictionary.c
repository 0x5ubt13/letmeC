// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table, tweaking to make it a trienode
typedef struct node
{
    char ch;
    struct node *next[LENGTH + 1];
    bool is_word;
}
node;

// Helper function to create a new node, allocating mem and setting all children to null
node *create_node() 
{
    node *root = malloc(sizeof(node))

    for (int i = 0; i < LENGTH; i++)
    {
        root->next[i] = NULL;
    }
    root->is_word = false;

    return root;
}

// Get it cleaned up recursively
void free_node(node *to_free) 
{
    for (int i = 0; i < LENGTH; i++)
    {
        if (to_free->next[i] != NULL)
        {
            free_node(to_free->next[i]);
        }
        else
        {
            continue;
        }
    }

    free(to_free);
}


// Insert a new word in the table
node insert_node(node *root, char *word) 
{
    // Set temp node to root to start traversing the tree
    node *temp = root;

    // Loop over every letter of the word
    for (int i = 0; word[i] != '\0'; i++)
    {
        // Get the number of the letter 
        int index = (int)word[i] - 'a';
        
        // Create new child if empty
        if (temp->children[index] == NULL)
        {
            temp->children[index] = create_node(word[i]);
        }
        
        // Follow the child
        temp = temp->children[index];
    }    

    // End of the work, mark current node as word
    temp->is_word = true;

    return root;
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
    // Return the numerical number of each letter in an array together?
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
        // Parse letter by letter
        for (int i = 0; i < strlen(next_word); i++) 
        {
            //not convinced by this, will research other options
        }

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
    // Breadth-first search? Look for every terminal node and stop if next pointer is null, then go back to previous node
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
