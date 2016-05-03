class Solution {
public:
    int canTran(string a,string b){
        int res=0;
        for(int i=0;i<a.length();i++){
            if(a[i]!=b[i]){
                res++;
            }
        }
        return res;
    }
    int bfs(unordered_set<string>& b,unordered_set<string>& e,unordered_set<string> wordList){
        if(b.size()>e.size())
            return bfs(e,b,wordList);
        for(string i:b) wordList.erase(i);
        for(string i:e) wordList.erase(i);
        unordered_set<string> dic;
        for(string i:b){
            for(int pos=0;pos<i.length();pos++){
                string temp=i;
                for(char j='a';j<='z';j++){
                    temp[pos]=j;
                    if(e.find(temp)!=e.end()){
                        return 2;
                    }
                    if(wordList.find(temp)!=wordList.end()){
                        dic.insert(temp);
                    }
                }
            }
        }
        if(wordList.empty()||dic.empty())
            return 0;
        return 1+bfs(dic,e,wordList);
    }
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        unordered_set<string> qBegin;
        unordered_set<string> qEnd;
        qBegin.insert(beginWord);
        qEnd.insert(endWord);
        // wordList.erase(beginWord);
        // wordList.erase(endWord);
        return bfs(qBegin,qEnd,wordList);
    }
};
