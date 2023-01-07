#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;

    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
};

Node *cloneGraph(Node *node)
{

    if (node == NULL)
    {
        return NULL;
    }

    unordered_map<Node *, Node *> map;
    queue<Node *> q;
    Node *newRoot = new Node(node->val);
    map[node] = newRoot;

    q.push(node);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        for (int i = 0; i < curr->neighbors.size(); i++)
        {
            Node *currNeighbor = curr->neighbors[i];

            if (map.find(currNeighbor) == map.end())
            {
                map[currNeighbor] = new Node(currNeighbor->val);
                q.push(currNeighbor);
            }

            map[curr]->neighbors.push_back(map[currNeighbor]);
        }
    }

    return newRoot;
}