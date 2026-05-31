#include<stdio.h>
#include<stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
void func(struct TreeNode* root, int* res, int* returnSize)
{
    if (root == NULL) return;
    res[*returnSize] = root->val;
    (*returnSize)++;
    func(root->left, res, returnSize);
    func(root->right, res, returnSize);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int* res = (int*)malloc(sizeof(int) * 100);
    func(root, res, returnSize);
    return res;
}
