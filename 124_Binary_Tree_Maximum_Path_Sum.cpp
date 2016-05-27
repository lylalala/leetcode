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
private:
    int res;
    int mv;
public:
    int dfs(TreeNode* root){
        if(root==NULL)
            return 0;
        mv=max(mv,root->val);
        int leftmax=0,rightmax=0,maxvalue=0;
        if(root->left!=NULL){
            leftmax=dfs(root->left);
            maxvalue=max(maxvalue,leftmax);
        }
        if(root->right!=NULL){
            rightmax=dfs(root->right);
            maxvalue=max(maxvalue,rightmax);
        }
        res=max(res,leftmax+rightmax+root->val);
        return max(max(root->val,maxvalue+root->val),0);
    }
    int maxPathSum(TreeNode* root) {
        mv=INT_MIN;
        res=max(dfs(root),res);
        if(mv<0)
            return mv;
        else
            return res;
    }
};
