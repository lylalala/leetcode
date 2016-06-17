class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2) return 0;
        int maxVal=*max_element(nums.begin(),nums.end());
        int minVal=*min_element(nums.begin(),nums.end());
        if(maxVal==minVal) return 0;
        int agGap=ceil((double)(maxVal-minVal)/nums.size());
        if(agGap==0) agGap++;
        vector<pair<int,int>> buckets(nums.size(),make_pair(INT_MIN,INT_MAX));
        for (auto val : nums){
            int bucketNum = (val - minVal) / agGap;
            if(bucketNum>=buckets.size()) bucketNum--;
            if (val > buckets[bucketNum].first)
                buckets[bucketNum].first = val; // 存储最大值
            if (val < buckets[bucketNum].second) buckets[bucketNum].second = val; // 存储最小值
        }
        int res=0;
        int preMax=buckets[0].first;
        for(int i=1;i<buckets.size();i++){
            if(buckets[i].first==INT_MIN) continue;
            res=max(res,buckets[i].second-preMax);
            preMax=buckets[i].first;
        }
        return res;
    }
};
