#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <cs50.h>


#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

int total_words = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int key = hash(word);
    
    node *cursor = table[key];
    
    while(cursor != NULL)
    {
        if(strcasecmp(cursor -> word, word) == 0)
        {
            return true;
        }
        cursor = cursor -> next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int sum = 0;
    
    for(int i = 0; word[i]!= '\0'; i++)
    {
        sum += tolower(word[i]);
    }
    
   return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r'");
    if(file == NULL)
    {
        return false; 
    }
    
    for(int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
    char tmp_word[LENGTH +1];
    
    while(fscanf(file, "%s\n", tmp_word) != EOF)
    {
        node *new_node = malloc(sizeof(node));
        strcpy(new_node -> word, tmp_word);
        
        int key = hash(tmp_word);
        
        if(table[key] == NULL)
        {
            new_node -> next = NULL;
            table[key] = new_node; 
        }
        else
        {
            new_node -> next = table[key];
            table[key] = new_node;
        }
        
        total_words++;
    }
    fclose(file);
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
   for(int i = 0; i < N; i++)
   {
       node *head = table[i];
       
       while(head != NULL)
       {
           node *delete_ = head;
           head = head -> next;
           free(delete_);
       }
      table[i] = NULL;
   }
    return true;
}
