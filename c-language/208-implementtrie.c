/* 
  Implement a trie with insert, search, and startsWith methods.
  
  Runtime: 48ms
  Memory: 37.7MB
  Top 93.52% of C submissions
*/

#include <string.h>
#include <stdbool.h>

typedef struct trieNode{
    int isLeaf;
    struct trieNode* child[26];
} Trie;

/** Initialize your data structure here. */

Trie* trieCreate() {
    Trie *base = (Trie *)malloc(sizeof(Trie));
    if (base != NULL)
    {
        base->isLeaf = -1;
        for (int i = 0; i < 26; i++)
        {
            base->child[i] = NULL;
        }
    }
    return base;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char * word) {
    Trie *traversal = obj;
    while (*word != '\0')
    {
        int index = *word - 'a';
        if (traversal->child[index] == NULL)
            traversal->child[index] = trieCreate();
        if (traversal->child[index]->isLeaf != 1) traversal->child[index]->isLeaf = 0;
        traversal = traversal->child[index];
        word++;
    }
    traversal->isLeaf = 1;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char * word) {
    Trie *traversal = obj;
    while (*word != '\0')
    {
        int index = *word - 'a';
        if (traversal->child[index] != NULL)
        {
            traversal = traversal->child[index];
            word++;
        }
        else
            return false;
    }
    if (traversal->isLeaf == 1)
        return true;
    else
        return false;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char * prefix) {
  Trie *traversal = obj;
    while (*prefix != '\0')
    {
        int index = *prefix - 'a';
        if (traversal->child[index] != NULL)
        {
            traversal = traversal->child[index];
            prefix++;
        }
        else
            return false;
    }
    return true;
}

void trieFree(Trie* obj) {
    for(int i = 0; i < 26; i++)
    {
        if (obj->child[i] != NULL)
            return trieFree(obj->child[i]);
    }
    free(obj);
    return;
    
}

/** comments by Leetcode
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/
