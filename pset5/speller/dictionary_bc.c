// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "dictionary.h"

#define HASHTABLELENGTH 10000

typedef struct _node
{
    char *word;
    struct _node* next;
} node;

int NoOfWords = 0;

node* hashtable[HASHTABLELENGTH] = { NULL };

// Hashing Function credits: http://www.cse.yorku.ca/~oz/hash.html (djb2)
unsigned long hash(const char *str)
    {
        unsigned long hash = 5381;
        int c;

        while ((c = *str++))
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash;
    }

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    unsigned long hashedValue = 0;

    char s[strlen(word)+1];
    for(int i = 0;i < strlen(word); i++)
    {
        s[i] = tolower(word[i]);
    }
    s[strlen(word)] = '\0';

    hashedValue = hash(s) % HASHTABLELENGTH;
    node* PTR = hashtable[hashedValue];

    while(PTR != NULL)
    {
        if(strcmp(PTR->word,s) == 0)
        {
            return true;
        }
        PTR = PTR->next;
    }
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *inFile = fopen(dictionary,"r");
    if (!inFile)
    {
        fprintf(stderr,"Could not open File!!!");
        return false;
    }
    char tempStr[LENGTH+1] = {};
    unsigned long hashedValue=0;
    while(fscanf(inFile,"%s",tempStr))
    {
        if(feof(inFile))
        {
            fclose(inFile);
            break;
        }
        hashedValue = hash(tempStr) % HASHTABLELENGTH;
        node *PTR = (node *) malloc(sizeof(node));
        if (PTR == NULL)
        {
            fprintf(stderr,"Could not allocate memory");
            return false;
        }
        PTR->word = (char*) malloc((strlen(tempStr) + 1) * sizeof(char));
        if(PTR->word == NULL) return false;
        strcpy(PTR->word,tempStr);
        PTR->next = hashtable[hashedValue];
        hashtable[hashedValue] = PTR;
        NoOfWords++;
    }
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return NoOfWords;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    node* current = NULL;
    for(int i = 0; i<HASHTABLELENGTH;i++)
    {
        while(hashtable[i] != NULL)
        {
            current = hashtable[i];
            hashtable[i] = current->next;
            free(current->word);
            free(current);
        }
    }
    return true;
}