#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *invertTree(TreeNode *root);

int main()
{
    TreeNode *root = new TreeNode();
    root->val = 4;
    TreeNode *l1 = new TreeNode();
    l1->val = 2;
    TreeNode *l2 = new TreeNode();
    l2->val = 1;
    TreeNode *l3 = new TreeNode();
    l3->val = 3;
    TreeNode *r1 = new TreeNode();
    r1->val = 7;
    TreeNode *r2 = new TreeNode();
    r2->val = 6;
    TreeNode *r3 = new TreeNode();
    r3->val = 9;

    root->left = l1;
    root->right = r1;
    l1->left = l2;
    l1->right = l3;

    r1->left = r2;
    r1->right = r3;

    invertTree(root);
}

// recrusive solution
TreeNode *invertTree(TreeNode *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    swap(root->left, root->right);

    invertTree(root->left);
    invertTree(root->right);

    return root;
}

// iterative solution using stack, using a queue is exactly the same but bfs traversal

/* TreeNode *inverTree(TreeNode *root)
{

    if (root == NULL)
    {

        return NULL;
    }

    stack<TreeNode *> s;

    s.push(root);

    while (!s.empty())
    {

        TreeNode *curr = s.top();
        s.pop();

        swap(curr->left, curr->right);

        if (curr->left != NULL)
        {
            s.push(curr->left);
        }

        if (curr->right != NULL)
        {

            s.push(curr->right);
        }
    }

    return root;
} */

