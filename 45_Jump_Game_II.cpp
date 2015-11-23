//贪心算法，O(N)
class Solution {
public:
    int jump(vector<int>& nums) {
        int res=1;
        vector<int> maxPos(1,0);
        //不用动就可以
        if(nums[0]>=0&&nums.size()==1)
            return 0;
        //第一步可以到达则为真
        if(nums[0]>=nums.size()-1)
            return 1;
        maxPos.push_back(nums[0]);
        while(1){
            res++;
            int maxNum=0;
            //版本1：区间弄错
            //for(int i=maxPos[maxPos.size()-2];i<maxPos[maxPos.size()-1];i++){
            for(int i=maxPos[maxPos.size()-2]+1;i<=maxPos[maxPos.size()-1];i++){
                maxNum=(maxNum>i+nums[i])?maxNum:i+nums[i];
            }
            if(maxNum>=nums.size()-1)
                return res;
            maxPos.push_back(maxNum);
        }
    }
};
