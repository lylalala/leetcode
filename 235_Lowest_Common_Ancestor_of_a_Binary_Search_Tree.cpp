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
    vector<TreeNode*> path1;
    vector<TreeNode*> path2;
    bool find1;
    bool find2;
public:
    void solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL) return;
        if(root==p){
            path1.push_back(root);
            find1=true;
        }
        if(root==q){
            path2.push_back(root);
            find2=true;
        }
        if(!find1) path1.push_back(root);
        if(!find2) path2.push_back(root);
        if(!(find1&&find2)) solve(root->left,p,q);
        if(!(find1&&find2)) solve(root->right,p,q);
        if(!find1) path1.pop_back();
        if(!find2) path2.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        find1=find2=false;
        if(root==NULL) return NULL;
        solve(root,p,q);
        for(int i=1;i<path1.size()&&i<path2.size();i++){
            if(path1[i]!=path2[i])
                return path1[i-1];
        }
        if(path1.size()<path2.size()) return path1.back();
        else return path2.back();
        return NULL;
    }
};
