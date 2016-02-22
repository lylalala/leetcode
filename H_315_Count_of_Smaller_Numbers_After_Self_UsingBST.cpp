struct MyTreeNode{
    int data;
    int count;
    MyTreeNode* left;
    MyTreeNode* right;
    MyTreeNode(int d):data(d),count(1),left(NULL),right(NULL){};
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.size()==0) {
            return nums;
        }
        vector<int> res(nums.size(),0);
        if (nums.size()==1) {
            return res;
        }
        MyTreeNode* root=new MyTreeNode(nums.back());
        for (int i=(int)nums.size()-2; i>=0; i--) {
            res[i]=insert(root, nums[i]);
        }
        return res;
    }
    int insert(MyTreeNode* root,int d){
        int res=0;
        MyTreeNode* temp=root;
        MyTreeNode* father=root;
        int lor;
        while (temp!=NULL) {
            //insert to the right
            if (temp->data>=d) {
                temp->count++;
                father=temp;
                temp=temp->left;
                lor=1;
            }
            //insert to the left
            else{
                if (temp->left!=NULL) {
                    res+=(temp->left->count);
                }
                res++;
                temp->count++;
                father=temp;
                temp=temp->right;
                lor=2;
            }
        }
        if(lor==1)
            father->left=new MyTreeNode(d);
        else
            father->right=new MyTreeNode(d);
        return res;
    }
};