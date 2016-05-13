class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<1)
            return 0;
        vector<int> ma(n,prices.back());
        for(int i=n-2;i>=0;i--){
            ma[i]=max(ma[i+1],prices[i]);
        }
        int res=0;
        int mi=prices[0];
        for(int i=0;i<n-1;i++){
            mi=min(mi,prices[i]);
            int pro=ma[i+1]-mi;
            res=(res>pro)?res:pro;
        }
        return res>0?res:0;
    }
};
