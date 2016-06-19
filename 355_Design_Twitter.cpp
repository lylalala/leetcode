class Twitter {
private:
    int orderId;
    struct Node{
        int id;
        int userId;
        int tweetId;
        Node(int order,int user,int tweet){
            id=order;
            userId=user;
            tweetId=tweet;
        }
    };
    struct cmp{
        bool operator()(const Node a,const Node b){
            return a.id<b.id;
        }
    };
    unordered_map<int,vector<pair<int,int> > > selfInfo;
    unordered_map<int,vector<int> > relation;//1 follows 2, relation[1].push_back(2);
    
public:
    /** Initialize your data structure here. */
    Twitter() {
        selfInfo.clear();
        relation.clear();
        orderId=0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        selfInfo[userId].insert(selfInfo[userId].begin(),make_pair(orderId,tweetId));
        orderId++;
        if(selfInfo[userId].size()>10)
            selfInfo[userId].pop_back();
        follow(userId, userId);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        map<int,int> pos;
        priority_queue<Node,vector<Node>,cmp> q;
        for(int i=0;i<relation[userId].size();i++){
            if(selfInfo.find(userId)!=selfInfo.end()){
                pos[relation[userId][i]]=0;
            }
        }
        for(int i=0;i<10;i++){
            if(q.empty()){
                for(int j=0;j<relation[userId].size();j++){
                    if(selfInfo.find(relation[userId][j])!=selfInfo.end()&&pos[relation[userId][j]]<selfInfo[relation[userId][j]].size()){
                        Node temp(selfInfo[relation[userId][j]][pos[relation[userId][j]]].first,relation[userId][j],selfInfo[relation[userId][j]][pos[relation[userId][j]]].second);
                        q.push(temp);
                        pos[relation[userId][j]]++;
                    }
                }
            }
            if(q.empty()) break;
            int who=q.top().userId;
            res.push_back(q.top().tweetId);
            q.pop();
            if(pos[who]<selfInfo[who].size()){
                Node temp(selfInfo[who][pos[who]].first,who,selfInfo[who][pos[who]].second);
                q.push(temp);
                pos[who]++;
            }
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(find(relation[followerId].begin(),relation[followerId].end(),followeeId)==relation[followerId].end())
            relation[followerId].push_back(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(followerId==followeeId) return;
        auto it=find(relation[followerId].begin(),relation[followerId].end(),followeeId);
        if(it!=relation[followerId].end()){
            relation[followerId].erase(it);
        }
    }
};
