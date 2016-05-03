/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int str2int(string str){
    int res=0;
    for(int i=0;i<str.length();i++){
        res=res*10+(str[i]-'0');
    }
    return res;
}
string int2str(int num){
    if(num==0)
        return "0";
    if(num<0)
        return "-"+int2str(0-num);
    string res="";
    while(num!=0){
        string temp="0";
        temp[0]=(num%10)+'0';
        num=num/10;
        res=temp+res;
    }
    return res;
}
class Solution {
private:
    int res;
    string temp;
public:
    void dfs(TreeNode* root){
        if(root->left==NULL&&root->right==NULL){
            temp=temp+int2str(root->val);
            res=res+str2int(temp);
            temp=temp.substr(0,temp.length()-1);
            return;
        }
        temp=temp+int2str(root->val);
        if(root->left!=NULL)
            dfs(root->left);
        if(root->right!=NULL)
            dfs(root->right);
        temp=temp.substr(0,temp.length()-1);
    }
    int sumNumbers(TreeNode* root) {
        temp="";
        res=0;
        if(root!=NULL)
            dfs(root);
        return res;
    }
};
