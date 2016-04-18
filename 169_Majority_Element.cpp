class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res;
        int one=0;
        int two=1;
        vector<bool> ok(nums.size(),true);
        while(two<nums.size()){
            if(nums[one]!=nums[two]){
                ok[one]=false;
                ok[two]=false;
                while(!ok[one]) one++;
                while(!ok[two]) two++;
                
            }else{
                two++;
            }
        }
        return nums[one];
    }
};
