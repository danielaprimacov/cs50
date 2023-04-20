// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
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
const unsigned int N = 10000;

// Hash table
node *table[N];

// Counter for words in dictionary
int count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // Creating copy of the word
    int l = strlen(word);
    char copy[LENGTH + 1];
    for (int i = 0; i < l; i++)
    {
        copy[i] = tolower(word[i]);
    }
    // Adding null terminator to end string
    copy[l] = '\0';
    // Initializng index for hashes
    int h = hash(copy);
    // Seting cursor to point to same address as hashtables index
    node *cursor = table[h];
    // While cursor doesnt point to NULL, search dictionary for word
    while (cursor != NULL)
    {
        // true if word has been found
        if (strcasecmp(cursor -> word, copy) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor -> next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int hash = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        hash = (hash << 2) ^ word[i];
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    // Scan dictionary word by words
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        // Allocate memory for each word
        node *new = malloc(sizeof(node));
        // Check if memory is allocated
        if (new == NULL)
        {
            return false;
        }
        // Copy word into node
        strcpy(new -> word, word);
        new -> next = NULL;
        // Initializing and calculating index of word
        int h = hash(new -> word);
        // Initializing head to poitn to hashtable
        node *head = table[h];
        // Inserting new nodes at beginning of lists
        if (head == NULL)
        {
            table[h] = new;
        }
        else
        {
            new -> next = table[h];
            table[h] = new;
        }
        count++;
    }
    // Close opened file
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            node *temp = table[i] -> next;
            free(table[i]);
            table[i] = temp;
        }
    }
    return true;
}
