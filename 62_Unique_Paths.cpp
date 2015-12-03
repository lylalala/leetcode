//a easy problem
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> array(m+1,vector<int>(n+1,-1));
        solve(array,m,n);
        return array[m][n];
    }
    void solve(vector<vector<int>> &arr,int row,int col){
        if(row==1||col==1){
            arr[row][col]=1;
            return;
        }else{
            if(arr[row-1][col]==-1)
                solve(arr,row-1,col);
            if(arr[row][col-1])
                solve(arr,row,col-1);
            arr[row][col]=arr[row-1][col]+arr[row][col-1];
        }
    }
};
