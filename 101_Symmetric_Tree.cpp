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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return same(root->left,root->right);
    }
    bool same(TreeNode* a,TreeNode* b){
        if(a==NULL&&b==NULL)
            return true;
        if(a==NULL||b==NULL)
            return false;
        if(a->val!=b->val)
            return false;
        if(!same(a->left,b->right))
            return false;
        if(!same(a->right,b->left))
            return false;
        return true;
    }
};
