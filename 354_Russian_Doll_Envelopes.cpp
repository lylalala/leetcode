bool comp(pair<int,int>& a,pair<int,int>& b){
    if(a.first==b.first) return a.second>b.second;
    return a.first<b.first;
}
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if(envelopes.empty())
            return 0;
        sort(envelopes.begin(),envelopes.end(),comp);
        vector<int> help;
        for(int i=0;i<envelopes.size();i++){
            int left=0,right=help.size();
            while(left<right){
                int mid=(left+right)/2;
                if(help[mid]<envelopes[i].second)
                    left=mid+1;
                else
                    right=mid;
            }
            if(left>=help.size())
                help.push_back(envelopes[i].second);
            else
                help[left]=envelopes[i].second;
        }
        return help.size();
    }
};
