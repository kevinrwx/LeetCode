//test
//Implement Trie

#include <iostream>
#include <string>

#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

using namespace std;

//typedef struct trie_node trie_node_t;
struct trie_node
{
    int value;
    trie_node* children[ALPHABET_SIZE];
};

//typedef struct trie trie_t;
struct trie
{
    trie_node* root;
    int counts;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

trie_node* getNode()
{
    trie_node* pNode = new trie_node;
    pNode->value = 0;
    if(pNode != NULL) {
        for(int i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }
    return pNode;
}

void initialize(trie* pTrie)
{
    pTrie->root = getNode();
    pTrie->counts = 0;
}

void insert(trie* pTrie, string str)
{
    int level;
    int length = str.size();
    int index;
    trie_node* pCrawl;

    pTrie->counts++;
    pCrawl = pTrie->root;
    for(level = 0; level < length; level++) {
        index = CHAR_TO_INDEX(str[level]);
        if(pCrawl->children[index] == NULL)
            pCrawl->children[index] = getNode();
        pCrawl = pCrawl->children[index];
    }
    pCrawl->value = pTrie->counts;
    cout<<"Insert: "<<pCrawl->value<<endl;
}

int search(trie* pTrie, string str)
{
    int level;
    int length = str.size();
    int index;
    trie_node* pCrawl;

    pCrawl = pTrie->root;
    for(level = 0; level < length; level++) {
        index = CHAR_TO_INDEX(str[level]);
        if(pCrawl->children[index] == NULL)
            return 0;
        pCrawl = pCrawl->children[index];
    }
//    cout<<"Search: "<<pCrawl->value<<endl;
//    return pCrawl->value;
    return (0 != pCrawl && pCrawl->value);
}


int main()
{
    string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    trie tr;
    int n = sizeof(keys) / sizeof(keys[0]);
    initialize(&tr);
    for(int i = 0; i < n; i++)
        insert(&tr, keys[i]);
    int result = search(&tr, "a");
    cout<<result<<endl;
    return 0;
}



