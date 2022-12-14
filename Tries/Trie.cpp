#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    TrieNode *children[26];
    bool isWord;

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }

        isWord = false;
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *node = root;
        int curr = 0;

        for (int i = 0; i < word.size(); i++)
        {
            curr = word[i] - 'a'; // finding position of letter in alphabet
            if (node->children[curr] == NULL)
            {
                node->children[curr] = new TrieNode();
            }
            node = node->children[curr];
        }

        node->isWord = true;
    }

    bool search(string word)
    {
        int index = 0;
        TrieNode *node = root;

        for (int i = 0; i < word.size(); i++)
        {
            index = word[i] - 'a';
            if (node->children[index] == NULL)
            {
                return false;
            }
            node = node->children[index];
        }

        return node->isWord;
    }

    bool startsWith(string word)
    {
        int index = 0;
        TrieNode *node = root;

        for (int i = 0; i < word.size(); i++)
        {
            index = word[i] - 'a';
            if (node->children[index] == NULL)
            {
                return false;
            }
            node = node->children[index];
        }

        return true;
    }
};