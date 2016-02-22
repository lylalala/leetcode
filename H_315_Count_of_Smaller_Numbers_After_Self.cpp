//http://blog.csdn.net/qiaofangjie/article/details/7559843 归并排序，空间复杂度为1
//http://algobox.org/count-of-smaller-numbers-after-self/ 可乐大神的JAVA解法
typedef struct tuple{
    int data;
    int index;
    tuple(int d,int i):data(d),index(i){};
    tuple(const tuple &d):data(d.data),index(d.index){};
    tuple& operator=(tuple& d){
        data=d.data;
        index=d.index;
        return *this;
    }
} myvector;
class Solution {
public:
    typedef vector<myvector> tt;
    typedef vector<int> vv;
    vector<int> countSmaller(vector<int>& nums) {
        if(nums.empty())
            return nums;
        tt numsAndIndex;
        for(int i=0;i<nums.size();i++)
            numsAndIndex.push_back(myvector(nums[i],i));
        vv res(nums.size(),0);
        mergeSort(res,numsAndIndex,0,res.size());
        return res;
    }
    
    void mergeSort(vv& res,tt& nums,int begin,int end){
        if(end-begin>1){
            //i and j are lengths of the leftArray and rightArray
            int i=(end-begin)/2,j=(end-begin-i);
            //iPos and jPos are the posiztions of the end of leftArray and rightArray
            int iPos=begin+i,jPos=end;
            mergeSort(res,nums,begin,begin+i);
            mergeSort(res,nums,begin+i,end);
            tt temp(end-begin,myvector(0,0));
            for(int pos=end-begin-1;pos>=0;pos--){
                //move to the right
                if(j==0||(i>0&&nums[iPos-1].data>nums[jPos-1].data)){
                    res[nums[iPos-1].index]+=j;
                    temp[pos]=nums[--iPos];
                    i--;
                }else{
                    temp[pos]=nums[--jPos];
                    j--;
                }
            }
            for(int pos1=begin,pos2=0;pos1<end;pos1++,pos2++){
                nums[pos1]=temp[pos2];
            }
        }
    }
};

