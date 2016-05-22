class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<int> myS;
        unordered_map<char,int> tree;
        unordered_map<char,bool> ok;
        for(int i=0;i<s.length();i++){
            tree[s[i]]++;
        }
        for(char i='a';i<='z';i++){
            ok[i]=false;
        }
        for(int i=0;i<s.length();i++){
            if(!ok[s[i]]){
                while(!myS.empty()&&myS.top()>s[i]&&tree[myS.top()]>0){
                    ok[myS.top()]=false;
                    myS.pop();
                }
                myS.push(s[i]);
                ok[s[i]]=true;
                tree[s[i]]--;
            }else
                tree[s[i]]--;
        }
        string res(myS.size(),'0');
        for(int i=myS.size()-1;i>=0;i--){
            res[i]=myS.top();
            myS.pop();
        }
        return res;
    }
};
