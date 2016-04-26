class Solution {
public:
    bool isScramble(string s1, string s2) {
        int len=s1.length();
        if(len!=s2.length()) return false;
        bool*** dp=new bool**[len];
        for(int i=0;i<len;i++){
            dp[i]=new bool*[len];
            for(int j=0;j<len;j++)
                dp[i][j]=new bool[len];
        }
        for(int j=0;j<len;j++)
            for(int k=0;k<len;k++)
                dp[0][j][k]=(s1[j]==s2[k]);
        for(int i=2;i<=len;i++){
            for(int j=0;j+i<=len;j++){
                for(int k=0;k+i<=len;k++){
                    dp[i-1][j][k]=false;
                    for(int m=1;m<=i-1;m++){
                        if((dp[m-1][j][k]&&dp[i-m-1][j+m][k+m])||(dp[m-1][j][k+i-m]&&dp[i-m-1][j+m][k]))
                            dp[i-1][j][k]=true;
                    }
                }
            }
        }
        
        return dp[len-1][0][0];
    }
};

