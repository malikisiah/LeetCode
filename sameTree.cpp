#include <bits/stdc++.h>

using namespace std;


struct TreeNode{
    int val;

    TreeNode* left;
    TreeNode* right;
};

bool isSameTree(TreeNode* p, TreeNode* q){

    // Base Cases
    if (p == NULL && q == NULL){
        return true;
    }

    if (p == NULL || q == NULL || p->val != q->val){
        return false;
    }


    //Recursive Call

    return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}