#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{

public:
    Node *copyRandomList(Node *head)
    {
        if (head == NULL)
        {
            return NULL;
        }

        Node *oldNode = head;
        Node *newNode = new Node(oldNode->val);

        map[oldNode] = newNode;

        while (oldNode != NULL)
        {
            newNode->next = getClone(oldNode->next);
            newNode->random = getClone(oldNode->random);
            oldNode = oldNode->next;
            newNode = newNode->next;
        }

        return map[head];
    }

private:
    unordered_map<Node *, Node *> map;

    Node *getClone(Node *node)
    {
        if (node == NULL)
        {
            return NULL;
        }

        if (map.find(node) != map.end())
        {
            return map[node];
        }

        map[node] = new Node(node->val);
        return map[node];
    }
};