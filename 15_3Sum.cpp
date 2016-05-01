class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size()<3)
            return result;
        sort(nums.begin(),nums.end());
        int temp=nums[0]-1;
        vector<int> res;
        
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]==temp)
                continue;
            int begin=i+1;
            int end=nums.size()-1;
            while(begin<end){
                if(nums[i]+nums[begin]+nums[end]>0)
                    end--;
                else if(nums[i]+nums[begin]+nums[end]<0)
                    begin++;
                else{
                    res.clear();
                    res.push_back(nums[i]);
                    res.push_back(nums[begin]);
                    res.push_back(nums[end]);
                    result.push_back(res);
                    while(begin<end&&nums[begin]==nums[begin+1])
                        begin++;
                    begin++;
                }
            }
            temp=nums[i];
        }
        return result;
    }
};
