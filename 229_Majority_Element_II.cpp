class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n1,n2,w1,w2;
        vector<int> res;
        n1=n2=0;
        for(int i=0;i<nums.size();i++){
            if(n1>0&&nums[i]==w1){n1++;continue;}
            if(n2>0&&nums[i]==w2){n2++;continue;}
            if(n1==0){n1++;w1=nums[i];continue;}
            if(n2==0){n2++;w2=nums[i];continue;}
            n1--;n2--;
        }
        n1=n2=0;
        if(w1==w2)
            w2++;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==w1) n1++;
            if(nums[i]==w2) n2++;
        }
        if(n1*3>nums.size()) res.push_back(w1);
        if(n2*3>nums.size()) res.push_back(w2);
        return res;
    }
};
