class Solution {
private:
    vector<vector<int>> result;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size()<1)
            return result;
        vector<bool> use(nums.size(),true);
        vector<int> res;
        recursion(nums,use,res,1);
        return result;
    }
    
    int recursion(vector<int>& nums, vector<bool>& use, vector<int>& res, int depth){
        if(depth==use.size()){
            for(int i=0;i<use.size();i++){
                if(use[i]){
                    res.push_back(nums[i]);
                    result.push_back(res);
                    res.pop_back();
                    break;
                }
            }
        }else{
            for(int i=0;i<use.size();i++){
                if(use[i]){
                    res.push_back(nums[i]);
                    use[i]=false;
                    recursion(nums,use,res,depth+1);
                    use[i]=true;
                    res.pop_back();
                }
            }
        }
    }
};
