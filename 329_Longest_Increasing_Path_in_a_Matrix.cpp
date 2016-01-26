int a[4]={0,-1,0,1};
int b[4]={-1,0,1,0};
class Solution {
private:
    int row;
    int col;
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size()==0)
            return 0;
        int res=-1;
        row=matrix.size();
        col=matrix[0].size();
        vector<vector<int>> depth(row,vector<int>(col,-1));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                depth[i][j]=solve(matrix,depth,i,j);
                if(depth[i][j]>res)
                    res=depth[i][j];
            }
        }
        return res;
    }
    bool ok(int i,int j){
        if(i>=0&&j>=0&&i<row&&j<col)
            return true;
        else
            return false;
    }
    int solve(vector<vector<int>>& matrix,vector<vector<int>>& depth,int i,int j){
        if(depth[i][j]!=-1)
            return depth[i][j];
        int max=1;
        for(int dir=0;dir<4;dir++){
            int ii=i+a[dir];
            int jj=j+b[dir];
            if(ok(ii,jj)&&matrix[ii][jj]<matrix[i][j]){
                int temp=solve(matrix,depth,ii,jj);
                if(temp+1>max)
                    max=temp+1;
            }
        }
        depth[i][j]=max;
        return max;
    }
};
