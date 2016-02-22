class Solution {
private:
    int res;
    int l;
    int u;
public:
    //typedef vector<int>::iterator it;
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if(nums.size()==0)
            return 0;
        res=0;
        l=lower;
        u=upper;
        vector<long long> preSum(1,nums[0]);
        for(int i=1;i<nums.size();i++)
            preSum.push_back(preSum[i-1]+nums[i]);
        mergeSort(preSum,int(preSum.size()));
        return res;
    }
    vector<long long> mergeSort(vector<long long>& sum,int n){
        if(n>1){
            int i=n/2,j=n-i;
            vector<long long> left;
            vector<long long> right;
            left.assign(sum.begin(),sum.begin()+i);
            right.assign(sum.begin()+i,sum.end());
            vector<long long> resLeft=mergeSort(left,i);
            vector<long long> resRight=mergeSort(right,j);
            vector<long long> resArray(n,0);
            int low=0;
            int high=0;
            for(int pos=0;pos<right.size();pos++){
                /*low=lower_bound(resLeft.begin(),resLeft.end(),resRight[pos]-l);
                 high=lower_bound(resLeft.begin(),resLeft.end(),resRight[pos]-u);
                 res+=(int)(low-high);
                 if(high!=resLeft.end()&&*high==resRight[pos]-l)
                 res++;*/
                while ((low<resLeft.size())&&(resLeft[low]<resRight[pos]-u)) {
                    low++;
                }
                while ((high<resLeft.size())&&(resLeft[high]<=resRight[pos]-l)) {
                    high++;
                }
                res+=(high-low);
            }
            for(int pos=int(resArray.size())-1;pos>=0;pos--){
                if(j==0||(i>0&&resRight[j-1]<resLeft[i-1])){
                    resArray[pos]=resLeft[i-1];
                    i--;
                }else{
                    resArray[pos]=resRight[j-1];
                    j--;
                }
            }
            return resArray;
        }else{
            if(sum[0]>=l&&sum[0]<=u)
                res++;
            return sum;
        }
    }
    
};

