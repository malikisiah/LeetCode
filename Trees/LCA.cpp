#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (p->val > root->val && q->val > root->val)
    {
        lowestCommonAncestor(root->right, p, q);
    }

    else if (p->val < root->val && q->val < root->val)
    {
        lowestCommonAncestor(root->left, p, q);
    }
    else
    {
        return root;
    }
}