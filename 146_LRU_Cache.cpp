class LRUCache{
private:
    list<pair<int,int>> mylist;
    unordered_map<int,list<pair<int,int>>::iterator> mymap;
    int cap;
    int len;
public:
    LRUCache(int capacity) {
        cap=capacity;
        len=0;
    }
    
    int get(int key) {
        unordered_map<int,list<pair<int,int>>::iterator>::iterator it=mymap.find(key);
        if(it==mymap.end())
            return -1;
        else{
            pair<int,int> temp=*(it->second);
            mylist.erase(it->second);
            mylist.push_front(temp);
            mymap[key]=mylist.begin();
            return mylist.begin()->second;
        }
    }
    
    void set(int key, int value) {
        unordered_map<int,list<pair<int,int>>::iterator>::iterator it=mymap.find(key);
        if(it==mymap.end()){
            if(len==cap){//删除再添加
                mymap.erase(mylist.rbegin()->first);
                mylist.pop_back();
            }else{
                len++;
            }
            mylist.push_front(pair<int,int>(key,value));
            mymap[key]=mylist.begin();
        }else{
            get(key);
            mylist.begin()->second=value;
        }
    }
};
