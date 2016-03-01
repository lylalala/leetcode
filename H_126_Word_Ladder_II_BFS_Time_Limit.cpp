//深度优先搜索剪枝难度太大，不适合这类搜索
//这里最麻烦之处是如何记录下来自己的父节点，而且搜索路径不止一条
class Solution {
private:
    string end;
    vector<vector<string>> res;
    vector<string> result;
    int min;
    typedef unordered_set<string>::iterator point;
public:
    inline int abs(char num1,char num2){return (num1==num2)?0:1;}
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        min=INT_MAX;
        end=endWord;
        vector<bool> ok(wordList.size(),true);
        result.push_back(beginWord);
        DS(beginWord,wordList,ok,-1,1);
        return res;
    }
    void DS(string begin,unordered_set<string> &wordList,vector<bool> &ok,int pos,int depth){
        if (depth<=min) {
            if(simillar(begin,end,pos)>-1){
                result.push_back(end);
                if (depth<min) {
                    min=depth;
                    res.clear();
                }
                res.push_back(result);
                result.pop_back();
            }else{
                point it;
                int i;
                for(it=wordList.begin(),i=0;it!=wordList.end();it++,i++){
                    int temp=simillar(*it,begin,pos);
                    if(ok[i]&&temp>-1&&norepeat(*it)){
                        result.push_back(*it);
                        ok[i]=false;
                        DS(*it,wordList,ok,temp,depth+1);
                        ok[i]=true;
                        result.pop_back();
                    }
                }
            }
        }
    }
    bool norepeat(string str){
        for (int i=0; i<result.size()-1; i++) {
            if (simillar(str, result[i], -1)>-1) {
                return false;
            }
        }
        return true;
    }
    int simillar(string a,string b,int pos){
        int thisres=0;
        int thispos=0;
        for(int i=0;i<a.length();i++){
            if (abs(a[i], b[i])==1) {
                thispos=i;
                thisres++;
                if (thisres>1) {
                    break;
                }
            }
        }
        if (pos!=thispos&&thisres==1) {
            return thispos;
        }
        return -1;
    }
};
