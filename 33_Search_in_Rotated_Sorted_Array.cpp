class Solution {
public:
    int search(vector<int>& nums,int b,int e,int target){
        if(b+1==e||b==e){
            if(nums[b]==target) return b;
            else if(nums[e]==target) return e;
            return -1;
        }
        int mid=(b+e)/2;
        if(nums[mid]==target)
            return mid;
        else if(nums[0]<nums[mid]){
            if(target<nums[mid]&&target>=nums[0])
                return search(nums,b,mid-1,target);
            else
                return search(nums,mid+1,e,target);
        }else{
            if(target<nums[mid]||target>=nums[0])
                return search(nums,b,mid-1,target);
            else
                return search(nums,mid+1,e,target);
        }
    }
    int search(vector<int>& nums, int target) {
        return search(nums,0,nums.size()-1,target);
    }
};
