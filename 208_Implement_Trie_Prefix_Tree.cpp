class TrieNode {
public:
    bool isEnd;
    TrieNode** next;
    // Initialize your data structure here.
    TrieNode() {
        isEnd=false;
        next = new TrieNode*[26]();
    }
    ~TrieNode(){
        for(int i=0;i<26;i++)
            delete next[i];
        delete[] next;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* temp=root;
        for(int i=0;i<word.length();i++){
            if(temp->next[word[i]-'a']==NULL){
                temp->next[word[i]-'a']=new TrieNode();
            }
            temp=temp->next[word[i]-'a'];
        }
        temp->isEnd=true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* temp=root;
        for(int i=0;i<word.length();i++){
            if(temp->next[word[i]-'a']==NULL)
                return false;
            temp=temp->next[word[i]-'a'];
        }
        if(temp->isEnd)
            return true;
        else
            return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* temp=root;
        for(int i=0;i<prefix.length();i++){
            if(temp->next[prefix[i]-'a']==NULL)
                return false;
            temp=temp->next[prefix[i]-'a'];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
