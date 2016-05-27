class Solution {
public:
    int solve(vector<int>& nums,int b,int e){
        if(b==e){
            if(nums[b]==b)
                return b+1;
            else
                return b;
        }else{
            int flag=nums[b];
            int bb=b,ee=e;
            while(bb<ee){
                while(bb<ee&&nums[ee]>flag)
                    ee--;
                nums[bb]=nums[ee];
                while(bb<ee&&nums[bb]<flag)
                    bb++;
                nums[ee]=nums[bb];
            }
            nums[bb]=flag;
            if(bb==nums[bb]){
                if(bb==e)
                    return e+1;
                else
                    return solve(nums,bb+1,e);
            }else{
                if(bb==b)
                    return b;
                else
                    return solve(nums,b,bb-1);
            }
        }
    }
    int missingNumber(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);
    }
};
