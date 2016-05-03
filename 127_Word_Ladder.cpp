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
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        wordList.insert(endWord);
        wordList.erase(beginWord);
        queue<string> myqueue;
        myqueue.push(beginWord);
        myqueue.push("");
        int res=1;
        while(myqueue.front()!=""){
            res++;
            unordered_set<string> dic;
            while(myqueue.front()!=""){
                string temp=myqueue.front();
                myqueue.pop();
                // for(string i:wordList){
                //     if(canTran(i,temp)==1){
                //         if(i==endWord) return res;
                //         dic.insert(i);
                //     }
                // }
                string temp0=temp;
                for(int i=0;i<temp.size();i++){
                    temp0=temp;
                    for(char it='a';it<='z';it++){
                        temp0[i]=it;
                        if(wordList.find(temp0)!=wordList.end()){
                            if(temp0==endWord)
                                return res;
                            dic.insert(temp0);
                        }
                    }
                }
            }
            for(string i:dic){
                myqueue.push(i);
                wordList.erase(i);
            }
            myqueue.pop();
            myqueue.push("");
        }
        return 0;
    }
};
