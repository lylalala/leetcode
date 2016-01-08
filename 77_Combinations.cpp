class Solution {
private:
    vector<vector<int>> result;
    vector<int> res;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<bool> ok(n+1,true);
        com(0,k,ok);
        return result;
    }
    void com(int dep,int k,vector<bool> &ok){
        if(dep==k){
            result.push_back(res);
        }
        else{
            for(int i=1;i<ok.size();i++){
                if(ok[i]&&(res.empty()||i>res[res.size()-1])){
                    ok[i]=false;
                    res.push_back(i);
                    com(dep+1,k,ok);
                    res.pop_back();
                    ok[i]=true;
                }
            }
        }
    }
};
