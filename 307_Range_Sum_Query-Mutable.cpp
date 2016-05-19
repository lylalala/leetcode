class NumArray {
private:
    vector<int> arr;
    vector<int> s;
public:
    NumArray(vector<int> &nums) {
        arr=nums;
        if(arr.size()>0){
            s.push_back(arr[0]);
            for(int i=1;i<arr.size();i++)
                s.push_back(arr[i]+s.back());
        }
    }

    void update(int i, int val) {
        if(i<arr.size()){
            int temp=val-arr[i];
            arr[i]=val;
            for(int k=i;k<arr.size();k++)
                s[k]+=temp;
        }
    }

    int sumRange(int i, int j) {
        if(i==0)
            return s[j];
        else
            return s[j]-s[i-1];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
