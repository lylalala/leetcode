//---------------------------------------------------------------------------------------------------------------
//42题 Trapping Rain Water
//8ms,27.97%
//记录已扫描值中第二大小的值
//参考了http://www.xuebuyuan.com/1586534.html
//刘阳，2015.10.10
//liuyang070424@163.com/liuyang070424@gmail.com
//---------------------------------------------------------------------------------------------------------------


class Solution {
public:
    int trap(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int res=0;
        int secHeight=0;
        while(right-left>1){
            if(height[left]>=height[right]){
                secHeight=(secHeight>=height[right])?secHeight:height[right];
                res=(height[right-1]>secHeight)?res:res+secHeight-height[right-1];
                right--;
            }else{
                secHeight=(secHeight>=height[left])?secHeight:height[left];
                res=(height[left+1]>secHeight)?res:res+secHeight-height[left+1];
                left++;
            }
        }
        return res;
    }
};