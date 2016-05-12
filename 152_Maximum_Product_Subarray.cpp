class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> arr(nums.size(),0);
        int start=0;
        int fn=-1;
        int ln=-1;
        int res=0;
        int result=nums[0];
        bool zero=false;
        for(int i=0;i<=nums.size();i++){
            if(i==nums.size()||nums[i]==0){
                if(i<nums.size()) zero=true;
                if(i-start==1)
                    result=max(result,res);
                else if(res<0){
                    res=max(res/arr[fn],arr[ln-1]);
                }
                result=max(res,result);
                start=i+1;
                fn=ln=-1;
                res=0;
                continue;
            }else if(nums[i]<0){
                if(fn==-1){
                    fn=ln=i;
                }else
                    ln=i;
            }
            if(res!=0)
                res=res*nums[i];
            else
                res=nums[i];
            arr[i]=res;
        }
        return zero?max(0,result):result;
    }
};
