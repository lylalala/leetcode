class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //nums.push_back(INT_MIN);
        if(nums.size()==1)
            return 0;
        int res=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                return res;
            }else{
                res++;
            }
        }
        return res;
    }
};
