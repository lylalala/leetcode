class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        // if(nums.empty()||nums.back()<n)
        //     nums.push_back(n);
        long sum=0;
        int res=0;
        for(int i=0;i<nums.size();i++){
            while(nums[i]>sum+1&&sum<=n){
                sum=(sum<<1)+1;
                res++;
            }
            if(sum>n) return res;
            sum=sum+nums[i];
        }
        while(n>sum){
            sum=(sum<<1)+1;
            res++;
        }
        return res;
    }
};
