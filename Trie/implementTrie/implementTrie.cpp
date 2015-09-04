
//Method I

//Implement Trie

#include <iostream>
#include <string>

#define ALPHABET_SIZE (26)

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

int charToInt(char c)
{
    return ((int)c - (int)'a');
}

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
        index = charToInt(str[level]);
        if(pCrawl->children[index] == NULL)
            pCrawl->children[index] = getNode();
        pCrawl = pCrawl->children[index];
    }
    pCrawl->value = pTrie->counts;
}

int search(trie* pTrie, string str)
{
    int level;
    int length = str.size();
    int index;
    trie_node* pCrawl;

    pCrawl = pTrie->root;
    for(level = 0; level < length; level++) {
        index = charToInt(str[level]);
        if(pCrawl->children[index] == NULL)
            return 0;
        pCrawl = pCrawl->children[index];
    }
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

=========================================================================================
=========================================================================================

//Method II
#include <iostream>
#include <string>

#define ALPHABET_SIZE (26)

using namespace std;

struct TrieNode
{
    char c;
    TrieNode* children[ALPHABET_SIZE];
};


int charToInt(char c)
{
    return ((int)c - (int)'a');
}

TrieNode* getNode(char ch)
{
    TrieNode* pNode = new TrieNode;
    pNode->c = ch;
    for(int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
    return pNode;
}

void insert(TrieNode* root ,string word)
{
    int level;
    int length = word.size();
    int index;
    TrieNode* pCrawl = root;
    for(level = 0; level < length; level++) {
        index = charToInt(word[level]);
        if(pCrawl->children[index] == NULL)
            pCrawl->children[index] = getNode(word[level]);
        pCrawl = pCrawl->children[index];
    }
}

bool search(TrieNode* root ,string word)
{
    int level;
    int length = word.size();
    int index;
    TrieNode* pCrawl = root;

    for(level = 0; level < length; level++) {
        index = charToInt(word[level]);
        if(pCrawl->children[index] == NULL)
            return false;
        pCrawl = pCrawl->children[index];
    }
    return (level == length) ? true : false;
}

bool startsWith(string prefix)
{
    return false;
}

void initialize(TrieNode* root)
{
    if(root != NULL) {
        root->c = ' ';
        for(int i = 0; i < ALPHABET_SIZE; i++)
            root->children[i] = NULL;
    }
}

int main()
{
    string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    int n = sizeof(keys) / sizeof(keys[0]);
    TrieNode* root = new TrieNode;
    initialize(root);
    for(int i = 0; i < n; i++)
        insert(root, keys[i]);
    bool result = search(root, "a");
    if(result)
        cout<<"find the string"<<endl;
    else
        cout<<"not find one"<<endl;
    return 0;
}


=========================================================================================
=========================================================================================

//Method III

#include <iostream>
#include <string>

using namespace std;


class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode* children[26];
    bool isWord;
    TrieNode() : isWord(false){
        for(int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* pCrawl = root;
        int level;
        int index;
        int length = word.size();
        for(level = 0; level < length; level++) {
            index = word[level] - 'a';
            if(pCrawl->children[index] == NULL)
                pCrawl->children[index] = new TrieNode();
            pCrawl = pCrawl->children[index];
        }
        pCrawl->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        int level;
        int index;
        int length = word.size();
        TrieNode* pCrawl = root;
        for(level = 0; level < length; level++) {
            index = word[level] - 'a';
            if(pCrawl->children[index] == NULL)
                return false;
            pCrawl = pCrawl->children[index];
        }
        if(pCrawl->isWord)
            return true;
        else
            return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* pCrawl = root;
        int level;
        int index;
        int length = prefix.size();
        for(level = 0; level < length; level++) {
            index = prefix[level] - 'a';
            if(pCrawl->children[index] == NULL)
                return false;
            pCrawl = pCrawl->children[index];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");






