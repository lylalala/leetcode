class NumArray {
private:
    vector<int> arr;
public:
    NumArray(vector<int> &nums) {
        arr.resize(nums.size(),nums[0]);
        for(int i=1;i<nums.size();i++){
            arr[i]=arr[i-1]+nums[i];
        }
    }

    int sumRange(int i, int j) {
        return arr[j]-(i<=0?0:arr[i-1]);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
