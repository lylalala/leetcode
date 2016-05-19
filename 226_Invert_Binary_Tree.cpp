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
    void dfs(TreeNode* root){
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;
        if(root->left!=NULL)
            dfs(root->left);
        if(root->right!=NULL)
            dfs(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
            return NULL;
        dfs(root);
        return root;
    }
};
