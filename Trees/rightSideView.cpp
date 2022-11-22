#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

vector<int> rightSideView(TreeNode *root)
{
    vector<int> ans;

    if (root == NULL)
    {
        return ans;
    }

    queue<TreeNode *> q;

    q.push(root);

    while (!q.empty())
    {
        int count = q.size();
        vector<int> curr;

        for (int i = 0; i < count; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            curr.push_back(node->val);

            if (node->left != NULL)
            {
                q.push(node->left);
            }
            if (node->right != NULL)
            {
                q.push(node->right);
            }
        }

        ans.push_back(curr[curr.size() - 1]);
    }

    return ans;
}