class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> pos;
        int res=0;
        for(int i=0;i<heights.size();){
            if(!pos.empty()&&heights[pos.top()]>heights[i]){
                int tempPos=pos.top();
                pos.pop();
                res=max(res,heights[tempPos]*((pos.empty())?i:i-pos.top()-1));
            }else{
                pos.push(i++);
            }
        }
        return res;
    }
};
