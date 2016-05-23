//深搜超时
// class Solution {
// public:
//     bool solve(string s,unordered_set<string>& wordDict,int pos){
//         if(pos==s.length())
//             return true;
//         for(unordered_set<string>::iterator it=wordDict.begin();it!=wordDict.end();it++){
//             int len=it->length();
//             if(len<=s.length()-pos&&s.substr(pos,len)==(*it)&&solve(s,wordDict,pos+len)){
//                 return true;
//             }
//         }
//         return false;
//     }
//     bool wordBreak(string s, unordered_set<string>& wordDict) {
//         return solve(s,wordDict,0);
//     }
// };
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<bool> dp(s.length(),false);
        dp[0]=true;
        for(int i=1;i<=s.length();i++){
            for(int j=i-1;j>=0;j--){
                if(dp[j]&&wordDict.find(s.substr(j,i-j))!=wordDict.end()){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};
