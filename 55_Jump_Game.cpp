class Solution {
public:
    //版本二：前两个版本思路错，当有一堆0的时候必须遍历完所有的路径才能知道false，这是不科学的
    /*bool canJump(vector<int>& nums) {
        return jump(nums,0)?true:false;
    }
    bool jump(vector<int>& nums, int pos){
        if(nums[pos]+pos>=nums.size()-1)
            return true;
        //版本一：数据量很大的时候超时
        //for(int i=1;i<nums[pos];i++){
        for(int i=nums[pos];i>=1;i--){
            if(nums[pos+i]!=0&&jump(nums,pos+i))
                return true;
        }
        return false;
    }*/
    bool canJump(vector<int>& nums){
        if(nums.size()==1)
            return true;
        if(nums[0]==0)
            return false;
        //版本四：用了两个vector可能导致执行时间过长
        /*vector<int> max;
        vector<int> pos;
        max.push_back(nums[0]);
        pos.push_back(0);
        for(int i=1;i<nums.size();i++){
            if(i!=nums.size()-1){
                if(nums[i]+(i-pos[i-1])>=max[i-1]){
                    if(nums[i]==0)
                        return false;
                    max.push_back(nums[i]);
                    pos.push_back(i);
                }
                else{
                    max.push_back(max[i-1]);
                    pos.push_back(pos[i-1]);
                }
            }else{
                if(nums[i]==0&&nums[i]+i-pos[i-1]>max[i-1])
                    return false;
            }
        }*/
        int maxNum=nums[0];
        for(int i=1;i<nums.size()-1;i++){
            maxNum--;
            if(maxNum<0)
                return false;
            if(nums[i]>maxNum)
                maxNum=nums[i];
        }
        maxNum--;
        if(maxNum<0)
            return false;
        //版本三：发现只要遍历一次的办法
        /*int num;
        for(int i=0;i<nums.size();i++){
            num=0;
            if(nums[i]==0){
                int j;
                for(j=i;j<nums.size()&&nums[j]==0;j++)
                    num++;
                if(j==nums.size()){
                    if(max[i-1]-(i-pos[i-1]-1)<num)
                        return false;
                }
                else{
                    if(max[i-1]-(i-pos[i-1]-1)<=num)
                        return false;
                i=j;
                }
            }
        }*/
        return true;
    }
};
