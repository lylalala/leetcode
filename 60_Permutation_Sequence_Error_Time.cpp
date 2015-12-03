//dps
class Solution {
private:
    string res;
    int which;
    int whichfind;
public:
    string getPermutation(int n, int k) {
        string num(n,'0');
        vector<bool> ok(n,true);
        res=num;
        which=0;
        whichfind=k;
        for(int i=1;i<=n;i++)
            num[i-1]=i+'0';
        return solve(num,ok,0);
    }
    string solve(string& num,vector<bool> &ok,int depth){
        if(depth==num.size()){
            which++;
            return res;
        }else{
            for(int i=0;i<num.size();i++){
                if(ok[i]){
                    res[depth]=num[i];
                    ok[i]=false;
                    string thisres=solve(num,ok,depth+1);
                    if(which==whichfind)
                        return thisres;
                    ok[i]=true;
                }
            }
            return res;
        }
    }
};
