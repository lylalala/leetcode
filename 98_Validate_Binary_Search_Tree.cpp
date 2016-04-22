/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long long small=-2147483649;
        long long big=2147483648;
        return isBST(root,small,big);
    }
    bool isBST(TreeNode* root,long long small,long long big){
        if(root==NULL)
            return true;
        long long num=root->val;
        TreeNode* l=root->left;
        TreeNode* r=root->right;
        if(l!=NULL&&(l->val>=num||l->val<=small))
            return false;
        if(r!=NULL&&(r->val<=num||r->val>=big))
            return false;
        return isBST(l,small,num)&&isBST(r,num,big);
    }
};
