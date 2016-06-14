class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> help;
        for(int i=0;i<nums.size();i++){
            int left=0,right=help.size();
            while(left<right){
                int mid=(left+right)/2;
                if(help[mid]<nums[i])
                    left=mid+1;
                else
                    right=mid;
            }
            if(left>=help.size())
                help.push_back(nums[i]);
            else
                help[left]=nums[i];
        }
        return help.size();
    }
};
