class Solution {
public:
    int findMin(vector<int>& nums) {
        int f=0;
        int l=nums.size()-1;
        int m;
        while(f<=l){
            if(f==l)
                return nums[f];
            else if(l-1==f)
                return min(nums[f],nums[l]);
            m=(f+l)/2;
            if(nums[f]>nums[m]){
                l=m;
            }else if(nums[m+1]<=nums[l]){
                return min(nums[f],nums[m+1]);
            }else{
                f=m+1;
            }
        }
        return 0;
    }
};
