class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(),0);
        int e=1;
        bool zero=false;
        int zeroPos=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                if(zero)
                    return res;
                zero=true;
                zeroPos=i;
                continue;
            }else
                e=e*nums[i];
        }
        if(zero){
            res[zeroPos]=e;
            return res;
        }
        for(int i=0;i<nums.size();i++){
            res[i]=e/nums[i];
        }
        return res;
    }
};
