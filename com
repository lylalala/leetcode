class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(),candidates.end(),less_equal<int>());
        vector<int> res;
        int i=0,j=0,rest=target;
        stack<int> posStack;
        while(j<candidates.size()){
            while(1){
                if(candidates[i]>rest){
                    break;
                }else if(candidates[i]==rest){
                    res.push_back(candidates[i]);
                    result.push_back(res);
                    res.pop_back();
                    break;
                }
                posStack.push(i);
                rest-=candidates[i];
                res.push_back(candidates[i]);
                i++;
                if(i>=candidates.size()){
                    int pos=posStack.top();
                    posStack.pop();
                    res.pop_back();
                    rest+=candidates[pos];
                    break;
                }
            }
            int pos;
            if(!posStack.empty()){
                pos=posStack.top();
                rest+=candidates[pos];
                i=pos+1;
                while(candidates[i]==candidates[i-1])
                    i++;
                posStack.pop();
                res.pop_back();
            }else{
                i++;
                while(candidates[i]==candidates[i-1]){
                    i++;
                    j++;
                }
                if(i>=candidates.size())
                    return result;
            }
            if(posStack.empty())
                j++;
        }
        return result;
    }
};