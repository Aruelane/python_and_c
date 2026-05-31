#include<stdio.h>
#include <limits.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void func(struct TreeNode* root,int arr[],int *i)
{
    if(root==NULL)return ;
    arr[*i] = root->val;
    *i=*i+1;
    func(root->left,arr,i);
    func(root->right,arr,i);
}
int findSecondMinimumValue(struct TreeNode* root) {
    if(root->left==NULL)return -1;
    int i=0,j,ans;
    int arr[25];
    func(root,arr,&i);
    ans=INT_MAX;
    for(j=1;j<i;j++)
    {
        if(arr[j]!=arr[0]&&arr[j]<ans) ans = arr[j];
    }
    if(ans==INT_MAX&&root->left->val!=INT_MAX&&root->right->val!=INT_MAX)return -1;
    else if(root->left->val==INT_MAX&&root->right->val==INT_MAX) return -1;
    else return ans;
    
}