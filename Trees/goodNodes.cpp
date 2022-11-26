#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

int goodNodes(TreeNode *root)
{
    int result = 0;

    dfs(root, root->val, result);

    return result;
}

void dfs(TreeNode *root, int maxVal, int &result)
{
    if (root == NULL)
    {
        return;
    }

    if (root->val >= maxVal)
    {
        result++;
    }

    dfs(root->left, max(maxVal, root->val), result);
    dfs(root->right, max(maxVal, root->val), result);
}