//---------------------------------------------------------------------------------------------------------------
//40题 Combination Sum II
//递归做法，时间16ms，高于41.36%
//刘阳，2015.10.10
//liuyang070424@163.com/liuyang070424@gmail.com
//---------------------------------------------------------------------------------------------------------------

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> res;
        sort(candidates.begin(),candidates.end(),less_equal<int>());
        vector<int> sumRest;
        int rest=target;
        int sum=0;
        //int nonDuplicate=-1;
        for(vector<int>::reverse_iterator it=candidates.rbegin();it!=candidates.rend();it++){
            sum+=(*it);
            sumRest.insert(sumRest.begin(),sum);
        }
        combination(result,candidates,sumRest,rest,res,0);
        return result;
    }
    void combination(vector<vector<int>>& result,vector<int>& num,vector<int> &sumRest,int rest,vector<int> res,int i){
        if(rest==0){
            result.push_back(res);
            return;
        }
        int nonDuplicate=-1;//设置来避免重复结果，即：被抛弃的数字没有必要再利用，所以nonDuplicate等于被抛弃的数字，while循环要保证它不再出现
        for(int it=i;it<num.size();it++){
            if(num[it]<=rest&&sumRest[it]>=rest){
                //while(it+1<num.size()&&num[it]==num[it+1])
                //    it++;
                //while(it+1<num.size()&&num[it]==nonDuplicate)
                //    it++;
                while(num[it]==nonDuplicate){
                    if(it+1>=num.size())
                        return;
                    it++;
                }
                res.push_back(num[it]);
                combination(result,num,sumRest,rest-num[it],res,it+1);
                nonDuplicate=res[res.size()-1];
                res.pop_back();
            }
        }
    }
};
