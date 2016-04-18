class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        vector<vector<int> > arr(matrix.size(),vector<int>(matrix[0].size()+1,0));
        for(int i=0;i<matrix[0].size();i++){
            if(matrix[0][i]=='1')
                arr[0][i]=1;
        }
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='1'){
                    arr[i][j]=arr[i-1][j]+1;
                }
            }
        }
        int res=0;
        for(int i=0;i<arr.size();i++){
            stack<int> pos;
            for(int j=0;j<arr[0].size();){
                if(!pos.empty()&&arr[i][j]<arr[i][pos.top()]){
                    int tempPos=pos.top();
                    pos.pop();
                    res=max(res,arr[i][tempPos]*((pos.empty())?j:j-pos.top()-1));
                }else
                    pos.push(j++);
            }
        }
        return res;
    }
};
