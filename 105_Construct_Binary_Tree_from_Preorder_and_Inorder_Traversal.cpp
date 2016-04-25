//下标老弄错
class Solution {
public:
    TreeNode* buildTreeDFS(vector<int>& preorder,int Pbegin,int Pend,vector<int>& inorder,int Ibegin,int Iend){
        if(Pend<=Pbegin) return NULL;
        TreeNode* res=new TreeNode(preorder[Pbegin]);
        int pos=0;
        for(int i=Ibegin;i<Iend;i++){
            if(res->val==inorder[i]){
                pos=i;
                break;
            }
        }
        int len1=pos-Ibegin;
        int len2=Iend-Ibegin-len1-1;
        if(len1!=0) res->left=buildTreeDFS(preorder,Pbegin+1,Pbegin+len1+1,inorder,Ibegin,Ibegin+len1);
        if(len2!=0) res->right=buildTreeDFS(preorder,Pbegin+len1+1,Pend,inorder,pos+1,Iend);
        return res;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeDFS(preorder,0,preorder.size(),inorder,0,inorder.size());
    }
};
