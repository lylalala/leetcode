//没有考虑到正括号要在前
class Solution {
private:
    vector<string> result;
    string res;
    int nn;
public:
    void dfs(int now,int r){
        if(now==0&&r==0)
            result.push_back(res);
        else if(r>0){
            //left
            now++;
            res=res+"(";
            if(now<=nn&&now>=0){
                dfs(now,r-1);
            }
            //right
            now-=2;
            res=res.substr(0,res.length()-1);
            res=res+")";
            if(now<=nn&&now>=0){
                dfs(now,r-1);
            }
            res=res.substr(0,res.length()-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        res="";
        int r=n*2;
        nn=n;
        int now=0;
        dfs(now,r);
        return result;
    }
};
