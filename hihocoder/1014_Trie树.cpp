#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <stack>
using namespace std;
int const INF = 0x3fffffff;

struct TreeNode{
    int val;
    map<char,TreeNode*> arr;
    TreeNode(int n):val(n){};
};

class tree{
private:
    TreeNode* root;
public:
    tree(){
        root=new TreeNode(0);
    }
    void insert(string str){
        TreeNode* temp=root;
        for(int i=0;i<str.length();i++){
            map<char,TreeNode*>::iterator it=temp->arr.find(str[i]);
            if(it!=temp->arr.end()){//找到了
                temp=it->second;
                temp->val++;
            }else{
                TreeNode* t=new TreeNode(1);
                temp->arr[str[i]]=t;
                temp=t;
            }
        }
    }
    int search(string str){
        TreeNode* temp=root;
        int res=0;
        for(int i=0;i<str.length();i++){
            map<char,TreeNode*>::iterator it=temp->arr.find(str[i]);
            if(it!=temp->arr.end()){
                temp=it->second;
                if(i==str.length()-1){
                    res=temp->val;
                }
            }else{
                break;
            }
        }
        return res;
    }
};

int main()
{
    int Q;
    cin>>Q;
    string temp;
    tree mytree;
    while(Q--)
    {
        cin>>temp;
        mytree.insert(temp);
    }
    cin>>Q;
    while(Q--){
        cin>>temp;
        cout<<mytree.search(temp)<<endl;
    }
    return 0;
}

