//核心在二分查找，四个注意点
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.empty()||nums2.empty()){
            if(nums1.empty()) nums1.swap(nums2);
            if(nums1.size()%2==1)
                return nums1[nums1.size()/2];
            else
                return ((double)(nums1[nums1.size()/2]+nums1[nums1.size()/2-1]))/2;
        }
        double res=0;
        int findPos=(nums1.size()+nums2.size()+1)/2;
        int pos[2]={0,0};
        int first,second,middle;
        vector<int>::iterator it;
        first=0;
        second=nums1.size()-1;//注意点1：指向最后一个数据
        while(first<=second){//注意点2：等于
            middle=(first+second)/2;
            it=upper_bound(nums2.begin(),nums2.end(),nums1[middle]);
            if(middle+1+(it-nums2.begin())<=findPos){//注意点3：等于
                first=middle+1;//注意点4：进入等于的那个不是答案
            }else{
                second=middle-1;
            }
        }
        pos[0]=second;
        //it=upper_bound(nums2.begin(),nums2.end(),nums[second]);
        findPos-=(second+1);
        pos[1]=findPos-1;
        if((nums1.size()+nums2.size())%2==1){
            return nums1[pos[0]]>nums2[pos[1]]?nums1[pos[0]]:nums2[pos[1]];
        }else{
            double temp=nums1[pos[0]]>nums2[pos[1]]?nums1[pos[0]]:nums2[pos[1]];
            double temp2=0;
            if((pos[1]==nums2.size()-1)||(pos[0]!=nums1.size()-1&&(nums1[pos[0]+1]<nums2[pos[1]+1])))
                temp2=nums1[pos[0]+1];
            else
                temp2=nums2[pos[1]+1];
            return (temp+temp2)/2;
        }
    }
};

/*
 int upper(int pos1,int pos2,int value){
 int first=pos1,second=pos2-1;
 int middle;
 while(first<=second){
 middle=(first+second)/2;
 if(arr[middle]<=value){
 first=middle+1;
 }else{
 second=middle-1;
 }
 }
 return first;
 }
 */
