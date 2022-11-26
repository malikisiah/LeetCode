#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isValidBST(TreeNode *root)
{
    TreeNode *prev = NULL;
    return inOrder(root, prev);
}

bool inOrder(TreeNode *root, TreeNode *&prev)
{
    if (root == NULL)
    {
        return true;
    }

    if (!inOrder(root->left, prev))
    {
        return false;
    }

    if (prev != NULL && prev->val >= root->val)
    {
        return false;
    }

    prev = root;

    if (!inOrder(root->right, prev))
    {
        return false;
    }
    return true;
}