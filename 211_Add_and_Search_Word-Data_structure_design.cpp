struct myTreeNode{
    bool end;
    unordered_map<char,myTreeNode*> tree;
    myTreeNode(bool theEnd):end(theEnd){};
};
class WordDictionary {
private:
    myTreeNode* root;
public:
    WordDictionary(){
        root=new myTreeNode(false);
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        myTreeNode* temp=root;
        for(int i=0;i<word.length();i++){
            auto it=temp->tree.find(word[i]);
            if(it==temp->tree.end()){
                temp->tree[word[i]]=new myTreeNode(false);
            }
            temp=temp->tree[word[i]];
        }
        temp->end=true;
    }
    
    bool dfs(myTreeNode* root,string word,int pos){
        if(pos==word.length()){
            if(root->end)
                return true;
        }else{
            if(word[pos]!='.'){
                auto it=root->tree.find(word[pos]);
                if(it!=root->tree.end()&&dfs(it->second,word,pos+1))
                    return true;
            }else{
                auto it=root->tree.begin();
                for(;it!=root->tree.end();it++){
                    if(dfs(it->second,word,pos+1))
                        return true;
                }
            }
        }
        return false;
    }
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return dfs(root,word,0);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
