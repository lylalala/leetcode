class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> res(amount+1,INT_MAX);
        res[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(i-coins[j]>=0&&res[i-coins[j]]!=INT_MAX)
                    res[i]=min(res[i],res[i-coins[j]]+1);
            }
        }
        if(res.back()==INT_MAX)
            return -1;
        else
            return res.back();
    }
};
