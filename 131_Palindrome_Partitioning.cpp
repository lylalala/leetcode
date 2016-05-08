class Solution {
private:
    vector<vector<string>> result;
    vector<string> res;
public:
    void dfs(vector<vector<bool>>& arr,int len,string s,int pos){
        if(pos==len){
            result.push_back(res);
        }else{
            for(int i=pos+1;i<=len;i++){
                if(arr[pos][i]){
                    res.push_back(s.substr(pos,i-pos));
                    dfs(arr,len,s,i);
                    res.pop_back();
                }
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int len=s.length();
        vector<vector<bool>> arr(len,vector<bool>(len+1,false));
        for(int i=0;i<len;i++)
            arr[i][i+1]=true;
        for(int i=0;i<len-1;i++)
            if(s[i]==s[i+1]) arr[i][i+2]=true;
        for(int l=3;l<=len;l++){
            for(int i=0;i<len-l+1;i++){
                if(arr[i+1][i+l-1]&&s[i]==s[i+l-1]) arr[i][i+l]=true;
            }
        }
        dfs(arr,len,s,0);
        return result;
    }
};
