class Solution {
private:
    vector<int> result;
    vector<vector<int>> res;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<bool> ok(nums.size(),true);
        sort(nums.begin(),nums.end(),less_equal<int>());
        for(int i=0;i<=nums.size();i++){
            solve(i,ok,0,nums,0);
        }
        return res;
    }
    void solve(int depth,vector<bool> &ok,int realDepth,vector<int> &nums,int which){
        if(realDepth==depth){
            res.push_back(result);
            return;
        }else{
            for(int i=which;i<ok.size();i++){
                if(ok[i]){
                    ok[i]=false;
                    result.push_back(nums[i]);
                    solve(depth,ok,realDepth+1,nums,i+1);
                    result.pop_back();
                    ok[i]=true;
                }
            }
        }
    }
};
