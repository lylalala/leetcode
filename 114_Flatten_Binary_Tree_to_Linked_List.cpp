class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* temp=root;
        while(temp!=NULL){
            if(temp->left!=NULL){
                TreeNode* last=temp->left;
                while(last->right!=NULL)
                    last=last->right;
                last->right=temp->right;
                temp->right=temp->left;
                temp->left=NULL;
            }
            temp=temp->right;
        }
    }
};
