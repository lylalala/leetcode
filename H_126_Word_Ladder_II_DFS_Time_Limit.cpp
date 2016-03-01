inline int abs(char num1,char num2){return (num1==num2)?0:1;}
struct node{
    string word;
    int posOld;
    int posNew;
    vector<int> posFather;
    int depth;
    node(string w,int pO,int pN,int d):word(w),posOld(pO),posNew(pN),depth(d){};
};
class Solution {
    typedef unordered_set<string>::iterator ite;
public:
    vector<vector<string>> result;
    vector<string> res;
    string start;
    
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector<string> words;
        start=beginWord;
        for(ite it=wordList.begin();it!=wordList.end();it++)
            words.push_back(*it);
        vector<string>::iterator it=find(words.begin(), words.end(), endWord);
        if (it==words.end())
            words.push_back(endWord);
        else{
            string temp=*(words.end()-1);
            *(words.end()-1)=endWord;
            *it=temp;
        }
        it=find(words.begin(), words.end(), beginWord);
        if (it==words.end()) {
            words.insert(words.begin(), beginWord);
        }else{
            string temp=*(words.begin());
            *(words.begin())=beginWord;
            *it=temp;
        }
        bool notFind=true;
        
        vector<string> queueStringTemp;//存放每一层的字符串
        vector<bool> ok(words.size(),true);
        vector<node> resqueue;//搜索过的字符串及其信息都存放在这里
        vector<node> queueTemp;//存放每一层字符串及其信息
        
        int resPos=0;
        queue<node> myqueue;//广搜的队列
        node* nodeNULL=new node("",-1,-1,-1);
        node* nodeTemp=new node(beginWord,0,resPos,1);
        myqueue.push(*nodeTemp);
        myqueue.push(*nodeNULL);
        ok[0]=false;
        
        //广度搜索
        while(!myqueue.empty()){
            string stringTemp=myqueue.front().word;
            int posTemp=myqueue.front().posNew;
            int depthTemp=myqueue.front().depth;
            
            for(int i=0;i<words.size();i++){
                if(ok[i]&&simillar(stringTemp,words[i],-1)>=0){
                    if (words[i]==endWord) {
                        notFind=false;
                    }
                    vector<string>::iterator it;
                    it=find(queueStringTemp.begin(),queueStringTemp.end(),words[i]);
                    if(it==queueStringTemp.end()){//没找到
                        node* myNode=new node(words[i],i,++resPos,depthTemp+1);
                        myNode->posFather.push_back(posTemp);
                        queueTemp.push_back(*myNode);
                        queueStringTemp.push_back(words[i]);
                    }else{//找到
                        queueTemp[it-queueStringTemp.begin()].posFather.push_back(posTemp);
                    }
                }
            }
            
            resqueue.push_back(myqueue.front());
            myqueue.pop();
            
            if(myqueue.front().word==""){//到达这一层的结尾了
                //把queueTemp导入queue中
                for(int i=0;i<queueTemp.size();i++){
                    ok[queueTemp[i].posOld]=false;
                    myqueue.push(queueTemp[i]);
                }
                myqueue.pop();
                if (!queueTemp.empty()) {
                    myqueue.push(*nodeNULL);
                }
                if(!notFind){
                    break;
                }
                queueTemp.clear();
                queueStringTemp.clear();
            }
        }
        
        it=find(queueStringTemp.begin(), queueStringTemp.end(), endWord);
        if (it==queueStringTemp.end()) {
            return result;
        }
        //将答案整理输出,深度搜索
        res.push_back(endWord);
        for (int i=0; i<queueTemp[it-queueStringTemp.begin()].posFather.size(); i++) {
            ds(resqueue,queueTemp[it-queueStringTemp.begin()].posFather[i]);
        }
        return result;
    }
    void ds(vector<node>& resqueue,int pos){//传过来是父亲的位置
        if (pos==0) {
            res.insert(res.begin(), start);
            result.push_back(res);
            res.erase(res.begin());
        }else{
            for (int i=0; i<resqueue[pos].posFather.size(); i++) {
                res.insert(res.begin(), resqueue[pos].word);
                ds(resqueue, resqueue[pos].posFather[i]);
                res.erase(res.begin());
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
        if (/*pos!=thispos&&*/thisres==1) {
            return thispos;
        }
        return -1;
    }
    
};
