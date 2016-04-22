class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1=s1.length();
        int len2=s2.length();
        if(len1+len2!=s3.length())
            return false;
        vector<vector<bool>> dp(len1+1,vector<bool>(len2+1,false));
        dp[0][0]=true;
        // if(s1[0]==s3[0])
        //     dp[1][0]=true;
        for(int i=0;i<len2;i++){
            if(s2[i]==s3[i]){
                dp[0][i+1]=true;
            }else
                break;
        }
        for(int i=0;i<len1;i++){
            if(s1[i]==s3[i]){
                dp[i+1][0]=true;
            }else
                break;
        }
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                // if((dp[i][j+1]||dp[i+1][j])&&)
                if((dp[i-1][j]&&s1[i-1]==s3[i+j-1])||(dp[i][j-1]&&s2[j-1]==s3[i+j-1]))
                    dp[i][j]=true;
            }
        }
        return dp[len1][len2];
    }
};
