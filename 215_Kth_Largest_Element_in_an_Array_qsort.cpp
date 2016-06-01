class Solution {
public:
    int find(vector<int>& nums,int b,int e,int k){
        if(b==e)
            return nums[b];
        int flag=nums[b];
        int bb=b,ee=e;
        while(bb<ee){
            while(bb<ee&&nums[ee]<=flag)
                ee--;
            nums[bb]=nums[ee];
            while(bb<ee&&nums[bb]>flag)
                bb++;
            nums[ee]=nums[bb];
        }
        nums[bb]=flag;
        if(bb-b+1==k)
            return nums[bb];
        else if(bb-b+1<k)
            return find(nums,bb+1,e,k-(bb-b+1));
        else
            return find(nums,b,bb-1,k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        return find(nums,0,nums.size()-1,k);
    }
};
