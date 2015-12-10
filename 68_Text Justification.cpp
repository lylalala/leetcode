//greedy
class Solution {
public:
    string getstring(vector<string>& ss,int maxWidth,int length){
        int morespace=maxWidth-length;
        int average=morespace/(ss.size()-1);
        int more=morespace%(ss.size()-1);
        string result="";
        for(int j=0;j<ss.size();j++){
            result+=ss[j];
            if(j<ss.size()-1)
                result=(more-->0)?result+string(2+average,' '):result+string(1+average,' ');
        }
        return result;
    }
    string getstring2(vector<string>& ss,int maxWidth,int length){
        string result=ss[0];
        for(int i=1;i<ss.size();i++)
            result=result+" "+ss[i];
        result=result+string(maxWidth-length,' ');
        return result;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        if(words.empty())
            return res;
        vector<string> thisone;
        int length=0;
        string result="";
        for(int i=0;i<words.size();i++){
            if(length+1+words[i].length()<=maxWidth&&(!thisone.empty())){
                length+=(words[i].length()+1);
                thisone.push_back(words[i]);
                if(i==words.size()-1){
                    result=result=getstring2(thisone,maxWidth,length);
                    res.push_back(result);
                }
            }else if(words[i].length()<=maxWidth&&thisone.empty()){
                length+=(words[i].length());
                thisone.push_back(words[i]);
                if(i==words.size()-1){
                    result=thisone[0]+string(maxWidth-thisone[0].size(),' ');
                    res.push_back(result);
                }
            }else{
                //deal with "thisone"
                if(thisone.size()==1){
                    result=thisone[0]+string(maxWidth-thisone[0].size(),' ');
                    res.push_back(result);
                }else{
                    result=getstring(thisone,maxWidth,length);
                    res.push_back(result);
                }
                
                thisone.clear();
                result="";
                length=0;
                i--;
            }
        }
        return res;
    }
};
