class Solution {
private:
    typedef UndirectedGraphNode gNode;
    //typedef pair<int,gNode*> pa;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==NULL)
            return NULL;
        queue<gNode*> q;
        unordered_map<int,gNode*> tree;
        gNode* newRoot=new UndirectedGraphNode(node->label);
        
        q.push(node);
        //tree.insert(pa(newRoot->label,newRoot));
        tree[newRoot->label]=newRoot;
        q.push(NULL);
        gNode* t=newRoot;
        while(q.front()!=NULL){
            while(q.front()!=NULL){
                gNode* temp=q.front();
                q.pop();
                t=tree[temp->label];
                for(int i=0;i<temp->neighbors.size();i++){
                    unordered_map<int,gNode*>::iterator it=tree.find(temp->neighbors[i]->label);
                    if(it!=tree.end()){
                        t->neighbors.push_back(it->second);
                    }else{
                        gNode* newNode=new UndirectedGraphNode(temp->neighbors[i]->label);
                        t->neighbors.push_back(newNode);
                        tree[temp->neighbors[i]->label]=newNode;
                        q.push(temp->neighbors[i]);
                    }
                }
            }
            q.pop();
            q.push(NULL);
        }
        return newRoot;
    }
};
