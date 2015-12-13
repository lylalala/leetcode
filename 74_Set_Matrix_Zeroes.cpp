//i make a mistake to write "row[i]" as "i"
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> row;
        vector<int> col;
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        if(row.empty())
            return;
        else{
            //sort(row.begin(),row.end(),less<int>());
            sort(col.begin(),col.end(),less<int>());
            int pre=-1;
            for(int i=0;i<row.size();i++){
                if(row[i]==pre)
                    continue;
                for(int j=0;j<matrix[0].size();j++)
                    matrix[row[i]][j]=0;
                pre=row[i];
            }
            pre=-1;
            for(int j=0;j<col.size();j++){
                if(col[j]==pre)
                    continue;
                for(int i=0;i<matrix.size();i++)
                    matrix[i][col[j]]=0;
                pre=col[j];
            }
        }
    }
};
