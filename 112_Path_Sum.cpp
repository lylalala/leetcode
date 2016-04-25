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
    int s;
public:
    bool dfs(TreeNode* root,int sum){
        if(root!=NULL&&root->left==NULL&&root->right==NULL&&sum+root->val==s)
            return true;
        // if(root!=NULL&&sum+root->val>=s)
        //     return false;
        if(root!=NULL){
            if(root->left!=NULL&&dfs(root->left,sum+root->val))
                return true;
            if(root->right!=NULL&&dfs(root->right,sum+root->val))
                return true;
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        s=sum;
        return dfs(root,0);
    }
};
