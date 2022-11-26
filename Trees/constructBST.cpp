#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int index = 0;
    return build(preorder, inorder, index, 0, inorder.size() - 1);
}

TreeNode *build(vector<int> &preorder, vector<int> &inorder, int &index, int i, int j)
{
    if (i > j)
    {
        return NULL;
    }

    TreeNode *root = new TreeNode(preorder[index]);

    int split = 0;

    for (int i = 0; i < preorder.size(); i++)
    {
        if (preorder[index] == inorder[i])
        {
            split = i;
            break;
        }
    }
    index++;

    root->left = build(preorder, inorder, index, i, split - 1);
    root->right = build(preorder, inorder, index, split + 1, j);
}