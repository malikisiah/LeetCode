#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    char val;
    TreeNode *left;
    TreeNode *right;
    bool hasParent;
};

TreeNode *constructTree(string input, string &result);

void printTree(TreeNode *root);

bool hasCycle(TreeNode *root, string &result);

int main()
{
    unordered_map<char, TreeNode *> map;

    string input = "(A,B) (A,C) (B,C) (B,D)";
    string result = "";

    TreeNode *node = constructTree(input, result);
    hasCycle(node, result);
    if (result == "")
    {
        printTree(node);
    }
    else
    {
        cout << result;
    }
}

TreeNode *constructTree(string input, string &result)
{
    unordered_map<char, TreeNode *> map;

    if (input[0] != '(' || input[input.size() - 1] != ')') // if input format is invalid
    {
        result = "E1";
        return NULL;
    }

    // creating a node each value in the string
    for (int i = 0; i < input.size(); i++)
    {
        if (iswalnum(input[i]) != 0 && map.find(input[i]) == map.end())
        {
            TreeNode *node = new TreeNode();
            map.insert({input[i], node});
            map.at(input[i])->val = input[i];
        }
    }

    // assigned child for each node pair
    for (int i = 0; i < input.size() - 3; i++)
    {
        if (iswalnum(input[i]) != 0)
        {
            if (map.at(input[i])->left == NULL)
            {
                map.at(input[i])->left = map.at(input[i + 2]);
                map.at(input[i])->left->hasParent = true;
                i = input.find('(', i);
                if (i == -1)
                    break;
            }
            else if (map.at(input[i])->left == map.at(input[i + 2])) // if node is attemping to place the same left child and right child i.e) duplicate pair
            {
                result = "E2";
                return NULL;
            }

            else if (map.at(input[i])->right != NULL) // if a node has more than 2 children
            {
                result = "E3";
                return NULL;
            }
            else
            {
                map.at(input[i])->right = map.at(input[i + 2]);
                map.at(input[i])->right->hasParent = true;
                i = input.find('(', i);
                if (i == -1)
                    break;
            }
        }
    }

    int count = 0;
    TreeNode *root = new TreeNode();
    for (auto x : map)
    {
        if (x.second->hasParent == false)
        {
            count++;
            root = x.second;
        }
    }

    if (count > 1) // if tree has multiple roots
    {
        result = "E4";
        return NULL;
    }

    return root;
}

void printTree(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << "(";
    cout << root->val;
    printTree(root->left);
    printTree(root->right);
    cout << ")";
}
bool hasCycle(TreeNode *root, string &result)
{
    if (root == NULL)
    {
        return false;
    }

    unordered_set<TreeNode *> set;
    stack<TreeNode *> stk;
    stk.push(root);

    while (!stk.empty())
    {
        TreeNode *node = stk.top();
        stk.pop();

        if (set.find(node) != set.end())
        {
            if (result == "")
            {
                result = "E5";
            }
            return true;
        }
        else
        {
            set.insert(node);
        }

        if (node->left != NULL)
        {
            stk.push(node->left);
        }

        if (node->right != NULL)
        {
            stk.push(node->right);
        }
    }

    return false;
}