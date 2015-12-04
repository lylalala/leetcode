class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row=obstacleGrid.size();
        if(row==0)
            return 0;
        int col=obstacleGrid[0].size();
        if(col==0)
            return 0;
        vector<vector<int>> arr(row,vector<int>(col,-1));
        
        solve(arr,obstacleGrid,0,0);
        return arr[0][0];
    }
    void solve(vector<vector<int>> &arr,vector<vector<int>>& obstacleGrid,int row,int col){
        if(arr[row][col]!=-1)
            return;
        if(obstacleGrid[row][col]==1){
            arr[row][col]=0;
            return;
        }
        if((row==arr.size()-1)&&(col==arr[0].size()-1)){
            arr[row][col]=1;
            return;
        }
        if(row==arr.size()-1){
            solve(arr,obstacleGrid,row,col+1);
            arr[row][col]=arr[row][col+1];
            return;
        }
        if(col==arr[0].size()-1){
            solve(arr,obstacleGrid,row+1,col);
            arr[row][col]=arr[row+1][col];
            return;
        }
        solve(arr,obstacleGrid,row+1,col);
        solve(arr,obstacleGrid,row,col+1);
        arr[row][col]=arr[row+1][col]+arr[row][col+1];
        return;
    }
};
