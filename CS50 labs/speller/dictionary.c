// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table, tweaking to make it a trie node

// Helper function to create a new node, allocating mem and setting all children to null
node *create_node() 
{
    node *root = (node*) malloc(sizeof(node));

    for (int i = 0; i < N; i++)
    {
        root->next[i] = NULL;
    }
    root->is_word = false;

    return root;
}

// Get it cleaned up recursively
void free_node(node *to_free) 
{
    for (int i = 0; i < LENGTH+1; i++)
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
void insert_node(node *root, char *raw_word) 
{
    printf("Starting insert_node()");

    // Set temp node pointer to root to start traversing the tree
    node *temp = root;
    
    // Loop over every letter of the word
    for (int i = 0; raw_word[i] != '\0'; i++)
    {
        int index;
        // Get the number of the letter 
        if (islower(raw_word[i]) == 0)
        {
            index = (int) tolower(raw_word[i]) - 'a';
        }
        else
        {
            index = (int) raw_word[i] - 'a';
        }
        printf("%i", index);
        // Create new child if empty
        if (temp->next[index] == NULL)
        {
            temp->next[index] = create_node();
        }
        
        // Follow the child
        temp = temp->next[index];
    }    

    // End of the word, mark current node as word and add 1 to the global count
    temp->is_word = true;
}

int total_words = 0;

// Hash table - modified to be the root of the trie node
node *table;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    node *temp = table;

    int len = strlen(word);
    char lowercase_word[len+1];
    for (int i = 0; word[i]; i++)
    {
        lowercase_word[i] = tolower(word[i]);
    }

    for (int i = 0; lowercase_word[i] != '\0'; i++)
    {
        // Get the numerical value for the letter
        int pos = lowercase_word[i] - 'a'; 
        
        // Check whether it exists
        if (temp->next[pos] == NULL)
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
    int len = strlen(word);
    char lowercase_word[len+1];
    for (int i = 0; word[i]; i++)
    {
        lowercase_word[i] = tolower(word[i]);
    }

    int hashed_result= 0;

    for (int i = 0; lowercase_word[i] == '\0'; i++)
    {
        hashed_result += lowercase_word[i] - 'A' + i;
    }
    
    return hashed_result;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    printf("Starting load()");

    // TODO
    // Open dictionary file, create root node and declare space for words
    FILE *f = fopen(dictionary, "r"); 
    if (f == NULL) 
    { 
        return false; 
    }

    char next_word[50];
   
    
    // Read strings from file one at a time
    while (fscanf(f, "%s", next_word) != EOF)
    {
        printf("Starting fscanf()");

        // Load word in the trie node
        insert_node(table, next_word);
        total_words++;

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
    return total_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    free_node(table);

    return true;
}
