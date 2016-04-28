//class Solution {
//public:
//    bool increasingTriplet(vector<int>& nums) {
//        if(nums.size()<3)
//            return false;
//        vector<int> maxArray(nums.size(),nums.back());
//        vector<int> minArray(nums.size(),nums[0]);
//        for(int i=1;i<nums.size();i++){
//            minArray[i]=min(minArray[i-1],nums[i]);
//        }
//        for(int i=nums.size()-2;i>=0;i--){
//            maxArray[i]=max(maxArray[i+1],nums[i]);
//        }
//        for(int i=1;i<nums.size()-1;i++){
//            if(minArray[i-1]<nums[i]&&nums[i]<maxArray[i+1])
//                return true;
//        }
//        return false;
//    }
//};
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3)
            return false;
        int i=0;
        for(;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1])
                break;
        }
        int min1=nums[i++];
        int min2=nums[i++];
        for(;i<nums.size();i++){
            if(nums[i]<min1)
                min1=nums[i];
            else if(nums[i]<min2&&nums[i]>min1)
                min2=nums[i];
            else if(nums[i]>min2)
                return true;
        }
        return false;
    }
};