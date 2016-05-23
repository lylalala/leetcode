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
    vector<string> result;
    string res;
public:
    void dfs(TreeNode* root){
        string temp=to_string(root->val);
        res=res+"->"+temp;
        if(root->left==NULL&&root->right==NULL){
            result.push_back(res);
        }else{
            if(root->left!=NULL){
                dfs(root->left);    
            }
            if(root->right!=NULL){
                dfs(root->right);
            }
        }
        res=res.substr(0,res.length()-2-temp.length());
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        res="";
        if(root==NULL)
            return result;
        res=res+to_string(root->val);
        if(root->left==NULL&&root->right==NULL)
            result.push_back(res);
        if(root->left!=NULL)
            dfs(root->left);
        if(root->right!=NULL)
            dfs(root->right);
        return result;
    }
};
