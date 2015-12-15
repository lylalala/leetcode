class Solution {
public:
    void sortColors(vector<int>& nums) {
        int first=0;
        int second=nums.size()-1;
        while(first<second){
            while(first<second&&nums[first]==0)
                first++;
            while(first<second&&nums[second]!=0)
                second--;
            swap(nums[first],nums[second]);
        }
        second=nums.size()-1;
        while(first<second){
            while(first<second&&nums[first]==1)
                first++;
            while(first<second&&nums[second]!=1)
                second--;
            swap(nums[first],nums[second]);
        }
    }
};

//better solution
void sortColors(vector<int>& nums) {
    int zero =0, l = 0, r = nums.size()-1;
    while (l <= r) {
        if (nums[l] == 0)
            swap(nums[l++], nums[zero++]);
        else if (nums[l] == 2)
            swap(nums[l], nums[r--]);
        else
            l++;
    }
}
