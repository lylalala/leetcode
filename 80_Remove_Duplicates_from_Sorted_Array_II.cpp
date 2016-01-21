class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int res=nums.size();
        int i=0,count=0;
        int temp=nums[0]-1;
        while(i<nums.size()){
            if(temp==nums[i]){
                if(count==1){
                    nums.erase(nums.begin()+i);
                    res--;
                    i--;
                }else
                    count++;
            }else{
                count=0;
                temp=nums[i];
            }
            i++;
        }
        return res;
    }
};

