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
    int depth(TreeNode* root){
        if(root==NULL) return 0;
        if(root->left==NULL&&root->right==NULL) return 1;
        int leftDepth=depth(root->left);
        int rightDepth=depth(root->right);
        if(leftDepth==-1||rightDepth==-1) return -1;
        int diff=(rightDepth>leftDepth)?rightDepth-leftDepth:leftDepth-rightDepth;
        if(diff>1) return -1;
        return 1+max(rightDepth,leftDepth);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        if(depth(root)==-1)
            return false;
        else
            return true;
    }
};
