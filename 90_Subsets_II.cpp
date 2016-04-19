class Solution {
private:
    vector<vector<int> > res;
    vector<int> result;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end(),less_equal<int>());
        dfs(nums,0);
        return res;
    }
    void dfs(vector<int>& nums,int pos){
        res.push_back(result);
        //int temp=INT_MIN;
        for(int i=pos;i<nums.size();i++){
            /*if(nums[i]!=temp){
                temp=nums[i];
                result.push_back(temp);
                dfs(nums,i+1);
                result.pop_back();
            }*/
            if(i==pos||nums[i]!=nums[i-1]){
                result.push_back(nums[i]);
                dfs(nums,i+1);
                result.pop_back();
            }
        }
    }
};
