//---------------------------------------------------------------------------------------------------------------
//40题 Combination Sum II
//利用stack实现非递归做法，时间8ms，高于72.78%
//刘阳，2015.10.10
//liuyang070424@163.com/liuyang070424@gmail.com
//---------------------------------------------------------------------------------------------------------------
//相关总结
/*
代码主要思路：
当可以往res中加入数字的时候就加入(内层while循环)，不能加入的时候分两种情况：第一种是满足target了，这时候将res放入result中，然后从res中取出最后一个数字，跳出while；第二种是数字大了，那么直接跳出while。跳出while后先取出res最后一个数字，换下一个数字，再进while循环尝试。
错误总结：
主要是几个边界条件的处理：
 1.现阶段判断的所有数据加起来都不够满足target。
 2.
*/
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
