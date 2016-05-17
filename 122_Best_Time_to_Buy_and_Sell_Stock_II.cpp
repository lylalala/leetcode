class Solution {
 public:
     int maxProfit(vector<int> &prices) {
         int len = prices.size();
         if(len <= 1)return 0;
         int res = 0;
         for(int i = 0; i < len-1; i++)
             if(prices[i+1]-prices[i] > 0)
                 res += prices[i+1] - prices[i];
         return res;
     }
 };
