class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> res;
        if(edges.empty()){
            res.push_back(0);
            return res;
        }
            
        unordered_map<int,unordered_set<int>> tree;
        for(int i=0;i<edges.size();i++){
            tree[edges[i].first].insert(edges[i].second);
            tree[edges[i].second].insert(edges[i].first);
        }
        while(tree.size()!=1&&tree.size()!=2){
            unordered_map<int,int> temp;
            for(auto it=tree.begin();it!=tree.end();it++){
                if(it->second.size()==1){
                    temp[it->first]=*(it->second.begin());
                }
            }
            for(auto it=temp.begin();it!=temp.end();it++){
                auto that=tree.find(it->first);
                tree.erase(that);
                tree[it->second].erase(it->first);
            }
        }
        
        for(auto it=tree.begin();it!=tree.end();it++)
            res.push_back(it->first);
        return res;
    }
};
