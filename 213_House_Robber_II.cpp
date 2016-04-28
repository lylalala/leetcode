class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        vector<int> res1(nums.size(),0);
        vector<int> res2(nums.size(),0);
        res1[0]=nums[0];
        res2[0]=0;
        res1[1]=max(nums[0],nums[1]);
        res2[1]=nums[1];
        for(int i=2;i<nums.size();i++){
            res1[i]=max(res1[i-1],res1[i-2]+nums[i]);
            res2[i]=max(res2[i-1],res2[i-2]+nums[i]);
        }
        if(res1.back()==res2.back())
            return res1.back();
        else{
            if(res1[res1.size()-1]==res1[res1.size()-2])
                return res1.back();
            else
                return max(res2.back(),res1[res1.size()-2]);
        }
    }
};
