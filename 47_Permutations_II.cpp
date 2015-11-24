class Solution {
private:
    vector<vector<int>> result;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.size()<1)
            return result;
        sort(nums.begin(),nums.end(),less_equal<int>());
        vector<bool> use(nums.size(),true);
        vector<int> res;
        recursion(nums,use,res,1);
        return result;
    }
    
    int recursion(vector<int>& nums, vector<bool>& use, vector<int>& res, int depth){
        if(depth>use.size())
            result.push_back(res);
        else{
            int nono=-100;
            for(int i=0;i<use.size();i++){
                if(use[i]&&nums[i]!=nono){
                    res.push_back(nums[i]);
                    use[i]=false;
                    recursion(nums,use,res,depth+1);
                    use[i]=true;
                    res.pop_back();
                    nono=nums[i];
                }
            }
        }
    }
};
