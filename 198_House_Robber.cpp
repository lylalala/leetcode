class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        vector<int> res(nums.size(),0);
        res[0]=nums[0];
        res[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            res[i]=max(res[i-1],res[i-2]+nums[i]);
        }
        return res.back();
    }
};
