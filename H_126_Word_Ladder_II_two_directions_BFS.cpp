inline int abs(char num1,char num2){return (num1==num2)?0:1;}
class Solution {
    typedef vector<string> vecStr;
    typedef unordered_set<string> setStr;
    typedef unordered_map<string,vecStr> mapStr2VecStr;
    string end;
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector<vecStr> result;
        vecStr path(1,beginWord);
        if(beginWord==endWord){
            result.push_back(path);
            return result;
        }
        end=endWord;
        //双向bfs
        setStr begin;
        setStr end;
        begin.insert(beginWord);
        end.insert(endWord);
        setStr words(wordList);
        mapStr2VecStr tree;
        bool flip=false;
        if(buildTree(begin,end,words,tree,flip))//双向bfs
            //output
            getPath(result,path,tree,beginWord);//dfs得到答案
        return result;
    }
    bool buildTree(setStr& begin,setStr& end,setStr& words,mapStr2VecStr& tree,bool flip){
        if (begin.empty()||words.empty()) {
            return false;
        }
        if(begin.size()>end.size()){//那边搜索代价小就从哪边搜索
            return buildTree(end,begin,words,tree,!flip);
        }
        setStr intermediate;
        for(string word:begin) words.erase(word);
        for(string word:end) words.erase(word);
        bool findPath=false;
        for(string w:begin){
            for(string i:end){
                if(simillar(w,i,-1)>-1){
                    findPath=true;
                    flip?tree[i].push_back(w):tree[w].push_back(i);
                }
            }
            if(!findPath){
                for(string i:words){
                    if(simillar(w,i,-1)>-1){
                        flip?tree[i].push_back(w):tree[w].push_back(i);
                        intermediate.insert(i);
                    }
                }
            }
        }
        return findPath||buildTree(intermediate,end,words,tree,flip);
    }
    void getPath(vector<vecStr> &result,vecStr& path,mapStr2VecStr &tree,string word){
        if(end==word){
            result.push_back(path);
        }else{
            for(string i:tree[word]){
                path.push_back(i);
                getPath(result,path,tree,i);
                path.pop_back();
            }
        }
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
        if (thisres==1) {
            return thispos;
        }
        return -1;
    }
};

