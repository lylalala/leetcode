class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> num(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=grid.size()-1;i>=0;i--)
            for(int j=grid[0].size()-1;j>=0;j--){
                if((i==grid.size()-1)&&(j==grid[0].size()-1)) num[i][j]=grid[i][j];
                else{ 
                    if(i==grid.size()-1) num[i][j]=num[i][j+1]+grid[i][j];
                    else{
                        if(j==grid[0].size()-1) num[i][j]=num[i+1][j]+grid[i][j];
                        else num[i][j]=min(num[i+1][j],num[i][j+1])+grid[i][j];
                    }
                }
            }
        return num[0][0];
    }
};
