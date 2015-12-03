class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        int top=0,left=0,bottom=n-1,right=n-1;
        int step=1;
        while(1){
            for(int i=left;i<=right;i++)
                res[top][i]=step++;
            top++;
            if(top>bottom) break;
            
            for(int i=top;i<=bottom;i++)
                res[i][right]=step++;
            right--;
            if(left>right) break;
            
            for(int i=right;i>=left;i--)
                res[bottom][i]=step++;
            bottom--;
            if(bottom<top) break;
            
            for(int i=bottom;i>=top;i--)
                res[i][left]=step++;
            left++;
            if(right<left) break;
        }
        return res;
    }
};
