//Memory Limit Exceeded
//i think the divide and conquer approach is not a concise approach
//when the two parts are being merging, it can not avoid to traverse the two parts

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return solve(nums,0,nums.size());
    }
    int solve(vector<int> nums,int left,int right){
        if(left+1==right)
            return nums[left];
        int mid=(left+right)/2;
        int leftMax=solve(nums,left,mid);
        int rightMax=solve(nums,mid,right);
        
        int leftMaxFromMid=INT_MIN;
        int rightMaxFromMid=INT_MIN;
        int sumNum;
        sumNum=0;
        for(int i=mid-1;i>=left;i--){
            sumNum+=nums[i];
            leftMaxFromMid=max(leftMaxFromMid,sumNum);
        }
        if(leftMaxFromMid<0)
            return max(leftMax,rightMax);
        sumNum=0;
        for(int i=mid;i<right;i++){
            sumNum+=nums[i];
            rightMaxFromMid=max(rightMaxFromMid,sumNum);
        }
        if(rightMaxFromMid<0)
            return max(leftMax,rightMax);
        return max(max(leftMaxFromMid+rightMaxFromMid,leftMax),rightMax);
    }
};
