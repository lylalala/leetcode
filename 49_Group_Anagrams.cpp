//the old version 100ms
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        if(strs.size()==1&&strs[0]==""){
            vector<string> newString(1,"");
            result.push_back(newString);
            return result;
        }
        map<string,int> hashTB;
        int i=0;
        for(vector<string>::iterator it=strs.begin();it!=strs.end();it++){
            string sortString=*it;
            vector<char> charVec(sortString.begin(),sortString.end());
            sort(charVec.begin(),charVec.end(),less_equal<char>());
            sortString.clear();
            sortString.assign(charVec.begin(),charVec.end());
            map<string,int>::iterator pos=hashTB.find(sortString);
            if(pos==hashTB.end()){
                hashTB.insert(pair<string,int>(sortString,i));
                i++;
                vector<string> newString;
                newString.push_back(*it);
                result.push_back(newString);
            }else{
                result[pos->second].push_back(*it);
            }
        }
        for(i=0;i<result.size();i++)
            sort(result[i].begin(),result[i].end());
        return result;
    }
};



//new version:use unorder_map
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        if(strs.size()==0) return result;
        unordered_map<string,int> hashTB;
        int i=0;
        for(vector<string>::iterator it=strs.begin();it!=strs.end();it++){
            string sortString=*it;
            sort(sortString.begin(),sortString.end());
            auto pos=hashTB.find(sortString);
            if(pos==hashTB.end()){
                hashTB.insert(pair<string,int>(sortString,i++));
                result.push_back(vector<string>(1,*it));
            }
            else result[pos->second].push_back(*it);
        }
        for(i=0;i<result.size();)
            sort(result[i++].begin(),result[i].end());
        return result;
    }
};
