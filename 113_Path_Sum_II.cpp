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
    vector<vector<int>> result;
    vector<int> res;
public:
    void dfs(TreeNode* root,int sum){
        if(root!=NULL&&root->left==NULL&&root->right==NULL&&sum==root->val){
            res.push_back(root->val);
            result.push_back(res);
            res.pop_back();
        }else{
            //if(root->val<=sum){
                res.push_back(root->val);
                if(root->left!=NULL) dfs(root->left,sum-root->val);
                if(root->right!=NULL) dfs(root->right,sum-root->val);
                res.pop_back();
            //}
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return result;
        dfs(root,sum);
        return result;
    }
};
