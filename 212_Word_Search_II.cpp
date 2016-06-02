class TrieNode{
public:
    bool isEnd;
    vector<TrieNode*> next;
    TrieNode(){
        isEnd=false;
        next.resize(26,NULL);
    }
};

class Trie{
private:
    TrieNode* root;
public:
    Trie(){
        root=new TrieNode();
    }
    void insert(string str){
        TrieNode* temp=root;
        for(int i=0;i<str.length();i++){
            if(temp->next[str[i]-'a']==NULL)
                temp->next[str[i]-'a']=new TrieNode();
            temp=temp->next[str[i]-'a'];
        }
        temp->isEnd=true;
    }
    TrieNode* getRoot(){
        return root;
    }
};

class Solution {
private:
    unordered_set<string> res;
public:
    void find(vector<vector<char>>& board,int x,int y,TrieNode* root,string& tmp){
        if(x<0||y<0||x>=board.size()||y>=board[0].size()||board[x][y]==' ') return;
        char it=board[x][y];
        root=root->next[it-'a'];
        if(root==NULL) return;
        string temp(1,' ');
        temp[0]=board[x][y];
        tmp=tmp+temp;
        if(root->isEnd)
            res.insert(tmp);
        board[x][y]=' ';
        find(board,x-1,y,root,tmp);
        find(board,x+1,y,root,tmp);
        find(board,x,y-1,root,tmp);
        find(board,x,y+1,root,tmp);
        board[x][y]=it;
        tmp=tmp.substr(0,tmp.length()-1);
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie tree;
        for(string str:words) tree.insert(str);
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                string temp="";
                find(board,i,j,tree.getRoot(),temp);
            }
        }
        vector<string> result;
        for(string str:res) result.push_back(str);
        return result;
    }
};
