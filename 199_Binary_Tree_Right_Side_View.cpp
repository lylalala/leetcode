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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root==NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        // res.push_back(root->val);
        q.push(NULL);
        while(q.front()!=NULL){
            int thisValue;
            while(q.front()!=NULL){
                TreeNode* temp=q.front();
                q.pop();
                thisValue=temp->val;
                if(temp->left!=NULL)
                    q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);
            }
            q.pop();
            q.push(NULL);
            res.push_back(thisValue);
        }
        return res;
    }
};
