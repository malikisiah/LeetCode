#include <bits/stdc++.h>

using namespace std;


struct TreeNode{
    int val;

    TreeNode* left;
    TreeNode* right;

};


bool isBalanced (TreeNode* root){

if (dfs(root) == -1){
    return false;
}

return true;


}



int dfs(TreeNode* root){
if (root == NULL){
    return 0;
}

int leftHeight = dfs(root->left);
if (leftHeight == -1){
    return -1;
}
int rightHeight = dfs(root->right);

if (rightHeight == -1){
    return -1;
}


if (abs(leftHeight - rightHeight) > 1){
    return -1;
}


return 1 + (max(leftHeight, rightHeight));

}