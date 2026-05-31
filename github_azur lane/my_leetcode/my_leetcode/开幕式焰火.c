#include<stdio.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

 void func(struct TreeNode*root,int arr[])
 {
    if(root==NULL)return;
    arr[root->val]=1;
    func(root->left,arr);
    func(root->right,arr);
 }
int numColor(struct TreeNode* root){
      int arr[1001]={0},j,count=0;
      func(root,arr);
      for(j=0;j<1001;j++)
      {
           if(arr[j]==1) count++;
      }
      return count;
}