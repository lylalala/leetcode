class Solution {
private:
    vector<string> result;
    vector<string> res;
    int minLen;
    int maxLen;
public:
    void dfs(string s,unordered_set<string>& wordDict,vector<bool>& dp,int pos){
        if(pos==s.length()){
            string temp="";
            for(int i=0;i<res.size();i++){
                temp=temp+res[i]+" ";
            }
            result.push_back(temp.substr(0,temp.length()-1));
        }else{
            for(int len=minLen;len<=maxLen&&(pos+len)<=s.length();len++){
                string temp=s.substr(pos,len);
                if(dp[pos+len]&&wordDict.find(temp)!=wordDict.end()){
                    res.push_back(temp);
                    dfs(s,wordDict,dp,pos+len);
                    res.pop_back();
                }
            }
        }
    }
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        if(s.length()==0||wordDict.empty()) return result;
        minLen=INT_MAX;
        maxLen=INT_MIN;
        for(string str:wordDict){
            minLen=min(minLen,int(str.length()));
            maxLen=max(maxLen,int(str.length()));
        }
        vector<bool> dp(s.length()+1,false);
        dp[0]=true;
        for(int i=1;i<=s.length();i++){//i is the position of end(STL standard end)
            int len;
            for(int j=i-minLen,len=minLen;j>=0&&len<=maxLen;j--,len++){//j is the position of begin
                if(dp[j]&&(wordDict.find(s.substr(j,i-j))!=wordDict.end())){
                    dp[i]=true;
                }
            }
        }
        if(!dp.back()) return result;
        
        dfs(s,wordDict,dp,0);
        return result;
    }
};
