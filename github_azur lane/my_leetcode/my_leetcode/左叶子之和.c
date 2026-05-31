#include<stdio.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

 void func(struct TreeNode*root,struct TreeNode *parent,int *sum)
 {
    if(root==NULL) return;
    if(root->left==NULL&&root->right==NULL&&root==parent->left) *sum += root->val;
    func(root->left,root,sum);
    func(root->right,root,sum);
 }
int sumOfLeftLeaves(struct TreeNode* root) {
    int sum=0;
    func(root,root,&sum);
    return sum;
}