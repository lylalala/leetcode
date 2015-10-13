//---------------------------------------------------------------------------------------------------------------
//42题 Trapping Rain Water
//利用while循环来得到各个"峰值"，求取每两个峰值之间的数据。思路错误，例如[12,1,2,2,3,4,1,2,3,12]的情况下，此办法错误
//刘阳，2015.10.13
//liuyang070424@163.com/liuyang070424@gmail.com
//---------------------------------------------------------------------------------------------------------------

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<=1)
            return 0;
        vector<pair<int,int>> maxHeight;
        int temp=0,res=0;
        int i=0;
        bool flag=false;
        for(;i<=height.size()-2;){
            while(i+1<height.size()&&height[i+1]<=height[i])//下降区间
                i++;
            if(i+1<height.size()&&height[i+1]>=height[i]){//如果是上升区间，则flag是真，后面需要记录顶点值
                i++;
                flag=true;
            }
            while(i+1<height.size()&&height[i+1]>=height[i])//遍历完上升区间，挑选最值
                i++;
            if(flag){//记录最值
                maxHeight.push_back(make_pair(i,height[i]));
                flag=false;
            }
        }
        if(maxHeight.size()<=1)
            return 0;
        for(vector<pair<int,int>>::iterator it=maxHeight.begin();it!=maxHeight.end();it++){
            temp=(it+1)->second<it->second?(it+1)->second:(it)->second;
            for(int j=it->first;j<(it+1)->first;j++)
                if(temp-height[j]>0)
                    res+=(temp-height[j]);
        }
        temp=height[0]>maxHeight[0].second?maxHeight[0].first:height[0];
        for(int j=0;j<=maxHeight[0].first;j++)
            if(temp-height[j]>0)
                res+=(temp-height[j]);
        return res;
    }
    
};
