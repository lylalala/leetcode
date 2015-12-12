class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1=word1.length();
        int l2=word2.length();
        if(l1==0||l2==0)
            return max(l1,l2);
        vector<vector<int>> res(l1+1,vector<int>(l2+1,-1));
        //res[0][0]=0;
        for(int i=0;i<=l1;i++){
            for(int j=0;j<=l2;j++){
                if(i==0) res[i][j]=j;
                if(j==0) res[i][j]=i;
                if(i!=0&&j!=0){
                    if(word1[i-1]==word2[j-1])
                        res[i][j]=res[i-1][j-1];
                    else
                        res[i][j]=min(min(res[i-1][j],res[i][j-1]),res[i-1][j-1])+1;
                }
            }
        }
        return res[l1][l2];
    }
};
