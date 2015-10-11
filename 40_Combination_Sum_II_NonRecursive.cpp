class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(),candidates.end(),less_equal<int>());//从小到大排序
        /*vector<int> sumRest;//做一个存放sum的数组，来判断i有没有必要继续往下做，比如[1 3 4]和10的情景
         int sum=0;
         for(vector<int>::reverse_iterator it=candidates.rbegin();it!=candidates.rend();it++){
         sum+=(*it);
         sumRest.insert(sumRest.begin(),sum);
         }*/
        vector<int> res;
        int i=0,rest=target;//i是当前处理数字的position，j遍历到candidates.end()的时候遍历结束
        stack<int> posStack;
        //while(j<candidates.size()){
        while(1){
            while(1){
                if(candidates[i]>rest){//当前数据大于剩余的数据，则跳出压栈，进行出栈
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
                //if(sumRest[i]<rest)
                //    break;
                if(i>=candidates.size()){//从j开始后所有的数据加起来也不够target的情况，则要先出栈一个数据再跳出循环后出栈
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
            }else//当res里面没有数字并且当前数字较大（或者等于）的时候，直接结束这个程序
                return result;
            /*if(posStack.empty())
             j++;*/
        }
        return result;
    }
};
