//---------------------------------------------------------------------------------------------------------------
//41题 First Missing Positive
//4ms,5.78%
//考虑到将数组遍历一次，每访问一个数据的时候，将它交换到以它的值-1为下标的地方
//  1.它小于0，就等着别人来换走它；
//  2.它大于等于数组长度，则它也是无效数组
//例如：[3 4 -1 1] -> [-1 4 3 1] -> [-1 4 3 1] ->[-1 4 3 1] -> [1 4 3 -1]
//但是存在问题：如果某个很小的正整数在数组后面，前面存在一个正整数和它交换，那么这个小数还是不在正确的位置上
//例如[-1 4 2 1 9 10]
//改进:交换后检查换过来的数字如果是小数，是不是在正确位置上
//
//刘阳，2015.10.10
//liuyang070424@163.com/liuyang070424@gmail.com
//---------------------------------------------------------------------------------------------------------------

//出错代
/*
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0&&nums[i]<nums.size()){//交换nums[i]和nums[nums[i]-1]位置上的数据
                int temp=nums[i];
                int pos=nums[i]-1;
                nums[i]=nums[nums[i]-1];
                nums[pos]=temp;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1)
                return i+1;
        }
        return nums.size()+1;
    }
};
*/

class Solution {
public:
    void swapNum(vector<int>& num,int a,int b){
        int temp=num[a];
        num[a]=num[b];
        num[b]=temp;
    }
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            while(nums[i]>0&&nums[i]<nums.size()&&nums[i]!=i+1&&nums[nums[i]-1]!=nums[i]){//交换nums[i]和nums[nums[i]-1]位置上的数据
                int pos=nums[i]-1;
                swapNum(nums,i,pos);
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1)
                return i+1;
        }
        return nums.size()+1;
    }
    
};