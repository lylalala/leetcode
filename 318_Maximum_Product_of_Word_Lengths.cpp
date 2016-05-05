bool compare(string a,string b){
    return a.length()<b.length();
}
class Solution {
private:
    
public:
    int maxProduct(vector<string>& words) {
        sort(words.begin(),words.end(),compare);
        vector<int> arr(words.size(),0);
        for(int i=0;i<words.size();i++){
            unordered_set<char> temp;
            for(int j=0;j<words[i].length();j++){
                temp.insert(words[i][j]);
            }
            for(char j:temp)
                arr[i]=arr[i]+(1<<(j-'a'));
        }
        int res=0;
        for(int i=words.size()-1;i>=1;i--){
            if(words[i].length()*words[i].length()<=res)
                return res;
            for(int j=words.size()-2;j>=0;j--){
                if((arr[i]&arr[j])==0)
                    res=max(res,int(words[i].length()*words[j].length()));
            }
        }
        return res;
    }
};
