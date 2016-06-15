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
    int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        int res=0;
        TreeNode* temp=root;
        int depth=0;

        //1.get the depth
        while(temp->left!=NULL){
            depth++;
            temp=temp->left;
        }
        
        //2.get the number of leaves in last level
        temp=root;
        int i=0;
        while(temp!=NULL){
            //deal with compelete binary tree
            if(temp->left==NULL&&temp->right==NULL){
                if(i==depth) res++;
                break;
            }
            TreeNode* father=temp;
            temp=temp->left;
            int d=i+1;
            while(temp->right!=NULL){
                d++;
                temp=temp->right;
            }
            if(d==depth){
                res=res+(1<<(depth-i-1));
                temp=father->right;
            }else{
                temp=father->left;
            }
            i++;
        }
        
        //3.caculate all the nodes
        res=res+(1<<depth)-1;
        
        return res;
    }
};
