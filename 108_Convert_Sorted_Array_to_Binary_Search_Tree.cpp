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
    TreeNode* build(vector<int>& num,int b,int e){
        if(b>=e)
            return NULL;
        int m=(b+e)/2;
        TreeNode* root=new TreeNode(num[m]);
        root->left=build(num,b,m);
        root->right=build(num,m+1,e);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums,0,nums.size());
    }
};
