class Solution {
private:
    vector<vector<int>> result;
    vector<int> res;
    int getUpper(int k){
        return (18-k+1)*k/2;
    }
public:
    void solve(int k,int pos,int n){
        if(k==0&&n==0)
            result.push_back(res);
        if(k>(9-pos)||getUpper(k)<n||pos+1>n)
            return;
        for(int i=pos+1;i<=9;i++){
            res.push_back(i);
            solve(k-1,i,n-i);
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        solve(k,0,n);
        return result;
    }
};
