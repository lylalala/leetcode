class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int arr=0;
        arr=(nums[0]==0)?1:0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==0){
                arr++;
            }else
                nums[i-arr]=nums[i];
        }
        for(int i=nums.size()-arr;i<nums.size();i++)
            nums[i]=0;
    }
};
