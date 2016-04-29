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
    TreeNode* build(vector<int>& inorder,int is,int ie,vector<int>& postorder,int ps,int pe){
        if(is>=ie)
            return NULL;
        TreeNode* root=new TreeNode(postorder[pe-1]);
        int pos=is;
        for(;pos<ie;pos++){
            if(inorder[pos]==postorder[pe-1])
                break;
        }
        int lenfirst=pos-is;
        root->left=build(inorder,is,pos,postorder,ps,ps+lenfirst);
        root->right=build(inorder,pos+1,ie,postorder,ps+lenfirst,pe-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0)
            return NULL;
        return build(inorder,0,inorder.size(),postorder,0,postorder.size());
    }
};
