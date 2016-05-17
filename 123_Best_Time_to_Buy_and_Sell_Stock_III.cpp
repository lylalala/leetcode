class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)
            return 0;
        vector<int> fi(prices.size(),0);
        int minNum=prices[0];
        for(int i=1;i<prices.size();i++){
            fi[i]=max(prices[i]-minNum,fi[i-1]);
            if(prices[i]<minNum) minNum=prices[i];
        }
        int result=fi.back();
        int maxNum=prices.back();
        int se=0;
        for(int i=prices.size()-2;i>=2;i--){
            se=max(maxNum-prices[i],se);
            result=max(result,fi[i]+se);
            if(prices[i]>maxNum) maxNum=prices[i];
        }
        return result;
    }
};
