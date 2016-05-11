//可以更加省空间,四种字母可以分别用两位表示
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_set<string> str;
        for(int i=0;i<int(s.length())-9;i++){
            string temp=s.substr(i,10);
            if(str.find(temp)!=str.end()&&find(res.begin(),res.end(),temp)==res.end())
                res.push_back(temp);
            else
                str.insert(temp);
        }
        return res;
    }
};
