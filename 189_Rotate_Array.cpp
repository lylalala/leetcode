class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        if(k==n||k==0)
            return;
        if(n%k==0||n%(n-k)==0){
            if(n-k>k){
                for(int i=0;i<k;i++){
                    int temp=nums[i];
                    int pos=i;
                    for(int j=0;j<n/k;j++){
                        pos=(pos+k)%n;
                        swap(nums[pos],temp);
                    }
                }
            }else{
                for(int i=0;i<n-k;i++){
                    int temp=nums[i];
                    int pos=i;
                    for(int j=0;j<n/(n-k);j++){
                        pos=(pos+k)%n;
                        swap(nums[pos],temp);
                    }
                }
            }
        }else{
            int times=0;
            int pos=0;
            int temp=nums[0];
            while(times<n){
                pos=(pos+k)%n;
                swap(nums[pos],temp);
                times++;
            }
        }
        return;
    }
};
