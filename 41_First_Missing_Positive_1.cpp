//---------------------------------------------------------------------------------------------------------------
//41题 First Missing Positive
//额外申请了一个和原数组大小相同的数组，时间4ms，高于5.78%
//刘阳，2015.10.10
//liuyang070424@163.com/liuyang070424@gmail.com
//---------------------------------------------------------------------------------------------------------------


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int *array=new int[nums.size()+1];//第一次运行时只考虑了nums一定有数的情况所以采用了int[nums.size()]，所以nums为空的时候跑不通
        memset(array,-1,(nums.size()+1)*sizeof(int));
        for(vector<int>::iterator it=nums.begin();it!=nums.end();it++){
            if(*it>0)
                array[(*it)-1]=1;
        }
        for(int i=0;i<nums.size()+1;i++){
            if(array[i]!=1)
                return i+1;
        }
    }
};