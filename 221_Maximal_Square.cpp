class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
            return 0;
        int res=0;
        vector<vector<pair<int,int>>> dp(matrix[0].size(),vector<pair<int,int>>());
        for(int i=0;i<matrix.size();i++){
            int temp=0;
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='1'){
                    temp++;
                    if(temp<=res){
                        dp[j].clear();
                        continue;
                    }
                    if(dp[j].empty()){
                        dp[j].push_back(pair<int,int>(1,temp));
                        res=max(res,1);
                    }else{
                        bool add=true;//增加新值
                        vector<int> de;
                        for(int k=0;k<dp[j].size();k++){
                            if(max(dp[j][k].first,dp[j][k].second)<=res){
                                de.push_back(k);
                                continue;
                            }
                            if(dp[j][k].second<temp){//上小 下大
                                dp[j][k].first++;
                            }
                            else{//上大或者等于 下小
                                dp[j][k].first++;
                                dp[j][k].second=temp;
                                add=false;
                            }
                            res=max(min(dp[j][k].first,dp[j][k].second),res);
                        }
                        for(int i=de.size()-1;i>=0;i--)
                            dp[j].erase(dp[j].begin()+de[i]);
                        if(add&&temp>res)
                            dp[j].push_back(pair<int,int>(1,temp));
                    }
                }else{
                    temp=0;
                    dp[j].clear();
                }
            }
        }
        return res*res;
    }
};
