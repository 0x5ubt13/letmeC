// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table, tweaking to make it a trie node
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
    node *root = malloc(sizeof(node));

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

// Helper function to insert a new word in the table
node insert_node(node *root, char *raw_word) 
{
    // Set temp node pointer to root to start traversing the tree
    node *temp = root;

    char *word = tolower(raw_word);

    // Loop over every letter of the word
    for (int i = 0; word[i] != '\0'; i++)
    {
        // Get the number of the letter 
        int index = (int)word[i] - 'a';
        
        // Create new child if empty
        if (temp->next[index] == NULL)
        {
            temp->next[index] = create_node(word[i]);
        }
        
        // Follow the child
        temp = temp->next[index];
    }    

    // End of the word, mark current node as word
    temp->is_word = true;

    return root;
}

// Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table - modified to be the root of the trie node
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    node *temp = table;
    char *lowercase_word = tolower(word);

    for (int i = 0; lowercase_word[i] != '\0'; i++)
    {
        // Get the numerical value for the letter
        int pos = lowercase_word[i] - 'a'; 
        
        // Check whether it exists
        if (temp->next == NULL)
        {
            return false;
        }
        
        // If exists, traverse to next position
        temp = temp->next[pos];
    }

    // If traversed to the end of the word and trie node is true, return check successful
    if (temp != NULL && temp->is_word == true)
    {
        return true;
    }
    
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Return the numerical number of each letter plus the incremental value of i to avoid collisions
    char *lowercase_word = tolower(word);

    int hashed_result = 0;

    for (int i = 0; lowercase_word[i] = '\0'; i++)
    {
        hashed_result += lowercase_word[i] - 'A' + i;
    }
    
    return hashed_result;
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

    table = create_node();
    char *next_word = malloc(sizeof(char) * LENGTH);
    if (next_word == NULL)
    {
        return false;
    }
    
    // Read strings from file one at a time
    while (fscanf(f, "%s", next_word) != EOF)
    {
        // Load word in the trie node
        table = insert_node(table, next_word);

        // Hash word to obtain a hash value
        int new_hash = hash(next_word);

        // Insert node into hash table at that location
        // skipping for now
    }

    fclose(f);
    
    return true;
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
