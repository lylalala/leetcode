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
    void postorder(TreeNode* root,TreeNode* dp){
        dp->val=root->val;
        if(root->left!=NULL){
            dp->left=new TreeNode(0);
            postorder(root->left,dp->left);
        }
        if(root->right!=NULL){
            dp->right=new TreeNode(0);
            postorder(root->right,dp->right);
        }
        dp->val=max(max(((dp->left!=NULL)?dp->left->val:0)+((dp->right!=NULL)?dp->right->val:0),((dp->left!=NULL&&dp->left->left!=NULL)?dp->left->left->val:0)+((dp->left!=NULL&&dp->left->right!=NULL)?dp->left->right->val:0)+((dp->right!=NULL&&dp->right->left!=NULL)?dp->right->left->val:0)+((dp->right!=NULL&&dp->right->right!=NULL)?dp->right->right->val:0)+root->val),root->val);
    }
    int rob(TreeNode* root) {
        if(root==NULL)
            return 0;
        TreeNode* dpRoot=new TreeNode(0);
        postorder(root,dpRoot);
        return dpRoot->val;
    }
};
