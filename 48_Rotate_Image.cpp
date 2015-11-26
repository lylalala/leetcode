class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size()==0)
            return;
        int length=matrix.size();
        //加1下取整
        for(int i=0;i<(length+1)/2;i++)
            //下取整
            for(int j=0;j<length/2;j++){
                swap(matrix[j][length-i-1],matrix[i][j]);
                swap(matrix[i][j],matrix[length-j-1][i]);
                swap(matrix[length-j-1][i],matrix[length-i-1][length-j-1]);
            }
    }
};
